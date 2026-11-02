#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in.is_open()) {
        std::cerr << "Cannot open input.txt" << std::endl;
        return 1;
    }
    const std::string zapr = "useragmnt";
    std::set<char> forbidden(zapr.begin(), zapr.end());

    std::string text((std::istreambuf_iterator<char>(in)),
        std::istreambuf_iterator<char>());

    for (char c : text) {
        char lower = std::tolower(static_cast<unsigned char>(c));
        if (forbidden.find(lower) == forbidden.end()) {
            out << c;
        }
    }
    in.close();
    out.close();
    return 0;
}