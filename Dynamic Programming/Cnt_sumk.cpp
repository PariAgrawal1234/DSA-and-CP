//Count subsets with sum k

#include <bits/stdc++.h>
using namespace std;

int fn(vector <int> & nums, int target, int indx, vector <vector<int>> &dp){
    if(indx == 0){
        if(target == 0 && nums[indx] == 0) return 2;
        if(target == 0 || nums[0] == target) return 1;
        return 0;
    }
    if(dp[indx][target] != -1) return dp[indx][target];

    int pick = 0;
    int notpick = fn(nums,target,indx-1,dp);
    if(nums[indx] <= target) pick = fn(nums,target - nums[indx], indx -1, dp);

    return dp[indx][target] = pick + notpick;
}
int countSubsets(vector<int>& nums, int k){
    vector <vector <int>> dp(nums.size(), vector <int> (k+1, -1));
    return fn(nums, k, nums.size()-1, dp);
}