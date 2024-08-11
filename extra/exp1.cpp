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
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int len = nums.size();

        for(int i=0;i<len;i++){
            auto location = mp.find(nums[i]);
            if(location==mp.end()){
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]] += 1;
            }
        }

        for(auto it:mp){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
    }
};

int main(){
    cout<<"hello world!"<<endl;
    vector<int> nums = {4,1,2,1,2};

    Solution sol;
    int result = sol.singleNumber(nums);
    cout<<"result: "<<result;
}