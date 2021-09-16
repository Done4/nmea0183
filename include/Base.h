/*
 * base.h
 *
 *  Created on: Sep 15, 2021
 *      Author: bnkj
 */

#ifndef BASE_H_
#define BASE_H_
#include <iostream>
#include <string>

class Base{

public:
	Base()=default;
	virtual ~Base()=default;
	virtual bool parse(const std::string &);
	virtual int firstparse(std::string&);
	virtual int BccCheck(const char *src);

};



#endif /* BASE_H_ */
