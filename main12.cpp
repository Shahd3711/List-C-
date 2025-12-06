#include "list.h"
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;
int read_list_size() {
    int size = 0;
    while (true) {
        cout << "Enter the size of the list you want to create: ";
        if (cin >> size && size >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return size;
        } else {
            cout << "Invalid input. Please enter a non-negative integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    cout << "### Dynamic Type List Generator (C++17) ###" << endl;

    int list_size = read_list_size();
    
    DynamicList my_dynamic_list;
    my_dynamic_list.reserve(list_size);

    cout << "\nStarting input process for " << list_size << " items..." << endl;

    for (int i = 0; i < list_size; ++i) {
        try {
            process_user_input(my_dynamic_list, i);
        } catch (const exception& e) {
            cerr << "An unexpected error occurred: " << e.what() << endl;
            i--; 
        }
    }

    display_list_content(my_dynamic_list);

    return 0;
}
//g++ -std=c++17 main.cpp list.cpp -o main12