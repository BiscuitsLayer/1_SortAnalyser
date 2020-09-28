#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

    //  TRAITS  //
#include "fonts/traits.hpp"
#include "textures/traits.hpp"

class Button : public sf::Drawable {
public:
    Button (sf::Texture texture, sf::Vector2f position, sf::Vector2f size, sf::Text text):
        texture_ (texture),
        rect_ ({size}),
        text_ (text)
        {
            rect_.setPosition (position);
            rect_.setTexture (&texture_);     

            using namespace textureParams;
            rect_.setTextureRect (sf::Rect <int> (posX, posY, sizeX, sizeY));

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
    sf::Vector2f GetPosition () const {
        return rect_.getPosition ();
    }
    sf::Vector2f GetSize () const {
        return rect_.getSize ();
    }
    void MouseCheck (sf::RenderWindow &window, bool isButtonPressed) {
        using namespace textureParams;
        if (OnMouse (window)) {
            if (isButtonPressed)
                rect_.setTextureRect (sf::Rect <int> (posX, posYPressed, sizeX, sizeY));
            else
                rect_.setTextureRect (sf::Rect <int> (posX, posYOnMouse, sizeX, sizeY));
        }
        else 
            rect_.setTextureRect (sf::Rect <int> (posX, posY, sizeX, sizeY));
    }
private:
    sf::Texture texture_ = {};
    sf::RectangleShape rect_;
    sf::Text text_ = {};

    bool OnMouse (sf::RenderWindow &window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition (window);
        sf::Vector2f buttonPosLT = rect_.getPosition ();
        sf::Vector2f buttonPosRB = buttonPosLT + rect_.getSize ();
        if (mousePos.x > buttonPosLT.x && mousePos.x < buttonPosRB.x) {
            if (mousePos.y > buttonPosLT.y && mousePos.y < buttonPosRB.y) {
                return true;
            }
        }
        return false;
    }
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
    texture.loadFromFile ("textures/blue.png");

    sf::RectangleShape rect ({250, 40});
    rect.setTexture (&texture);

    sf::Font font;
    font.loadFromFile ("fonts/Russian.ttf");

    sf::Text text = {};
    text.setString ("KNOPKA");
    text.setColor (sf::Color::White);
    text.setFont (font);
    text.setCharacterSize (fontParams::charSize);
    text.setOrigin ({fontParams::posX, fontParams::posY});

    Button *buttons = new Button (texture, rect.getPosition (), rect.getSize (), text);

    while (window.isOpen ())
    {
        sf::Event event;
        while (window.pollEvent (event))
        {
            buttons[0].MouseCheck (window, sf::Mouse::isButtonPressed (sf::Mouse::Button::Left));

            if (event.type == sf::Event::Closed || 
                sf::Keyboard::isKeyPressed (sf::Keyboard::Key::Q) ||
                sf::Keyboard::isKeyPressed (sf::Keyboard::Key::Escape))
                window.close ();
        } 
      
        Draw (window, buttons, 1);
    }

    return 0;
}