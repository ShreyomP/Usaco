#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<pair<int, int>> directions = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

void floodfill(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int n, int &size, int &perim) {
	visited[x][y] = 1;
	for (auto it : directions) {
		int newX = x + it.first;
		int newY = y + it.second;
		if (newX < 0 || newX >= n || newY < 0 || newY >= n) {
			perim++;
			continue;
		}
		if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
			if (grid[newX][newY] == '.') {
				perim++;
			}
			else if (grid[newX][newY] == '#' && visited[newX][newY]==0) {
				size++;
				floodfill(grid, visited, newX, newY, n, size,perim);
			}
		}
	}
}


int main() {
	ifstream in("perimeter.in");
	ofstream out("perimeter.out");
	int n;
	in >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			in >> grid[i][j];
		}
	}
	vector<vector<int>> visited(n, vector<int>(n,0));
	int maxarea = 0;
	int smolperim= 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (visited[x][y]==0 && grid[x][y] == '#') {
				int size = 1;
				int perim = 0;
				floodfill(grid, visited, x, y, n, size, perim);
				if (size > maxarea) {
					maxarea = size;
					smolperim = perim;
				}
				if (size == maxarea && perim<smolperim) {
					smolperim = perim;
				}
			}
		}
	}
	out << maxarea << " " << smolperim;
	return 0;
}
