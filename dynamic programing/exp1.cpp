#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>

using namespace std;

// class Solution {
// public:
//     int ans = 0;
//     void climb(int cur, int n){
//         if(cur == n){
//             ans++;
//             return;
//         }

//         if(cur>n){
//             return;
//         }

//         cur++;
//         climb(cur,n);
//         cur++;
//         climb(cur,n);
//     }
//     int climbStairs(int n) {
//         climb(0,n);
//         return ans;
//     }
// };

class Solution{
public:
    int climbStairs(int n){
        int p = 0, q = 0, r = 1;
        for(int i=1;i<=n;i++){
            p = q;
            q = r;
            r = p+q;
        }

        return r;
    }
};

int main(){
    cout<<"hello world!"<<endl;
    int n = 3;

    Solution sol;
    int result = sol.climbStairs(n);

    cout<<"result: "<<result;
}