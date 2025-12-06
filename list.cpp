#include "list.h"

using namespace std;

bool is_integer(const string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+') {
        if (s.length() == 1) return false;
        start = 1;
    }
    for (size_t i = start; i < s.length(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

void process_user_input(DynamicList& myList, int current_index) {
    string input;
    cout << "\n[" << current_index + 1 << "] Enter value (char, int, 1.0f, true, 1.0, 10000000000LL, or string): ";
    
    if (!getline(cin, input)) {
        return;
    }

    if (input.empty()) {
        cout << "  No input entered. Treating as empty string." << endl;
        input = "";
    }

    if (input == "true" || input == "True" || input == "TRUE") {
        myList.push_back(true);
        cout << "  Entered: true. The typeid is: " << typeid(bool).name() << endl;
        return;
    }
    if (input == "false" || input == "False" || input == "FALSE") {
        myList.push_back(false);
        cout << "  Entered: false. The typeid is: " << typeid(bool).name() << endl;
        return;
    }

    if (input.length() == 1 && !isdigit(input[0])) {
        myList.push_back(input[0]);
        cout << "  Entered: '" << input[0] << "'. The typeid is: " << typeid(char).name() << endl;
        return;
    }

    if (!input.empty() && (input.back() == 'f' || input.back() == 'F')) {
        string numeric_part = input.substr(0, input.length() - 1);
        try {
            size_t pos;
            float float_val = stof(numeric_part, &pos);
            if (pos == numeric_part.length()) {
                myList.push_back(float_val);
                cout << "  Entered: " << float_val << ". The typeid is: " << typeid(float).name() << endl;
                return;
            }
        } catch (...) {}
    }

    if (!input.empty() && (input.length() >= 2 && (input.substr(input.length() - 2) == "ll" || input.substr(input.length() - 2) == "LL"))) {
        string numeric_part = input.substr(0, input.length() - 2);
        try {
            size_t pos;
            long long ll_val = stoll(numeric_part, &pos);
            if (pos == numeric_part.length()) {
                myList.push_back(ll_val);
                cout << "  Entered: " << ll_val << ". The typeid is: " << typeid(long long).name() << endl;
                return;
            }
        } catch (...) {}
    }
    
    try {
        size_t pos;
        double double_val = stod(input, &pos);
        if (pos == input.length()) {
            if (input.find('.') != string::npos) {
                myList.push_back(double_val);
                cout << "  Entered: " << double_val << ". The typeid is: " << typeid(double).name() << endl;
                return;
            }
            else if (is_integer(input)) { 
                try {
                    int int_val = stoi(input);
                    myList.push_back(int_val);
                    cout << "  Entered: " << int_val << ". The typeid is: " << typeid(int).name() << endl;
                    return;
                } catch (...) {
                    myList.push_back(stoll(input));
                    cout << "  Entered: " << stoll(input) << ". The typeid is: " << typeid(long long).name() << " (Default large integer)" << endl;
                    return;
                }
            }
        }
    } catch (...) {} 

    myList.push_back(input);
    cout << "  Entered: \"" << input << "\". The typeid is: " << typeid(string).name() << endl;
}

void display_list_content(const DynamicList& myList) {
    cout << "\n\n=======================================================" << endl;
    cout << "     SHAHOODA'S  F I N A L   L I S T   C O N T E N T           " << endl;
    cout << "=======================================================" << endl;
    
    for (size_t i = 0; i < myList.size(); ++i) {
        const auto& item = myList[i];
        cout << "[" << i << "] Value: ";
        
        if (item.type() == typeid(char)) {
            cout << "'" << std::any_cast<char>(item) << "'";
        } else if (item.type() == typeid(bool)) {
            cout << (std::any_cast<bool>(item) ? "true" : "false");
        } else if (item.type() == typeid(int)) {
            cout << std::any_cast<int>(item);
        } else if (item.type() == typeid(long long)) {
            cout << std::any_cast<long long>(item) << "LL";
        } else if (item.type() == typeid(float)) {
            cout << std::any_cast<float>(item) << "f";
        } else if (item.type() == typeid(double)) {
            cout << std::any_cast<double>(item);
        } else if (item.type() == typeid(string)) {
            cout << "\"" << std::any_cast<string>(item) << "\"";
        } else {
             cout << "[Unsupported Type]";
        }
        
        cout << " | C++ Type ID: " << item.type().name() << endl;
    }
    cout << "=======================================================" << endl;
}