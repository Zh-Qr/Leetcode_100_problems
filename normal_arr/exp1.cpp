#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int pre = 0, maxAns = nums[0];
//         for (const auto &x: nums) {
//             pre = max(pre + x, x);
//             maxAns = max(maxAns, pre);
//         }
//         return maxAns;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = nums[0];
        for (auto i :nums)
        {
            /* code */
            pre = max(pre+i,i);
            ans = max(pre,ans);
        }
        return ans;
    }
};


int main(void){
    cout<<"hello world! "<<endl;

    vector<int> nums = {1};

    Solution solution;
    int max = solution.maxSubArray(nums);
    cout<<"result: "<<max<<endl;

}