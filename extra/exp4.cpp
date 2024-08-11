#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>
#include<unordered_set>

using namespace std;

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int i = nums.size() - 2;
//         while (i >= 0 && nums[i] >= nums[i + 1]) {
//             i--;
//         }
//         if (i >= 0) {
//             int j = nums.size() - 1;
//             while (j >= 0 && nums[i] >= nums[j]) {
//                 j--;
//             }
//             swap(nums[i], nums[j]);
//         }
//         reverse(nums.begin() + i + 1, nums.end());
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums){
        int i = nums.size()-2;
        while(i>=0 && nums[i]>nums[i+1]){
            i--;
        }
        if(i>=0){
            int j = nums.size() - 1;
            while(j>=0 && nums[i]>=nums[j]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+1,nums.end());
    }
};


int main(){
    cout<<"hello world!"<<endl;
    vector<int> nums = {1,2,3};

    Solution sol;
    sol.nextPermutation(nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
}