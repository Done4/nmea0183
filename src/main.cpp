/*
 * main.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

#include "Base.h"
#include "GGA.h"
#include <memory>
int main()
{
	std::shared_ptr<Base> p = std::make_shared<Base>();
	p->parse("jhhhh");
	std::shared_ptr<Base> c = std::make_shared<GGA>();
	c->parse("ch");
	return 0;
}


