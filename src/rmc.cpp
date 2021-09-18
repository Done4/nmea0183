/*
 * rmc.cpp
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#include "RMC.h"

bool RMC::parse(std::vector<std::string>&res)
{
	try
		{
			UTC = res[0];
			status = res[1];
			lat = res[2];
			latname = res[3];
			lng = res[4];
			lngname = res[5];
			speed = res[6];
			azimuth = res[7];
			UTCdate = res[8];
			md = res[9];
			mdd = res[10];
			mode = res[11];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}

		std::cout<<"UTC 时间:"<<UTC<<" 定位状态:"<<status<<" 纬度:"<<convertLat(lat,latname)<<" N/S:"<<latname<<" 经度:"<<convertLat(lng,lng)<<" E/W:"<<lngname<<" 地面速率"<<converSpeed(speed)<<"千米／小时"<<" 地面航向:"<<azimuth<<" UTC日期:"<<UTCdate<<" 磁偏角:"<<md<<" 磁偏角方向:"<<mdd<<" 模式:"<<mode<<std::endl;
		char*date = new char[17];
		UTCTolocal(UTC,UTCdate,date);
		printf("%s",date);
		delete date;
		date = NULL;
		return true;
}



