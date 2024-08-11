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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));

        dp[0][0] = grid[0][0];

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                dp[i][j] = 0;
                if(i-1>=0&&j-1>=0){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
                    continue;
                }
                if(j-1<0 && i-1>=0){
                    dp[i][j] += dp[i-1][j] + grid[i][j];
                    continue;
                }
                if(i-1<0 && j-1>=0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    continue;
                }
                if(i-1<0 && j-1<0){
                    dp[i][j] = grid[i][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(){
    cout<<"hello world!"<<endl;

    // vector<vector<int>> grid{{1,3,1},
    //                          {1,5,1},
    //                          {4,2,1}};
    vector<vector<int>> grid{{1,2,3},
                             {4,5,6}};

    Solution sol;
    int result = sol.minPathSum(grid);
    cout<<"result: "<<result;
}