#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Range {
    long long start;
    long long end;
};

int main() {
    std::fstream file("day5.txt"); 
    std::string line;
    std::vector<Range> ranges;
    std::vector<long long> ids;
    int count = 0;
    if (!file.is_open()) return 1;
    while (std::getline(file, line)) {
        if (line.empty() || line == "\r") break;
        size_t hyphenPos = line.find('-');
        if (hyphenPos == std::string::npos) continue;
        long long start = std::stoll(line.substr(0, hyphenPos));
        long long end = std::stoll(line.substr(hyphenPos + 1));
        ranges.push_back({start, end});
    }
    while (std::getline(file, line)) {
        if (line.empty() || line == "\r") continue;
        long long number = std::stoll(line);
        ids.push_back(number);
    }
    for(long long number : ids) {
        for(const auto& range : ranges) {
            if (number >= range.start && number <= range.end) {
                count++;
                break; 
            }
        }
    }

    std::cout << "Count: " << count << std::endl;
    return 0;
}