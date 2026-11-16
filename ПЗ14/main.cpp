//Задача 1

//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//int main() {
//    // Переменная для хранения входной строки
//    string s;
//
//    // Считываем всю строку целиком, включая пробелы (до символа перевода строки)
//    getline(cin, s);
//
//    // Создаем стек для хранения символов '('
//    stack<char> st;
//    bool correct = true;
//
//    // Проходим по каждому символу строки
//    for (char c : s) {
//        if (c == '(') {
//            // Если открывающая скобка - добавляем в стек
//            st.push(c);
//        }
//        else if (c == ')') {
//            // Если закрывающая скобка:
//            if (st.empty()) {
//                // Если стек пуст, значит закрывать нечего - ошибка
//                correct = false;
//                break;
//            }
//            else {
//                // Иначе удаляем соответствующую открывающую скобку
//                st.pop();
//            }
//        }
//        // Остальные символы игнорируем
//    }
//
//    // Если после цикла стек не пуст, значит остались незакрытые скобки
//    if (!st.empty()) {
//        correct = false;
//    }
//
//    // Выводим результат согласно условию
//    if (correct) {
//        cout << "yes" << endl;
//    }
//    else {
//        cout << "no" << endl;
//    }
//
//    return 0;
//}


//Задача 2

//#include <iostream>
//#include <string>
//#include <set>
//#include <sstream>
//#include <algorithm>
//#include <cctype>
//
//int main() {
//    std::string line;
//    std::getline(std::cin, line);
//
//    // Приводим весь текст к нижнему регистру
//    std::transform(line.begin(), line.end(), line.begin(),
//        [](unsigned char c) { return std::tolower(c); });
//
//    // Заменяем знаки препинания на пробелы, КРОМЕ дефиса '-'
//    for (char& c : line) {
//        if (std::ispunct(static_cast<unsigned char>(c)) && c != '-') {
//            c = ' ';
//        }
//    }
//
//    // Разбиваем на слова и собираем уникальные в set
//    std::istringstream iss(line);
//    std::set<std::string> unique_words;
//    std::string word;
//    while (iss >> word) {
//        unique_words.insert(word);
//    }
//
//    for (const auto& w : unique_words) {
//        std::cout << w << '\n';
//    }
//
//    return 0;
//}

//Задача 3

//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//class MinStack {
//private:
//    stack<int> mainStack; // Основной стек для хранения значений
//    stack<int> minStack;  // Вспомогательный стек для хранения минимумов
//
//public:
//    // Добавление элемента
//    void push(int val) {
//        mainStack.push(val);
//
//        // Если стек минимумов пуст или новый элемент меньше/равен текущему минимуму,
//        // добавляем его в стек минимумов. Иначе дублируем текущий минимум.
//        if (minStack.empty() || val <= minStack.top()) {
//            minStack.push(val);
//        }
//        else {
//            minStack.push(minStack.top());
//        }
//    }
//
//    // Извлечение элемента
//    void pop() {
//        if (mainStack.empty()) {
//            cout << "Error: stack is empty!" << endl;
//            return;
//        }
//        mainStack.pop();
//        minStack.pop(); // Синхронно удаляем из вспомогательного стека
//    }
//
//    // Проверка на пустоту
//    bool empty() {
//        return mainStack.empty();
//    }
//
//    // Получение минимального элемента за O(1)
//    int getMin() {
//        if (minStack.empty()) {
//            cout << "Error: stack is empty, no minimum." << endl;
//            return -1;
//        }
//        return minStack.top();
//    }
//
//    // Вывод текущего стека: дно слева, вершина справа
//    void printStack() {
//        if (mainStack.empty()) {
//            cout << "[ Empty ]" << endl;
//            return;
//        }
//
//        // Копируем основной стек, чтобы не разрушить оригинал
//        stack<int> temp = mainStack;
//        stack<int> reversed;
//
//        // Перекладываем элементы, чтобы восстановить порядок от дна к вершине
//        while (!temp.empty()) {
//            reversed.push(temp.top());
//            temp.pop();
//        }
//
//        cout << "[ ";
//        while (!reversed.empty()) {
//            cout << reversed.top() << " ";
//            reversed.pop();
//        }
//        cout << "] <- top" << endl;
//    }
//};
//
//int main() {
//    MinStack s;
//    string command;
//    int value;
//
//    cout << "Available commands: push <number>, pop, empty, getMin, print, exit" << endl;
//
//    while (true) {
//        cout << "> ";
//        cin >> command;
//
//        if (command == "push") {
//            cin >> value;
//            s.push(value);
//        }
//        else if (command == "pop") {
//            if (!s.empty()) {
//                s.pop();
//            }
//            else {
//                cout << "Stack is empty, cannot pop." << endl;
//            }
//        }
//        else if (command == "empty") {
//            if (s.empty()) {
//                cout << "Stack is empty (true)" << endl;
//            }
//            else {
//                cout << "Stack is not empty (false)" << endl;
//            }
//        }
//        else if (command == "getMin") {
//            if (!s.empty()) {
//                cout << "Minimum element: " << s.getMin() << endl;
//            }
//            else {
//                cout << "Stack is empty." << endl;
//            }
//        }
//        else if (command == "print") {
//            s.printStack();
//        }
//        else if (command == "exit") {
//            break;
//        }
//        else {
//            cout << "Unknown command." << endl;
//        }
//
//        // Автоматически выводим текущий стек после каждой операции для наглядности
//        if (command == "push" || command == "pop") {
//            s.printStack();
//            if (!s.empty()) cout << "Current minimum: " << s.getMin() << endl;
//        }
//    }
//
//    return 0;
//}