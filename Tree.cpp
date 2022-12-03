//Binary Tree Pruning
TreeNode *solve(TreeNode *root){
        if(root==NULL)
            return NULL;
            root->left = solve(root->left);
            root->right = solve(root->right);
            if(!root->left && !root->right && root->val==0)
                return NULL;
            return root;
}