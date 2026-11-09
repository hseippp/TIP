#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // Проверка: можно ли разбить на <= D групп, чтобы разность в каждой <= X
    auto can = [&](int X) -> bool {
        int groups = 1;
        int start = 0;
        for (int i = 1; i < N; i++) {
            if (a[i] - a[start] > X) {
                groups++;
                start = i;
                if (groups > D) return false;
            }
        }
        return groups <= D;
        };

    // Бинарный поиск по ответу
    int lo = 0, hi = a[N - 1] - a[0], ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (can(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}