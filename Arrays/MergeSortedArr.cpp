// With no extra space

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt1 = m-1, pt2 = n-1;
        int k = m + n -1;
        while(pt2 >= 0){
            if(pt1 >= 0 && nums1[pt1] > nums2[pt2]){
                nums1[k] = nums1[pt1];
                k--;
                pt1--;
            }
            else{
                nums1[k] = nums2[pt2];
                k--;
                pt2--;
            }
        }
    }

int main(){
    return 0;
}