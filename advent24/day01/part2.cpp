/* Advent of Code 2024 - Day 01 - Part 1

Go through the left list and find each time the number appears in the right list.
If number is found keep the count in mind
Multiply each number with its count and add all of it up

Sample Input:

3   4
4   3
2   5
1   3
3   9
3   3

Sample Output:
31

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


int main(){

    freopen("day1_input.txt", "r", stdin);

    std::vector<int> left;
    std::vector<int> right;

    int a, b;
    while (std::cin >> a >> b) {
        left.push_back(a);
        right.push_back(b);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    std::map<int, int> counter_map;
    for(int i : left){
        for (int j : right){
            if (i == j){
                counter_map[i]++;
            }
            if (i < j){
                break;
            }
        }
    }


    int similarity_sum = 0;
    // Print out counter Map Pairs
    for (auto pair : counter_map){
        std::cout << pair.first << " " << pair.second << std::endl;
        similarity_sum += pair.first * pair.second;
    }

    std::cout << similarity_sum << std::endl;
}