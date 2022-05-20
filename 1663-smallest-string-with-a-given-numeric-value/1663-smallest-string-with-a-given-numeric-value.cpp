class Solution {
public:
    
    
    string getSmallestString(int n, int k) 
    {
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(26*(n-i-1)<k)
            {
                ans+=(k-26*(n-i-1)-1)+'a';
                k=26*(n-i-1);
            }   
            else
            {
                ans+='a';
                k=k-1;
            }
                
        }
        return ans;
    }
};