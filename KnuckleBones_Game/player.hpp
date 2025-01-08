/*
 * Player Class
 *
 * Description:
 *      This class contains methods for managing the player's
 *      username. The player's score is managed by the game and
 *      grid classes.
 *      
 *
 * Public Methods:
 *            - Player()
 *  sf::Text  - getName()
 *  
 *
 * Private Methods:
 * 
 *
 * Usage:
 *
 *       - This class is used to create an instance of the
 *         player and keep track of their username.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
    std::string uName;
    sf::Font font;
    sf::Text uNameText;
    
public:
    /*
    * Public : Player
    *
    * Description:
    *      Constructor for the player to initialize 
    *      the username passed in into an sf::Text object,
    *      as well as loading the font.
    *
    * Params:
    *     std::string - The username of the player
    *
    * Returns:
    *     None
    */
    Player(std::string un)
    {
        // Save username
        uName = un;
        
         // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        // Convert username to sf::Text
        uNameText.setString(uName);
        uNameText.setFont(font);
        uNameText.setCharacterSize(24);
        uNameText.setPosition(0,0);
        uNameText.setFillColor(sf::Color::Blue);
    }

    /*
    * Public : getName
    *
    * Description:
    *      Returns the username of the player.
    *
    * Params:
    *     None
    *
    * Returns:
    *     sf::Text - The uname of the player as a displayable object
    */
    sf::Text getName()
    {
        //return name in sf::Text format
        return uNameText;
    }
};