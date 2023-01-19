#include "window.hpp"

Window::Window()
{
    Reader::getInstance().read_from_file(input);
    vm = sf::VideoMode::getDesktopMode();
    window.create(vm, "Quick Sort Visualizer", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    width = (float)vm.width / input.size();
    update_rectangles();
}

void Window::update_rectangles()
{
    rects.clear();
    for (size_t i = 0; i < input.size(); ++i)
    {
        sf::RectangleShape temp;
        temp.setSize(sf::Vector2f(width, (float)input[i]));
        temp.setPosition(i * width, vm.height - temp.getSize().y);
        temp.setOutlineColor(sf::Color::Black);
        temp.setOutlineThickness(-1.f);
        temp.setFillColor(sf::Color::White);

        rects.push_back(temp);
    }
}

void Window::run()
{
    sf::Clock clock; // delta time
    const sf::Time time_per_frame = sf::seconds(1.0f / 12.0f);
    sf::Time time_since_last_update = sf::Time::Zero;
    while (window.isOpen())
    {
        update_poll_events();
        time_since_last_update += clock.restart();
        while (time_since_last_update > time_per_frame)
        {
            time_since_last_update -= time_per_frame;
            update_poll_events();
            render();
        }
    }
}

void Window::update_poll_events()
{
    while (window.pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
        case sf::Event::KeyPressed:
        {
            if (ev.key.code == sf::Keyboard::Escape)
            {
                window.close();
                break;
            }
            else if (ev.key.code == sf::Keyboard::Space || ev.key.code == sf::Keyboard::Return)
            {
                quicksort();
                break;
            }
        }
        default:
            break;
        }
    }
}

void Window::quicksort()
{
    Quicksort qs;
    qs.sort(input, this);
    update_rectangles();
}

void Window::render()
{
    window.clear();
    for (auto &i : rects)
    {
        window.draw(i);
    }
    window.display();
}

Window::~Window() {}