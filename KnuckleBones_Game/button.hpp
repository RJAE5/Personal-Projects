/*
 * Button Class
 *
 * Description:
 *      This class contains methods to construct and
 *      utilize different buttons throughout the game
 *      depending on the game state
 *      
 *
 * Public Methods:
 *            - Button()
 *  void      - drawButton(sf::RenderWindow& window)
 *  void      - setRolling()
 *  void      - setInstruction()
 *  void      - setReady()
 *  void      - setGameOver()
 *  bool      - isButtonClicked() 
 *  
 *
 * Private Methods:
 *
 * 
 * Usage:
 *
 *       - This class is used to create an instance of a button
 *         for which the user can click to initiate a rool of
 *         the die. The state of the button will vary depending
 *         on what the state of the die is.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Button
{
    // Button elements 
    sf::RectangleShape body;
    sf::RectangleShape outline;
    sf::Text text;
    sf::Font font;

    // Parameters of button elements
    int buttonStartX;
    int buttonStartY;
    int buttonWidth;
    int buttonHeight;
    int textStartX;
    int textStartY;

public:

    /*
    * Public : Button
    *
    * Description:
    *      Default constructor for button, used to initialize
    *      button parameters and load the font.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    Button()
    {
         // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        // Button and text starting positions
        buttonStartX = 395;
        buttonStartY = 475;
        buttonWidth = 200;
        buttonHeight = 100;
        textStartX = (buttonStartX + (.25 * buttonWidth));
        textStartY = (buttonStartY + (.25 * buttonHeight));

        // Main body of the button parameters
        body.setSize(sf::Vector2f(buttonWidth, buttonHeight));
        body.setPosition(buttonStartX, buttonStartY);
        body.setFillColor(sf::Color::Green);

        // Outline of button parameters
        outline.setSize(sf::Vector2f(buttonWidth + 10, buttonHeight + 10));
        outline.setPosition(buttonStartX - 5, buttonStartY - 5);
        outline.setFillColor(sf::Color::Black);

        // Initial text parameters
        text.setString("Roll");
        text.setFont(font);
        text.setCharacterSize(36);
        text.setFillColor(sf::Color::Black);
        text.setPosition(textStartX + 20, textStartY);   
    }

    /*
    * Public : drawButton
    *
    * Description:
    *      Draws all of the elemnts of the button
    *      in order to resembl an actual button.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void drawButton(sf::RenderWindow& window)
    {
        // Drawing button elements in order
        window.draw(outline);
        window.draw(body);
        window.draw(text);
    }

    /*
    * Public : setRolling
    *
    * Description:
    *      Changes the button state to show
    *      that it is currently rolling.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void setRolling()
    {
        // Change button to rolling status
        text.setPosition(textStartX, textStartY);
        body.setFillColor(sf::Color::Red);
        text.setString("Rolling");
    }

    /*
    * Public : setInstruction
    *
    * Description:
    *      Changes the button state to show
    *      the user an instruction to place
    *      the value in the grid.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void setInstruction()
    {
        // Change button to instruction status
        body.setFillColor(sf::Color::Yellow);
        text.setString("Place");
    }

    /*
    * Public : setReady
    *
    * Description:
    *      Changes the button state to show
    *      that it is ready to be clicked.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void setReady()
    {
        // Change button to ready status
        text.setPosition(textStartX + 20, textStartY);
        body.setFillColor(sf::Color::Green);
        text.setString("Roll");
    }

    /*
    * Public : setGameOver
    *
    * Description:
    *      Changes the button state to show
    *      that the game is over, giving the
    *      user the option to restart the game.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void setGameOver()
    {
        text.setPosition(textStartX - 10, textStartY);
        body.setFillColor(sf::Color::Red);
        text.setString("Restart");
    }


    /*
    * Public : setRolling
    *
    * Description:
    *      Compares the position that was clicked
    *      to the bounds of the button.
    *
    * Params:
    *     sf::Vector2i& - The coordinates of the mouse click
    *
    * Returns:
    *     bool - Whether or not the button was clicked
    */
    bool isButtonClicked(sf::Vector2i& mousePos)
    {
        // Determine if button is what was clicked
        if(body.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            return true;
        else
            return false;
    }
};