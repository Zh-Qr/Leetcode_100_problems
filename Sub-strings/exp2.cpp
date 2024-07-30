#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>

using namespace std;

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<pair<int, int>> q;
//         for (int i = 0; i < k; ++i) {
//             q.emplace(nums[i], i);
//         }
//         vector<int> ans = {q.top().first};
//         for (int i = k; i < n; ++i) {
//             q.emplace(nums[i], i);
//             while (q.top().second <= i - k) { //弹出最大值
//                 q.pop();
//             }
//             ans.push_back(q.top().first);
//         }
//         return ans;
//     }
// };

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < k; i++)
        {
            q.emplace(nums[i],i);
        }
        vector<int> result = {q.top().first};
        for (int i = k; i < nums.size(); i++)
        {
            /* code */
            q.emplace(nums[i],i);
            while (q.top().second<=i-k)
            {
                /* code */
                q.pop();
            }
            result.push_back(q.top().first);
            
        }
        return result;
        
    }
};


int main(void){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k =3;
    cout<<"hello world!"<<endl;

    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums,k);
    for(auto i:result){
        cout<<i<<" ";
    }
}