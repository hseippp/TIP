//Задача 1
//#include <iostream>
//
//int sumOfDivisors(int n, int current) {
//    if (current >= n) {
//        return 0;
//    }
//    if (n % current == 0) {
//        return current + sumOfDivisors(n, current + 1);
//    }
//    return sumOfDivisors(n, current + 1);
//}
//
//bool isPerfect(int n) {
//    if (n <= 1) {
//        return false;
//    }
//    return sumOfDivisors(n, 1) == n;
//}
//
//int main() {
//    int number;
//    std::cout << "Enter a natural number: ";
//    std::cin >> number;
//
//    if (isPerfect(number)) {
//        std::cout << number << " is a perfect number." << std::endl;
//    }
//    else {
//        std::cout << number << " is not a perfect number." << std::endl;
//    }
//
//    return 0;
//}

//Задача 2
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <map>
//#include <cctype>
//
//int main() {
//    std::ifstream fin("input.txt");
//    std::ofstream fout("output.txt");
//
//    if (!fin.is_open() || !fout.is_open()) {
//        std::cerr << "Ошибка открытия файла\n";
//        return 1;
//    }
//
//    std::map<std::string, int> freq;
//    std::string word;
//
//    while (fin >> word) {
//        auto isLetter = [](unsigned char c) { return std::isalpha(c) || c >= 128; };
//
//        while (!word.empty() && !isLetter(word.front())) word.erase(word.begin());
//        while (!word.empty() && !isLetter(word.back()))  word.pop_back();
//
//        for (char& c : word)
//            if ((unsigned char)c < 128) c = std::tolower((unsigned char)c);
//
//        if (!word.empty())
//            ++freq[word];
//    }
//
//    for (auto& [w, count] : freq)
//        fout << w << ": " << count << "\n";
//
//    std::cout << "Готово! Уникальных слов: " << freq.size() << "\n";
//    return 0;
//}


//Задача 3
//#include <iostream>
//
//int main() {
//    double x, y;
//
//    std::cout << "Введите координаты точки (x y): ";
//    std::cin >> x >> y;
//
//    std::cout << "(" << x << ", " << y << ")" << std::endl;
//
//    return 0;
//}