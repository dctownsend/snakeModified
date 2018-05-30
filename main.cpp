//
//  main.cpp
//  sfml tut
//
//  Created by dakota townsend on 5/24/18.
//  Copyright © 2018 dakota townsend. All rights reserved.

//HOMEWORK

// change image of food
// change speed as grow
// add second player


#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace sf;

//globals
int num_vertBox = 30, num_horzBox = 20;
int size= 16; //num of pixels
int w = size * num_horzBox; //background num of pixels (width)
int h = size * num_vertBox; //background num of pixels (height)

int direction, snake_length= 4;

//max size of snake
struct Snake{
    int x, y;
}s{100};

struct Fruit {
    int x, y;
}food[100];

void tick() {
    //move remaining pieces of snake
    for(int i = snake_length; i > 0; --i){
    s[i].x = s[i-1].x;
    s[i].y = s[i-1].y;
    }
    
    //head of snake depends on direction
    if(direction == 3)
        s[0].y -= 1;
    if(direction == 0)
        s[0].y += 1;
    if(direction == 1)
        s[0].x = -= 1;
    if(direction == 2)
        s[0].x += 1;
    
    //if snake eats food
    if( (s[0].x) == food.x && (s[0].y) == food.y ) {
        snake_length++;
        
        //randomly place food somewhere
        food.x = rand() % num_horzBox;
        food.y = rand() % num_vertBox;
    }
    
    if(s[0].x > num_horzBox)
        s[0].x = 0;
    if(s[0].x < 0)
        s[0].x = num_horzBox
        
    if(s[0].y > num_vertBox)
            s[0].y = 0;
    if(s[0].y < 0)
        s[0].y = num_vertBox;
    
    //check is go over snake
    for(int i = 1; i < snake_length; i++) {
        //cut snake in hald from place eaten
        if(s[0].x == s[i].x && s[0].y == s[i].y)
            snake_length = i;
    }

int main() {
    srand(time(0));
    
    RenderWindow window(VideoMode(w, h), "Snake Game!");
    
    //textures
    Texture t1, t2, t3;
    t1.loadFromFile("image/white.png");
    t2.loadFromFile("image/red.png");
    t3.loadFromFile("image/green.png");
    
    //Sprites have physical dimensions
    Sprite sprite1(t1);
    Sprite sprite(t2);
    Sprite sprite(t3);
    
    food.x = 10;
    food.y = 10;
    
    Clock clock;
    float timer = 0, delay = 0.1;
    
    While(window.isOpen()) {
        
        float time = clock.getElapsedTime().asSeconds();
        clcok.restart();
        
        //allow us to check when a user does something
        Event e;
        
        //check when the window is closing
        while(window.pollEvent(e)) {
            if(e.type == Event::Closed) {
                window.close();
            }
        }
         if(Keyboard:: isKeyPressed(Keyboard::Up)) direction = 3;
         if(Keyboard:: isKeyPressed(Keyboard::Down)) direction = 0;
         if(Keyboard:: isKeyPressed(Keyboard::Left)) direction = 1;
         if(Keyboard:: isKeyPressed(Keyboard::Right)) direction = 1;
        
        if(time > delay){
            timer = 0;
            tick();
        }
        
        //draw
        window.clear();
        
        //background
        for(int 0 = 0; i < num_horzBox; i++)
            for(int j=0; j < num_vertBox; j++) {
                sprite1.setPosition(i*size, j*size);
                window.draw(sprite1);
            }
        //draw snake
        for (int i = 0l i < snake_length; i++){
            sprite2.setPosition(s[i].x*size, s[i].y*size);
            window.draw(sprite2);
        }
        
        sprite3.setPosition(food.x*size, food.y*size);
        window.draw(sprite3);
        
        window.display();
    }
    
    return 0;
}


