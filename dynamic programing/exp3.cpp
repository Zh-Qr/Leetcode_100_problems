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
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> money(len,0);
        int maxMoney = 0;

        for(int i = 0;i<len;i++){
            if(i<3){
                if(i<2){
                    money[i] = nums[i];
                    maxMoney = max(maxMoney,money[i]);
                    continue;
                }
                else{
                    money[i] = money[i-2] + nums[i];
                    maxMoney = max(maxMoney,money[i]);
                }
                continue;
            }
        money[i] = max(money[i-2]+nums[i],money[i-3]+nums[i]);
        maxMoney = max(maxMoney,money[i]);
        }

        return maxMoney;
    }
};

int main(){
    cout<<"hello world!"<<endl;
    vector<int> nums = {2,7,9,3,1};

    Solution sol;
    int result = sol.rob(nums);
    cout<<"result: "<<result;
}