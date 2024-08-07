#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;

class Solution {
private:
    vector<string> ans;
    stack<char> save;
    string s;
    
    void backtrack(int n, int current, int open, int close) {
        if (current == 2 * n) {
            if (save.empty()) {
                ans.push_back(s);
            }
            return;
        }
        
        if (open < n) {
            s[current] = '(';
            save.push('(');
            backtrack(n, current + 1, open + 1, close);
            save.pop();
        }
        
        if (close < open) {
            s[current] = ')';
            if (!save.empty() && save.top() == '(') {
                save.pop();
                backtrack(n, current + 1, open, close + 1);
                save.push('(');  // 恢复栈的状态
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        s = string(2 * n, ' ');
        backtrack(n, 0, 0, 0);
        return ans;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    int n = 3;

    Solution sol;
    auto result = sol.generateParenthesis(n);
    for(auto it:result){
        cout<<it<<endl;
    }
}