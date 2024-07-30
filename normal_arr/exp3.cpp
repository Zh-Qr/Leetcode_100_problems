#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        vector<int> tmp(k,0);
        for(int i =0;i<k;i++){
            tmp[i] = nums[nums.size()-k+i];
        }
        for(int i=nums.size()-1;i>=k;i--){
            nums[i] = nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i] = tmp[i];
        }
    }
};


int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {-1};
    int k = 2;

    Solution solution;
    solution.rotate(nums,k);
    for(auto it:nums){
        cout<<it<<" ";
    }
}