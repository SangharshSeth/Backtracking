/*
Leercode 47: Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    vector<vector<int>> result;
    vector<int> current_permutations;
    sort(nums.begin(), nums.end());
    backtrack(nums, used, current_permutations, result);
    return result;
  }

  void backtrack(vector<int> &nums, vector<bool> &used,
                 vector<int> &current_permutations,
                 vector<vector<int>> &result) {
    if (current_permutations.size() == nums.size()) {
      // Got a permutation
      result.push_back(current_permutations);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
        continue;
      }
      used[i] = true;
      current_permutations.push_back(nums[i]);

      // Backtrack on current choice
      backtrack(nums, used, current_permutations, result);

      current_permutations.pop_back();
      used[i] = false;
    }
  }
};