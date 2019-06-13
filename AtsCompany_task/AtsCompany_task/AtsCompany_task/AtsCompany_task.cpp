#include <iostream>
#include "company.h"

int main()
{
	company* cmp = new company();
	terminal* user_1 = cmp->create_subscriber("arseni");
	
	delete cmp;
}
