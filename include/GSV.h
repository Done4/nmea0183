/*
 * GSV.h
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#ifndef GSV_H_
#define GSV_H_

#include "Base.h"

class GSV : public Base
{
public:
	GSV()=default;
	~GSV()=default;
	bool parse(std::vector<std::string>&);//给成员变量赋值
private:
	std::string num;//本次GSV语句的总数目（1 - 3）
	std::string index;//本条GSV语句是本次GSV语句的第几条（1 - 3）
	std::string visNum;//当前可见卫星总数（00 - 12）（前导位数不足则补0）
	std::string PRN;//PRN 码（伪随机噪声码）（01 - 32）（前导位数不足则补0）
	std::string satAngle;//卫星仰角（00 - 90）度（前导位数不足则补0）
	std::string satAzimuth;//卫星方位角（00 - 359）度（前导位数不足则补0）
	std::string SNR;//信噪比（00－99）dbHz
};



#endif /* GSV_H_ */
