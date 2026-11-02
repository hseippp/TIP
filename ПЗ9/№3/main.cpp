#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;
string toBinary(string num) {
    string res;
    while (num != "0") {
        string q;
        int rem = 0;
        for (char c : num) {
            int cur = rem * 10 + (c - '0');
            q += char('0' + cur / 2);
            rem = cur % 2;
        }
        res += char('0' + rem);
        size_t p = q.find_first_not_of('0');
        num = (p == string::npos) ? "0" : q.substr(p);
    }
    if (res.empty()) return "0";
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string line;
    getline(in, line);
    string res;
    for (size_t i = 0; i < line.size(); ) {
        if (isdigit((unsigned char)line[i])) {
            string num;
            while (i < line.size() && isdigit((unsigned char)line[i]))
                num += line[i++];
            res += toBinary(num);
        }
        else {
            res += line[i++];
        }
    }
    out << res;
    return 0;
}