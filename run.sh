#!/bin/sh
# 
# File:   run.sh
# Author: Zexi Liu
#
# Created on May 30th, 2012, 11:26:06 PM
#
set -e

echo "CLEANING..."
rm -f -r build/Release
echo "CLEAN SUCCESSFUL!" 


echo "Compiling..."
mkdir -p build/Release/GNU-Linux-x86/raytracer
rm -f "build/Release/GNU-Linux-x86/raytracer/myRaytracer.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/myRaytracer.o.d" -o build/Release/GNU-Linux-x86/raytracer/myRaytracer.o raytracer/myRaytracer.cpp
echo "Compiled myRaytracer.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/BRDF.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/BRDF.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/BRDF.o raytracer/BRDFs/BRDF.cpp
echo "Compiled BRDF.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/GlossySpecular.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/GlossySpecular.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/GlossySpecular.o raytracer/BRDFs/GlossySpecular.cpp
echo "Compiled GlossySpecular.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/Lambertian.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/Lambertian.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/Lambertian.o raytracer/BRDFs/Lambertian.cpp
echo "Compiled Lambertian.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/PerfectSpecular.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/PerfectSpecular.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/PerfectSpecular.o raytracer/BRDFs/PerfectSpecular.cpp
echo "Compiled PerfectSpecular.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_GlossySpecular.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_GlossySpecular.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_GlossySpecular.o raytracer/BRDFs/SV_GlossySpecular.cpp
echo "Compiled SV_GlossySpecular.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_Lambertian.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_Lambertian.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_Lambertian.o raytracer/BRDFs/SV_Lambertian.cpp
echo "Compiled SV_Lambertian.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BRDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_PerfectSpecular.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_PerfectSpecular.o.d" -o build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_PerfectSpecular.o raytracer/BRDFs/SV_PerfectSpecular.cpp
echo "Compiled SV_PerfectSpecular.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BTDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BTDFs/BTDF.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BTDFs/BTDF.o.d" -o build/Release/GNU-Linux-x86/raytracer/BTDFs/BTDF.o raytracer/BTDFs/BTDF.cpp
echo "Compiled BTDF.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/BTDFs
rm -f "build/Release/GNU-Linux-x86/raytracer/BTDFs/PerfectTransmitter.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/BTDFs/PerfectTransmitter.o.d" -o build/Release/GNU-Linux-x86/raytracer/BTDFs/PerfectTransmitter.o raytracer/BTDFs/PerfectTransmitter.cpp
echo "Compiled PerfectTransmitter.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Cameras
rm -f "build/Release/GNU-Linux-x86/raytracer/Cameras/Camera.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Cameras/Camera.o.d" -o build/Release/GNU-Linux-x86/raytracer/Cameras/Camera.o raytracer/Cameras/Camera.cpp
echo "Compiled Camera.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Cameras
rm -f "build/Release/GNU-Linux-x86/raytracer/Cameras/Pinhole.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Cameras/Pinhole.o.d" -o build/Release/GNU-Linux-x86/raytracer/Cameras/Pinhole.o raytracer/Cameras/Pinhole.cpp
echo "Compiled Pinhole.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Compound.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Compound.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Compound.o raytracer/GeometricObjects/CompoundObjects/Compound.cpp
echo "Compiled Compound.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Grid.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Grid.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Grid.o raytracer/GeometricObjects/CompoundObjects/Grid.cpp
echo "Compiled Grid.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/GeometricObject.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/GeometricObject.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/GeometricObject.o raytracer/GeometricObjects/GeometricObject.cpp
echo "Compiled GeometricObject.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Instance.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Instance.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Instance.o raytracer/GeometricObjects/Instance.cpp
echo "Compiled Instance.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/PartObjects
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/PartObjects/ConvexPartSphere.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/PartObjects/ConvexPartSphere.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/PartObjects/ConvexPartSphere.o raytracer/GeometricObjects/PartObjects/ConvexPartSphere.cpp
echo "Compiled ConvexPartSphere.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/OpenCylinder.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/OpenCylinder.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/OpenCylinder.o raytracer/GeometricObjects/Primitives/OpenCylinder.cpp
echo "Compiled OpenCylinder.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Plane.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Plane.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Plane.o raytracer/GeometricObjects/Primitives/Plane.cpp
echo "Compiled Plane.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Rectangle.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Rectangle.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Rectangle.o raytracer/GeometricObjects/Primitives/Rectangle.cpp
echo "Compiled Rectangle.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Sphere.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Sphere.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Sphere.o raytracer/GeometricObjects/Primitives/Sphere.cpp
echo "Compiled Sphere.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Torus.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Torus.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Torus.o raytracer/GeometricObjects/Primitives/Torus.cpp
echo "Compiled Torus.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/FlatMeshTriangle.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/FlatMeshTriangle.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/FlatMeshTriangle.o raytracer/GeometricObjects/Triangles/FlatMeshTriangle.cpp
echo "Compiled FlatMeshTriangle.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/MeshTriangle.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/MeshTriangle.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/MeshTriangle.o raytracer/GeometricObjects/Triangles/MeshTriangle.cpp
echo "Compiled MeshTriangle.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothMeshTriangle.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothMeshTriangle.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothMeshTriangle.o raytracer/GeometricObjects/Triangles/SmoothMeshTriangle.cpp
echo "Compiled SmoothMeshTriangle.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothTriangle.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothTriangle.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothTriangle.o raytracer/GeometricObjects/Triangles/SmoothTriangle.cpp
echo "Compiled SmoothTriangle.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles
rm -f "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/Triangle.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/Triangle.o.d" -o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/Triangle.o raytracer/GeometricObjects/Triangles/Triangle.cpp
echo "Compiled Triangle.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Lights
rm -f "build/Release/GNU-Linux-x86/raytracer/Lights/Ambient.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Lights/Ambient.o.d" -o build/Release/GNU-Linux-x86/raytracer/Lights/Ambient.o raytracer/Lights/Ambient.cpp
echo "Compiled Ambient.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Lights
rm -f "build/Release/GNU-Linux-x86/raytracer/Lights/Directional.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Lights/Directional.o.d" -o build/Release/GNU-Linux-x86/raytracer/Lights/Directional.o raytracer/Lights/Directional.cpp
echo "Compiled Directional.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Lights
rm -f "build/Release/GNU-Linux-x86/raytracer/Lights/Light.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Lights/Light.o.d" -o build/Release/GNU-Linux-x86/raytracer/Lights/Light.o raytracer/Lights/Light.cpp
echo "Compiled Light.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Lights
rm -f "build/Release/GNU-Linux-x86/raytracer/Lights/PointLight.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Lights/PointLight.o.d" -o build/Release/GNU-Linux-x86/raytracer/Lights/PointLight.o raytracer/Lights/PointLight.cpp
echo "Compiled PointLight.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Mappings
rm -f "build/Release/GNU-Linux-x86/raytracer/Mappings/Mapping.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Mappings/Mapping.o.d" -o build/Release/GNU-Linux-x86/raytracer/Mappings/Mapping.o raytracer/Mappings/Mapping.cpp
echo "Compiled Mapping.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Materials
rm -f "build/Release/GNU-Linux-x86/raytracer/Materials/Material.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Materials/Material.o.d" -o build/Release/GNU-Linux-x86/raytracer/Materials/Material.o raytracer/Materials/Material.cpp
echo "Compiled Material.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Materials
rm -f "build/Release/GNU-Linux-x86/raytracer/Materials/Matte.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Materials/Matte.o.d" -o build/Release/GNU-Linux-x86/raytracer/Materials/Matte.o raytracer/Materials/Matte.cpp
echo "Compiled Matte.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Materials
rm -f "build/Release/GNU-Linux-x86/raytracer/Materials/Reflective.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Materials/Reflective.o.d" -o build/Release/GNU-Linux-x86/raytracer/Materials/Reflective.o raytracer/Materials/Reflective.cpp
echo "Compiled Reflective.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Materials
rm -f "build/Release/GNU-Linux-x86/raytracer/Materials/SV_Matte.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Materials/SV_Matte.o.d" -o build/Release/GNU-Linux-x86/raytracer/Materials/SV_Matte.o raytracer/Materials/SV_Matte.cpp
echo "Compiled SV_Matte.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Materials
rm -f "build/Release/GNU-Linux-x86/raytracer/Materials/SV_Reflective.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Materials/SV_Reflective.o.d" -o build/Release/GNU-Linux-x86/raytracer/Materials/SV_Reflective.o raytracer/Materials/SV_Reflective.cpp
echo "Compiled SV_Reflective.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Materials
rm -f "build/Release/GNU-Linux-x86/raytracer/Materials/Transparent.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Materials/Transparent.o.d" -o build/Release/GNU-Linux-x86/raytracer/Materials/Transparent.o raytracer/Materials/Transparent.cpp
echo "Compiled Transparent.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/Adaptive.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/Adaptive.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/Adaptive.o raytracer/Samplers/Adaptive.cpp
echo "Compiled Adaptive.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/Hammersley.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/Hammersley.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/Hammersley.o raytracer/Samplers/Hammersley.cpp
echo "Compiled Hammersley.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/Jittered.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/Jittered.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/Jittered.o raytracer/Samplers/Jittered.cpp
echo "Compiled Jittered.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/MultiJittered.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/MultiJittered.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/MultiJittered.o raytracer/Samplers/MultiJittered.cpp
echo "Compiled MultiJittered.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/NRooks.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/NRooks.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/NRooks.o raytracer/Samplers/NRooks.cpp
echo "Compiled NRooks.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/PureRandom.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/PureRandom.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/PureRandom.o raytracer/Samplers/PureRandom.cpp
echo "Compiled PureRandom.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/Regular.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/Regular.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/Regular.o raytracer/Samplers/Regular.cpp
echo "Compiled Regular.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Samplers
rm -f "build/Release/GNU-Linux-x86/raytracer/Samplers/Sampler.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Samplers/Sampler.o.d" -o build/Release/GNU-Linux-x86/raytracer/Samplers/Sampler.o raytracer/Samplers/Sampler.cpp
echo "Compiled Sampler.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Textures
rm -f "build/Release/GNU-Linux-x86/raytracer/Textures/Checker3D.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Textures/Checker3D.o.d" -o build/Release/GNU-Linux-x86/raytracer/Textures/Checker3D.o raytracer/Textures/Checker3D.cpp
echo "Compiled Checker3D.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Textures
rm -f "build/Release/GNU-Linux-x86/raytracer/Textures/PlaneChecker.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Textures/PlaneChecker.o.d" -o build/Release/GNU-Linux-x86/raytracer/Textures/PlaneChecker.o raytracer/Textures/PlaneChecker.cpp
echo "Compiled PlaneChecker.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Textures
rm -f "build/Release/GNU-Linux-x86/raytracer/Textures/SphereChecker.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Textures/SphereChecker.o.d" -o build/Release/GNU-Linux-x86/raytracer/Textures/SphereChecker.o raytracer/Textures/SphereChecker.cpp
echo "Compiled SphereChecker.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Textures
rm -f "build/Release/GNU-Linux-x86/raytracer/Textures/Texture.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Textures/Texture.o.d" -o build/Release/GNU-Linux-x86/raytracer/Textures/Texture.o raytracer/Textures/Texture.cpp
echo "Compiled Texture.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Tracers
rm -f "build/Release/GNU-Linux-x86/raytracer/Tracers/MultipleObjects.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Tracers/MultipleObjects.o.d" -o build/Release/GNU-Linux-x86/raytracer/Tracers/MultipleObjects.o raytracer/Tracers/MultipleObjects.cpp
echo "Compiled MultipleObjects.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Tracers
rm -f "build/Release/GNU-Linux-x86/raytracer/Tracers/RayCast.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Tracers/RayCast.o.d" -o build/Release/GNU-Linux-x86/raytracer/Tracers/RayCast.o raytracer/Tracers/RayCast.cpp
echo "Compiled RayCast.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Tracers
rm -f "build/Release/GNU-Linux-x86/raytracer/Tracers/Tracer.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Tracers/Tracer.o.d" -o build/Release/GNU-Linux-x86/raytracer/Tracers/Tracer.o raytracer/Tracers/Tracer.cpp
echo "Compiled Tracer.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/BBox.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/BBox.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/BBox.o raytracer/Utilities/BBox.cpp
echo "Compiled BBox.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Maths.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Maths.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Maths.o raytracer/Utilities/Maths.cpp
echo "Compiled Maths.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Matrix.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Matrix.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Matrix.o raytracer/Utilities/Matrix.cpp
echo "Compiled Matrix.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Mesh.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Mesh.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Mesh.o raytracer/Utilities/Mesh.cpp
echo "Compiled Mesh.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Normal.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Normal.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Normal.o raytracer/Utilities/Normal.cpp
echo "Compiled Normal.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Point2D.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Point2D.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Point2D.o raytracer/Utilities/Point2D.cpp
echo "Compiled Point2D.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Point3D.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Point3D.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Point3D.o raytracer/Utilities/Point3D.cpp
echo "Compiled Point3D.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/RGBColor.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/RGBColor.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/RGBColor.o raytracer/Utilities/RGBColor.cpp
echo "Compiled RGBColor.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Ray.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Ray.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Ray.o raytracer/Utilities/Ray.cpp
echo "Compiled Ray.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/ShadeRec.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/ShadeRec.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/ShadeRec.o raytracer/Utilities/ShadeRec.cpp
echo "Compiled ShadeRec.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Timer.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Timer.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Timer.o raytracer/Utilities/Timer.cpp
echo "Compiled Timer.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/Utilities
rm -f "build/Release/GNU-Linux-x86/raytracer/Utilities/Vector3D.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/Utilities/Vector3D.o.d" -o build/Release/GNU-Linux-x86/raytracer/Utilities/Vector3D.o raytracer/Utilities/Vector3D.cpp
echo "Compiled Vector3D.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/World
rm -f "build/Release/GNU-Linux-x86/raytracer/World/ViewPlane.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/World/ViewPlane.o.d" -o build/Release/GNU-Linux-x86/raytracer/World/ViewPlane.o raytracer/World/ViewPlane.cpp
echo "Compiled ViewPlane.cpp"

mkdir -p build/Release/GNU-Linux-x86/raytracer/World
rm -f "build/Release/GNU-Linux-x86/raytracer/World/World.o.d"
g++    -c -O2 -Iraytracer -Iraytracer/World -Iraytracer/Utilities -Iraytracer/Tracers -Iraytracer/Textures -Iraytracer/Samplers -Iraytracer/Materials -Iraytracer/Mappings -Iraytracer/Lights -Iraytracer/GeometricObjects -Iraytracer/GeometricObjects/BeveledOjects -Iraytracer/GeometricObjects/CompoundObjects -Iraytracer/GeometricObjects/PartObjects -Iraytracer/GeometricObjects/Primitives -Iraytracer/GeometricObjects/Triangles -Iraytracer/Cameras -Iraytracer/build -Iraytracer/BTDFs -Iraytracer/BRDFs -I/include -std=c++11 -MMD -MP -MF "build/Release/GNU-Linux-x86/raytracer/World/World.o.d" -o build/Release/GNU-Linux-x86/raytracer/World/World.o raytracer/World/World.cpp
echo "Compiled World.cpp"

g++    -o myRaytracer build/Release/GNU-Linux-x86/raytracer/BRDFs/BRDF.o build/Release/GNU-Linux-x86/raytracer/BRDFs/GlossySpecular.o build/Release/GNU-Linux-x86/raytracer/BRDFs/Lambertian.o build/Release/GNU-Linux-x86/raytracer/BRDFs/PerfectSpecular.o build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_GlossySpecular.o build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_Lambertian.o build/Release/GNU-Linux-x86/raytracer/BRDFs/SV_PerfectSpecular.o build/Release/GNU-Linux-x86/raytracer/BTDFs/BTDF.o build/Release/GNU-Linux-x86/raytracer/BTDFs/PerfectTransmitter.o build/Release/GNU-Linux-x86/raytracer/Cameras/Camera.o build/Release/GNU-Linux-x86/raytracer/Cameras/Pinhole.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Compound.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/CompoundObjects/Grid.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/GeometricObject.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Instance.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/PartObjects/ConvexPartSphere.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/OpenCylinder.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Plane.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Rectangle.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Sphere.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Primitives/Torus.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/FlatMeshTriangle.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/MeshTriangle.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothMeshTriangle.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/SmoothTriangle.o build/Release/GNU-Linux-x86/raytracer/GeometricObjects/Triangles/Triangle.o build/Release/GNU-Linux-x86/raytracer/Lights/Ambient.o build/Release/GNU-Linux-x86/raytracer/Lights/Directional.o build/Release/GNU-Linux-x86/raytracer/Lights/Light.o build/Release/GNU-Linux-x86/raytracer/Lights/PointLight.o build/Release/GNU-Linux-x86/raytracer/Mappings/Mapping.o build/Release/GNU-Linux-x86/raytracer/Materials/Material.o build/Release/GNU-Linux-x86/raytracer/Materials/Matte.o build/Release/GNU-Linux-x86/raytracer/Materials/Reflective.o build/Release/GNU-Linux-x86/raytracer/Materials/SV_Matte.o build/Release/GNU-Linux-x86/raytracer/Materials/SV_Reflective.o build/Release/GNU-Linux-x86/raytracer/Materials/Transparent.o build/Release/GNU-Linux-x86/raytracer/Samplers/Adaptive.o build/Release/GNU-Linux-x86/raytracer/Samplers/Hammersley.o build/Release/GNU-Linux-x86/raytracer/Samplers/Jittered.o build/Release/GNU-Linux-x86/raytracer/Samplers/MultiJittered.o build/Release/GNU-Linux-x86/raytracer/Samplers/NRooks.o build/Release/GNU-Linux-x86/raytracer/Samplers/PureRandom.o build/Release/GNU-Linux-x86/raytracer/Samplers/Regular.o build/Release/GNU-Linux-x86/raytracer/Samplers/Sampler.o build/Release/GNU-Linux-x86/raytracer/Textures/Checker3D.o build/Release/GNU-Linux-x86/raytracer/Textures/PlaneChecker.o build/Release/GNU-Linux-x86/raytracer/Textures/SphereChecker.o build/Release/GNU-Linux-x86/raytracer/Textures/Texture.o build/Release/GNU-Linux-x86/raytracer/Tracers/MultipleObjects.o build/Release/GNU-Linux-x86/raytracer/Tracers/RayCast.o build/Release/GNU-Linux-x86/raytracer/Tracers/Tracer.o build/Release/GNU-Linux-x86/raytracer/Utilities/BBox.o build/Release/GNU-Linux-x86/raytracer/Utilities/Maths.o build/Release/GNU-Linux-x86/raytracer/Utilities/Matrix.o build/Release/GNU-Linux-x86/raytracer/Utilities/Mesh.o build/Release/GNU-Linux-x86/raytracer/Utilities/Normal.o build/Release/GNU-Linux-x86/raytracer/Utilities/Point2D.o build/Release/GNU-Linux-x86/raytracer/Utilities/Point3D.o build/Release/GNU-Linux-x86/raytracer/Utilities/RGBColor.o build/Release/GNU-Linux-x86/raytracer/Utilities/Ray.o build/Release/GNU-Linux-x86/raytracer/Utilities/ShadeRec.o build/Release/GNU-Linux-x86/raytracer/Utilities/Timer.o build/Release/GNU-Linux-x86/raytracer/Utilities/Vector3D.o build/Release/GNU-Linux-x86/raytracer/World/ViewPlane.o build/Release/GNU-Linux-x86/raytracer/World/World.o build/Release/GNU-Linux-x86/raytracer/myRaytracer.o lib/libtiff.a lib/libjpeg.a
echo "Built myRaytracer"

echo "COMPILE SUCCESSFUL!" 

echo "Running myRaytracer..."
./myRaytracer