/*
 * main.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */
#include <iostream>
#include <memory>
#include "Base.h"
#include "GGA.h"

using namespace std;
int main()
{

	std::shared_ptr<Base> gga = std::make_shared<GGA>();
	std::string str = "$GPGGA,053152,3957.7484,N,11626.7626,E,1,06,1.5,88.1,M,-8.0,M,,*64";
	if(gga->firstparse(str) < 0)
		exit(-1);
	gga->parse(str);
	return 0;
}


