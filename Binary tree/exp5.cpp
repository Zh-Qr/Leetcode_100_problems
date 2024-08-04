#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// private:
//     int ans;
//     int depth(TreeNode* rt){
//         if (rt == NULL) {
//             return 0; // 访问到空节点了，返回0
//         }
//         int L = depth(rt->left); // 左儿子为根的子树的深度
//         int R = depth(rt->right); // 右儿子为根的子树的深度
//         ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
//         return max(L, R) + 1; // 返回该节点为根的子树的深度
//     }
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         ans = 1;
//         depth(root);
//         return ans - 1;
//     }
// };

class Solution {
private:
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
};

int main(void){
    cout<<"hello world! "<<endl;
}