#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <vector>
#include <array>

class Input {
public:
    enum Type {
        yesNo,
        runFight,
        leftRight,
        none_type,
        max_types,
    };
    enum Value {
        yes,
        no,
        run,
        fight,
        left,
        right,
        none_value,
        max_values,
    };
private:
    std::string m_message;
    std::string m_inputString;
    Type m_type;
    Value m_value;

    bool check(const std::vector<std::string>);
    void getInput();
    void parseValue();
    int readValue(const std::vector<std::vector<std::string>>);

    static inline std::array<std::string, Type::max_types> typeStrings {
        "yesNo", "runFight", "leftRight", "none_type"
    };

    static inline std::array<std::string, Value::max_values> valueStrings {
        "yes", "no", "run", "fight", "left", "right", "none_value"
    };
public:
        
    Input();
    Input(Type, std::string_view);

    const std::string& getString() const {return m_inputString;}
    const std::string& getMessage() const {return m_message;}
    Type getType() const {return m_type;}
    Value getValue() const {return m_value;}
    const std::string& getTypeAsString() const {return typeStrings[m_type];}
    const std::string& getValueAsString() const {return valueStrings[m_value];}
    friend std::ostream& operator<<(std::ostream& os, const Input& obj);
};



#endif