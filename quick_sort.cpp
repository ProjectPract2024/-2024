#include <iostream>
#include <vector>

void quickSort(std::vector<int>& array, int left, int right) {
    int l = left, r = right;
    int rotate = array[(left + right) / 2];

    while (l <= r) {
        while (array[l] < rotate)
            l++;
        while (array[r] > rotate)
            r--;
        if (l <= r) {
            std::swap(array[l], array[r]);
            l++;
            r--;
        }
    }

    if (left < r)
        quickSort(array, left, r);
    if (l < right)
        quickSort(array, l, right);
}

int main() {
    std::vector<int> array = { 4, 65, 2, -31, 0, 99, 3, 83, 782, 1 };
    quickSort(array, 0, array.size() - 1);
    for (int i : array) {
        std::cout << i << " ";
    }
    return 0;
}