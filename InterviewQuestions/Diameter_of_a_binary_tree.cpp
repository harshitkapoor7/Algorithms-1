#include <bits/stdc++.h>
using namespace std;



typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;

int ans=0;

int height(TreeNode* root)
{
    if(!root) return 0;
    
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    
    ans= max(ans, 1 + lHeight + rHeight);
    return 1+ max( lHeight , rHeight);

}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    height(root);
    return ans-1;
}

int main(){
    // Creating nodes
    TreeNode* root=new TreeNode();
    root->left=new TreeNode();
    root->right=new TreeNode();
    root->left->left=new TreeNode();
    root->left->right=new TreeNode();
    root->left->left->left=new TreeNode();
    
    cout << diameterOfBinaryTree(root);
}
