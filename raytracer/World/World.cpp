// this file contains the definition of the World class

#include <string>
#include <fstream>

#include "World.h"
#include "Constants.h"

// geometric objects
#include "Grid.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Instance.h"

// tracers
#include "MultipleObjects.h"
#include "RayCast.h"

// cameras
#include "Pinhole.h"

// lights
#include "Directional.h"
#include "PointLight.h"

// materials
#include "Matte.h"
#include "SV_Matte.h"
#include "Reflective.h"
#include "SV_Reflective.h"
#include "Transparent.h"

// samplers
#include "Sampler.h"
#include "Hammersley.h"
#include "Jittered.h"
#include "Regular.h"
#include "MultiJittered.h"
#include "NRooks.h"
#include "PureRandom.h"
#include "Adaptive.h"

// textures
#include "PlaneChecker.h"

// utilities
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include "Maths.h"
#include "Mesh.h"

// -------------------------------------------------------------------- default constructor
// tracer_ptr is set to NULL because the build functions will always construct the appropriate tracer
// ambient_ptr is set to a default ambient light because this will do for most scenes
// camera_ptr is set to NULL because the build functions will always have to construct a camera
// and set its parameters

World::World(void) : background_color(black), tracer_ptr(NULL), ambient_ptr(new Ambient), camera_ptr(NULL) {
}

//------------------------------------------------------------------ destructor
World::~World(void) {
    if(tracer_ptr) {
        delete tracer_ptr;
        tracer_ptr = NULL;
    }

    if (ambient_ptr) {
        delete ambient_ptr;
        ambient_ptr = NULL;
    }

    if (camera_ptr) {
        delete camera_ptr;
        camera_ptr = NULL;
    }

    delete_objects();
    delete_lights();

    if ( outfile )
        TIFFClose( outfile );
    if ( outfile_int )
        TIFFClose( outfile_int );
    if ( buffer )
        _TIFFfree( buffer );
    if ( rpp_int )
        _TIFFfree( rpp_int );
}

//------------------------------------------------------------------ render_scene
// This uses orthographic viewing along the zw axis
void World::render_scene(void) const {
    RGBColor	pixel_color;
    Ray		ray;
    int 	hres 	= vp.hres;
    int 	vres 	= vp.vres;
    double	hs	= vp.hs;
    double	vs	= vp.vs;
    double	zw	= 100.0;				// hardwired in

    ray.d = Vector3D(0, 0, -1);

    for (int r = 0; r < vres; r++) {		// up
        for (int c = 0; c <= hres; c++)	{	// across

            ray.o = Point3D( hs * (c - hres / 2.0 + 0.5), vs * (r - vres / 2.0 + 0.5), zw );
            pixel_color = tracer_ptr->trace_ray( ray );
            set_color(r, c, pixel_color);
        }
    }
}

// ------------------------------------------------------------------ clamp
RGBColor World::max_to_one(const RGBColor& c) const {
    double max_value = std::max(c.r, std::max(c.g, c.b));

    if (max_value > 1.0)
        return (c / max_value);
    else
        return (c);
}

// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one
RGBColor World::clamp_to_color(const RGBColor& raw_color) const {
    RGBColor c(raw_color);

    if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
        c.r = 1.0; c.g = 0.0; c.b = 0.0;
    }

    return (c);
}

// ---------------------------------------------------------------------------set_color
// raw_color is the pixel color computed by the ray tracer
// its RGB doubleing point components can be arbitrarily large
// mapped_color has all components in the range [0, 1], but still doubleing point
// display color has integer components for computer display
// the Mac's components are in the range [0, 65535]
// a PC's components will probably be in the range [0, 255]
// the system-dependent code is in the function convert_to_display_color
// the function SetCPixel is a Mac OS function
RGBColor World::set_color(const int row, const int column, const RGBColor& raw_color) const {
    RGBColor mapped_color;

    if (vp.show_out_of_gamut)
        mapped_color = clamp_to_color(raw_color);
    else
        mapped_color = max_to_one(raw_color);

    if (vp.gamma != 1.0)
        mapped_color = mapped_color.powc(vp.inv_gamma);

   //have to start from max y coordinate to convert to screen coordinates
   int x = column;
   int y = vp.vres - row - 1;

   return ( mapped_color );
   //paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
   //                          (int)(mapped_color.g * 255),
   //                          (int)(mapped_color.b * 255));
}

// ----------------------------------------------------------------------------- hit_objects
ShadeRec World::hit_objects(const Ray& ray) {
    ShadeRec    sr(*this);
    double      t;
    Normal      normal;
    Point3D     local_hit_point;
    double      tmin 		= kHugeValue;
    size_t      num_objects 	= objects.size();

    for (size_t j = 0; j < num_objects; j++) {
        if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
            sr.hit_an_object	= true;
            tmin 		= t;
            sr.material_ptr     = objects[j]->get_material();
            sr.hit_point 	= ray.o + t * ray.d;
            normal 		= sr.normal;			// normal at hit point
            local_hit_point	= sr.local_hit_point;
        }
    }

    if(sr.hit_an_object) {
        sr.t = tmin;
        sr.normal = normal;
        sr.local_hit_point = local_hit_point;
    }

    return(sr);
}

//------------------------------------------------------------------ delete_objects
// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it's an automatic variable, but it's empty
void World::delete_objects(void) {
    size_t num_objects = objects.size();

    for (size_t j = 0; j < num_objects; j++) {
        delete objects[j];
        objects[j] = NULL;
    }

    objects.erase (objects.begin(), objects.end());
}

//------------------------------------------------------------------ delete_lights
void World::delete_lights(void) {
    size_t num_lights = lights.size();

    for (size_t j = 0; j < num_lights; j++) {
        delete lights[j];
        lights[j] = NULL;
    }

    lights.erase (lights.begin(), lights.end());
}

// This builds a scene that consists of 35 shaded spheres and a plane.
// The objects are illuminated by a directional light and rendered with
// ambient and diffuse shading.
// Perspective viewing is used with a pinhole camera.
// Jittered sampling for antialiasing is hardwired into the PinHole::render_scene function.
// There are no sampler classes in this project.
// These are in the Chapter 5 download file.
// The spheres are the same as those in the Chapter 14 page one image.
void World::build(void) {

    uint16_t spp = 3;
    uint16_t bpp = 8;
    uint32_t rowsperstrip = (uint32_t) -1;
    linebytes = 0;
    outfile = NULL;
    outfile_int = NULL;
    buffer = NULL;
    rpp_int = NULL;

    background_color = black;			// default color - this can be left out

    // ray tracer
    tracer_ptr = new RayCast(this);

    // camera
    Pinhole* pinhole_ptr = new Pinhole;

    size_t b = 0;
    size_t e = 0;
    double dataC[19];	// camera
    double dataL[9];	// lights
    double dataS[13];	// sphere
    double dataT[16];	// triangle
    double dataP[24];	// plane
    int cnt = 0;
    std::string fName;

    std::string line;
    std::ifstream myFile ( "scene.txt" );

    if ( myFile.is_open() ) {
        while ( !myFile.eof() ) {
            getline ( myFile, line );
            if ( line.size() > 1 ) {	// in Windows, line.size() does NOT count the Carriage Return
                                        // in Linux, line.size() does count the Carriage Return
                if ( line.compare( 0, 1, "C" ) == 0 ) {
                    read_scene_def_aline( dataC, &fName, line, 19 );
                    vp.set_hres( (int)dataC[0] );
                    vp.set_vres( (int)dataC[1] );
                    vp.set_pixel_size_h( tan( 0.5 * dataC[2] * PI / 180 ) / (0.5 * vp.hres) );
                    vp.set_pixel_size_v( tan( 0.5 * dataC[3] * PI / 180 ) / (0.5 * vp.vres) );
                    vp.set_max_depth( (int)dataC[18] );
                    vp.adap_sampler = false;
                    switch ( (int)dataC[14] ) {
                        case 0:
                            vp.set_sampler( new Adaptive( (int)dataC[16], dataC[17] ) );
                            vp.adap_sampler = true;
                            outfile_int = TIFFOpen( "out_int.tif", "w" );
                            if (outfile_int == NULL) {
                                fprintf( stderr, "%s: Can not open.\n", "out_int.tif" );
                                exit(0);
                            }
                            TIFFSetField( outfile_int, TIFFTAG_IMAGEWIDTH, (uint32_t) vp.hres );
                            TIFFSetField( outfile_int, TIFFTAG_IMAGELENGTH, (uint32_t) vp.vres );
                            TIFFSetField( outfile_int, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT );
                            TIFFSetField( outfile_int, TIFFTAG_SAMPLESPERPIXEL, spp );
                            TIFFSetField( outfile_int, TIFFTAG_BITSPERSAMPLE, bpp );
                            TIFFSetField( outfile_int, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG );
                            TIFFSetField( outfile_int, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB );
                            TIFFSetField( outfile_int, TIFFTAG_COMPRESSION, COMPRESSION_PACKBITS );
                            TIFFSetField( outfile_int, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(outfile_int, rowsperstrip) );
                            linebytes = spp * vp.hres;
                            rpp_int = (unsigned char *)_TIFFmalloc( linebytes );
                            break;
                        case 1:     vp.set_sampler( new Hammersley( (int)dataC[15] ) ); break;
                        case 2:     vp.set_sampler( new Jittered( (int)dataC[15] ) ); break;
                        case 3:     vp.set_sampler( new MultiJittered( (int)dataC[15] ) ); break;
                        case 4:     vp.set_sampler( new NRooks( (int)dataC[15] ) ); break;
                        case 5:     vp.set_sampler( new PureRandom( (int)dataC[15] ) ); break;
                        case 6:     vp.set_sampler( new Regular( (int)dataC[15] ) ); break;
                        default:    break;
                    }
                    //vp.set_samples( (int)dataC[15] );	// already done by set_sampler
                    pinhole_ptr->set_eye( dataC[4], dataC[5], dataC[6] );
                    pinhole_ptr->set_up_vector( dataC[7], dataC[8], dataC[9] );
                    pinhole_ptr->set_lookat( dataC[10], dataC[11], dataC[12] );
                    pinhole_ptr->set_view_distance( dataC[13] );
                    pinhole_ptr->compute_uvw();
                    set_camera( pinhole_ptr );
                }
                if ( line.compare( 0, 1, "L" ) == 0 ) {
                    read_scene_def_aline( dataL, &fName, line, 9 );
                    // setup light sources
                    Directional* light_ptr1 = new Directional;
                    light_ptr1->set_direction( dataL[4], dataL[5], dataL[6] );
                    light_ptr1->scale_radiance( dataL[7] );
                    light_ptr1->set_shadows(true);
                    add_light(light_ptr1);

                    PointLight* light_ptr2 = new PointLight;
                    light_ptr2->set_point( Point3D( dataL[0], dataL[1], dataL[2] ) );
                    light_ptr2->set_intensity( dataL[3] );
                    light_ptr2->set_shadows(true);
                    add_light(light_ptr2);

                    Ambient* ambient_ptr = new Ambient;
                    ambient_ptr->scale_radiance( dataL[8] );
                    set_ambient_light(ambient_ptr);
                }
                if ( line.compare( 0, 1, "S" ) == 0 ) {
                    read_scene_def_aline( dataS, &fName, line, 13 );

                    // setup reflective sphere models
                    //Sphere*	sphere_ptr = new Sphere( Point3D(dataS[0], dataS[1], dataS[2]), dataS[3] );
                    //Reflective* reflect_ptr = new Reflective;
                    //reflect_ptr->set_cr( RGBColor( dataS[4], dataS[5], dataS[6] ) );
                    //reflect_ptr->set_cd( RGBColor( dataS[4], dataS[5], dataS[6] ) );
                    //reflect_ptr->set_ka( dataS[7] );
                    //reflect_ptr->set_kd( dataS[8] );
                    //reflect_ptr->set_ks( dataS[9] );
                    //reflect_ptr->set_kr( dataS[9] );
                    //reflect_ptr->set_exp( dataS[10] );
                    //sphere_ptr->set_material(reflect_ptr);
                    //sphere_ptr->set_shadows(true);
                    //add_object(sphere_ptr);

                    // setup transparent sphere models
                    Sphere*	sphere_ptr = new Sphere( Point3D(dataS[0], dataS[1], dataS[2]), dataS[3] );
                    Transparent* trans_ptr = new Transparent;
                    trans_ptr->set_ct( RGBColor( dataS[4], dataS[5], dataS[6] ) );
                    trans_ptr->set_cd( RGBColor( dataS[4], dataS[5], dataS[6] ) );
                    trans_ptr->set_cr( RGBColor( dataS[4], dataS[5], dataS[6] ) );
                    trans_ptr->set_ka( dataS[7] );
                    trans_ptr->set_kd( dataS[8] );
                    trans_ptr->set_ks( dataS[9] );
                    trans_ptr->set_kr( dataS[9] );
                    trans_ptr->set_exp( dataS[10] );
                    trans_ptr->set_kt( dataS[11] );
                    trans_ptr->set_ior( dataS[12] );
                    sphere_ptr->set_material(trans_ptr);
                    sphere_ptr->set_shadows(true);
                    add_object(sphere_ptr);
                }
                if ( line.compare( 0, 1, "T" ) == 0 ) {
                    read_scene_def_aline( dataT, &fName, line, 16 );
                    Reflective* reflect_ptr = new Reflective;
                    reflect_ptr->set_cd( RGBColor( dataT[9], dataT[10], dataT[11] ) );	// set color
                    reflect_ptr->set_ka( dataT[12] );
                    reflect_ptr->set_kd( dataT[13] );
                    reflect_ptr->set_ks( dataT[14] );
                    reflect_ptr->set_kr( dataT[14] );
                    reflect_ptr->set_exp( dataT[15] );
                    Grid* grid_ptr = new Grid( new Mesh );
                    grid_ptr->scale( dataT[0], dataT[1], dataT[2] );	// must be set up before reading!
                    grid_ptr->rotate( dataT[3], dataT[4], dataT[5] );	//
                    grid_ptr->translate( dataT[6], dataT[7], dataT[8] );//
                    grid_ptr->read_smooth_triangles( fName );
                    grid_ptr->set_shadows(true);
                    grid_ptr->set_material( reflect_ptr );
                    grid_ptr->setup_cells();
                    add_object(grid_ptr);
                }
                if ( line.compare( 0, 1, "P" ) == 0 ) {
                    read_scene_def_aline( dataP, &fName, line, 24 );
                    // add planes
                    //Phong* phong_ptr = new Phong;
                    //Plane* plane_ptr = new Plane( Point3D( dataP[0], dataP[1], dataP[2] ), Normal( dataP[3], dataP[4], dataP[5] ) );
                    //phong_ptr->set_cd( RGBColor( dataP[6], dataP[7], dataP[8] ) );
                    //phong_ptr->set_ka( dataP[16] );
                    //phong_ptr->set_kd( dataP[17] );
                    ////phong_ptr->set_ks( dataP[11] );
                    ////phong_ptr->set_exp( dataP[12] );
                    //plane_ptr->set_material( phong_ptr );
                    //plane_ptr->set_shadows(true);
                    //add_object (plane_ptr);

                    // add checker planes
                    PlaneChecker* plane_checker_ptr = new PlaneChecker;
                    plane_checker_ptr->set_size( dataP[23] );
                    plane_checker_ptr->set_outline_width( dataP[15] );
                    plane_checker_ptr->set_color1( RGBColor( dataP[6], dataP[7], dataP[8] ) );
                    plane_checker_ptr->set_color2( RGBColor( dataP[9], dataP[10], dataP[11] ) );
                    plane_checker_ptr->set_outline_color( RGBColor( dataP[12], dataP[13], dataP[14] ) );

                    SV_Reflective* sv_reflect_ptr = new SV_Reflective;
                    sv_reflect_ptr->set_cd( plane_checker_ptr );
                    sv_reflect_ptr->set_cr( plane_checker_ptr );
                    sv_reflect_ptr->set_cs( plane_checker_ptr );
                    sv_reflect_ptr->set_ka( dataP[16] );
                    sv_reflect_ptr->set_kd( dataP[17] );
                    sv_reflect_ptr->set_ks( dataP[18] );
                    sv_reflect_ptr->set_kr( dataP[18] );
                    sv_reflect_ptr->set_exp( dataP[19] );

                    Instance* plane_ptr = new Instance(new Plane( Point3D( dataP[0], dataP[1], dataP[2] ), Normal( dataP[3], dataP[4], dataP[5] ) )); // a generic plane is the (x, z) plane
                    //Instance* plane_ptr = new Instance( new Plane ); // a generic plane is the (x, z) plane
                    plane_ptr->set_material( sv_reflect_ptr );
                    plane_ptr->rotate_x( dataP[20] );
                    plane_ptr->rotate_y( dataP[21] );
                    plane_ptr->rotate_z( dataP[22] );
                    plane_ptr->set_shadows(true);
                    add_object(plane_ptr);
                }
            }
        }
    }
    else {
	printf( "\nscene.txt: Cannot open.\n" );
        exit(0);
    }

    outfile = TIFFOpen( "out.tif", "w" );
    if (outfile == NULL) {
            fprintf( stderr, "%s: Can not open.\n", "out.tif" );
            exit(0);
    }
    TIFFSetField( outfile, TIFFTAG_IMAGEWIDTH, (uint32_t) vp.hres );
    TIFFSetField( outfile, TIFFTAG_IMAGELENGTH, (uint32_t) vp.vres );
    TIFFSetField( outfile, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT );
    TIFFSetField( outfile, TIFFTAG_SAMPLESPERPIXEL, spp );
    TIFFSetField( outfile, TIFFTAG_BITSPERSAMPLE, bpp );
    TIFFSetField( outfile, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG );
    TIFFSetField( outfile, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB );
    TIFFSetField( outfile, TIFFTAG_COMPRESSION, COMPRESSION_PACKBITS );
    TIFFSetField( outfile, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(outfile, rowsperstrip) );
    linebytes = spp * vp.hres;
    buffer = (unsigned char *)_TIFFmalloc( linebytes );
}

//void World::myTIFFwrite( TIFF* file_name, unsigned char* buff, int r ) const
//{
//	TIFFWriteScanline( file_name, buff, r, 0 );
//}
