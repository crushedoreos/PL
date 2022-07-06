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

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);    
}

Node *searchInBST(Node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    if(root->data > key)
        return searchInBST(root->left,key);
    else   
        return searchInBST(root->right, key);

}
Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while(curr && curr->left!=NULL)
        curr = curr->left;
    return curr;    
}

Node *deleteInBST(Node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(key<root->data)
        root->left = deleteInBST(root->left,key);
    else if(key>root->data)
        root->right = deleteInBST(root->right , key);
    else{
        if(root->left==NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

       else if(root->right == NULL)
       {
           Node *temp = root->left;
           free(root);
           return temp;
       }
       Node *temp = inorderSucc(root->right);
       root->data = temp->data;
       root->right = deleteInBST(root->right, temp->data);

    }            
    return root;
}


int main()
{
    Node *root =NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 7);
    //inorder(root);
    cout<<endl;
    if(searchInBST(root,2))
        cout<<"Element found!"<<endl;
    else
        cout<<"Element not found!"<<endl;    
    return 0;   
}