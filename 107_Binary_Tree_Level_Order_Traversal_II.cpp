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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> Ans;
        if(!root) return Ans;
        queue<TreeNode*> LevelOrder;
        LevelOrder.push(root);
        while(!LevelOrder.empty()){
            int n = LevelOrder.size();
            vector<int> Row(n);
            for(int i = 0; i < n; i++){
                TreeNode* Now = LevelOrder.front();
                LevelOrder.pop();
                if(Now->left) LevelOrder.push(Now->left);
                if(Now->right) LevelOrder.push(Now->right);
                Row[i] = Now->val;
            }
            Ans.push_back(Row);
        }
        for(int i = 0; i < Ans.size()/2; i++){
            vector<int> temp = Ans[i];
            Ans[i] = Ans[Ans.size()-1-i];
            Ans[Ans.size()-i-1] = temp;
        }
        return Ans;
    }
};