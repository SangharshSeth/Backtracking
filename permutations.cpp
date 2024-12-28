#include <vector>
using namespace std;

/*
LeetCode 46:
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> current_permutations;

        backtrack(nums, used, current_permutations, result);
        return result;
    }

    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &current_permutations, vector<vector<int>> &result)
    {
        if (current_permutations.size() == nums.size())
        {
            // Got a permutation
            result.push_back(current_permutations);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                current_permutations.push_back(nums[i]);

                // Backtrack on current choice
                backtrack(nums, used, current_permutations, result);

                current_permutations.pop_back();
                used[i] = false;
            }
        }
    }
};