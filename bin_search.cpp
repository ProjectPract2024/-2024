#include <iostream>
#include <vector>

int bin_search(const std::vector<int>& array, int goal) {
    int left = 0;
    int right = array.size() - 1;
    int score = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array[middle] == goal) {
            score = middle;
            break;
        }
        else if (array[middle] < goal) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return score;
}

int main() {
    std::vector<int> array = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int goal = 13;

    int score = bin_search(array, goal);

    if (score != -1) {
        std::cout << "Target detected at index " << score << std::endl;
    }
    else {
        std::cout << "Target not detected" << std::endl;
    }

    return 0;
}