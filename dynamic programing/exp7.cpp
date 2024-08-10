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
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> db(len,1);
        int ans = 1;
        for(int i=1;i<len;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    db[i] = max(db[i],db[j]+1);
                    ans = max(ans,db[i]);
                }
            }
        }
        return ans;
    }
};

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {7,7,7,7,7,7,7};
    Solution sol;
    int result = sol.lengthOfLIS(nums);
    cout<<"result: "<<result;
}