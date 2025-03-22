#ifndef JSON_H
#define JSON_H

#include <utility>
#include <string>
#include <vector>

class Json {
public:
    enum Type {
        list,
        element,
    };
private:
    std::vector<std::pair<std::string, std::string>> m_elements;
    Type m_type;
public:
    Type getType() const {return m_type;}
    std::vector<std::pair<std::string, std::string>>& getAllElements() {return m_elements;}
    void addElement(const std::string_view, const std::string_view);
    void removeElement(const std::string_view);
    std::pair<std::string&, std::string&>& const getElementByKey(const std::string_view);
    std::string& toString();

};


#endif