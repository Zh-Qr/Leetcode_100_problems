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
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            auto location = mp.find(nums[i]);
            if(location==mp.end()){
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]]++;
            }
        }

        int limit = nums.size()/2;
        for(auto it:mp){
            if(it.second>limit){
                return it.first;
            }
        }

        return -1;
    }
};

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {2,2,1,1,1,2,2};

    Solution sol;
    int result = sol.majorityElement(nums);

    cout<<"result: "<<result;
}