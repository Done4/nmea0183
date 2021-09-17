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
};



#endif /* GSV_H_ */
