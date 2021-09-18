/*
 * gsv.cpp
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */


#include "GSV.h"

bool GSV::parse(std::vector<std::string>&res)
{
	try
		{
			num = res[0];
			index = res[1];
			visNum = res[2];
			PRN = res[3];
			satAngle = res[4];
			satAzimuth = res[5];
			SNR = res[6];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return false;
		}

		std::cout<<"本次GSV语句的总数目:"<<num<<" 本条GSV语句是本次GSV语句的第几条:"<<index<<" 当前可见卫星总数:"<<visNum<<" PRN 码:"<<PRN<<" 卫星仰角:"<<satAngle<<" 卫星方位角:"<<satAzimuth<<" 信噪比:"<<SNR<<std::endl;
		return true;
}
