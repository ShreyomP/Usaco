// Zombie Survival Grid Game - Console Version (Player vs Zombies with Win Flag and BFS Pathfinding)
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int GRID_SIZE = 10;
const char PLAYER = 'P';
const char ZOMBIE = 'Z';
const char EMPTY = '.';
const char FLAG = 'F';
const char OBSTACLE = '#';

struct Position {
int row, col;
bool operator==(const Position& other) const {
    return row == other.row && col == other.col;
}
};

class ZombieGame {
    private:
    vector<vector<char>> grid;
    Position playerPos;
    vector<Position> zombies;
    Position flagPos;
    bool gameOver;
    bool playerWon;

    vector<Position> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public:
        ZombieGame(int numZombies = 3, int numObstacles = 10) : gameOver(false), playerWon(false) {
        grid = std::vector<std::vector<char>>(GRID_SIZE, std::vector<char>(GRID_SIZE, EMPTY));
        srand(time(0));

        int randomx=rand()%10+1;
        int randomy=rand()%10+1;
        grid[randomy][randomx] = 'P';
        playerPos.row=randomy;
        playerPos.col=randomx;
        
        for (int x=0; x<numObstacles; x++) {
            int randomx=rand()%10+1;
            int randomy=rand()%10+1;
            while (grid[randomy][randomx]!='.') {
                randomx=rand()%10+1;
                randomy=rand()%10+1;
            }
            grid[randomy][randomx]='#';
        }
        
        
        for (int x=0; x<numZombies; x++) {
            int randomx=rand()%10+1;
            int randomy=rand()%10+1;
            while (grid[randomy][randomx]!='.') {
                randomx=rand()%10+1;
                randomy=rand()%10+1;
            }
            grid[randomy][randomx]='Z';
            zombies.push_back({randomy,randomx});
        }
        
        int randomx=rand()%10+1;
        int randomy=rand()%10+1;
        while (grid[randomy][randomx]!='.') {
            randomx=rand()%10+1;
            randomy=rand()%10+1;
        }
        grid[randomy][randomx]='F';
        
    }

    // Pseudo-code:
    // For each row in the grid:
    //   For each cell in the row:
    //     Print the character (player, zombie, flag, obstacle, or empty)
    void displayGrid() {
        for (const auto& row : grid) {
            for (char cell : row)
                cout << cell << ' ';
            cout << '\n';
        }
    }

    // Pseudo-code:
    // 1. Calculate the new position based on input (w/a/s/d)
    // 2. If the new position is valid:
    //    - If it has a zombie, set game over
    //    - If it has the flag, set win
    //    - Otherwise, move the player
    void movePlayer(char direction) {
        int row=playerPos.row;
        int col=playerPos.col;
        if (direction=='w') {
            row++;
        }
        if (direction=='s') {
            row--;
        }
        if (direction=='a') {
            col--;
        }
        if (direction=='d') {
            col++;
        }
        if ((col<0 || col>=10) || (row<0 || row>=10)) {
            cout<<"Invalid move";
            return;
        }
        if (grid[row][col]=='F') {
            playerWon=true;
            gameOver=true;
            return;
        }
        if (grid[row][col]=='Z') {
            playerWon=false;
            gameOver=true;
            return;
        }
        grid[playerPos.row][playerPos.col]='.';
        playerPos.row=row;
        playerPos.col=col;
        return;
    }

    // Pseudo-code:
    // Return true if position is inside grid and not a zombie or obstacle
    bool isValid(int row, int col) {
        
    }

    // Pseudo-code:
    // 1. Initialize a queue with the start position
    // 2. Mark start as visited
    // 3. While queue is not empty:
    //    - Dequeue position
    //    - If it's the target, return the first step on the path
    //    - Add all valid neighboring positions to the queue
    Position bfsNextMove(Position start, Position target) {
        queue<pair<Position, vector<Position>>> q;
        vector<vector<bool>> visited(GRID_SIZE, vector<bool>(GRID_SIZE, false));
        
    }

    // Pseudo-code:
    // For each zombie:
    //   1. Clear its old position
    //   2. Use BFS to find next step toward the player
    //   3. If it reaches the player, game over
    //   4. Update the zombie's position on the grid
    // Pseudo-code:
    // For each zombie:
    //   1. Remove the zombie's symbol from its current position on the grid
    //   2. Use BFS to calculate the shortest path to the player's position
    //   3. If the next step is the player's position, set game over
    //   4. Otherwise, update the zombie's position and place it back on the grid
    void moveZombies() {
        
    }

    // Returns true if game is over (win or caught)
    bool isGameOver() const {
        
    }

    // Returns true if player won by reaching the flag
    bool didPlayerWin() const {
        
    }
};

// Pseudo-code:
// 1. Create a game instance
// 2. Loop while the game is not over:
//    - Show the grid
//    - Get player input and move the player
//    - If game isn't over, move the zombies
// 3. After the loop, print the result (win or lose)
int main() {
    ZombieGame game;
    int zombienum;
    cout<<"How many zombies: ";
    cin>>zombienum;
    int obstaclenum;
    cout<<endl<<"How many obstacles: ";  
    cin>>obstaclenum;
    while (!game.isGameOver()) {
        game.displayGrid();
        cout<<"What direction to move: ";
        char direction;
        cin>>direction;
        game.movePlayer(direction);
        game.moveZombies();
    }
    if (game.didPlayerWin()) {
        cout<<endl<<"You won!";
    }
    else {
        cout<<endl<<"You lost!";
    }

}
