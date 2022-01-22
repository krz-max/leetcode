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
    TreeNode* _solve(TreeNode* root){
        if(!root) return NULL;
        //Find the Tail node on the left subtree
        TreeNode* leftTail = _solve(root->left);
        TreeNode* rightTail = _solve(root->right);
        /*
        rightTail implies whether the Tail node is
        on the right or left of the root of its left subtree
        */
        if(root->left){
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }//move the left subtree to the right
        if(rightTail){
            return rightTail;
        }
        /*
        if the Tail node is on the right, the calling function will get rightTail
        which is the last node to be visited in the pre-order traversal and hence
        it should connect the root's right child
        */
        else if(leftTail){
            return leftTail;
        }
        else return root;
    }
    void flatten(TreeNode* root) {
        _solve(root);
    }
};