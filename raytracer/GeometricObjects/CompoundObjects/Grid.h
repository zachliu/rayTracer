#ifndef __GRID__
#define __GRID__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This contains the declaration of the class Grid.
// The copy constructor, assignment operator, and destructor, are dummy functions.
// The reason is that a grid can contain an arbitrary number of objects, can therefore be of arbitrary size.


// There is no set_bounding_box function because the bounding box is constructed in the setup_cells
// function.

// This Grid class is also way too large. All the triangle and PLY file code should be placed in
// a separate class called TriangleMesh that inherits from Grid.
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "Constants.h"
#include "Maths.h"

#include "Vector3D.h"
#include "Point3D.h"
#include "Grid.h"

#include "MeshTriangle.h"
#include "FlatMeshTriangle.h"
#include "SmoothMeshTriangle.h"
//#include "FlatUVMeshTriangle.h"
//#include "SmoothUVMeshTriangle.h"

#include "Triangle.h"
#include "SmoothTriangle.h"
#include "Compound.h"
#include "ShadeRec.h"
#include "Mesh.h"
#include "Matrix.h"

//---------------------------------------------------------------------- class Grid

class Grid: public Compound
{										  	
    public:
        Grid(void);
        Grid(Mesh* _mesh_ptr);
        virtual Grid* clone(void) const;
        Grid(const Grid& rg);
        Grid& operator= (const Grid& rhs);
        virtual ~Grid(void);   			

        virtual BBox get_bounding_box(void);
        void read_flat_triangles( const std::string file_name );
        void read_smooth_triangles( const std::string file_name );
        void tessellate_flat_sphere(const int horizontal_steps, const int vertical_steps);
        void tessellate_smooth_sphere(const int horizontal_steps, const int vertical_steps);
        virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
        virtual bool shadow_hit(const Ray& ray, double& tmin) const;
        void setup_cells(void);
        void reverse_mesh_normals(void);
        void store_material(Material* material, const int index);

        // affine tranformation functions
        void translate( const double dx, const double dy, const double dz );
        void scale( const double sx, const double sy, const double sz );
        void rotate( const double a, const double b, const double c );

    private:
        std::vector<GeometricObject*>	cells;			// grid of cells
        int				nx, ny, nz;    	// number of cells in the x, y, and z directions
        BBox				bbox;			// bounding box
        Mesh*				mesh_ptr;		// holds triangle data
        bool				reverse_normal;	// some PLY files have normals that point inwards
        static Matrix			forward_matrix;	// transformation matrix

        Point3D find_min_bounds(void);
        Point3D find_max_bounds(void);
        void read_obj_file( const std::string file_name, const int triangle_type );
        bool read_obj_file_aline( double *coord, const std::string& line );
        void compute_mesh_normals(void);	
};

// ------------------------------------------------------------------------------ store_material
inline void Grid::reverse_mesh_normals(void) {   
    reverse_normal = true;
}

// ------------------------------------------------------------------------------ store_material
// stores the material in the specified object
// this is called from the Rosette and Archway classes, which inherit from Grid
inline void Grid::store_material(Material* material_ptr, const int index) {
    objects[index]->set_material(material_ptr); 
}

//-------------------------------------------------------------------------------- translate
inline void Grid::translate(const double dx, const double dy, const double dz) {
		
    Matrix translation_matrix;					// temporary translation matrix	

    translation_matrix.m[0][3] = dx;
    translation_matrix.m[1][3] = dy;
    translation_matrix.m[2][3] = dz;

    forward_matrix = translation_matrix * forward_matrix; 
}

//-------------------------------------------------------------------------------- scale
inline void Grid::scale(const double sx, const double sy, const double sz) {

    Matrix scaling_matrix;						// temporary scaling matrix
	
    scaling_matrix.m[0][0] = sx;
    scaling_matrix.m[1][1] = sy;
    scaling_matrix.m[2][2] = sz;
	
    forward_matrix = scaling_matrix * forward_matrix; 	
}

//-------------------------------------------------------------------------------- rotate_x
inline void Grid::rotate( const double a, const double b, const double c ) {

    double sin_a = sin( a * PI_ON_180 );
    double cos_a = cos( a * PI_ON_180 );
    double sin_b = sin( b * PI_ON_180 );
    double cos_b = cos( b * PI_ON_180 );
    double sin_c = sin( c * PI_ON_180 );
    double cos_c = cos( c * PI_ON_180 );

    Matrix x_rotation_matrix;	// temporary rotation matrix about x axis
    Matrix y_rotation_matrix;	// temporary rotation matrix about y axis
    Matrix z_rotation_matrix;	// temporary rotation matrix about z axis

    x_rotation_matrix.m[1][1] = cos_a;
    x_rotation_matrix.m[1][2] = -sin_a;
    x_rotation_matrix.m[2][1] = sin_a;
    x_rotation_matrix.m[2][2] = cos_a;

    y_rotation_matrix.m[0][0] = cos_b;
    y_rotation_matrix.m[0][2] = sin_b;
    y_rotation_matrix.m[2][0] = -sin_b;
    y_rotation_matrix.m[2][2] = cos_b;

    z_rotation_matrix.m[0][0] = cos_c;
    z_rotation_matrix.m[0][1] = -sin_c;
    z_rotation_matrix.m[1][0] = sin_c;
    z_rotation_matrix.m[1][1] = cos_c;

    forward_matrix = x_rotation_matrix * forward_matrix;
    forward_matrix = y_rotation_matrix * forward_matrix;
    forward_matrix = z_rotation_matrix * forward_matrix;
}

#endif









