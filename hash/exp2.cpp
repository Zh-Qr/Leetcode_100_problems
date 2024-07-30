// 字母异位词分组
#include <iostream>
#include <vector> //数组
#include <map> //实现哈希表
#include <algorithm>
using namespace std;


// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<string, vector<string>> map;
//         // 创建一个 map，它的键是 string 类型，值是 vector<string> 类型。
//         // 用于将排序后的字符串（作为键）与它们的原始形式（作为值）进行关联。
//         for (string str : strs) { // 遍历输入的字符串向量 strs
//             string key = str;
//             sort(key.begin(), key.end()); // 对 key 进行排序，使其字符按字典序排列
//             map[key].push_back(str);
//             // 将排序后的字符串 key 作为键，原始字符串 str 作为值，添加到 map 中
//             // 如果 key 已经存在于 map 中，则将 str 添加到对应的 vector 中
//         }

//         vector<vector<string>> result;// 创建一个结果向量 result，用于存储所有分组后的异位词

//         for (auto it = map.begin(); it != map.end(); ++it) {
//             result.push_back(it->second); //push_back在末尾添加数据
//         }
//         return result;
//     }
// };

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        map<string, vector<string>> map;
        for(string str:strs){
            string key = str;
            sort(key.begin(),key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> result;

        for(auto it = map.begin(); it!=map.end(); ++it){
            result.push_back(it->second);
        }
        return result;

    }
};


int main(){

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for(int i=0;i<strs.size();i++){
        cout<<strs[i]<<endl;
    }

    cout<<"the words are listed above!"<<endl;

    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for(int i=0;i<result.size();i++){
        vector<string> str = result[i];
        for(int j=0;j<str.size();j++){
            cout<<str[j]<<" ";
        }
        cout<<endl;
    }

    string key = "test";
    cout<<"test result: "<<*key.begin()<<endl; //返回第一个字符的地址
    // cout<<"test result: "<<*key.end()<<endl; //返回最后一个字符的后一个地址

    return 0;
}