/*
 * base.h
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

#ifndef BASE_H_
#define BASE_H_
#include <string>
#include <iostream>
class Base{

public:
	Base()=default;
	virtual ~Base()=default;
	virtual bool parse(const std::string & );

};



#endif /* BASE_H_ */
