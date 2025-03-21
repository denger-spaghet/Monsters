#include "input.h"

Input::Input():
    m_inputString { "" },
    m_message { "" },
    m_type { Type::none_type },
    m_value { Value::none_value } {
        getInput();
    }

Input::Input(Type type, std::string_view message):
    m_inputString { "" },
    m_message { message },
    m_type { type },
    m_value { Value::none_value } {
        parseValue();
    }

void Input::getInput() {
    std::string input {};
    std::cout << m_message;

    std::getline(std::cin, input);
    m_inputString = input;
}

bool Input::check(const char **options) {
    const char* input = m_inputString.c_str();
    size_t cnt { 0 };
    while(options[cnt] != nullptr) {
        if(strcmp(options[cnt], input) == 0) {
            return true;
        }
    }
    return false;
}

void Input::parseValue() {
    const char *optionsYes[] {"yes", "y", "Y", nullptr}; 
    const char *optionsNo[] {"no", "n", "N", nullptr}; 
    const char *optionsRun[] {"run", "r", "R", nullptr}; 
    const char *optionsFight[] {"fight", "f", "F", nullptr}; 
    const char *optionsleft[] {"left", "l", "L", nullptr}; 
    const char *optionsRight[] {"right", "r", "R", nullptr}; 

    switch(m_type) {
        case Type::yesNo: 
            if(readValue(optionsYes, optionsNo)){
                m_value = Value::yes;
            } else {
                m_value = Value::no;
            }
            return;
        case Type::runFight:
            
            
            if(readValue(optionsRun, optionsFight)){
                m_value = Value::run;
            } else {
                m_value = Value::fight;
            };
            return;
        case Type::leftRight:
            
           
            if(readValue(optionsleft, optionsRight)){
                m_value = Value::left;
            } else {
                m_value = Value::right;
            };
            return;
        default: return;
    }
}

bool Input::readValue(const char **optionsA, const char **optionsB) {
    bool a { false };
    bool b { false };

    do {
        getInput();
        a = check(optionsA);
        b = check(optionsB);
    } while(!a && !b);
    std::cout << "here";
    return a;
}
