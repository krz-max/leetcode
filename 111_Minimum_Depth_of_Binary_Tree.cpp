#include <iostream>
#include <queue>
using namespace std;

//Definition for a binary tree node.
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
    int _solve(TreeNode* root){
        if(!root) return 99999;
        if(!root->left && !root->right) return 1;
        return min(_solve(root->left), _solve(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return _solve(root);
    }
};