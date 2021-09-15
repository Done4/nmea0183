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
	p->parse("father");
	std::shared_ptr<Base> c = std::make_shared<GGA>();
	c->parse("$GPGGA,092204.999,4250.5589,S,14718.5084,E,1,04,24.4,19.7,M,,,,0000*1F");
	return 0;
}


