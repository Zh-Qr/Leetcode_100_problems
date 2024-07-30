#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int len = nums.size();
//         int sum = 0;
//         int count = 0;
//         for(int i = 0;i<len;i++){
//             for (int j = i; j < len; j++)
//             {
//                 /* code */
//                 for(int k=i;k<=j;k++){
//                     sum = sum +nums[k];
//                 }
//                 if (sum == k)
//                 {
//                     count++;
//                     sum = 0;
//                 }
//                 sum = 0;
//             }
            
//         }
//     return count;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         for (int start = 0; start < nums.size(); ++start) {
//             int sum = 0;
//             for (int end = start; end >= 0; --end) {
//                 sum += nums[end];
//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         mp[0] = 1;
//         int count = 0, pre = 0;
//         for (auto& x:nums) {
//             pre += x;
//             if (mp.find(pre - k) != mp.end()) {
//                 count += mp[pre - k];
//             }
//             mp[pre]++;
//         }
//         return count;
//     }
// };

class Solution{
public:
    int subarraySum(vector<int>& nums, int k){
        int count = 0;
        unordered_map<int,int> map;
        map[0] = 1; //方便独立形成子串
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            sum += nums[i];
            if (map.count(sum - k)!=0)
            {
                /* code */
                count += map[sum - k];
            }
            map[sum]++;
            
        }
        return count;
        
    }
};


int main(void){
    cout<<"hello world!"<<endl;
    vector<int> nums = {1,0,0,0,0,0,1};
    int k = 0;

    Solution solution;
    int count = solution.subarraySum(nums,k);
    cout<<"result: "<<count<<endl;

}