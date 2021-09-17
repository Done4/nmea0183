/*
 * util.h
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */

#ifndef UTIL_H_
#define UTIL_H_
#include <iostream>
#include <string>
#include <vector>

bool baseparse(std::string &,std::vector<std::string>&);
int BccCheck(const char *src);
double convertLat(std::string&,std::string&);//度分格式转换成纬度
double convertLng(std::string&,std::string&);//度分格式转换成经度
#endif /* UTIL_H_ */
