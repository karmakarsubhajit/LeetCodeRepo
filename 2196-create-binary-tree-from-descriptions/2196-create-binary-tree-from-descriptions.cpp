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
class Solution 
{
    public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> mp;
        
        for(auto it:descriptions)
        {
            mp[it[1]]=new TreeNode(it[1]);
        }
        TreeNode* root;
        for(auto it:descriptions)
        {
            TreeNode* par;
            TreeNode* ch;
            if(mp.find(it[0])==mp.end())
            {
                root = new TreeNode(it[0]);
                par = root;
                mp[it[0]] = root;
                ch = mp[it[1]];
            }
            else
            {
                par = mp[it[0]];
                ch = mp[it[1]];
            }
            if(it[2]==1)
            {
                par->left = ch;
            }
            else
                par->right = ch;
        }
        return root;
    }
};