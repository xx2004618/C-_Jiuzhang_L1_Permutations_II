//
//  main.cpp
//  C++_Jiuzhang_L1_Permutations_II
//
//  Created by Xiao Xiang on 16/3/7.
//  Copyright © 2016年 Xiang Xiao. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<bool> visited = vector<bool>(nums.size(), false);
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(result, path, nums, visited);
        return result;
    }
    void helper(vector<vector<int>> &result, vector<int> path, vector<int> nums, vector<bool> &visited){
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            if (i != 0 && visited[i - 1] && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = true;
            helper(result, path, nums, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {3, 0, 3, 3};
    Solution solution;
    vector<vector<int>> result = solution.permuteUnique(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
