/* Advent of code 2024, day 2, part 1

Determine if Levels are "Safe" or "Unsafe"
"Safe": Levels arae all increasing or decreasing (not both), and never by more than three or lower than 1
"Unsafe": Not that


Sample Input:
7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9

Sample Output:
Safe
Unsafe
Unsafe
Unsafe
Unsafe
Safe

-> 2 is the answer

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{

    std::ifstream file("day2_input.txt");
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line + " ");
    }

    std::vector<std::vector<int>> levels;
    for (auto line : lines)
    {
        // Split each line at the spaces and convert to int before pushing into levels
        std::vector<int> level_curve;
        std::string temp;
        for (auto c : line)
        {
            if (c == ' ' || c == '\n')
            {

                level_curve.push_back(std::stoi(temp));
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        levels.push_back(level_curve);
    }

    int safe_sum = 0;
    for (auto level_curve : levels)
    {
        int prev_level = -10000;
        bool safe = true, increase = true, first = true;
        for (auto level : level_curve)
        {
            // I need to remember the first level. But since its the first i dont have anything to compare it against
            if (prev_level == -10000)
            {
                prev_level = level;
                continue;
            }

            // Getting diff and abs diff is a bit overkill but it works
            int diff = level - prev_level;
            int abs_diff = abs(diff);
            if (abs_diff > 3 || abs_diff == 0)
            {
                safe = false;
                break;
            }

            // If it is the first time we compared we can set the desired direction (increasing or decreasing levels)
            if (first)
            {
                increase = (diff > 0) ? true : false;
                first = false;
                prev_level = level;
            }
            else
            {
                // If the direction is the same as the previous one, we can continue
                if (increase == (diff > 0))
                {
                    prev_level = level;
                    continue;
                } else{
                    safe = false;
                    break;
                }
            }
        }
        safe_sum += safe;
        std::cout << (safe ? "Safe" : "Unsafe") << std::endl;
    }

    std::cout << safe_sum << std::endl;
}