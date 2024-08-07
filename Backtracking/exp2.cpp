#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

// class Solution {
// public:
//     vector<int> t;
//     vector<vector<int>> ans;

//     void dfs(int cur, vector<int>& nums) {
//         if (cur == nums.size()) {
//             ans.push_back(t);
//             return;
//         }
//         t.push_back(nums[cur]);
//         dfs(cur + 1, nums);
//         t.pop_back(); //回退！
//         dfs(cur + 1, nums);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         dfs(0, nums);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;
    void dfs(int cur, vector<int>& nums){
        if(cur == nums.size()){
            ans.push_back(t);
            return;
        }

        t.push_back(nums[cur]);
        dfs(cur+1,nums);
        t.pop_back();
        dfs(cur+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<int> nums = {1,2,3};

    Solution sol;

    auto result = sol.subsets(nums);

    for(auto it:result){
        for(auto is:it){
            cout<<is<<" ";
        }
        cout<<endl;
    }
}