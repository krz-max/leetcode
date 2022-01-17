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
    bool inorder(TreeNode* p, TreeNode* q){
        if((p && !q) || (!p && q)) return false;
        if(!p && !q) return true;
        return inorder(p->left, q->left) && inorder(p->right, q->right) && (p->val == q->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return inorder(p, q);
    }
};