#ifndef FONT_TRAITS_HPP
#define FONT_TRAITS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

std::ostream& operator << (std::ostream& stream, const sf::String& str) {
    stream << std::string (str);
    return stream;
}

#endif //FONT_TRAITS_HPP
