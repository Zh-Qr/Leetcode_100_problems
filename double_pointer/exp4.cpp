#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ans = 0;
//         int left = 0, right = height.size() - 1;
//         int leftMax = 0, rightMax = 0;
//         while (left < right) {
//             leftMax = max(leftMax, height[left]);
//             rightMax = max(rightMax, height[right]);
//             if (height[left] < height[right]) {
//                 ans += leftMax - height[left];
//                 ++left;
//             } else {
//                 ans += rightMax - height[right];
//                 --right;
//             }
//         }
//         return ans;
//     }
// };

class Solution{
public:
    int trap(vector<int>& height){
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        while (left<right)
        {
            /* code */
            if(leftMax<height[left]){
                leftMax = height[left];
            }

            if(rightMax<height[right]){
                rightMax = height[right];
            }

            if (height[left]<height[right])
            {
                /* code */
                ans += leftMax - height[left];
                left ++;
            }
            else{
                ans += rightMax - height[right];
                right--;
            }
            
            
            
        }
        return ans;
        
    }
};


int main(void){
    cout<<"hello world!"<<endl;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution solution;

    int save = solution.trap(nums);
    cout<<save<<endl;
}