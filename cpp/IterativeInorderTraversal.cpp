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


Node *insertBST(Node *root, int val)
{
    if(root==NULL)
        return new Node(val);
    if(val<root->data)
        root->left = insertBST(root->left,val);
    else
        root->right = insertBST(root->right,val);

    return root;            
}


vector<int> inorderTraversal(Node *root){

    vector<int> inorder;
    if(root==NULL)
        return inorder;
    Node *node = root;
    stack<Node*> st;
    while(true){
        if(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()==true)
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;

        }
    }

    return inorder;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = inorderTraversal(root);

    for(auto it:res)
        cout<<it<<"  ";
     
    return 0; 
}