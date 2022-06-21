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
    
    bool getDir(TreeNode* root, int val, string& path)
    {
        if(root==NULL)
            return false;
        if(root->val==val)
        {
            return true;
        }
        if(getDir(root->left,val,path)==true)
        {
            path.push_back('L');
        }
        else if(getDir(root->right,val,path)==true)
        {
            path.push_back('R');
        }
        if(path.empty()==1)
            return false;
        return true;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string startStr="";
        string destStr="";
        getDir(root, startValue, startStr);
        getDir(root, destValue, destStr);
        
        
        int i=0;
        int j=0;
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