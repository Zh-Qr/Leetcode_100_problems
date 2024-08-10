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
    int jump(vector<int>& nums) {
        int maxLen = 0;
        int len = nums.size();
        int step = 0;
        int end = 0;
        for(int i=0;i<len-1;i++){
            // if(maxLen >= len-1){
            //     return step;
            // }
            // else{
            //     step++;
            // }
            // maxLen = max(maxLen,nums[i]+i);
            if(maxLen >= i){
                maxLen = max(maxLen,i+nums[i]);
                if(i==end){
                    end = maxLen;
                    step++;
                }
            }
        }
        return step;
    }
};

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    int result = sol.jump(nums);
    cout<<"result: "<<result;
}