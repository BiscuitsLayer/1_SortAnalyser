#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

    //  TRAITS  //
#include "fonts/traits.hpp"

class Button : public sf::Drawable {
public:
    Button (sf::Texture texture, sf::Vector2f position, sf::Vector2f size, sf::Text text):
        texture_ (texture),
        rect_ ({size}),
        text_ (text)
        {
            rect_.setPosition (position);
            rect_.setTexture (&texture_);
            text_.setPosition (position);
        }
    Button ():
        texture_ ({}),
        rect_ (), 
        text_ ()
        {
            text_.setString ("Sample text");
        }
    ~Button () = default;
    sf::Vector2f GetPosition () {
        return rect_.getPosition ();
    }
    sf::Vector2f GetSize () {
        return rect_.getSize ();
    }
private:
    sf::Texture texture_ = {};
    sf::RectangleShape rect_;
    sf::Text text_ = {};
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw (rect_);
        target.draw (text_);
    }
};

class Window {
public:
    Window (size_t capacity):
        capacity_ (capacity)
        {
            buttons_ = new Button [capacity_] ();
        }
    ~Window () {
        delete [] buttons_;
    }
private:
    Button *buttons_ = nullptr;
    size_t capacity_ = 0;    
};

void Draw (sf::RenderWindow& window, sf::Drawable *drawables, size_t drawablesSize) {
    window.clear ();
    for (size_t i = 0; i < drawablesSize; ++i) {
        window.draw (drawables[i]);
    }
    window.display ();
}

int main()
{
    sf::RenderWindow window (sf::VideoMode(500, 500), "Sort Analyser");

    sf::Texture texture = {};
    texture.loadFromFile ("textures/ice.jpg");

    sf::RectangleShape rect ({100.f, 100.f});
    rect.setTexture (&texture);

    sf::Font font;
    font.loadFromFile ("fonts/Russian.ttf");

    sf::Text text = {};
    text.setString ("KNOPKA");
    text.setColor (sf::Color::White);
    text.setFont (font);

    Button *buttons = new Button (texture, rect.getPosition (), rect.getSize (), text);

    while (window.isOpen ())
    {
        sf::Event event;
        while (window.pollEvent (event))
        {
            if (event.type == sf::Event::Closed)
                window.close ();
        }

        Draw (window, buttons, 1);
    }

    return 0;
}