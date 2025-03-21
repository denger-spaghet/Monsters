#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <cstring>

class Input {
public:
    enum Type {
        yesNo,
        runFight,
        leftRight,
        none_type,
    };
    enum Value {
        yes,
        no,
        run,
        fight,
        left,
        right,
        none_value
    };
private:
    std::string m_message;
    std::string m_inputString;
    Type m_type;
    Value m_value;

    bool check(const char**);
    void getInput();
    void parseValue();
    bool readValue(const char**, const char**);
public:
        
    Input();
    Input(Type, std::string_view);

    const std::string& getString() const {return m_inputString;}
    Type getType() const {return m_type;}
    Value getValue() const {return m_value;}
};



#endif