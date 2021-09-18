/*
 * gsa.cpp
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */


#include "GSA.h"

bool GSA::parse(std::vector<std::string>&res)
{
	try
		{
			mode = res[0];
			type = res[1];
			PRN1 = res[2];
			PRN2 = res[3];
			PRN3 = res[4];
			PRN4 = res[5];
			PRN5 = res[6];
			PRN6 = res[7];
			PRN7 = res[8];
			PRN8 = res[9];
			PRN9 = res[10];
			PRN10 = res[11];
			PRN11 = res[12];
			PDOP = res[13];
			HDOP = res[14];
			VDOP = res[15];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}

		std::cout<<"定位模式:"<<mode<<" 类型:"<<type<<std::endl;
		for (int i = 2;i < 13;++i)
			std::cout<<"第"<<i-1<<"信道正在使用的卫星PRN码编号:"<<res[i]<<std::endl;
		std::cout<<"PDOP综合位置精度因子:"<<PDOP<<" HDOP水平精度因子:"<<HDOP<<" VDOP垂直精度因子:"<<VDOP<<std::endl;
		return true;
}
