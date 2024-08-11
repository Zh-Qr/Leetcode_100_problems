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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = 0;
                if(i-1>=0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j-1>=0){
                    dp[i][j] += dp[i][j-1];
                }
                if(i==0 && j == 0){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    cout<<"hello world!"<<endl;

    int m = 3, n = 2;

    Solution sol;
    int result = sol.uniquePaths(m,n);
    cout<<"result: "<<result;
}