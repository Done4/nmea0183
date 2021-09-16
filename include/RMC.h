/*
 * RMC.h
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#ifndef RMC_H_
#define RMC_H_
#include "Base.h"

class RMC : public Base
{
public:
	RMC()=default;
	~RMC()=default;
	bool parse(std::vector<std::string>&);////给成员变量赋值
private:
	std::string UTC;//UTC时间，hhmmss.sss格式
    std::string status;//定位状态，A=定位，V=未定位
    std::string lat;//纬度ddmm.mmmm，度分格式（前导位数不足则补0
	std::string latname;//纬度N（北纬）或S（南纬）
	std::string lng;//经度dddmm.mmmm，度分格式（前导位数不足则补0）
	std::string lngname;//经度E（东经）或W（西经）
	std::string speed;//速度，节，Knots,地面速率（000.0~999.9节，前面的0也将被传输）（一节也是1.852千米／小时）
	std::string azimuth;//地面航向（000.0~359.9度，以真北为参考基准，前面的0也将被传输）
	std::string UTCdate;//UTC日期，DDMMYY格式
	std::string md;//磁偏角，（000 - 180）度（前导位数不足则补0）
	std::string mdd;//磁偏角方向，E=东，W=西
	std::string mode;//模式，A=自动，D=差分，E=估测，N=数据无效（3.0协议内容）
};


#endif /* RMC_H_ */
