#include "world.h"

// geometric objects
#include "geometric_object.h"
#include "sphere.h"

// tracers
#include "single_sphere.h"

// utilities
#include "vector3.h"
#include "point3.h"
#include "normal.h"
#include "shade_rec.h"
#include "maths.h"

void World::build(void) 
{
	vp.set_hres(200);
	vp.set_vres(200);
	vp.set_pixel_size(1.0);

	background_color = Color::black;
	tracer_ptr = new SingleSphere(this);

	sphere.set_center(Point3(0.0));
	sphere.set_radius(85.0);
}