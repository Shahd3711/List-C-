#include "list.h"
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;
int read_sz() 
{
    int sz=0;
    while(1) 
    {
        cout<<"Enter the size of the list: ";
        if(cin>>sz&&sz>=0) 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return sz;
        }
        else
        {
            cout<<"Invalid input! Please enter a non-negative integer."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
int main() 
{
    int sz=read_sz();
    DynamicList my_dynamic_list;
    my_dynamic_list.reserve(sz);
    cout << "\n Gr8! Just a sec..." << sz << " Loading..." << endl;
    for(int i=0; i<sz; i++)
    {
        check(my_dynamic_list, i);
        //cout<<typeid(my_dynamic_list[i]).name()<<endl;
    } 
    display(my_dynamic_list);

    return 0;
}
//g++ -std=c++17 main12.cpp list.cpp -o main12
