#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

// class Solution {
// public:
// vector<vector<int>> slide(vector<vector<int>>& matrix,int m, int n){
//     int row = matrix.size()-m;
//     int col = matrix[0].size()-n;

//     vector<vector<int>> result;

//     for(int i=0;i<row;i++){
//         vector<int> r;
//         for(int j=0;j<col;j++){
//             r.push_back(matrix[m+i][n+j]);
//         }
//         result.push_back(r);
//     }

//     return result;

// }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix[0][0]==target){
//             return true;
//         }
//         bool down = false;
//         bool right = false;
//         if(matrix[0].size()>1){
//             if(matrix[0][1]==target) return true;
//         }
//         if(matrix.size()>1){
//             if(matrix[1][0]==target) return true;
//             // if(matrix[1][0]<target) return searchMatrix(slide(matrix,1,0),target);
//             if (matrix[1][0] < target){
//                 vector<vector<int>> newMatrix = slide(matrix, 1, 0);
//                 down = searchMatrix(newMatrix, target);
//             }
//         }

//         if(matrix[0].size()>1){
            
//             if(matrix[0][1]<target){
//                 vector<vector<int>> newMatrix = slide(matrix, 0, 1);
//                 right =  searchMatrix(newMatrix,target);
//             }
//         }

//         bool result = (down||right);
//         return result;
//     }
// };

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==target) return true;
//             }
//         }

//         return false;
//     }
// };

//二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};



int main(void){
    cout<<"hello world! "<<endl;
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    int target = 20;

    Solution solution;
    bool result = solution.searchMatrix(matrix,target);
    if(result){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}