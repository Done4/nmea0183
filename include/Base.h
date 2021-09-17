/*
 * base.h
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

#ifndef BASE_H_
#define BASE_H_
#include "util.h"

class Base{

public:
	Base()=default;
	virtual ~Base()=default;
	virtual bool parse(std::vector<std::string>&)=0;
	virtual int firstparse(std::string&,std::vector<std::string>&);//将报文按逗号分割放到vector里面
};



#endif /* BASE_H_ */
