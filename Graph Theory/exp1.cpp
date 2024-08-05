#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int nr,int nc,int r, int c){
        if(grid[r][c] == '0'){
            return;
        }
        else{
            grid[r][c] = '0';
            if(r-1>=0 && grid[r-1][c]=='1'  ) dfs(grid,nr,nc,r-1,c);
            if(c-1>=0 && grid[r][c-1]=='1'  ) dfs(grid,nr,nc,r,c-1);
            if(r+1<nr && grid[r+1][c]=='1'  ) dfs(grid,nr,nc,r+1,c);
            if(c+1<nc && grid[r][c+1]=='1'  ) dfs(grid,nr,nc,r,c+1);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();

        int ans = 0;
        for(int i=0;i<nr;i++){
            for(int j=0;j<nc;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,nr,nc,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};

    Solution sol;
    int ans = sol.numIslands(grid);
    
    cout<<"result: "<<ans;

}