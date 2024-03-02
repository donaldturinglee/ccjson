#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

#define JSON_TYPE JsonPtr
#define JSON_BOOL bool
#define JSON_INT  int
#define JSON_FLOAT float
#define JSON_STRING std::string
#define JSON_ARRAY std::vector<JSON_TYPE>
#define JSON_OBJECT std::map<std::string, JSON_TYPE>

#endif // TYPE_H
