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
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nr = matrix.size();
        if (nr == 0) return false;
        int nc = matrix[0].size();
        if (nc == 0) return false;

        int r = 0,c = 0;

        int left= 0;
        int right = nr-1;
        while(left<right){
            int middle = (left+right+1)/2;
            if(matrix[middle][0]<=target){
                r = middle;
                left = middle;
            }
            else{
                right = middle-1;
            }
        }

        left = 0;
        right = nc-1;
        while(left<right){
            int middle = (left+right+1)/2;
            if(matrix[r][middle]<=target){
                c = middle;
                left = middle;
            }
            else{
                right = middle-1;
            }
        }
        return matrix[r][c] == target;

    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<vector<int>> matrix = {{1,3,5,7},
                                  {10,11,16,20},
                                  {23,30,34,60}};

    int target = 3;

    Solution sol;
    auto result = sol.searchMatrix(matrix,target);

    if(result){
        cout<<"success";
    }
    else{
        cout<<"error";
    }
}