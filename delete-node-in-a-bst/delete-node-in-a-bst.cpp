/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findLastRight(TreeNode* root)
    {
        if(root->right == NULL)
            return root;
        
        return findLastRight(root->right);
    }
    
    TreeNode* deleter(TreeNode* root)
    {
        if(root->left == NULL)
            return root->right;
        else if(root -> right == NULL)
            return root->left;
        
        TreeNode* rightchild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightchild;
        
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return NULL;
        
        if(root->val == key)
            return deleter(root);
        
        TreeNode* dummy = root;
        
        while(root!= NULL)
        {
            if(root->val > key)
            {
                if(root->left != NULL && root->left->val == key)
                {
                    root->left = deleter(root->left);
                    break;
                }
                
                else
                    root = root->left;
            }
            
            else
            {
                if(root -> right != NULL && root -> right -> val == key)
                {
                    root -> right = deleter(root -> right);
                    break;
                }
                
                else
                    root = root -> right;
            }
        }
        
        
        return dummy;
    }
};