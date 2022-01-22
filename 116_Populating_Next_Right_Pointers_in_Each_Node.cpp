/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> Q1, Q2;
        Q1.push(root);
        while(!(Q1.empty() && Q2.empty())){
            if(Q1.empty()){
                Node* Now;
                while(!Q2.empty()){
                    Now = Q2.front();
                    Q2.pop();
                    if(Q2.empty()) Now->next = NULL;
                    else Now->next = Q2.front();
                    if(Now->left) Q1.push(Now->left);
                    if(Now->right) Q1.push(Now->right);
                }
            }
            else{
                Node* Now;
                while(!Q1.empty()){
                    Now = Q1.front();
                    Q1.pop();
                    if(Q1.empty()) Now->next = NULL;
                    else Now->next = Q1.front();
                    if(Now->left) Q2.push(Now->left);
                    if(Now->right) Q2.push(Now->right);
                }
            }
        }
        return root;
    }
};