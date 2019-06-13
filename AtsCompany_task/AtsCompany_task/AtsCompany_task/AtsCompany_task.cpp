#include <iostream>
#include "company.h"

int main()
{
	company* cmp = new company();
	terminal* user_terminal_1 = cmp->create_subscriber("arseni");
	std::string call_result = user_terminal_1->make_call(22222222);
	delete cmp;
}
