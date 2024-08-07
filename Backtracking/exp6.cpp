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

// class Solution {
// private:
//     vector<vector<int>> di = {
//         {-1, 0}, {1, 0}, {0, -1}, {0, 1}
//     };
//     bool isExist = false;
//     int m, n;
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         m = board.size(), n = board[0].size();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == word[0]) {
//                     backtrack(board, 0, word, i, j);
//                     if (isExist) return true;
//                 }
//             }
//         }
//         return false;
//     }

//     void backtrack(vector<vector<char>>& board, int index, string& word, int i, int j) {
//         if (index + 1 == word.length()) {
//             isExist = true;
//         } else {
//             auto board_val = board[i][j];
//             board[i][j] = '0';
//             for (int d = 0; d < 4; d++) {
//                 int newi = i + di[d][0];
//                 int newj = j + di[d][1];
//                 if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
//                     if (board[newi][newj] == word[index + 1]) {
//                         backtrack(board, index + 1, word, newi, newj);
//                     }
//                 }
//             }
//             board[i][j] = board_val;
//         }
//     }
// };

//遍历过的地方置零！！！回溯后重置！！！

class Solution {
private:
    vector<vector<int>> di = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    bool isExist = false;
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    backtrack(board, 0, word, i, j);
                    if (isExist) return true;
                }
            }
        }
        return false;
    }

    void backtrack(vector<vector<char>>& board, int index, string& word, int i, int j) {
        if (index + 1 == word.length()) {
            isExist = true;
        } else {
            auto board_val = board[i][j];
            board[i][j] = '0';
            for (int d = 0; d < 4; d++) {
                int newi = i + di[d][0];
                int newj = j + di[d][1];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                    if (board[newi][newj] == word[index + 1]) {
                        backtrack(board, index + 1, word, newi, newj);
                    }
                }
            }
            board[i][j] = board_val;
        }
    }
};

int main(void){
    cout<<"hello world!"<<endl;

    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    // vector<vector<char>> board = {{'A'}};

    string word = "ABCB";

    Solution sol;

    auto result = sol.exist(board,word);

    if(result){
        cout<<"success";
    }
    else{
        cout<<"error";
    }

}