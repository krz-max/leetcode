#include <iostream>
#include <queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> List;
        ListNode* walk = head;
        while(walk){
            List.push_back(walk->val);
            walk = walk->next;
        }
        return _solve(List, 0, List.size());
    }
};