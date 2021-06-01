//Question link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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
        if(root == NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
            levelOrder(q, q.size());
        return root;
    }
    void levelOrder(queue<Node *> &q, int size){
        for(int i=0; i<size; i++){
            Node *u = q.front();
            q.pop();
            if(i != size-1)
                u->next = q.front();
            else
                u->next = NULL;
            
            if(u->left)
                q.push(u->left);
            if(u->right)
                q.push(u->right);
        }
    }
};
