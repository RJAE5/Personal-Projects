/*
 * Grid Class
 *
 * Description:
 *      This class contains methods for managing the game grid,
 *      detecting grid input, and calculating the user's score
 *      
 *
 * Public Methods:
 *            - Grid()
 *  void      - createGrid()
 *  void      - drawGrid(sf::RenderWindow& window)
 *  void      - drawBounds(sf::RenderWindow& window)
 *  void      - drawGridText(sf::RenderWindow& window)
 *  void      - inputGrid(int val, sf::Vector2i mousePos, bool& colClicked)
 *  void      - calcScore()
 *  int       - getScore()
 *  bool      - isFull()
 *  
 *
 * Private Methods:
 *  void      - initGridTextPos(std::vector<sf::Text>& colVals, int col)
 *  void      - calcColumnScore(std::vector<int>& column)
 *  void      - calcScoreLogic(int val1, int val2, int val3)
 * 
 *
 * Usage:
 *
 *       - This class is used to create an instance of the
 *         grid, display the grid and numbers, and calculate 
 *         the user's score based on grid values.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Grid
{
    int rows;
    int cols;
    float cellSize;     // Width and height of each cell
    float gridStartX;   // Starting X position of the grid
    float gridStartY;   // Starting Y position of the grid
    float cellSpacing;  // Spacing between cells

    float hitColSizeX;  // Width of each column hitbox
    float hitColSizeY;  // Height of each column hitbox
    float hitColStartX; // StartX of first column hitbox
    float hitColStartY; // StartY of first column hitbox

    // Hitboxes
    sf::RectangleShape col1;
    sf::RectangleShape col2;
    sf::RectangleShape col3;

    // Grid structure and value columns
    std::vector<sf::RectangleShape> grid;
    sf::RectangleShape cell;
    std::vector<sf::Text> gridText1;
    std::vector<sf::Text> gridText2;
    std::vector<sf::Text> gridText3;
    sf::Text value;

    // Numerical values of columns for ease of tracking
    std::vector<int> gridNums1;
    std::vector<int> gridNums2;
    std::vector<int> gridNums3;
    int num;

    // Miscellaneous stuff
    int score;
    sf::Font font;

    /*
    * Private : initGridTextPos
    *
    * Description:
    *      Determine offset to display values in the correct
    *      column, and calculate where in the grid to display
    *      values from the value vectors.
    *
    * Params:
    *     std::vector<sf::Text>& - The displayable numbers for the grid
    *     int                    - The column in which the numbers are to be displayed
    *
    * Returns:
    *     None
    */
    void initGridTextPos(std::vector<sf::Text>& colVals, int col)
    {
        int offset;
        switch(col)
        {
            case 1 :  offset = 0; break;  
            case 2 :  offset = 110; break;
            case 3 :  offset = 220; break;
        }

        for (int i = 0; i < colVals.size(); i++)
        {
            // Centering text horizontally within column
            float x = hitColStartX + offset + hitColSizeX / 2 - (colVals[i].getLocalBounds().width / 2);  

            // Calculate vertical position based on index i
            float y = hitColStartY + (2 - i) * (hitColSizeY / 3) + 50;  // Vertical adjustment

            // Apply position
            colVals[i].setPosition(x, y);
        } 
    }

    /*
    * Private : calcColumnScore
    *
    * Description:
    *      Calculates the score of a single column dependent
    *      on how full it is and using calcScoreLogic().
    *
    * Params:
    *     std::vector<int>& - The int values of a particular column
    *
    * Returns:
    *     None
    */
    void calcColumnScore(std::vector<int>& column) 
    {
        // Assign 3 temporary values to each column space if appropriately sized
        int val1 = column.size() >= 1 ? column[0] : 0;
        int val2 = column.size() >= 2 ? column[1] : 0;
        int val3 = column.size() >= 3 ? column[2] : 0;

        // Call logic function with vals
        calcScoreLogic(val1, val2, val3);
    }


    /*
    * Private : calcScoreLogic
    *
    * Description:
    *      Applies the score multiplier rules of 
    *      Knucklebones depending on matching
    *      column values and adds it to global score
    *
    * Params:
    *     int - First value of the column
    *     int - Middle value of the column
    *     int - Last value of the column
    *
    * Returns:
    *     None
    */
    void calcScoreLogic(int val1, int val2, int val3)
    {
        int addScore = 0;

        // Check if all values are the same
        if(val2 == 0 && val3 == 0)
        {addScore = val1;}
        // Check for two matching values
        else if(val1 == val2 && val2 == val3 && val1 > 0)
        {
            // Triple the value if all three match
            addScore = (val1 * 3) * 3;
        }
        else if (val1 == val2 && val1 > 0) 
        {
            // Double the value if the first two match
            addScore = (val1 * 2) * 2 + val3;
        }
        else if (val2 == val3 && val1 > 0) 
        {
            // Double the value if the last two match
            addScore = (val2 * 2) * 2 + val1;  
        }
        else if (val1 == val3 && val1 > 0) 
        {
            // Double the value if the first and last match
            addScore = (val1 * 2) * 2 + val2;  
        }
        else 
        {
            // Otherwise, all 3 are a mismatch so add them with no bonus
            addScore = val1 + val2 + val3;
        }

        // Add the score for this calculation to the total score
        score += addScore;
    }

public:
 /*
  * Public : Grid
  *
  * Description:
  *      Create and initialize and instance of the grid,
  *      init display columns, init hitboxes, load font,
  *      and init properties of displayed grid numbers.
  *
  * Params:
  *     None
  *
  * Returns:
  *     None
  */
    Grid()
    {
        // General grid dimensions
        rows = 3;
        cols = 3;
        cellSize = 100.f;
        gridStartX = 325.f;
        gridStartY = 100.f;
        cellSpacing = 10.f;

        // General hitbox dimensions
        hitColSizeX = 100.f;
        hitColSizeY = 320.f;
        hitColStartX = 325.f;
        hitColStartY = 100.f;

        // Initalize column hitboxes based on needed position
        col1.setSize(sf::Vector2f(hitColSizeX, hitColSizeY));
        col1.setPosition(hitColStartX, hitColStartY);
        col1.setFillColor(sf::Color::Blue);

        col2.setSize(sf::Vector2f(hitColSizeX, hitColSizeY));
        col2.setPosition(hitColStartX + 110, hitColStartY);
        col2.setFillColor(sf::Color::Red);

        col3.setSize(sf::Vector2f(hitColSizeX, hitColSizeY));
        col3.setPosition(hitColStartX + 220, hitColStartY);
        col3.setFillColor(sf::Color::Green);

        // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        // Initialize sf::Text properties for displayed value
        value.setFont(font);
        value.setFillColor(sf::Color::Red);
        value.setCharacterSize(24);
        score = 0;
    }
    
    /*
    * Public : createGrid()
    *
    * Description:
    *      Create 9 grid cells and push them to a vector
    *      containing the cells to be displayed.
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void createGrid()
    {
        // Initializing and creating the general grid
        // Create the grid cells
        for (int row = 0; row < rows; ++row) 
        {
            for (int col = 0; col < cols; ++col) 
            {
                // Initialize cell properties
                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setFillColor(sf::Color::White);
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(6.f);

                // Calculate cell position
                float x = gridStartX + col * (cellSize + cellSpacing);
                float y = gridStartY + row * (cellSize + cellSpacing);
                cell.setPosition(x, y);

                // Add the cell to the grid
                grid.push_back(cell);
            }
        }
    }

    /*
    * Public : drawGrid
    *
    * Description:
    *      Simple loop to draw every cell of the grid.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void drawGrid(sf::RenderWindow& window)
    {
        // Draw all grid cell
        for (const auto& cell : grid) 
        {window.draw(cell);}
    }
    
    /*
    * Public : drawBounds
    *
    * Description:
    *      A debugging method to verify the position
    *      of the hitboxes.
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void drawBounds(sf::RenderWindow& window)
    {
        // Shows bright colors of the hitboxes for debugging
        window.draw(col1);
        window.draw(col2);
        window.draw(col3);
    }

    /*
    * Public : drawGridText
    *
    * Description:
    *      Display each value for each column
    *
    * Params:
    *     sf::RenderWindow& - The window to display to
    *
    * Returns:
    *     None
    */
    void drawGridText(sf::RenderWindow& window)
    {
        // Draw loop for each value column
        for (const auto& value : gridText1) 
        {window.draw(value);}

        for (const auto& value : gridText2) 
        {window.draw(value);}

        for (const auto& value : gridText3) 
        {window.draw(value);}
    }

    /*
    * Public : inputGrid
    *
    * Description:
    *      Detects which column hitbox is clicked, and
    *      adds both the display and integer value to
    *      separate vectors before displaying and 
    *      setting an exit flag to true.
    *
    * Params:
    *     int          - Value of the dice being input into the grid
    *     sf::Vector2i - Vector containing the mouse position
    *     bool&        - Exit flag to ensure a column was clicked
    *
    * Returns:
    *     None
    */
    void inputGrid(int val, sf::Vector2i mousePos, bool& colClicked)
    {
        // Convert int from dice roll to string for sf::Text object
        value.setString(std::to_string(val));

        // Detect hitbox 1
        if (col1.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) 
        {
            // Verify column is not full
            if(gridNums1.size() < 3)
            {
                // Store both sf::Text and int values
                gridText1.push_back(value);
                gridNums1.push_back(val);
            }

            // Place col 1 values location on grid
            initGridTextPos(gridText1, 1);
            colClicked = true;
        } 

        // Detect hitbox 2
        if (col2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            // Verify column is not full
            if(gridNums2.size() < 3)
            {
                // Store both sf::Text and int values
                gridText2.push_back(value);
                gridNums2.push_back(val);
            }

            // Place col 2 values location on grid
            initGridTextPos(gridText2, 2);
            colClicked = true;
        }

        // Detect hitbox 3
        if (col3.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            // Verify column is not full
            if(gridNums3.size() < 3)
            {
                // Store both sf::Text and int values
                gridText3.push_back(value);
                gridNums3.push_back(val);

            }

            // Place col 3 values location on grid
            initGridTextPos(gridText3, 3);
            colClicked = true;
        }
  
    }

    /*
    * Public : calcScore()
    *
    * Description:
    *      Resets score to ensure proper addition of score
    *      before calculating the score of each column
    *      by calling calcColumnScore().
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void calcScore()
    {
        // Reset score to add properly
        score = 0;

        // Process each column independently
        calcColumnScore(gridNums1);
        calcColumnScore(gridNums2);
        calcColumnScore(gridNums3);
    }

    /*
    * Public : getScore
    *
    * Description:
    *      Returns the global score value
    *
    * Params:
    *     None
    *
    * Returns:
    *     int - The current score of the player
    */
    int getScore()
    {return score;}

    /*
    * Public : isFull
    *
    * Description:
    *      Returns a flag indicating whether or
    *      not the entire grid is full
    *
    * Params:
    *     None
    *
    * Returns:
    *     Bool - The flag to be returned
    */
    bool isFull()
    {return (gridNums1.size() == 3 && gridNums2.size() == 3 && gridNums3.size() == 3);}

    /*
    * Public : wipe
    *
    * Description:
    *      Completely clears grid elements
    *      to restart the game
    *
    * Params:
    *     None
    *
    * Returns:
    *     None
    */
    void wipe()
    {
        // Clear the sf::Text vectors
        gridText1.clear();
        gridText2.clear();
        gridText3.clear();

        // Clear the numerical vectors
        gridNums1.clear();
        gridNums2.clear();
        gridNums3.clear();

        // Set score to 0
        score = 0;
    }

};