/*
 * util.cpp
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */
#include "util.h"

bool baseparse(std::string & msg,std::vector<std::string>&res)
{
	std::string strs = msg+"\r\n";//最后加个分割符不然取不到最后一段
	size_t pos = 0;
	while ((pos = strs.find("\r\n"))!= strs.npos)
	{
		res.push_back(strs.substr(0,pos));
		strs = strs.substr(pos+2,strs.size());//找到\r就停下了，要+2把两个字符都跳过
	}
	return 1;
}

int BccCheck(const char *src) {
	  int sum = 0;
	  int num = 0;
	  try
	  {
		  sscanf(src, "%*[^*]*%x", &num);
		  for (int i = 1; src[i] != '*'; ++i)
		  {
			  sum ^= src[i];
		  }
	  }
	  catch(...)
	  {
		  std::cout<<"读取校验值失败"<<std::endl;
		  return -1;
	  }
	  return sum - num;
}

double convertLat(std::string &lat,std::string&latname)
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

double convertLng(std::string&lng,std::string&lngname)
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
