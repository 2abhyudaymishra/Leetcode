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
class SubTreeInfo{
    public:
    int maxVal;
    int minVal;
    bool isValid;
    int sum;

    SubTreeInfo(int _maxVal, int _minVal, bool _isValid, int _sum):maxVal(_maxVal), minVal(_minVal), isValid(_isValid), sum(_sum){}
};

class Solution {
    int maxSum = 0;
public: 
    SubTreeInfo maxSumBSTHelper(TreeNode * root){
        if(root==NULL){
            return SubTreeInfo(INT_MIN, INT_MAX, true, 0);
        }

        SubTreeInfo leftData = maxSumBSTHelper(root->left);
        SubTreeInfo rightData= maxSumBSTHelper(root->right);
        
        //valid
        if(leftData.isValid && rightData.isValid && (root->val > leftData.maxVal) && (root->val< rightData.minVal) ){
            int sum = root->val + leftData.sum + rightData.sum;
            maxSum = max(sum, maxSum);
            int maxVal = max({root->val, leftData.maxVal, rightData.maxVal});
            int minVal = min({root->val, rightData.minVal, leftData.minVal});
            return SubTreeInfo(maxVal, minVal, true, sum);
        }else{
            return SubTreeInfo(INT_MAX, INT_MIN, false, 0);
        }
        
    }
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};