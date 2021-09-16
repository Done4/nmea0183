/*
 * GSA.h
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#ifndef GSA_H_
#define GSA_H_

#include "Base.h"
class GSA : public Base
{
public:
	GSA()=default;
	~GSA()=default;
	bool parse(std::vector<std::string>&);//给成员变量赋值
private:
	std::string mode;//定位模式，A=自动手动2D/3D，M=手动2D/3D
	std::string type;//定位类型，1=未定位，2=2D定位，3=3D定位
	std::string PRN1;//PRN码（伪随机噪声码），第1信道正在使用的卫星PRN码编号
	std::string PRN2;//PRN码（伪随机噪声码），第2信道正在使用的卫星PRN码编号
	std::string PRN3;//PRN码（伪随机噪声码），第3信道正在使用的卫星PRN码编号
	std::string PRN4;//PRN码（伪随机噪声码），第4信道正在使用的卫星PRN码编号
	std::string PRN5;//PRN码（伪随机噪声码），第5信道正在使用的卫星PRN码编号
	std::string PRN6;//PRN码（伪随机噪声码），第6信道正在使用的卫星PRN码编号
	std::string PRN7;//PRN码（伪随机噪声码），第7信道正在使用的卫星PRN码编号
	std::string PRN8;//PRN码（伪随机噪声码），第8信道正在使用的卫星PRN码编号
	std::string PRN9;//PRN码（伪随机噪声码），第9信道正在使用的卫星PRN码编号
	std::string PRN10;//PRN码（伪随机噪声码），第10信道正在使用的卫星PRN码编号
	std::string PRN11;//PRN码（伪随机噪声码），第11信道正在使用的卫星PRN码编号
	std::string PRN12;//PRN码（伪随机噪声码），第12信道正在使用的卫星PRN码编号
	std::string PDOP;//PDOP综合位置精度因子（0.5 - 99.9）
	std::string HDOP;//HDOP水平精度因子（0.5 - 99.9）
	std::string VDOP;//VDOP垂直精度因子（0.5 - 99.9）
};



#endif /* GSA_H_ */
