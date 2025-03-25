#pragma once
#include "Vect2.h"
#include <string>

class Action
{
    private:
        std::string m_type = ""; // START or END
        std::string m_name = ""; // name of the action
        Vect2 m_mousePosition;
        
    public:
        Action(std::string type, std::string name):m_type(type), m_name(name){}
        Action(std::string type, std::string name, Vect2 mousePosition): m_type(type), m_name(name) ,m_mousePosition(mousePosition){}

        const std::string& getType() const
        {
            return m_type;
        }

        const std::string& getName() const
        {
            return m_name;
        }

        Vect2& getMousePosition()
        {
            return m_mousePosition;
        }
};