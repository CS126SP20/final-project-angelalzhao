# Color Gradient Game (new idea)

Author: Angela Zhao

---

## Premise

I want to create a color gradient game that is very similar to [I Love Hue](http://i-love-hue.com/). The premise of the game is very simple. The user must arrange a grid of colored tiles to form a gradient. First, the user will specify the level of difficulty (easy, medium, hard, etc). The difficulty level is determined by the number of tiles the user must rearrange. To start, four colors are chosen at random and placed in the corners of the screen. A gradient is generated from these four colors and every tile except the corner tiles are shuffled. Once the user has placed all the tiles correctly, the games end and a leaderboard is displayed with the top scores at that level, where the score is the number of moves it took to complete the game. I will be using SQLite to create a leaderboard database that stores the player name, score, and level for each game.

I used to play I Love Hue a lot when I was bored. It's a really simple but also calming and engaging, which is why I want to create a similar game. I don't have much previous experience in this area but I can reference the snake assignment for the GUI components. While the concept is simple, I believe it has enough complexity for 2 weeks of work because there are still a lot of components to implement (generating colors for the gradient, swapping tiles, etc).

## Design

The app first displays a menu for choosing the difficulty level. Once the difficulty is selected, the tiles are generated and placed. The user clicks on two tiles that they want to swap, and the tiles switch places. Once the user finishes the game, a leaderboard of the best scores at that level is displayed.

## Tools

* I will use Cinder for the GUI (displaying the tiles, menus, leaderboard)
* I will use [SQLiteModernCpp](https://github.com/SqliteModernCpp/sqlite_modern_cpp.git) + [SQLite3](https://github.com/alex85k/sqlite3-cmake.git) for storing and reading the leaderboard data

## Timeline
### Week 1
By the end of week 1, I will have the SQLite C++ library set up and working.
### Week 2
By the end of week 2 I will have the level menu set up. I will also have the color generating logic done. I will start working on the logic and graphics for swapping tiles.
### Week 3
I will finish working on tile swapping and implement the leaderboard.
### Stretch goals
* Having "color presets" (pastels, cool colors, rainbow, etc) that the user can select instead of the default random colors.
* Having the tile switching be drag and drop instead of just click based.
* Adding background music and sound effects for tile swaps, winning, high scores, etc.
* Displaying the average score along with the player score.
