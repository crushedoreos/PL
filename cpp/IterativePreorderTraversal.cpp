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

vector<int> preorderTraversal(Node *root){

    vector<int> preorder;
    if(root==NULL)
        return preorder;
    
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root= st.top();
        st.pop();
        preorder.push_back(root->data);

        if(root->right!=NULL)
            st.push(root->right);
        if(root->left!=NULL)
            st.push(root->left);


    }

    return preorder;
}


int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    
    vector<int> res = preorderTraversal(root);

    for(auto it: res){
        cout<<it<<"  ";
    }

}

