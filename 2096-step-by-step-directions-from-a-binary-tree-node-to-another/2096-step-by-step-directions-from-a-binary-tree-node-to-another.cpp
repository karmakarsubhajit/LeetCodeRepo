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
        if(getDir(root->left,val,p)==true)
        {
            p.push_back('L');
        }
        else if(getDir(root->right,val,p)==true)
        {
            p.push_back('R');
        }
        return(p.length()!=0);
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* lca = getLCA(root,startValue,destValue);
        string startStr="";
        string destStr="";
        getDir(root, startValue, startStr);
        getDir(root, destValue, destStr);

        
        while(startStr.length()!=0 && destStr.length()!=0 && startStr.back()==destStr.back())
        {
            startStr.pop_back();
            destStr.pop_back();
        }
        reverse(startStr.begin(),startStr.end());
        reverse(destStr.begin(),destStr.end());
        
        string t(startStr.length(),'U');
        return t+destStr;
    }
};