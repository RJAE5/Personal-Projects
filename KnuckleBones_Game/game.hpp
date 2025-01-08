/*
 * Game Class
 *
 * Description:
 *      This class contains methods for managing the prompts displayed
 *      by the game as well as displaying the score of the player
 *      
 *
 * Public Methods:
 *            - Game()
 *  void      - drawPrompt(sf::RenderWindow& window)
 *  void      - drawFinalPrompt(sf::RenderWindow& window)
 *  void      - setRollPrompt()
 *  void      - setPlacePrompt()
 *  void      - setGameOverPrompt(int s)
 *  void      - drawScore(sf::RenderWindow& window, int s)
 *  
 *
 * Private Methods:
 * 
 *
 * Usage:
 *
 *       - This class is used to create an instance of the
 *         game and manage the prompts to be displayed for
 *         the user, as well as displaying player's score
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Game
{
    sf::Text playerDisplayScore;     // Player's score to be displayed
    sf::Text playerDisplayHighScore; // Player's highest score to be displayed
    sf::Text prompt;                 // Variable prompt to be displayed
    sf::Text finalPrompt;            // Prompt to be displayed in game over state
    sf::Font font;                   // Font object
    int score;                       // Player's score value
    int highScore;                   // Player's highest score

    Grid gameGrid;                  // Instance of the grid object

public:

    /*
    * Public : Game
    *
    * Description:
    *      Overloaded constructor where grid instance is required,
    *      loads the font, inits display score, inits prompts, and
    *      assigns the grid to the gameGrid object.
    *      
    *
    * Params:
    *     Grid& - The grid instance to link
    *
    * Returns:
    *     None
    */
    Game(Grid& grid)
    {
         // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        score = 0;
        highScore = 0;

        // Initialize score to be displayed
        playerDisplayScore.setString("Current Score: " + std::to_string(score));
        playerDisplayScore.setFont(font);
        playerDisplayScore.setCharacterSize(24);
        playerDisplayScore.setPosition(775.f, 0.f);
        playerDisplayScore.setFillColor(sf::Color::Blue);

        // Initialize score to be displayed
        playerDisplayHighScore.setString("High Score: " + std::to_string(highScore));
        playerDisplayHighScore.setFont(font);
        playerDisplayHighScore.setCharacterSize(24);
        playerDisplayHighScore.setPosition(775.f, 950.f);
        playerDisplayHighScore.setFillColor(sf::Color::Blue);

        // Initialize variable prompt
        prompt.setFont(font);
        prompt.setCharacterSize(48);
        prompt.setFillColor(sf::Color::Red);

        // Initialize game ending prompt
        finalPrompt.setFont(font);
        finalPrompt.setCharacterSize(36);
        finalPrompt.setFillColor(sf::Color::White);
        finalPrompt.setPosition(375.f, 675.f);

        // Link grid instance to game
        gameGrid = grid;
    }

    /*
    * Public : drawPrompt
    *
    * Description:
    *      Draws the variable prompt.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void drawPrompt(sf::RenderWindow& window)
    {window.draw(prompt);}

    /*
    * Public : drawFinalPrompt
    *
    * Description:
    *      Draws the prompt for the game over state
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void drawFinalPrompt(sf::RenderWindow& window)
    {window.draw(finalPrompt);}

    /*
    * Public : setRollPrompt
    *
    * Description:
    *      Changes variable prompt to ask the player to roll
    *      the dice.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void setRollPrompt()
    {
        // Roll instance of variable prompt
        prompt.setString("Press Spacebar to roll!");
        prompt.setPosition(250.f, 600.f);
    }

    /*
    * Public : setPlacePrompt
    *
    * Description:
    *      Changes variable prompt to ask the user to
    *      place the die value in the grid.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void setPlacePrompt()
    {
        // Place instance of variable prompt
        prompt.setString("Place value in grid.");
        prompt.setPosition(275.f,600.f);
    }

    /*
    * Public : setGameOverPrompt
    *
    * Description:
    *      Initialize the game over prompt with
    *      the final score of the player.
    *
    * Params:
    *     int - The value of the final score
    *
    * Returns:
    *     None
    */
    void setGameOverPrompt(int s)
    {
        // Initialize variable prompt for game over state
        prompt.setString("GAME OVER");
        prompt.setPosition(350.f,600.f);
        finalPrompt.setString("Final score: " + std::to_string(s));
        finalPrompt.setFillColor(sf::Color::Red);
    }

    /*
    * Public : drawScore
    *
    * Description:
    *      Draws the current score of the player.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *     int               - The current score of the player
    *
    * Returns:
    *     None
    */
    void drawScore(sf::RenderWindow& window, int s)
    {
        // Determine if new high score needs to be set
        if(s > highScore)
        {
            highScore = s;
            playerDisplayHighScore.setString("High Score: " + std::to_string(highScore));
        }
        // Draw sf::Text score
        playerDisplayScore.setString("Current Score: " + std::to_string(s));
        
        window.draw(playerDisplayScore);
        window.draw(playerDisplayHighScore);
    }

    /*
    * Public : setScore
    *
    * Description:
    *      Sets the score variable, used
    *      when restarting the game
    *
    * Params:
    *     int  - The score to be set
    *
    * Returns:
    *     None
    */
    void setScore(int i)
    {score = i;}

    /*
    * Public : hideFinalPrompt
    *
    * Description:
    *      Hides the final prompt that
    *      shows the final score.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void hideFinalPrompt()
    {finalPrompt.setFillColor(sf::Color::White);}
};