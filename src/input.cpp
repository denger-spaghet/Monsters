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
    if(m_message != "") {
        std::cout << m_message << ": ";
    }
    

    std::getline(std::cin, input);
    m_inputString = input;
}

bool Input::check(const std::vector<std::string> options) {
    for(auto& option : options) {
        if(option == m_inputString) return true;
    }
    return false;
}

void Input::parseValue() {
    int option { -1 };
    switch(m_type) {
        case Type::yesNo: 
            option = readValue({{"yes", "y", "Y"}, {"no", "n", "N"}});
            if(option == 0) m_value = Value::yes;
            if(option == 1) m_value = Value::no;
            return;
        case Type::runFight:
            option = readValue({{"run", "r", "R"}, {"fight", "f", "F"}});            
            if(option == 0) m_value = Value::run;
            if(option == 1) m_value = Value::fight;
            return;
        case Type::leftRight:
            option = readValue({{"left", "l", "L"}, {"right", "r", "R"}});            
            if(option == 0) m_value = Value::left;
            if(option == 1) m_value = Value::right;
            return;
        default: return;
    }
}

int Input::readValue(const std::vector<std::vector<std::string>> options) {
    do {
        getInput();
        for(int i { 0 }; i < options.size(); i++) {
            if(check(options[i])) {
                return i;
            }
        }
    } while(true);
}

std::ostream& operator<<(std::ostream& os, const Input& obj) {
    os << "Input: \n"
        << "string: " << obj.getString() << "\n"
        << "message: " << obj.getMessage() << "\n"
        << "Type: " << obj.getTypeAsString() << "\n"
        << "Value: " << obj.getValueAsString() << "\n";
    return os;
}