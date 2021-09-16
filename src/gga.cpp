/*
 * gga.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */


#include "GGA.h"

bool GGA::parse(std::vector<std::string>&res)
{
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return false;
	}
	
	std::cout<<"UTC 时间:"<<UTC<<" 纬度:"<<convertLat(lat,latname)<<" N/S:"<<latname<<" 经度:"<<convertLat(lng,lng)<<" E/W:"<<lngname<<" GPS状态"<<GPSStatus<<" 正在使用的卫星数量:"<<satNum<<" HDOP水平精度因子:"<<haf<<" 海拔高度:"<<altitude<<" 地球椭球面相对大地水准面的高度:"<<relative_altitude<<" 差分时间:"<<difftime<<" 差分站ID号:"<<diffid<<std::endl;
	return true;
}
