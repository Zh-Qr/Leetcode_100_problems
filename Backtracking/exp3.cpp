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
    unordered_map<int,string> mp;
     void initial() {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
    }
public:
    string s;
    vector<string> res;
    void dfs(vector<int>& nums,int cur,int len){
        if(cur==len){
            res.push_back(s);
            return;
        }
        string currentString = mp[nums[cur]];
        int currentSize = (int)currentString.size();

        for(int i=0;i<currentSize;i++){
            s[cur] = currentString[i];
            dfs(nums,cur+1,len);
        }

    }
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if(len==0){
            return res;
        }
        initial();
        vector<int> nums;
        for(int i=0;i<(int)digits.size();i++){
            nums.push_back(digits[i]-'0');
        }
        
        s.resize(len,'/0');
        dfs(nums,0,len);
        return res;
    }
};

int main(void){
    cout<<"hello world!"<<endl;

    string s ="23";
    Solution sol;
    vector<string> result = sol.letterCombinations(s);
    for(auto s:result){
        cout<<s<<endl;
    }
}