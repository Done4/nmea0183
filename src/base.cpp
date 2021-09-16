/*
 * base.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

#include "Base.h"
bool Base::parse(const std::string& msg)
{
	std::cout<<msg<<std::endl;
	return 1;
}

int Base::firstparse(std::string & msg)
{
	if(msg[0] != '$')
		return -1;
	if(BccCheck(msg.c_str()))
		return -2;
	int pos = msg.find("*");
	std::string temp = msg.substr(1,5);//类型都是5位
	msg = msg.substr(7,pos-7);
	std::cout<<"类型："<<temp<<std::endl;
	if(temp == "GPGGA")
		return 1;
	return 0;
}
int Base::BccCheck(const char *src) {
	  int sum = 0;
	  int num = 0;
	  sscanf(src, "%*[^*]*%x", &num);
	  for (int i = 1; src[i] != '*'; ++i) {
	    sum ^= src[i];
	  }
	  return sum - num;
}

