#ifndef FONT_TRAITS_HPP
#define FONT_TRAITS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

std::ostream& operator << (std::ostream& stream, const sf::String& str) {
    stream << std::string (str);
    return stream;
}

namespace fontParams {
    const int posX = -75, posY = -3;
    const int charSize = 25;
}

#endif //FONT_TRAITS_HPP
