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


    bool isEqual(TreeNode* curr1, TreeNode* curr2)
    {
        if(curr1==NULL && curr2==NULL)
            return true;
        if(curr1!=NULL && curr2==NULL)
            return false;
        if(curr1==NULL && curr2!=NULL)
            return false;
        if(curr1->val!=curr2->val)
            return false;
        return true;
    }

    

class Solution 
{
    public:

    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);
        
        while(q.empty()!=1)
        {
            TreeNode* curr1 = q.front();
            q.pop();
            TreeNode* curr2 = q.front();
            q.pop();
            if(curr1==NULL && curr2==NULL)
                continue;
            
            if(isEqual(curr1,curr2)==false)
                return false;
            
            if(isEqual(curr1->left,curr2->left)==true && isEqual(curr1->right,curr2->right)==true)
            {
                q.push(curr1->left);
                q.push(curr2->left);
                q.push(curr1->right);
                q.push(curr2->right);
                
            }
            else if(isEqual(curr1->left,curr2->right)==true && isEqual(curr1->right,curr2->left)==true)
            {
                q.push(curr1->left);
                q.push(curr2->right);
                q.push(curr1->right);
                q.push(curr2->left);              
            }
            else
                return false;
        }
        return true;
    }
};