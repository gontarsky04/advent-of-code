#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool check_pattern(long long n) {
    std::string s = std::to_string(n);
    int len = s.length();

    if (len % 2 != 0) return false;

    std::string first_half = s.substr(0, len / 2);
    std::string second_half = s.substr(len / 2);

    return first_half == second_half;
}

int main() {
    std::ifstream file("day2.txt");
    if (!file.is_open()) return 1;

    long long sum = 0;
    std::string line;
    
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;

        while (std::getline(ss, segment, ',')) {
            if (segment.empty()) continue;

            size_t dash_pos = segment.find('-');
            if (dash_pos != std::string::npos) {
                long long start = std::stoll(segment.substr(0, dash_pos));
                long long end = std::stoll(segment.substr(dash_pos + 1));

                for (long long i = start; i <= end; ++i) {
                    if (check_pattern(i)) {
                        sum += i;
                    }
                }
            }
        }
    }

    std::cout << "Sum = " << sum << std::endl;

    return 0;
}