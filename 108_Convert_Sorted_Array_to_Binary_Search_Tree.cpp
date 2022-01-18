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
    TreeNode* _solve(vector<int>& nums, int Start, int End, TreeNode* root=NULL){
        if(Start >= End) return NULL;
        int Mid = (Start+End)/2;
        root = new TreeNode(nums[Mid]);
        root->left = _solve(nums, Start, Mid);
        root->right = _solve(nums, Mid+1, End);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _solve(nums, 0, nums.size());
    }
};