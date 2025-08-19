
#include <iostream>
//#include <stack>
//#include <queue>
#include "ArrayStack.h"
#include "ArrayQueue.h"
using namespace std;

// Dimensions of the maze
const int N = 6;
int visited[N][N];

// Directions: right, down, left, up
int rowDir[] = {0, 1, 0, -1};
int colDir[] = {1, 0, -1, 0};

void printXY(int x, int y) {
	cout << "<" << x << "," << y << "> ";
}

// Function to check if a position is safe to move
bool isSafe(int maze[N][N], int visited[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

bool solveMaze(int maze[N][N], int x, int y, int destination_x, int destination_y) {
// int visited[N][N] = {0};

    if (x == destination_x && y == destination_y) {
    	visited[x][y] = 1; printXY(x, y);
    	cout << "Recursion: Path found!" << endl;
    	return true;
    }
    if (isSafe(maze, visited, x, y)) {
        visited[x][y] = 1; printXY(x, y);
        if (solveMaze(maze, x+1, y, destination_x, destination_y)) return true;
        if (solveMaze(maze, x, y+1, destination_x, destination_y)) return true;
//        visited[x][y] = 0; // backtrack
    }
    return false;
}

// Depth-First Search (DFS) using a stack
bool solveMazeDFS(int maze[N][N], int startX, int startY, int endX, int endY) {
    ArrayStack<pair<int, int>> st;
//    int visited[N][N] = {0};


    st.push({startX, startY});	printXY(startX, startY);
    visited[startX][startY] = 1;

    while (!st.empty()) {
        auto current = st.top();
//      st.pop();

        int x = current.first;
        int y = current.second;

        if (x == endX && y == endY) {
            cout << "DFS: Path found!" << endl;
            return true;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            int newX = x + rowDir[i];
            int newY = y + colDir[i];

            if (isSafe(maze, visited, newX, newY)) {
                st.push({newX, newY});	printXY(newX, newY);
                visited[newX][newY] = 1;
                moved = true;
                break;
            }
        }

        if (!moved){
        	st.pop();
        }
    }

    cout << "DFS: No path found!" << endl;
    return false;
}

// Breadth-First Search (BFS) using a queue
bool solveMazeBFS(int maze[N][N], int startX, int startY, int endX, int endY) {
    ArrayQueue<pair<int, int>> q;
//    int visited[N][N] = {0};

    q.enqueue({startX, startY});		printXY(startX, startY);
    visited[startX][startY] = 1;

    while (!q.empty()) {
        auto current = q.front();
        q.dequeue();

        int x = current.first;
        int y = current.second;

        if (x == endX && y == endY) {
            cout << "BFS: Path found!" << endl;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + rowDir[i];
            int newY = y + colDir[i];

            if (isSafe(maze, visited, newX, newY)) {
                q.enqueue({newX, newY});	printXY(newX, newY);
                visited[newX][newY] = 1;
            }
        }
    }

    cout << "BFS: No path found!" << endl;
    return false;
}

int main() {
    int maze[N][N] = {
        {1, 1, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0},
		{0, 1, 1, 0, 1, 1}
    };

    int startX = 0, startY = 0; 	// Start position
    int endX = N-1, endY = N-1;     // End position

    // Solve the maze using recursion
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            visited[i][j] = 0; 			// Initialize with 0 (or any desired value)

    solveMaze(maze, startX, startY, endX, endY);

    // Solve the maze using DFS
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            visited[i][j] = 0; 			// Initialize with 0 (or any desired value)
    solveMazeDFS(maze, startX, startY, endX, endY);

    // Solve the maze using BFS
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            visited[i][j] = 0; 			// Initialize with 0 (or any desired value)
    solveMazeBFS(maze, startX, startY, endX, endY);

    return 0;
}


