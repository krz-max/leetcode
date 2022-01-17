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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> Ans;
        bool dir = true;
        queue<TreeNode*> ZigZagTraversal;
        ZigZagTraversal.push(root);
        while(!ZigZagTraversal.empty()){
            int n = ZigZagTraversal.size();
            vector<int> row(n);
            for(int i = 0; i < n; i++){
                TreeNode* Now = ZigZagTraversal.front();
                ZigZagTraversal.pop();
                if(dir){
                    row[i] = Now->val;
                }
                else{
                    row[n-i-1] = Now->val;
                }
                if(Now->left) ZigZagTraversal.push(Now->left);
                if(Now->right) ZigZagTraversal.push(Now->right);
            }
            dir = !dir;
            Ans.push_back(row);
        }
        return Ans;
    }
};
//shift V