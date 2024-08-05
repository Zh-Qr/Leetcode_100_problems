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
    int badTime[10][10];
    int cnt = 0;//记录新鲜
    //方向向量
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};


public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> badOranges;

        //全部赋值-1
        memset(badTime, -1, sizeof(badTime));
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<badTime[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    badOranges.emplace(i,j);
                    badTime[i][j] = 0;
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
                
            }
        }

        int ans = 0;
        //BFS
        while(!badOranges.empty()){
            auto [row,col] = badOranges.front();
            badOranges.pop();

            // 通过方向向量开始感染
            for (int i = 0; i < 4; ++i) {
                // 相邻橘子坐标
                int dx = row + dir_x[i];
                int dy = col + dir_y[i];
                // 越界访问，已经访问过，空单元格统统跳过
                if (dx < 0 || dx >= m || dy < 0 || dy >= n
                 || badTime[dx][dy] != -1 || grid[dx][dy] == 0) {
                    continue;
                }
                // 因为不相关的都跳过了，那么剩下的就是相邻橘子了
                badTime[dx][dy] = badTime[row][col] + 1;
                badOranges.emplace(dx, dy);
                if (grid[dx][dy] == 1) {
                    --cnt;
                    ans = badTime[dx][dy];
                    if (cnt == 0) break;
                }
            }
        }
        return cnt==0?ans:-1;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<vector<int>> grid = {{2,1,1},
                                 {1,1,0},
                                 {0,1,1}};
    
    Solution sol;
    cout<<sol.orangesRotting(grid);
    

}