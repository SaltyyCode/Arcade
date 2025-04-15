/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "Factories/NCursesTextFactory.hpp"
#include "Models/NCursesText.hpp"

namespace Arc {
    
    void NCursesTextFactory::load(std::string path)
    {
        this->_fontPath = path;
    }
    
    std::shared_ptr<Shared::Models::IText> NCursesTextFactory::create()
    {
        auto text = std::make_shared<NCursesText>();
        
        if (!_fontPath.empty()) {
            text->setFont(_fontPath);
        }
        
        return text;
    }
}