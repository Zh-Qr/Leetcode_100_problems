#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        int len = nums.size();
        if(len<=1){
            return true;
        }
        for(int i=0;i<len;i++){
            if(maxLen<i){
                break;
            }
            maxLen = max(maxLen,nums[i]+i);
        }
        if(maxLen+1>=len){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {2,0,0};
    Solution sol;
    if(sol.canJump(nums)){
        cout<<"success";
    }
    else{
        cout<<"error";
    }
}