#include <iostream>
using namespace std;

int main(){
    double k;
    cout<< "Введите коэффициент k:" << "\n" ;
    cin>> k;
    double c;
    cout<< "Введите коэффициент c:" << "\n" ;
    cin>> c;
    //Исходное выражение равно
    //0,7(2с-9к)-4(0,25с-к)
    //Упрощенное выражение равно
    //0.4с-2.3к
    double b = (0.4*c - 2.3*k);
    cout << "Выражение равно:" << b << endl;
    return 0;
}
