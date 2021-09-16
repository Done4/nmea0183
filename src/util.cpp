/*
 * util.cpp
 *
 *  Created on: Sep 16, 2021
 *      Author: bnkj
 */
#include "util.h"

bool baseparse(std::string & msg,std::vector<std::string>&res)
{
	std::string strs = msg+"\r\n";//最后加个分割符不然取不到最后一段
	size_t pos = 0;
	while ((pos = strs.find("\r\n"))!= strs.npos)
	{
		res.push_back(strs.substr(0,pos));
		strs = strs.substr(pos+2,strs.size());//找到\r就停下了，要+2把两个字符都跳过
	}
	return 1;
}

