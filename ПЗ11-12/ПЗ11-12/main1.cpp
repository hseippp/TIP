#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cout << "Enter N and M: ";
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    cout << "Enter grid values:" << endl;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    // dp[i][j] - максимальная сумма баллов при достижении клетки (i, j)
    vector<vector<long long>> dp(N, vector<long long>(M, LLONG_MIN));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 && j == 0) continue;
            long long best = LLONG_MIN;
            if (i > 0 && dp[i - 1][j] != LLONG_MIN)
                best = max(best, dp[i - 1][j]);
            if (j > 0 && dp[i][j - 1] != LLONG_MIN)
                best = max(best, dp[i][j - 1]);
            if (best != LLONG_MIN)
                dp[i][j] = best + grid[i][j];
        }
    }

    cout << "Max sum: " << dp[N - 1][M - 1] << endl;

    // Восстановление пути с конца
    vector<pair<int, int>> path;
    int i = N - 1, j = M - 1;
    path.push_back({ i, j });
    while (i != 0 || j != 0) {
        if (i > 0 && dp[i - 1][j] == dp[i][j] - grid[i][j]) {
            --i;
        }
        else {
            --j;
        }
        path.push_back({ i, j });
    }
    reverse(path.begin(), path.end());

    cout << "Path:" << endl;
    for (auto& p : path)
        cout << p.first << " " << p.second << endl;

    return 0;
}