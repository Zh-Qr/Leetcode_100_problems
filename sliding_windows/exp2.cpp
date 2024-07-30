#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {       
        vector<int> result;
        int slen = s.size();
        int plen = p.size();

        if (slen<plen)
        {
            /* code */
            return result;
        }
        vector<int> sCount(26,0);
        vector<int> pCount(26,0);
        // 记录p信息
        for (int i = 0; i < plen; i++)
        {
            /* code */
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            result.emplace_back(0);
        }
        
        for (int i = 0; i < slen- plen; i++)
        {
            /* code */
            --sCount[s[i] - 'a'];//回复sCount
            ++sCount[s[i + plen] - 'a'];

            if (sCount == pCount) {
                result.emplace_back(i + 1);
            }
            
        }
        
        
        return result;

    }
};

int main(void){

    string s = "abab";
    string p = "ab";

    Solution solution;
    vector<int> result = solution.findAnagrams(s,p);
    for (auto i : result)
    {
        /* code */
        cout<<i<<" ";
    }
    
    cout<<endl<<"hello world!"<<endl;
}