#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<string> maze;
pair<int, int> start, exit_pos;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    int current = (maze[x][y] == 'P') ? 1 : 0;

    if (x == exit_pos.first && y == exit_pos.second) {
        visited[x][y] = false;
        return current;
    }

    int best = -1000000;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
            !visited[nx][ny] && maze[nx][ny] != '1') {
            int res = dfs(nx, ny, visited);
            if (res >= 0) best = max(best, current + res);
        }
    }
    visited[x][y] = false;
    return best;
}

int main() {
    cin >> N >> M;
    maze.assign(N, string(M, '0'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];          // пропускает пробелы и \n
            if (maze[i][j] == 'S') start = { i, j };
            else if (maze[i][j] == 'E') exit_pos = { i, j };
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    cout << max(0, dfs(start.first, start.second, visited)) << endl;
    return 0;
}