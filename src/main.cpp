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
#include "RMC.h"
#include "util.h"
using namespace std;
int main()
{

	std::shared_ptr<Base>parsePtr {nullptr};
	std::string str = "$GPGGA,053152,3957.7484,N,11626.7626,E,1,06,1.5,88.1,M,-8.0,M,,*64\r\n"
			"$GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50";
	std::vector<std::string>all;
	baseparse(str,all);
	for(auto it = all.begin();it!=all.end();++it)
	{
		std::cout<<*it<<std::endl;
		std::string temp = it->substr(1,5);
		if(temp == "GPGGA")
		{
			parsePtr = make_shared<GGA>();
		}
		else if(temp == "GPRMC")
		{
			parsePtr = make_shared<RMC>();
		}
		else
		{
			std::cout<<"不支持解析这种类型"<<std::endl;
			continue;
		}
		std::vector<std::string>res;
		int code;
		if((code = parsePtr->firstparse(*it,res)) < 0)
		{
			std::cout<<"解析错误code:"<<code<<std::endl;
			continue;
		}
		parsePtr->parse(res);
	}
	return 0;
}


