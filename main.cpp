/*
 * 1- Place the camera and viewport as desired
 *    For each pixel on the canvas:
 * 2-   Determine which square on the viewport corresponds to this pixel
 * 3-   Determine the color seen through that square
 * 4-   Paint the pixel with that color
 */

#include <iostream>

#include "world.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    std::cout << "Hello RT!\n";

    World *world = new World;
    world->build();
    world->render_scene();
    world->save_to_ppm();
    delete world;

    return 0;
}