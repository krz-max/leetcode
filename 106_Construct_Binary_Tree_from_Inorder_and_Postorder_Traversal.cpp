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
    int count;
    TreeNode* _solve(vector<int>& inorder, vector<int>& postorder, int i, int j, TreeNode* root=NULL){
        if(i >= j || count == 0) return NULL;
        root = new TreeNode(postorder[--count]);
        int R = root->val;
        int x = i;
        while(inorder[x] != R) x++;
        root->right = _solve(inorder, postorder, x+1, j);
        root->left = _solve(inorder, postorder, i, x);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        count = postorder.size();
        return _solve(inorder, postorder, 0, postorder.size());
    }
};