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
//     int getSum(vector<int>& nums){
//         int sum = 0;
//         for(auto it:nums){
//             sum += it;
//         }
//         return sum;
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum = getSum(nums);
//         int len = nums.size();

//     }
// };

class Solution {
public:
    int getSum(vector<int>& nums){
        int sum = 0;
        for(auto it:nums){
            sum += it;
        }
        return sum;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = getSum(nums);
        int maxNum = *max_element(nums.begin(), nums.end());

        //总和为奇数
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;

        //最大值大于半数
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {1,2,3,5};

    Solution sol;
    auto result = sol.canPartition(nums);
    if(result){
        cout<<"success";
    }
    else{
        cout<<"error";
    }
}