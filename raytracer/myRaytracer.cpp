#include <iostream>
#include <iomanip>
#include "World.h"
#include "Timer.h"

int main( int argc, char ** argv ) {
    World *w;

    w = new World();

    std::cout << "|----------------------------------------------|" << std::endl;
    std::cout << "|Building world..." << std::endl;

    w->build();
    std::cout << "|Rendering, please wait..." << std::endl;

    long int Tic = Current_Clock();

    // TODO: rendering
    w->camera_ptr->render_scene(*w);

    long int Toc = Current_Clock();

    double T = ((double)Toc - (double)Tic) / CLOCKS_PER_SEC;

    std::cout << "|Total runtime: " << std::setprecision(4) << std::fixed << T << " second." << std::endl;
    std::cout << "|Ray tracing done! Congratulations!" << std::endl;
    std::cout << "|----------------------------------------------|" << std::endl;

    delete w;

    std::cout << "Enter to exit the program: ";
    std::cin.get();

    return 0;
}