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
		return false;
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

double Base::convertLat(std::string &lat,std::string&latname)
{
	try
	{
		std::string integer = lat.substr(0, 2);
		std::string decimal = lat.substr(2);
		double res = stod(integer)+stod(decimal)/60.0;//ddmm.mmmm,先取出小数部分再除60加上整数部分得到结果
		if(latname == "S")
			res = -res;
		return res;
	}
	catch(...)
	{
		std::cout<<"纬度转换失败:"<<lat<<std::endl;
		return -1;
	}
}

double Base::convertLng(std::string&lng,std::string&lngname)
{
	try
		{
			std::string integer = lng.substr(0, 3);
			std::string decimal = lng.substr(3);
			double res = stod(integer)+stod(decimal)/60.0;//dddmm.mmmm,先取出小数部分再除60加上整数部分得到结果
			if(lngname == "W")
				res = -res;
			return res;
		}
		catch(...)
		{
			std::cout<<"经度转换失败:"<<lng<<std::endl;
			return -1;
		}
}
