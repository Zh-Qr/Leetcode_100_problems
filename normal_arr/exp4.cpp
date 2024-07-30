#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

// class Solution {
// public:
// //典型的空间换时间方法
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int length = nums.size();

//         // L 和 R 分别表示左右两侧的乘积列表
//         vector<int> L(length, 0), R(length, 0);

//         vector<int> answer(length);

//         // L[i] 为索引 i 左侧所有元素的乘积
//         // 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
//         L[0] = 1;
//         for (int i = 1; i < length; i++) {
//             L[i] = nums[i - 1] * L[i - 1];
//         }

//         // R[i] 为索引 i 右侧所有元素的乘积
//         // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
//         R[length - 1] = 1;
//         for (int i = length - 2; i >= 0; i--) {
//             R[i] = nums[i + 1] * R[i + 1];
//         }

//         // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
//         for (int i = 0; i < length; i++) {
//             answer[i] = L[i] * R[i];
//         }

//         return answer;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len,1);
        vector<int> right(len,1);
        vector<int> result;
        for(int i=1;i<len;i++){
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=len-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for (int i = 0; i < len; i++)
        {
            result.push_back(left[i]*right[i]);
        }
        return result;
        
    }
};

int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {1,2,3,4};
    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);

    for(auto it:ans){
        cout<<it<<" ";
    }

}