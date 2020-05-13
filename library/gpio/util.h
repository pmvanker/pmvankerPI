/*
 * Created on: 13-May-2020
 *      Author: pmvanker
 */

#ifndef UTIL_H_
#define UTIL_H_
#include<string>
using std::string;

namespace pmvankerPI {


int write(string path, string filename, string value);
int write(string path, string filename, int value);
string read(string path, string filename);


} /* namespace pmvankerPI */

#endif /* UTIL_H_ */
