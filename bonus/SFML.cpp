/*
** EPITECH PROJECT, 2019
** test affichage ground ligne
** File description:
** SFML
*/

#include "groundhog.hpp"

void do_SFML(std::vector<float> moy, std::vector<float> boolplus, std::vector<float> boolmoins, std::vector<float> index)
{
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(1900, 900), "SFML works!", sf::Style::Close, settings);
    window.setFramerateLimit(20);

    sf::VertexArray line_moy(sf::LineStrip, moy.size());
    sf::VertexArray line_plus(sf::LineStrip, boolplus.size());
    sf::VertexArray line_moins(sf::LineStrip, boolmoins.size());
    std::vector<sf::CircleShape> point;

    std::vector<float>::iterator it = moy.begin();
    std::vector<float>::iterator it_plus = boolplus.begin();
    std::vector<float>::iterator it_moins = boolmoins.begin();
    std::vector<float>::iterator it_index = index.begin();

    int x_moy = 30;
    int x_plus = 30;
    int x_moins = 30;
    int x_index = 30;
    int y = 0;

    for (int i = 0; i < moy.size(); i += 1)
    {
        y = 1250 - ((*it * 800) / 30);
        line_moy[i].position = sf::Vector2f(x_moy, y);
        x_moy += 25;
        ++it;
    }
    for (int i = 0; i < boolplus.size(); i += 1)
    {
        y = 1250 - ((*it_plus * 800) / 30);
        line_plus[i].position = sf::Vector2f(x_plus, y);
        line_plus[i].color = sf::Color(100, 250, 50);
        x_plus += 25;
        ++it_plus;
    }
    for (int i = 0; i < boolmoins.size(); i += 1)
    {
        y = 1250 - ((*it_moins * 800) / 30);
        line_moins[i].position = sf::Vector2f(x_moins, y);
        line_moins[i].color = sf::Color(250, 100, 50);
        x_moins += 25;
        ++it_moins;
    }

    for (int i = 0; i < index.size(); i += 1)
        point.push_back(sf::CircleShape(1));

    for (auto m = point.begin(); m != point.end(); m++)
    {
        y = 1250 - ((*it_index * 800) / 30);
        m->setPosition(x_index, y);
        m->setFillColor(sf::Color::Red);
        ++it_index;
        x_index += 25;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(line_moy);
        window.draw(line_plus);
        window.draw(line_moins);
        for (auto p = point.begin(); p != point.end(); p++)
            window.draw(*p);
        window.display();
    }
}