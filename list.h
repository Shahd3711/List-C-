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

using DynamicList = std::vector<std::any>;

void process_user_input(DynamicList& myList, int current_index);

void display_list_content(const DynamicList& myList);

#endif 