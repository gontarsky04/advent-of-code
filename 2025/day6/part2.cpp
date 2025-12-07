#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::fstream file("day6.txt");
    if (!file.is_open()) return 1;
    std::string line;
    std::vector<std::string> lines;
    size_t max_width = 0;
    while (std::getline(file, line)) {
        lines.push_back(line);
        if (line.length() > max_width) max_width = line.length();
    }
    if (lines.empty()) return 0;
    for (auto& l : lines) l.resize(max_width, ' ');
    const size_t last_row = lines.size() - 1;
    long long total = 0;
    int start_col = 0;
    for (int col = 0; col <= static_cast<int>(max_width); ++col) {
        bool is_empty_col = (col == static_cast<int>(max_width));
        if (!is_empty_col) {
            is_empty_col = true;
            for (const auto& r : lines) {
                if (r[col] != ' ') { is_empty_col = false; break; }
            }
        }
        if (is_empty_col) {
            if (col > start_col) {
                char op = ' ';
                for (int c = start_col; c < col; ++c) {
                    char v = lines[last_row][c];
                    if (v == '+' || v == '*') { op = v; break; }
                }
                if (op == '+' || op == '*') {
                    std::vector<long long> numbers;
                    for (int c = col - 1; c >= start_col; --c) {
                        std::string digits;
                        for (size_t r = 0; r < last_row; ++r) {
                            char ch = lines[r][c];
                            if (std::isdigit(static_cast<unsigned char>(ch))) digits.push_back(ch);
                        }
                        if (!digits.empty()) numbers.push_back(std::stoll(digits));
                    }
                    if (!numbers.empty()) {
                        long long result = (op == '+') ? 0 : 1;
                        for (long long n : numbers) {
                            if (op == '+') result += n; else result *= n;
                        }
                        total += result;
                    }
                }
            }
            start_col = col + 1;
        }
    }

    std::cout << "Total: " << total << std::endl;
    return 0;
}