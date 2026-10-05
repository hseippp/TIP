#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    char symbol;
    cout << "Введите a, b, c:"<<"\n";
    cin >> a >> b >> c;
    cout << "Введите символ (I / 1 / c): ";
    cin >> symbol;
    if (symbol=='I')
    {
        cout << "Студент: Zemtsovskiy Konstantin" << endl;
    }
    else if (symbol=='1')
    {
        if (a==0 and b==0 and c==0)
            cout << "Корень—любое действительное число" << endl;
        else
        {
            double D = b*b-(4*a*c);
            if (D<0)
                cout << "Корней нет" << endl;
            else if (D==0)
                cout << "x =" << -b/(2*a) << endl;
            else
                cout << "x1 =" <<(-b-sqrt(D))/(2*a) << ", x2 =" << (-b+sqrt(D))/(2*a) << endl;
        }
    }
    else if (symbol=='c')
    {
        int day;
        cout << "Введите номер дня(год не високосный):"<<"\n";
        cin >> day;
        if (day>=152 and day<=243)
            cout << "Попадает в диапазон 1 июня-31 августа" << endl;
        else
            cout << "Не попадает в диапазон 1 июня-31 августа" << endl;
    }
    else
    {
        cout<<"Такого символа нет"<< endl;
    }
    return 0;
}