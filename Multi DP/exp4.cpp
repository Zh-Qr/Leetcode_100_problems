#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            char c1 = text1.at(i-1);
            for(int j=1;j<=n;j++){
                char c2 = text2.at(j-1);
                if(c1 == c2){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    cout<<"hello world!"<<endl;

    string text1 = "abcde";
    string text2 = "ace";

    Solution sol;

    int result = sol.longestCommonSubsequence(text1,text2);

    cout<<"result: "<<result;
}