#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

bool is_column_empty(const std::vector<std::string>& lines, int col_idx) {
    for (const auto& line : lines) {
        if (col_idx < line.length() && line[col_idx] != ' ') return false;
    }
    return true;
}

long long solve_block(const std::vector<long long>& numbers, char op) {
    if (numbers.empty()) return 0;    
    long long result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (op == '+') {
            result += numbers[i];
        } else if (op == '*') {
            result *= numbers[i];
        }
    }
    return result;
}

int main() {
    std::fstream file("day6.txt");
    if (!file.is_open()) return 1;
    std::string line;
    std::vector<std::string> lines;
    size_t max_width = 0;
    while (std::getline(file, line)) {
        lines.push_back(line);
        if (line.length() > max_width) {
            max_width = line.length();
        }
    }
    if (lines.empty()) return 0;
    for (auto& l : lines) l.resize(max_width, ' ');
    long long total = 0;
    int start_col = 0;
    for (int col = 0; col <= max_width; ++col) {
        if (col == max_width || is_column_empty(lines, col)) {
            if (col > start_col) {
                char op = ' ';
                bool found_op = false;
                std::string bottom_line_segment = lines.back().substr(start_col, col - start_col);                
                for (char c : bottom_line_segment) {
                    if (c == '+' || c == '*') {
                        op = c;
                        found_op = true;
                        break; 
                    }
                }
                if (found_op) {
                    std::vector<long long> numbers;
                    for (size_t row = 0; row < lines.size() - 1; ++row) {
                        std::string segment = lines[row].substr(start_col, col - start_col);
                        std::stringstream ss(segment);
                        long long num;
                        if (ss >> num) numbers.push_back(num);
                    }
                    total += solve_block(numbers, op);
                }
            }
            start_col = col + 1;
        }
    }
    std::cout << "Total: " << total << std::endl;

    return 0;
}