/*
 * GLL.h
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#ifndef GLL_H_
#define GLL_H_

#include "Base.h"

class GLL : public Base
{
public:
	GLL()=default;
	~GLL()=default;
	bool parse(std::vector<std::string>&);//给成员变量赋值
};



#endif /* GLL_H_ */
