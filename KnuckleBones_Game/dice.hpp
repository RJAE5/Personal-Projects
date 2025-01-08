/*
 * Dice Class
 *
 * Description:
 *      This class contains methods for rolling dice and primarily
 *      managing the animation of the dice roll
 *      
 *
 * Public Methods:
 *            - Dice()
 *  void      - rollDiceAnimate(sf::RenderWindow& window)
 *  void      - startRollAnimation()
 *  bool      - isRolling()
 *  void      - display(sf::RenderWindow& window)
 *  void      - rollForValue()
 *  int       - getRollValue()
 *  void      - setSpriteTexture(int i)
 *  
 *
 * Private Methods:
 *	void      - update()
 *	void      - loadAnimation()  
 *
 * Usage:
 *
 *       - This class is used to create an instance of a die
 *         used for animation, as well as handle rolling for
 *         a value to be used in the game
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Dice
{
    // Dice Variables
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;

    // Animation variables
    std::vector<sf::Texture> aniTextures;
    sf::Sprite aniSprite;
    sf::Clock clock;
    sf::Time frameDuration;
    int currentFrame;
    int rollValue;


 /*
    * Private : update
    *
    * Description:
    *      conditional function to perform an update of the rolling
    *      animation for the die.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void update() 
    {
        // Check for frame time
        if (clock.getElapsedTime() >= frameDuration) 
        {
            // Reset clock
            clock.restart();

            // Advance to the next frame
            currentFrame = (currentFrame + 1) % aniTextures.size();
            sprite.setTexture(aniTextures[currentFrame]);
        }
    }

    /*
    * Private : loadAnimation
    *
    * Description:
    *      Initialize animation frames and frame timing.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void loadAnimation()  
    {
        // Initialize animation variables
        frameDuration = sf::milliseconds(25);
        currentFrame = 0;

        // Load textures
        for (int i = 1; i <= 24; ++i) 
        {
            sf::Texture texture;
            std::string prefix = (i < 10) ? "00" : "0";
            std::string filename = "frame_" + prefix + std::to_string(i) + ".png";

            if (!texture.loadFromFile("./media/animations/dice_roll/" + filename)) 
                std::cerr << "Error loading " << filename << std::endl;

            // Store in vector for easy playback
            aniTextures.push_back(texture);
        }

        // Set beginning frame
        if (!aniTextures.empty()) 
            sprite.setTexture(aniTextures[currentFrame]);
    
        // Location of bottom middle
        sprite.setPosition(400.f, 700.f);
    }

public:

    /*
    * Public : Dice
    *
    * Description:
    *      Default constructor for dice, used to initialize
    *      dice face textures, sprites, and call loadAnimation().
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    Dice()
    {
        // Load dice frames onto textures
        for(int i = 1; i <= 6; ++i) 
        { 
            // Assume dice frames are named frame1.png to frame6.png
            sf::Texture texture;
            if (!texture.loadFromFile("./media/images/frame" + std::to_string(i) + ".png")) 
                std::cerr << "Error loading frame" << i << ".png" << std::endl;

            textures.push_back(texture);
        }

        sprite.setPosition(400.f, 700.f);

        // Load animation frames
        loadAnimation();
    }
    
    /*
    * Public : rollDiceAnimate
    *
    * Description:
    *      Call update() to progress the animation and
    *      draw the new frame to the window.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void rollDiceAnimate(sf::RenderWindow& window)
    {
        // Update animation and display to window
        update();
        display(window);    
    }

    /*
    * Public : startRollAnimation
    *
    * Description:
    *      Initialize the roll animation before rolling.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void startRollAnimation()
    {
        // Initialize animation preconditions
        clock.restart();
        currentFrame = 0;
        sprite.setTexture(aniTextures[currentFrame]);
    }

    /*
    * Public : isRolling()
    *
    * Description:
    *      Determines if the animation is currently in progress.
    *
    * Params:
    *     None
    *
    * Returns:
    *     Bool - The indicator of whether the die is rolling
    */
    bool isRolling() const
    {return currentFrame < aniTextures.size() - 1;}

    /*
    * Public : display
    *
    * Description:
    *      Draw the current die face.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void display(sf::RenderWindow& window)
    {window.draw(sprite);}

    /*
    * Public : rollForValue
    *
    * Description:
    *      Generate a random number 1-6 inclusive.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void rollForValue()
    {
        // Get actual dice value
        rollValue = (rand() % 6) + 1;
    }

    /*
    * Public : getRollValue
    *
    * Description:
    *      Gets the current value of the dice after
    *      rollForValue() is called.
    *
    * Params:
    *     None
    *
    * Returns:
    *     int - The current rollValue of the die
    */
    int getRollValue()
    {return rollValue;}

    /*
    * Public : setSpriteTexture
    *
    * Description:
    *      Set the die face to the current value
    *      of the rollValue.
    *
    * Params:
    *     int - the current rollValue
    *
    * Returns:
    *     None
    */
    void setSpriteTexture(int i)
    {sprite.setTexture(textures[i]);}
};