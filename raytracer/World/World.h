#ifndef __WORLD__
#define __WORLD__

// This file contains the declaration of the class World
// The World class does not have a copy constructor or an assignment operator, for the followign reasons:

// 1 	There's no need to copy construct or assign the World
// 2 	We wouldn't want to do this anyway, because the world can contain an arbitray amount of data
// 3 	These operations wouldn't work because the world is self-referencing:
//	 	the Tracer base class contains a pointer to the world. If we wrote a correct copy constructor for the 
// 	  	Tracer class, the World copy construtor would call itself recursively until we ran out of memory. 

#include <vector>
#include <string>
#include <iostream>

#include "ViewPlane.h"
#include "RGBColor.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "Ray.h"
//#include "SingleSphere.h"	// for Chapter 3 only

#include "Camera.h"
#include "Light.h"
#include "Ambient.h"

#include "tiffconf.h"
#include "tiffio.h"

class World {	
    public:
        ViewPlane			vp;
        RGBColor			background_color;
        Tracer*				tracer_ptr;
        Light*   			ambient_ptr;
        Camera*				camera_ptr;		
//	Sphere 				sphere;		// for Chapter 3 only
        std::vector<GeometricObject*>	objects;		
        std::vector<Light*> 		lights;
        TIFF*				outfile;	// file name for TIFF output
        TIFF*				outfile_int;// file name for TIFF output
        tsize_t				linebytes;	// for TIFF output
        unsigned char*                  buffer;		// for TIFF output
        unsigned char*			rpp_int;	// for TIFF output, the intensity of the pixels is proportional to the number of primary rays generated for the pixel (ray per pixel)

    public:

        World(void);
        ~World();

        void add_object(GeometricObject* object_ptr);
        void add_light(Light* light_ptr);
        void set_ambient_light(Light* light_ptr);			
        void set_camera(Camera* c_ptr);	 
        void build(void);
        void render_scene(void) const;
        RGBColor max_to_one(const RGBColor& c) const;
        RGBColor clamp_to_color(const RGBColor& c) const;
        RGBColor set_color(const int row, const int column, const RGBColor& pixel_color) const;
        ShadeRec hit_objects(const Ray& ray);
        void read_scene_def_aline( double *data, std::string *fName, const std::string& line, int size );
        void myTIFFwrite( TIFF* file_name, unsigned char* buff, int r ) const;

    private:
        void delete_objects(void);
        void delete_lights(void);
};

// ------------------------------------------------------------------ add_object
inline void World::add_object(GeometricObject* object_ptr) {  
    objects.push_back(object_ptr);	
}

// ------------------------------------------------------------------ add_light
inline void World::add_light(Light* light_ptr) {  
    lights.push_back(light_ptr);
}

// ------------------------------------------------------------------ set_ambient_light
inline void World::set_ambient_light(Light* light_ptr) {
    ambient_ptr = light_ptr;
}

// ------------------------------------------------------------------ set_camera
inline void World::set_camera(Camera* c_ptr) {
    camera_ptr = c_ptr;
}

//------------------------------------------------------------------ read_scene_def_aline
inline void World::read_scene_def_aline( double *data, std::string* fName, const std::string& line, int size ) {
    size_t b = 0;
    size_t e = 0;
    int cnt = 0;
    *fName = line.substr( ((int)line.find_first_of(" "))+1, (int)line.find_last_of("f")-1 );
    b = line.find_first_of( " ", (int)line.find_last_of("f")+1 );
    while ( b != std::string::npos ) {
        e = line.find_first_of( " ", b+1 );
        data[cnt] = atof( line.substr( b, e ).c_str() );
        b = e;
        cnt ++;
        if ( cnt == size )
            break;
    }
}

inline void World::myTIFFwrite( TIFF* file_name, unsigned char* buff, int r ) const {
    TIFFWriteScanline( file_name, buff, r, 0 );
}

#endif
