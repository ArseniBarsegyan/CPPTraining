#include <iostream>
#include "ground.h"
#include "road_sign.h"

int main()
{
	ground* battle_field = new ground(100, 100);

	road_sign* sign = new road_sign();

	delete sign;
	sign = nullptr;

	delete battle_field;
	battle_field = nullptr;
}
