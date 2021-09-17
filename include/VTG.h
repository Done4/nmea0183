/*
 * VTG.h
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#ifndef VTG_H_
#define VTG_H_

#include "Base.h"

class VTG : public Base
{
public:
	VTG()=default;
	~VTG()=default;
	bool parse(std::vector<std::string>&);//给成员变量赋值
};


#endif /* VTG_H_ */
