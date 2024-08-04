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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root){
            return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
        }
        else{
            return 0;
        }
    }
};

int main(void){
    cout<<"hello world! "<<endl;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    Solution solution;

    int result = solution.maxDepth(head);
    cout<<"result: "<<result;
}