#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

//insert
TreeNode* insert(TreeNode* root, int val){
    if(root==NULL){
        TreeNode* node=new TreeNode(val);
        return node;
    }
    
    if(val<root->val)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
    
    return root;
}

//searching in BST
TreeNode* search(TreeNode* root, int key){
    
    while(root!=NULL and root->val!=key){
        if(key<root->val){
            root=root->left;
        }
        else if(key>root->val){
            root=root->right;
        }
    }
    
    return root;
}

//Lowest Common Ancestor of BST
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL)
        return root;
    
    int cur=root->val;
    if(cur<p->val and cur<q->val){
        return lca(root->right,p,q);
    }
    
    if(cur>p->val and cur>q->val){
        return lca(root->left,p,q);
    }
    
    return root;
}

//display
void inorder(TreeNode* root){
    
    if(root==NULL)
        return;
        
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

//array to BST
TreeNode* arrayToBst(vector<int> arr, int start,int end){
    
    if(start>end)
        return NULL;
    
    int mid=(start+end)/2;
    TreeNode* root=new TreeNode(arr[mid]);
    
    root->left=arrayToBst(arr,start,mid-1);
    root->right=arrayToBst(arr,mid+1,end);
    
    return root;
}

int main(){
    
    vector<int> arr={1,2,3,4,5,6};
    int start=0, end=arr.size()-1;
    
    TreeNode* root=arrayToBst(arr,start,end);
    
    inorder(root);
    cout<<endl;
    
    TreeNode* pos=search(root,5);
    if(pos==NULL)
        cout<<-1;
    else
        cout<<pos->val;
    
    return 0;
}
