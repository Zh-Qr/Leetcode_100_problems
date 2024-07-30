#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>


using namespace std;

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         map<int,vector<int>> mp;
//         map<int,int> mp2;

//         vector<vector<int>> result;

//         for(auto it:intervals){
//             mp[it[0]].push_back(it[1]);
//         }
//         for(auto it:mp){
//             mp2[it.first] = *max_element(it.second.begin(),it.second.end());
//         }
//         bool flag =false;
//         while(mp2.size()==1||flag){
//             for(auto it:mp2){
//                 flag = true;
//                 if((it+1)==map.end()){
//                     break;
//                 }
//                 if(it.second<(it+1).first){
//                     continue;
//                 }
//                 else{
//                     flag = false;
//                     if (it.second<(it+1).second)
//                     {
//                         it.second =(it+1).second;
//                         mp2.erase(it+1);
//                     }
//                     else{
//                         mp2.erase(it+1);
//                     }
                    
//                 }
//             }
//         }
//         for(auto it:mp2){
//             result.emplace({it.first,it.second});
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end()); //以开始时间为依据进行排序
        vector<int> current = intervals[0];
        for(auto interval:intervals){
            if(current[1]>=interval[0]){
                current[1] = max(current[1],interval[1]);
            }
            else{
                result.push_back(current);
                current = interval;
            }
        }
        result.push_back(current);
        return result;

    }
};

int main(void){
    cout<<"hello world! "<<endl;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);
    for (auto i : result)
    {
        /* code */
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}