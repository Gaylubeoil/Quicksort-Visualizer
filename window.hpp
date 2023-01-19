#pragma once
#include "PCH.hpp"
#include "Reader.hpp"
#include "Quicksort.hpp"

class Window
{
public:
    Window();
    ~Window();

    void run();
    void update_poll_events();
    void render();

    void update_rectangles();
    void quicksort();

private:
    sf::RenderWindow window;
    sf::VideoMode vm;
    sf::Event ev;

    std::vector<int> input;
    std::vector<sf::RectangleShape> rects;

    float width;
};