#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;

    }
};



 vector<int> postorderTraversal(Node* root) {
        vector<int> postorder;
        if(root == NULL) 
            return postorder;
            
        stack<Node*> st1;
        Node* curr = root;  

        while(curr != NULL || !st1.empty()) {
            if(curr != NULL){
                st1.push(curr);
                curr = curr->left;
            }
            else{
                Node* temp = st1.top()->right;
                
                if (temp == NULL) {
                    temp = st1.top();
                    st1.pop(); 
                    postorder.push_back(temp->data);
                    while (!st1.empty() && temp == st1.top()->right) {
                        temp = st1.top();
                        st1.pop(); 
                        postorder.push_back(temp->data);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return postorder;
    }



int main()
{
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = postorderTraversal(root);

    for(auto it:res)
        cout<<it<<"  ";
     
    return 0; 

}