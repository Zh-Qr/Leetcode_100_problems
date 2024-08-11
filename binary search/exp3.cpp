#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if (nums.empty()) return ans;
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;

        //确定左边界
        while(left<right){
            middle = (left+right)/2;
            
            if(nums[middle]<target){
                left = middle+1;
            }
            else{
                right = middle;
            }
        }

        if(nums[left] != target) return ans;
        ans[0] = left;
        
        right = nums.size() - 1;
        while(left<right){
            middle = (left+right)/2 + 1;
            if(nums[middle]>target){
                right = middle-1;
            }
            else{
                left = middle;
            }
        }
        
        ans[1] = right;

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> ans(2, -1);  // 初始化结果向量，默认值为 [-1, -1]

//         if (nums.empty()) return ans;  // 如果数组为空，直接返回 [-1, -1]

//         int left = 0;
//         int right = nums.size() - 1;
//         int middle = 0;

//         // 二分查找左边界
//         while (left < right) {
//             middle = (left + right) / 2;
//             if (nums[middle] < target) {
//                 left = middle + 1;
//             } else {
//                 right = middle;
//             }
//         }

//         if (nums[left] != target) return ans;  // 如果没找到目标值，返回 [-1, -1]

//         ans[0] = left;  // 找到左边界

//         // 二分查找右边界
//         right = nums.size() - 1;
//         while (left < right) {
//             middle = (left + right) / 2 + 1;  // 注意这里的 +1 来避免死循环
//             if (nums[middle] > target) {
//                 right = middle - 1;
//             } else {
//                 left = middle;
//             }
//         }

//         ans[1] = right;  // 找到右边界

//         return ans;
//     }
// };



int main(){
    cout<<"Hello world!"<<endl;

    int arr[] = {1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int target = 0;

    Solution sol;
    auto result = sol.searchRange(nums,target);

    for(auto it:result){
        cout<<it<<" ";
    }

}