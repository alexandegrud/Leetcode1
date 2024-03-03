/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int now = 0, k = 0, single = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size(); j++) {
                now = nums[i];
                if (now == nums[j]) {
                    k++;
                }
                if (j == nums.size() - 1 && k == 1) {
                    single = now;
                }
                if (j == nums.size()- 1) {
                    k = 0;
                }
            }
        }
        return single; 
    }
};

int main() {
    int n; 
    cin >> n; 
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    Solution Solution; 
    int check = Solution.singleNumber(nums); 
    cout << check;
}