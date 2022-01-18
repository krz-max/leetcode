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
    bool Unbalanced;
    int _solve(TreeNode* root){
        if(!root || Unbalanced) return 0;
        int LD = _solve(root->left);
        int RD = _solve(root->right);
        if(abs(LD-RD) > 1){
            Unbalanced = true;
            return 0;
        }
        return max(LD, RD)+1;
    }
    bool isBalanced(TreeNode* root) {
        Unbalanced = false;
        _solve(root);
        return !Unbalanced;
    }
};