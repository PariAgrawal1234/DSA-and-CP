#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int>> output;
        sort(intervals.begin(), intervals.end());
        for(auto interval : intervals){
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(interval[1],output.back()[1]);
            }
        }
        return output;
    }

int main(){
    return 0;
}