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
private:
    vector<vector<int>> res;
    vector<int> t;
public:
    void dfs(vector<int>& candidates, int target,int cur,vector<int> t, int len, int sum){
        if(sum == target){
            res.push_back(t);
            return;
        }
        if(sum>target||cur>=len){
            return;
        }
        for(int i = cur;i<len;i++){
            sum += candidates[i];
            t.push_back(candidates[i]);
            dfs(candidates,target,i,t,len,sum);
            t.pop_back();
            sum -= candidates[i];
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        if(len == 0){
            return res;
        }
        dfs(candidates,target,0,t,len,0);
        return res;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<int> candidates{2,3,6,7};
    int target = 7;

    Solution sol;

    vector<vector<int>> result = sol.combinationSum(candidates,target);

    for(auto it:result){
        for(auto is:it){
            cout<<is<<" ";
        }
        cout<<endl;
    }
}