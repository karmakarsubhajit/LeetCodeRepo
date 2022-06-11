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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> mp;
        unordered_map<TreeNode*, int> child;

        for(auto it:descriptions)
        {
            int par = it[0];
            int ch = it[1];
            int l = it[2];
            
            TreeNode* chNode;
            TreeNode* pNode;
            
            if(mp.find(par)==mp.end())
            {
                pNode = new TreeNode(par);
                mp[par]=pNode;
            }
            else
                pNode=mp[par];
            
            if(mp.find(ch)==mp.end())
            {
                chNode = new TreeNode(ch);
                mp[ch]=chNode;
            }
            else
                chNode=mp[ch];
            
            if(l==1)
                pNode->left=chNode;
            else
                pNode->right=chNode;
            
            child[chNode]=1;    
        }
        for(auto it:mp)
        {
            if(child.find(it.second)==child.end())
                return mp[it.first];
        }
        return NULL;
    }
};