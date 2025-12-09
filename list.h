#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <vector>
#include <any>
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <limits>
#include <sstream>
using DynamicList=std::vector<std::any>;
void check(DynamicList& CList, int idx);
void display(const DynamicList& CList);
#endif
