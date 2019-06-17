#include "road_sign.h"
#include <iostream>

void road_sign::destroy_animation()
{
	std::cout << "sign is destroyed";
}

road_sign::~road_sign()
{
	road_sign::destroy_animation();
}
