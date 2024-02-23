/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector <int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			for (int J = i + 1; J < nums.size(); J++) {
				if (nums.at(i) + nums.at(J) == target) {
					return{ i, J };
				}
			}
		}

	}
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); i++) {
		cin >> nums[i];
	}
	int target;
	cin >> target;
	Solution Solution;
	vector <int> check = Solution.twoSum(nums, target);
	cout << check[0] << " " << check[1];
	return 0;
}
