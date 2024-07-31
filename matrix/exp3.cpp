#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size()-1;
        for(int i=0;i<l;i++){
            for(int j=i;j<l-i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[l-j][i];
                matrix[l-j][i] = matrix[l-i][l-j];
                matrix[l-i][l-j] = matrix[j][l-i];
                matrix[j][l-i] = tmp;
            }
            
        }

    }
};



int main(void){
    cout<<"hello world! "<<endl;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    Solution solution;
    solution.rotate(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}