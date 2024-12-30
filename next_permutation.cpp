//
// Created by Sangharsh Seth on 30/12/24.
//
/*
Leetcode 31: Next Permutation

A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]. The next permutation
of an array of integers is the next lexicographically greater permutation of its
integer. More formally, if all the permutations of the array are sorted in one
container according to their lexicographical order, then the next permutation of
that array is the permutation that follows it in the sorted container. If such
arrangement is not possible, the array must be rearranged as the lowest possible
order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].

While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement. Given an array of integers nums,
find the next permutation of nums.
*/

#include <iostream>
#include <vector>
using namespace std;
/*
Algorithm:
1. Find the position where the number starts decreasing from end
2. Find the smallest larger number from the end from the pivot number
4. Swap them
5. Reverse the elements after the position of pivot number
*/

vector<int> next_permutation(vector<int> &num) {
    int pivot = 0;
    size_t pivot_position = 0;
    bool pivot_found = false;
    int slightly_bigger = INT_MAX;
    size_t slightly_bigger_position = 0;

    for (size_t i = num.size() - 1; i >= 0; i--) {
        if ((i + 1 < num.size()) && num[i] < num[i + 1]) {
            pivot = num[i];
            pivot_position = i;
            pivot_found = true;
            break;
        }
    }
    // if pivot is not found then the next permutation does not exist, reverse the
    // array and return
    if (!pivot_found) {
        reverse(num.begin(), num.end());
        return num;
    }

    for (size_t i = num.size() - 1; i > pivot_position; i--) {
        if (num[i] > pivot && num[i] < slightly_bigger) {
            slightly_bigger = num[i];
            slightly_bigger_position = i;
        }
    }
    // swap the elements in index pivot_index and slighly_bigger_position
    swap(num[pivot_position], num[slightly_bigger_position]);

    reverse(num.begin() + pivot_position + 1, num.end());

    return num;
}

int main() {
    vector<int> num = {1, 2, 3};
    vector<int> result = next_permutation(num);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}