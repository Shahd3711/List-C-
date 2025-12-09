#include "list.h"
using namespace std;
#define el '\n'
bool is_int(const string& s)
{
    if(s.empty())return 0;
    int num=0;
    if(s[0]=='-'||s[0]=='+') 
    {
        if(s.size()==1)return 0;
        num=1;
    }
    for(int i=num; i<s.size(); i++) 
        if(!isdigit(s[i]))return 0;
    return 1;
}
void check(DynamicList& CList, int idx)
{
    string s;
    cout<<el<<"["<<idx+1<< "]Enter value: ";
    if(!getline(cin, s))
        return;
    if(s.empty())
        cout<<"Nothing was entered. MEHH! empty string."<<el, s="";
    if(s=="true"||s=="True"||s=="TRUE"||s=="false"||s=="False"||s=="FALSE")
    {
        CList.push_back(s);
        cout<<"You Entered: "<<s<<". The typeid is: "<< typeid(bool).name()<<el;
        return;
    }
    /*if(s=="true"||s=="True"||s=="TRUE")
    {
        CList.push_back(true);
        cout<<"You Entered: true. The typeid is: "<< typeid(bool).name()<<el;
        return;
    }
    if(s=="false"||s=="False"||s=="FALSE") 
    {
        CList.push_back(false);
        cout<<"You Entered: false. The typeid is: "<< typeid(bool).name()<<el;
        return;
    }*/
    if(s.size()==1&&!isdigit(s[0]))
    {
        CList.push_back(s[0]);
        cout<<"You Entered: '"<<s[0]<<"'. The typeid is: " << typeid(char).name()<<el;
        return;
    }
    if(!s.empty()&&(s.back()=='f'||s.back()=='F'))
    {
        string sub=s.substr(0, s.size()-1);
        size_t pos;
        float f=stof(sub, &pos);
        if(pos==sub.size())
        {
            CList.push_back(f);
            cout<<"You Entered: "<<f<<". The typeid is: "<<typeid(float).name()<<el;
            return;
        }
    }
    if(!s.empty()&&(s.size()>=2&&(s.substr(s.size()-2)=="ll"||s.substr(s.size()-2)=="LL"))) 
    {
        string sub=s.substr(0, s.size()-2);
        size_t pos;
        long long l=stoll(sub, &pos);
        if(pos==sub.size())
        {
            CList.push_back(l);
            cout<<"You Entered: "<<l<<". The typeid is: "<<typeid(long long).name()<<el;
            return;
        }
    }
    size_t pos;
    
    try {
        double d=stod(s, &pos);
        if(pos==s.size()) 
        {
            if(s.find('.')!=-1)
            {
                CList.push_back(d);
                cout<<"You Entered: "<<d<<". The typeid is: "<<typeid(double).name()<<el;
                return;
            }
            else if(is_int(s))
            { 
                try
                {
                    int i=stoi(s);
                    CList.push_back(i);
                    cout<<"You Entered: "<<i<< ". The typeid is: "<<typeid(int).name()<<el;
                    return;
                } 
                catch (const std::out_of_range& e)
                {
                    long long l=stoll(s); 
                    CList.push_back(l);
                    cout << "You Entered: " << l << ". The typeid is: "<<typeid(long long).name() << " long long" << el;
                    return;
                }
            }
        }
    } catch (const std::invalid_argument& e) {
    } catch (const std::out_of_range& e) {
    }
    CList.push_back(s);
    cout<<"You Entered: \""<<s<<"\". The typeid is: "<<typeid(string).name()<<el;
}
void display(const DynamicList& CList) 
{
    cout<<el<<el<<"-------------------------------------------------------"<<el;
    cout<<"     SHAHOODA'S  F I N A L   L I S T   C O N T E N T           "<<el;
    cout<<"-------------------------------------------------------"<<el;
    for(int i=0; i<CList.size(); i++) 
    {
        const auto& item=CList[i];
        cout<<"["<<i<<"] Value: ";
        if (item.type() == typeid(char))
            cout << "'" << std::any_cast<char>(item)<<"'";
        else if(item.type() == typeid(bool)) 
            cout << (std::any_cast<bool>(item)?"true" : "false");
        else if(item.type() == typeid(int)) 
            cout << std::any_cast<int>(item);
        else if(item.type() == typeid(long long)) 
            cout << std::any_cast<long long>(item)<<"LL";
        else if(item.type() == typeid(float)) 
            cout << std::any_cast<float>(item)<<"f";
        else if(item.type() == typeid(double)) 
            cout << std::any_cast<double>(item);
        else if(item.type() == typeid(string)) 
            cout << "\"" << std::any_cast<string>(item)<<"\"";
        else
             cout<<"OUCH! Unsupported Type!! :(";
        cout<<" & C++ Type ID is: "<< item.type().name()<<el;
    }
}
