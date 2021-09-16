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
#include <vector>
class Base{

public:
	Base()=default;
	virtual ~Base()=default;
	virtual bool parse(std::vector<std::string>&)=0;
	virtual int firstparse(std::string&,std::vector<std::string>&);
	virtual int BccCheck(const char *src);

};



#endif /* BASE_H_ */
