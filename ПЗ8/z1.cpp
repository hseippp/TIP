//1 задача 1 способ
#include <iostream>
using namespace std;

long long stepen(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long half = stepen(a, n / 2);
        return half * half;
    }
    return a * stepen(a, n - 1);
}

int main() {
    long long a, n;
    cout << "Введите основание и степень: ";
    cin >> a >> n;
    cout << a << "^" << n << " = " << stepen(a, n) << endl;
    return 0;
}

//1 задача 2 способ

#include <iostream>
using namespace std;

long long stepen(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n & 1) {
            result *= a;
        }
        a *= a;
        n >>= 1;
    }
    return result;
}

int main() {
    long long a, n;
    cout << "Введите основание и степень: ";
    cin >> a >> n;
    cout << a << "^" << n << " = " << fastPow(a, n) << endl;
    return 0;
}