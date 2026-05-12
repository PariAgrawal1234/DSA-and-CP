//Given an integer array nums, return true if you can partition the array into two subsets such that 
//the sum of the elements in both subsets is equal or false otherwise

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool fn(vector<int> & nums, int target, int indx, vector <vector<int>> &dp){
    if(target == 0) return true;
    if(indx == 0) return (nums[indx] == target);
    if(dp[indx][target] != -1) return dp[indx][target];

    bool notpick = fn(nums,target,indx-1,dp);
    bool pick = false;
    if(target >= nums[indx]) pick = fn(nums, target-nums[indx], indx-1, dp);

    return dp[indx][target] = pick|| notpick;
}

bool canPartition(vector<int>& nums){
    int sum = 0;
    for(int& num : nums) sum += num;
    if(sum%2 != 0) return false;
    sum = sum/2;
    vector <vector<int>> dp(nums.size(),vector <int> (sum+1, -1));
    return fn(nums,sum,nums.size()-1, dp);
}
};

int main(){
    return 0;
}