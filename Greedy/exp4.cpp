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
//     vector<int> partitionLabels(string s) {
//         int last[26];
//         int length = s.size();
//         for (int i = 0; i < length; i++) {
//             last[s[i] - 'a'] = i;
//         }
//         vector<int> partition;
//         int start = 0, end = 0;
//         for (int i = 0; i < length; i++) {
//             end = max(end, last[s[i] - 'a']);
//             if (i == end) {
//                 partition.push_back(end - start + 1);
//                 start = end + 1;
//             }
//         }
//         return partition;
//     }
// };

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        int last[26];
        for(int i=0;i<len;i++){
            last[s[i]-'a'] = i;
        }

        vector<int> ans;

        int start = 0, end = 0;
        for(int i = 0;i<len;i++){
            end = max(end,last[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};

int main(){
    cout<<"hello world!"<<endl;

    string s = "ababcbacadefegdehijhklij";

    Solution sol;
    auto result = sol.partitionLabels(s);
    for(auto it:result){
        cout<<it<<" ";
    }
}