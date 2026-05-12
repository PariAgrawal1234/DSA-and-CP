//You are given an integer array nums of 2 * n integers. 
//You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays.
// To partition nums, put each element of nums into one of the two array
//All numbers are positive

#include <bits/stdc++.h>
using namespace std;

bool fn(vector <int> &nums,vector <vector<int>> &dp, int indx, int target){
        if(target == 0) return true;
        if(indx == 0) return (nums[indx] == target);
        if(dp[indx][target] != -1) return dp[indx][target];

        bool pick = false;
        if(nums[indx] <= target)
            pick = fn(nums, dp, indx-1,target - nums[indx]);
        bool notpick = fn(nums, dp, indx-1, target);

        return dp[indx][target] = pick|| notpick;
    }
    int minimumDifference(vector<int>& nums) {
        int sum = 0;
        for(int &num : nums) sum += num;
        int nsum = sum/2;
        vector<vector <int>> dp(nums.size(), vector <int> (nsum+1, -1));
        int sum1 = 0;

        for(int i = nsum; i>= 0; i--){
            if(fn(nums,dp,nums.size()-1,i)) {
                sum1 = i;
                break;
            }
        }
        return abs(sum- 2*sum1);
    }