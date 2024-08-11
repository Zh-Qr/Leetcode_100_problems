#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l0 = 0, l1 = 0;
        int pivotal = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                swap(nums[i],nums[l1]);
                l1++;
            }
            else{
                if(nums[i] == 0){
                    swap(nums[i],nums[l0]);
                    if(l0<l1){
                        swap(nums[i],nums[l1]);
                    }
                    l0++;
                    l1++;
                }
            }
        }

        
    }
};


int main(){
    cout<<"hello world!"<<endl;
    vector<int> nums = {2,0,2,1,1,0};

    Solution sol;
    sol.sortColors(nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
}