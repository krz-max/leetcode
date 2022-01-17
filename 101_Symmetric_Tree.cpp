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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> BFSL, BFSR;
        BFSL.push(root->left);
        BFSR.push(root->right);
        while(!BFSL.empty() && !BFSR.empty()){
            TreeNode* NowL = BFSL.front(),* NowR = BFSR.front();
            if( (!NowL && NowR) || (NowL && !NowR) ) return false;
            if(NowL && NowR){
                if(NowL->val != NowR->val) return false;
                BFSR.push(NowR->right), BFSR.push(NowR->left);
                BFSL.push(NowL->left), BFSL.push(NowL->right);
                BFSR.pop(), BFSL.pop();
            }
        }
        if(!BFSR.empty() || !BFSL.empty()) return false;
        return true;
    }
};
