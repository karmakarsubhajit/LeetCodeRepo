class Solution {
public:
    
    
    string getSmallestString(int n, int k) 
    {
        string ans(n,'a');
        k-=n;
        
        for(int i=n-1;i>=0;i--)
        {
            if(k>0)
            {
                int temp = min(k,25);
                ans[i]+=temp;
                k=k-temp;
            }
            else
                return ans;
        }
        return ans;
    }
};