#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int saveMax = 0;
        if (s.size()==0)
        {
            /* code */
            return 0;
        }

        if (s.size()==1)
        {
            /* code */
            return 1;
        }
        
        unordered_set<char> set;
        for (int i = 0; i < s.size(); i++)
        {
            /* code */
            for (int j = i; j < s.size(); j++)
            {
                /* code */
                if (set.count(s[j])>0)
                {
                    /* code */
                    saveMax = max(saveMax,longest);
                    longest = 0;
                    set.clear();
                    break;
                }
                else{
                    set.insert(s[j]);
                    longest++;
                }   
            }
            
        }
        
    return saveMax;
    }
};

int main(void){
    cout<<"hello world"<<endl;
    string s = "abcabcbb";
    for (int i=0;i<s.size();i++)
    {
        /* code */
        cout<<s[i]<<" ";
    }
    cout<<endl;

    Solution solution;
    int longest = solution.lengthOfLongestSubstring(s);
    cout<<"the longest: "<<longest<<endl;
    
}