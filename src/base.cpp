/*
 * base.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

#include "Base.h"

int Base::firstparse(std::string & msg,std::vector<std::string>&res)
{
	if(msg[0] != '$')
		return -1;
	size_t pos_ = msg.find("*");
	if(pos_ == msg.npos)
		return -2;
	if(BccCheck(msg.c_str()) != 0)
		return -3;
	msg = msg.substr(7,pos_-7);
	if(msg.empty())
	{
		std::cout<<"msg为空"<<std::endl;
		return -4;
	}
	std::string strs = msg+",";//最后加个分割符不然取不到最后一段
	size_t pos = 0;
	while ((pos = strs.find(","))!= strs.npos)
	{
		res.push_back(strs.substr(0,pos));
		strs = strs.substr(pos+1,strs.size());
	}
	//std::cout<<"原报文:"<<msg<<std::endl;

	return 0;
}

