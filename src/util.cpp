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

void UTCTolocal(std::string& UTC,std::string& UTCdate,char *date)
{
	struct tm time;
	time.tm_year = stoi(UTCdate.substr(4,2));
	time.tm_mon = stoi(UTCdate.substr(2,2));
	time.tm_mday = stoi(UTCdate.substr(0,2));
	time.tm_hour = stoi(UTC.substr(0,2));
	time.tm_min = stoi(UTC.substr(2,2));
	time.tm_sec = stoi(UTC.substr(4,2));

	uint16_t year = time.tm_year+2000;
	time.tm_hour += 8;

	if(time.tm_mon==1||time.tm_mon==3||time.tm_mon==5||time.tm_mon==7||time.tm_mon==8||time.tm_mon==10||time.tm_mon==12)//1,3,5,7,8,9,12月每月为31天
	{
	if(time.tm_hour >= 24)
	{
	time.tm_hour -= 24;time.tm_mday += 1;//如果超过24小时，减去24小时，后再加上一天
	if(time.tm_mday > 31){time.tm_mday -= 31;time.tm_mon += 1;}//如果超过31一天，减去31天，后加上一个月
	if(time.tm_mon > 12){time.tm_mon -= 12;year++;}//如果超过12月,应该是1月,然后加上一年
	}
	}
	else if(time.tm_mon==4||time.tm_mon==6||time.tm_mon==9||time.tm_mon==11)//4，6，9，11月每月为30天
	{
	if(time.tm_hour >= 24)
	{
	time.tm_hour -= 24;time.tm_mday += 1;//如果超过24小时，减去24小时，后再加上一天
	if(time.tm_mday > 30){time.tm_mday -= 30;time.tm_mon += 1;}//如果超过30一天，减去30天，后加上一个月
	}
	}
	else//剩下为2月，闰年为29天，平年为28天
	{
	if(time.tm_hour >= 24)
	{
	time.tm_hour -= 24;time.tm_mday += 1;
	if((year%400 == 0)||(year%4 == 0 && year%100 != 0))//判断是否为闰年，年号能被400整除或年号能被4整除，而不能被100整除为闰年
	{if(time.tm_mday > 29){time.tm_mday -= 29;time.tm_mon += 1;}}//为闰年
	else{if(time.tm_mday > 28){time.tm_mday -= 28;time.tm_mon += 1;}}//为平年
	}
	}
	time.tm_year = year;
	snprintf(date,17,"%04d-%02d-%02d %02d:%02d",time.tm_year,time.tm_mon,time.tm_mday,time.tm_hour,time.tm_min);
}

double converSpeed(std::string& speed)
{
	return stod(speed)*1.852;
}
