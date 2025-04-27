#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 10;
char maze[N][N];
bool visited[N][N];
int dist[N][N];

int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] != 'R' && !visited[x][y];
}

int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    dist[startX][startY] = 0;
    q.push({startX, startY});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (maze[x][y] == 'B') {
            return dist[x][y]; 
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; 
}

int main() {
    int startX, startY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'L') {
                startX = i;
                startY = j;
            }
        }
    }

    int steps = bfs(startX, startY);

    cout<<steps-1;
}