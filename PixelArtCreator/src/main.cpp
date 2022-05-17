#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>

//-------Settings-------
int WIDTH=500;
int HEIGHT=500;

int ROWS=25;

sf::Color pen_color(sf::Color::Red);

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NeoPix-V2");

sf::RectangleShape matrix[30][30];

sf::RectangleShape blue(sf::Vector2f(20.f, 20.f));
sf::RectangleShape yellow(sf::Vector2f(20.f, 20.f));
sf::RectangleShape green(sf::Vector2f(20.f, 20.f));
sf::RectangleShape black(sf::Vector2f(20.f, 20.f));





void create_grid(){
    for(int i=0;i <= ROWS-1; i++)
    {
        for(int j=0; j <= ROWS-1; j++)
        {
            matrix[i][j] = sf::RectangleShape(sf::Vector2f(20.f, 20.f));
            matrix[i][j].setPosition(i*20, j*20);
            sf::Vector2f block_position = matrix[i][j].getPosition();
            matrix[i][j].setFillColor(sf::Color::White);
            matrix[i][j].setOutlineColor(sf::Color::Black);
            matrix[i][j].setOutlineThickness(-0.5);
            window.draw(matrix[i][j]);
        }
    }

    
}

void clear_grid(){
    for(int i=0;i <= ROWS-1; i++)
    {
        for(int j=0; j <= ROWS-1; j++)
        {
            matrix[i][j] = sf::RectangleShape(sf::Vector2f(20.f, 20.f));
            matrix[i][j].setPosition(i*20, j*20);
            sf::Vector2f block_position = matrix[i][j].getPosition();
            matrix[i][j].setFillColor(sf::Color::White);
            matrix[i][j].setOutlineColor(sf::Color::Black);
            matrix[i][j].setOutlineThickness(-0.5);
            window.draw(matrix[i][j]);
        }
    }

    
}


void color_square(int coord_x, int coord_y){
    for(int i=0;i <= ROWS-1; i++)
    {
        for(int j=0; j <= ROWS-1; j++)
        {

            sf::Vector2f block_position = matrix[i][j].getPosition();

            if(block_position.x == coord_x && block_position.y == coord_y)
                matrix[i][j].setFillColor(pen_color);
            matrix[i][j].setOutlineThickness(-0.5);

        }
    }
}

void delete_square(int coord_x, int coord_y){
    for(int i=0;i <= ROWS-1; i++)
    {
        for(int j=0; j <= ROWS-1; j++)
        {

            sf::Vector2f block_position = matrix[i][j].getPosition();

            if(block_position.x == coord_x && block_position.y == coord_y)
                {matrix[i][j].setFillColor(sf::Color::White);
                matrix[i][j].setOutlineThickness(-0.5);}

        }
    }
}


void update_matrix(){
    for(int i=0;i <= ROWS-1; i++)
        for(int j=0; j <= ROWS-1; j++)
            window.draw(matrix[i][j]);
}


int main()
{



    create_grid();
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) 
                    {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                        
                        
                        mouse_position.x-=(mouse_position.x%20);
                        mouse_position.y-=(mouse_position.y%20);


                        
                        if (event.mouseButton.button == sf::Mouse::Left) 
                            color_square(mouse_position.x, mouse_position.y);
                        if (event.mouseButton.button == sf::Mouse::Right)
                            delete_square(mouse_position.x, mouse_position.y);
                        if (event.mouseButton.button == sf::Mouse::Middle)
                            {
                                std::cout << "|------Enter the R G B of your color to change it------|" << '\n';
                                int r=0;
                                int g=0;
                                int b=0;
                                std::cout << "R: ";
                                std::cin >> r;
                                std::cout << "G: ";
                                std::cin >> g;
                                std::cout << "B: ";
                                std::cin >> b;
                                pen_color = sf::Color(r,g,b);
                            }
                    }
            if(event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                        clear_grid();
                
        }

        

        
        update_matrix();
        window.display();
    }

    return 0;
}