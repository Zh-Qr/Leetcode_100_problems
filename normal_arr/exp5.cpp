#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         auto last = unique(nums.begin(), nums.end());
    
//         nums.erase(last, nums.end());
//         if(*(nums.end()-1)<=0){
//             return 1;
//         }
//         int flag = 0;
//         int result;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>0){
//                 flag = i;
//                 break;
//             }
//         }
//         for(int i=0;i+flag<nums.size();i++){
//             if(nums[flag+i]!=i+1){
//                 return i+1;
//             }
//             result = i+2;
//         }
//         return result;

//     }
// };

//hash
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};


int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {0,2,2,1,1};

    Solution solution;
    int result = solution.firstMissingPositive(nums);
    cout<<"result: "<<result<<endl;

}