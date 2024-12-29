/* Advent of Code 2024 - Day 01 - Part 1

Sort each list (Left and Right side) in ascending order.
Compute the "distance" between each entry
Add all the disatances together


Sample Input:
3   4
4   3
2   5
1   3
3   9
3   3

Sample Output:
11

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    // Open test.txt file
    freopen("day1_input.txt", "r", stdin);

    std::vector<int> left;
    std::vector<int> right;

    int a, b;
    while (std::cin >> a >> b) {
        // Add the two numbers to the vector
        left.push_back(a);
        right.push_back(b);
    }

    // Sorting the Vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // Test sorting
    for (int i = 0; i < left.size(); i++) {
        std::cout << left[i] << " " << right[i] << std::endl;
    }

    // Compute the distance between each entry
    int distance_sum = 0;
    for (int i = 0; i < left.size(); i++) {
        distance_sum += abs(left[i] - right[i]);
    }

    std::cout << distance_sum << std::endl;
}