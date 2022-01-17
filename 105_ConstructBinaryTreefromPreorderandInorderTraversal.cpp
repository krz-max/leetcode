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
    TreeNode* _solve(vector<int>& preorder, vector<int>& inorder, int i, int j, TreeNode* root=NULL){
        if(i >= j) return NULL;
        int R = preorder[count++];
        int x = 0;
        while(inorder[x] != R) x++;
        return new TreeNode(R, _solve(preorder, inorder, i, x), _solve(preorder, inorder, x+1, j));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        count = 0;
        return _solve(preorder, inorder, 0, inorder.size());
    }
};

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    //vector<int> preorder = {1,2};
    //vector<int> inorder = {1,2};
    Solution s;
    TreeNode* Ans = s.buildTree(preorder, inorder);

    queue<TreeNode*> BFS;
    BFS.push(Ans);
    while(!BFS.empty()){
        TreeNode* Now = BFS.front();
        if(Now){
            cout << Now->val << " ";
            BFS.pop();
            BFS.push(Now->left);
            BFS.push(Now->right);
        }
        else{
            cout << "null ";
            BFS.pop();
        }
    }
    return 0;
}