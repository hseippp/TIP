#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readfile(const string& filename) {
    ifstream file(filename);
    string content;
    if (file.is_open()) {
        getline(file, content);
        file.close();
    }
    return content;
}
int main() {
    string X = readfile("input1.txt");
    string Y = readfile("input2.txt");
    if (X.find(Y) != string::npos) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}