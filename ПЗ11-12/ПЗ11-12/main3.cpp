#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, L;

    // Ввод данных
    cout << "Enter N (number of plants): ";
    cin >> N;
    cout << "Enter K (number of plants in the bouquet): ";
    cin >> K;
    cout << "Enter L (maximum number of identical plants): ";
    cin >> L;

    vector<int> costs(N);
    cout << "Enter plant costs: ";
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }

    // Сортируем стоимости по убыванию для жадного выбора
    sort(costs.begin(), costs.end(), greater<int>());

    // Группируем растения по стоимости
    vector<pair<int, int>> groups; // пара: (стоимость, количество)

    for (int i = 0; i < N; i++) {
        if (groups.empty() || groups.back().first != costs[i]) {
            groups.push_back({ costs[i], 1 });
        }
        else {
            groups.back().second++;
        }
    }

    // Жадный алгоритм: выбираем самые дорогие растения,
    // но не более L штук каждого типа
    long long totalCost = 0;
    int selected = 0;

    for (auto& group : groups) {
        if (selected >= K) break;

        int cost = group.first;
        int count = group.second;

        // Сколько можем взять из этой группы
        int takeFromGroup = min(count, min(L, K - selected));

        totalCost += (long long)cost * takeFromGroup;
        selected += takeFromGroup;
    }

    cout << "Maximum bouquet cost: " << totalCost << endl;

    return 0;
}