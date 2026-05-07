#include <bits/stdc++.h>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash;
        for(int i = 0; i< nums.size(); i++){
            int j = target-nums[i];
            if(hash.find(j)!= hash.end()) {
            return {i,hash[j]};
            }            
            hash[nums[i]] = i;
        }
        return {-1,-1};
    }