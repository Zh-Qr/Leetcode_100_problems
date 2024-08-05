#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

// class Solution {
// private:
//     bool check(vector<int> pre, int currentCourse){
//         for(int i=0;i<pre.size();i++){
//             if(pre[i]==currentCourse){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> course;
//         int len = prerequisites.size();

//         for(int i=0;i<len;i++){
//             int currentCourse = prerequisites[i][0];
//             int preCourse = prerequisites[i][1];
//             if(currentCourse == preCourse) return false;
//             vector<int> pre;
//             if(course.count(preCourse)){
//                 pre = course[preCourse];
        
//             }
//             pre.push_back(preCourse);            
//             course[currentCourse] = pre;
//             bool flag = check(pre,currentCourse);
//             if(!flag){
//                 return false;
//             }
//         }
//     return true;
//     }
// };

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u){
        visited[u] = 1;
        for(int v:edges[u]){
            if(visited[v] == 0){
                dfs(v);
                if(!valid){
                    return;
                }
            }
            else if(visited[v] == 1){
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return valid;
    }
};

int main(void){
    cout<<"hello world!"<<endl;
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1,0},
                                         {0,2},
                                         {2,1}};

    Solution sol;
    bool result = sol.canFinish(numCourses,prerequisites);
    if(result){
        cout<<"success"<<endl;
    }
    else{
        cout<<"error"<<endl;
    }

}