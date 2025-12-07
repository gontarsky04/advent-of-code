#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {
    std::fstream file("day7.txt");
    if(!file.is_open()) return 1;
    std::vector<std::string> lines;
    std::string line;
    long splitCount = 0;
    while(getline(file,line)) {
        lines.push_back(line);
    }
    long lineLength = line.length();
    long startPos = lines.front().find('S');
    lines[1][startPos] = '|';
    for(auto i = 2; i < lines.size(); i++) {
        for(int j = 0; j < lineLength; j++) {
            if(lines[i-1][j] == '|') {
                if(lines[i][j] == '^') {
                    lines[i][j-1] = '|';
                    lines[i][j+1] = '|';
                    splitCount++;
                } else {
                    lines[i][j] = '|';
                }
            }
        }
    }
    std::cout << "splitCount = " << splitCount;
    return 0;
}