#pragma once
#include "destroyable_object.h"

class road_sign : public destroyable_object
{
public:
	void destroy_animation() override;
	~road_sign();
};
