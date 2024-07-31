#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> row(m), col(n);
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (!matrix[i][j]) {
//                     row[i] = col[j] = true;
//                 }
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (row[i] || col[j]) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i] = col[j] = true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]||col[j]){
                    matrix[i][j] = 0;
            }
            }
        }

    }
};

int main(void){
    cout<<"hello world! "<<endl;
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    Solution solution;
    solution.setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}