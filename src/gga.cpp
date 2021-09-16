/*
 * gga.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */


#include "GGA.h"
#include <iostream>
#include <vector>

//$GPGGA,092204.999,4250.5589,S,14718.5084,E,1,04,24.4,19.7,M,,,,0000*1F
bool GGA::parse(const std::string & msg)
{
	if(msg.empty())
	{
		std::cout<<"msg为空"<<std::endl;
		return false;
	}
	std::vector<std::string>res;
	std::string strs = msg+",";//最后加个分割符不然取不到最后一段
	size_t pos = 0;
	while ((pos = strs.find(","))!= strs.npos)
	{
		res.push_back(strs.substr(0,pos));
		strs = strs.substr(pos+1,strs.size());
	}
	try
	{
		UTC = res[0];
		lat = res[1];
		latname = res[2];
		lng = res[3];
		lngname = res[4];
		GPSStatus = res[5];
		satNum = res[6];
		haf = res[7];
		altitude = res[8];
		relative_altitude = res[9];
		difftime = res[10];
		diffid = res[11];
		std::cout<<msg<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout<<"UTC 时间:"<<UTC<<" 纬度:"<<lat<<" N/S:"<<latname<<" 经度:"<<lng<<" E/W:"<<lngname<<" GPS状态"<<GPSStatus<<" 正在使用的卫星数量:"<<satNum<<" HDOP水平精度因子:"<<haf<<" 海拔高度:"<<altitude<<" 地球椭球面相对大地水准面的高度:"<<relative_altitude<<" 差分时间:"<<difftime<<" 差分站ID号:"<<diffid<<" 校验值:"<<check<<std::endl;
	return 1;
}
