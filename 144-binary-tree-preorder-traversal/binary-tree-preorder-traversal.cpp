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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode * curr =root;
        while(curr!=NULL){
            if(curr->left==NULL){ // left sub tree end reached
                preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode * rightMost = curr->left;
                while(rightMost->right && rightMost->right!=curr){
                    rightMost = rightMost->right;
                }
                //rightMost  of left sub tree
                if(rightMost->right==NULL){//left tree not evaluated yet create link and go left
                    preorder.push_back(curr->val);
                    rightMost->right = curr;
                    curr = curr->left;
                }else{ // left subtree evaluated and is pointing to curr . Push curr as inorder and go for right 
                    rightMost->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};