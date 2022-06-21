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
    
    TreeNode* getLCA(TreeNode* root,  int startValue, int destValue)
    {
        if(root==NULL)
            return NULL;
        if(root->val==startValue || root->val==destValue)
            return root;
        TreeNode* lf = getLCA(root->left,startValue,destValue);
        TreeNode* rt = getLCA(root->right,startValue,destValue);
        if(lf!=NULL && rt!=NULL)
            return root;
        if(lf!=NULL)
            return lf;
        else if(rt!=NULL)
            return rt;
        return NULL;
    }
    
    bool getDir(TreeNode* root, int val, string& p)
    {
        if(root==NULL)
            return false;
        if(root->val==val)
            return true;
        
        p.push_back('L');
        if(getDir(root->left,val,p)==true)
            return true;
        p.pop_back();
        
        p.push_back('R');
        if(getDir(root->right,val,p)==true)
            return true;
        p.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* lca = getLCA(root,startValue,destValue);
        string startStr="";
        string destStr="";
        getDir(lca, startValue, startStr);
        getDir(lca, destValue, destStr);

     

        string ans (startStr.length(),'U');
        ans+=destStr;
        return ans;
    }
};