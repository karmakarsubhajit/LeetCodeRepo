class Solution {
public:
    
    
    string getSmallestString(int n, int k) 
    {
        string ans(n,'.');
        
        for(int i=n-1;i>=0;i--)
        {
            int temp = min(k-i,26);
            ans[i]=(temp-1)+'a';
            k=k-temp;
        }
        return ans;
    }
};