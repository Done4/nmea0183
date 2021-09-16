/*
 * GGA.h
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

//字段1：UTC 时间，hhmmss.sss，时分秒格式
//
//字段2：纬度ddmm.mmmm，度分格式（前导位数不足则补0）
//
//字段3：纬度N（北纬）或S（南纬）
//
//字段4：经度dddmm.mmmm，度分格式（前导位数不足则补0）
//
//字段5：经度E（东经）或W（西经）
//
//字段6：GPS状态，0=未定位，1=非差分定位，2=差分定位，3=无效PPS，6=正在估算
//
//字段7：正在使用的卫星数量（00 - 12）（前导位数不足则补0）
//
//字段8：HDOP水平精度因子（0.5 - 99.9）
//
//字段9：海拔高度（-9999.9 - 99999.9）
//
//字段10：地球椭球面相对大地水准面的高度
//
//字段11：差分时间（从最近一次接收到差分信号开始的秒数，如果不是差分定位将为空）
//
//字段12：差分站ID号0000 - 1023（前导位数不足则补0，如果不是差分定位将为空）
//
//字段13：校验值
#ifndef GGA_H_
#define GGA_H_
#include "Base.h"

class GGA : public Base
{
public:
	GGA()=default;
	~GGA()=default;
	bool parse(std::vector<std::string>&);//给成员变量赋值
private:
	std::string UTC;//UTC 时间，hhmmss.sss，时分秒格式
	std::string lat;//纬度ddmm.mmmm，度分格式（前导位数不足则补0
	std::string latname;//纬度N（北纬）或S（南纬）
	std::string lng;//经度dddmm.mmmm，度分格式（前导位数不足则补0）
	std::string lngname;//经度E（东经）或W（西经）
	std::string GPSStatus;//GPS状态，0=未定位，1=非差分定位，2=差分定位，3=无效PPS，6=正在估算
	std::string satNum;//正在使用的卫星数量
	std::string haf;//HDOP水平精度因子（0.5 - 99.9）
	std::string altitude;//海拔高度
	std::string relative_altitude;//地球椭球面相对大地水准面的高度
	std::string difftime;//差分时间
	std::string diffid;//差分站ID号0000 - 1023（前导位数不足则补0，如果不是差分定位将为空）
};




#endif /* GGA_H_ */
