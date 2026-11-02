#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in.is_open()) {
        std::cerr << "Cannot open input.txt" << std::endl;
        return 1;
    }
    const std::string forbidden = "useragmnt";
    char c;
    while (in.get(c)) {
        char lower = std::tolower(static_cast<unsigned char>(c));
        if (forbidden.find(lower) == std::string::npos) {
            out.put(c);
        }
    }
    in.close();
    out.close();
    return 0;
}