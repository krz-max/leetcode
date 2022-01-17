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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> Ans;
        queue<TreeNode*> LevelOrder;
        LevelOrder.push(root);
        while(!LevelOrder.empty()){
            int n = LevelOrder.size();
            vector<int> row(n);
            for(int i = 0; i < n; i++){
                TreeNode* Now = LevelOrder.front();
                LevelOrder.pop();
                row[i] = Now->val;
                if(Now->left) LevelOrder.push(Now->left);
                if(Now->right) LevelOrder.push(Now->right);
            }
            Ans.push_back(row);
        }
        return Ans;
    }
};
