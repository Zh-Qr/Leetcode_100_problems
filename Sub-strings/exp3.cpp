#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

// class Solution {
// public:
//     unordered_map <char, int> ori, cnt; //保存各个元素出现次数

//     bool check() {
//         for (const auto &p: ori) {
//             if (cnt[p.first] < p.second) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     string minWindow(string s, string t) {
//         for (auto &c: t) {
//             ++ori[c];
//         }

//         int l = 0, r = -1;
//         int len = INT_MAX, ansL = -1;

//         while (r < int(s.size())) {
//             if (ori.find(s[++r]) != ori.end()) {
//                 ++cnt[s[r]];
//             }
//             while (check() && l <= r) {
//                 if (r - l + 1 < len) {
//                     len = r - l + 1;
//                     ansL = l;
//                 }
//                 if (ori.find(s[l]) != ori.end()) {
//                     --cnt[s[l]];
//                 }
//                 ++l;
//             }
//         }

//         return ansL == -1 ? string() : s.substr(ansL, len);
//     }
// };


class Solution {
public:
    unordered_map<char,int> sCount,tCount;
    bool check(){
        for(auto it:tCount){
            if (it.second>sCount[it.first])
            {
                /* code */
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        for(int i=0;i<t.size();i++){
            tCount[t[i]]++;
        }

        int l= 0, r=0;
        int len = INT_MAX, result_l = -1;
        while (r<s.size())
        {
            
            sCount[s[r++]]++;
            while (check())
            {
                if(len>r-l){
                    len = r-l;
                    result_l = l;
                }
                if(l<r){
                    sCount[s[l++]]--;
                }
                else{
                    break;
                }
            }
            
        }
        return result_l == -1 ? string() : s.substr(result_l, len);
        

    }
};



int main(void){
    string s = "ab";
    string t = "b";

    Solution solution;
    string result = solution.minWindow(s,t);
    cout<<result<<endl;

    cout<<"hello world! "<<endl;

}