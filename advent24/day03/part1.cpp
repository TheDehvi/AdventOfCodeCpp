/* Advent of Code 2024 - Day 03 - Part 1

Extract the mul(A,B) statements from the string and add the operations together

Example Input:
xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))

Example Output:
161 (2*4 + 5*5 + 11*8 + 8*5)

*/

#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <string>

int mul(int A, int B);

int main()
{
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");

    std::ifstream file("day3_input.txt");
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    int sum = 0;
    for (const auto &str : lines)
    {
        std::smatch matches;
        auto begin = str.cbegin();
        auto end = str.cend();

        while (std::regex_search(begin, end, matches, pattern))
        {
            int A = std::stoi(matches[1].str());
            int B = std::stoi(matches[2].str());
            sum += mul(A, B);
            begin = matches.suffix().first;
        }
    }

    std::cout << sum << std::endl;
}

int mul(int A, int B)
{
    return A * B;
}