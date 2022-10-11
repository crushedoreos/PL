#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left,*right;
    
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;

    }
};

vector<vector<int>> levelOrder(TreeNode* root){
    
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            
            //popping the node, if there is left/right node->insert to the stack
            q.pop();
            if(node->left!=NULL){ q.push(node->left); }
            if(node->right!=NULL){ q.push(node->right); }
            
            //store node to the DS
            level.push_back(node->val);
        }
        
        ans.push_back(level);
    }
    
    return ans;
}