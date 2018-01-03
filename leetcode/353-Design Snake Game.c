/*
 * Design Snake Game

Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)
 */

class SnakeGame {
private:
    deque<pair<int,int>> snake;
    vector<pair<int,int>> food;
    set<pair<int,int>> hist;
    int idx, w, h;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        snake.push_back(make_pair(0,0));
        this->food = food;
        hist.insert(make_pair(0,0));
        idx = 0;
        w = width, h = height;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string dir) {
        pair<int,int> head = snake.front();
        pair<int,int> tail = snake.back();
        snake.pop_back();
        hist.erase(tail);
        
        if (dir == "U") head.first--;
        else if (dir == "D") head.first++;
        else if (dir == "L") head.second--;
        else if (dir == "R") head.second++;
        if (head.first < 0 || head.first >= h || head.second < 0 || head.second >= w || hist.count(head)) return -1;
        snake.push_front(head);
        hist.insert(head);
        //cout << pos.first << " " << pos.second << " " << food[idx].first << " " << food[idx].second << endl;
        if (idx >= food.size()) {
            return snake.size()-1;
        }
        if (head.first == food[idx].first && head.second == food[idx].second) {
            snake.push_back(tail);
            hist.insert(tail);
            idx++;
        }

        return snake.size()-1;
    }
};
