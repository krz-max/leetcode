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
    int DFS(TreeNode* root, int h=1){
        if(!root) return h-1;
        return max(h, max(DFS(root->left, h+1), DFS(root->right, h+1)));
    }
    int maxDepth(TreeNode* root) {
        return DFS(root);
    }
};