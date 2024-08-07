#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        if(first == len){
            res.emplace_back(output);
            return;
        }
        for(int i = first;i<len;i++){
            swap(output[i], output[first]);
            backtrack(res,output,first+1,len);
            //取消修改
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res,nums,0,nums.size());
        return res;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<int> nums = {1,2,3};

    Solution sol;

    auto result = sol.permute(nums);

    for(auto it:result){
        for(auto is:it){
            cout<<is<<" ";
        }
        cout<<endl;
    }

}