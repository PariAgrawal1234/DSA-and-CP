#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> output;
        if(nums.size() < 4) return output;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i= 0; i < nums.size()-3; i++){
            for(int j = i+1; j < nums.size()-2; j++){
                long long newTarget = (long long)target - (long long) nums[i] - (long long) nums[j];
                int low = j+1, high = nums.size()-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int temp1 = low, temp2 = high;
                        while(low < high && nums[low] == nums[temp1]) low++;
                        while(low < high && nums[high] == nums[temp2]) high--;
                    }
                }

                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }