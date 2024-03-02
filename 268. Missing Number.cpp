/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.



Another way 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            sum+=i+1;
            curr+=nums[i];
        }
        return sum-curr;
    }
};
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size() - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                answer = i;
                return answer;
            }
        }
        return nums.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution Solution;
    int check = Solution.missingNumber(nums);
    cout << check;
}