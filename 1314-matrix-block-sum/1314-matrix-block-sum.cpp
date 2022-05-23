class Solution {
public:
    
    int getPrefixSum(int x, int y, vector<vector<int>>& prefixSum)
    {
        int m = prefixSum.size();
        int n = prefixSum[0].size(); 
        if(x<0 || y<0)
            return 0;
        if(x>=m)
            x=m-1;
        if(y>=n)
            y=n-1;
        return prefixSum[x][y];
    }
    
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m,vector<int>(n,0));
        
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                prefixSum[i][j]= mat[i][j]+ getPrefixSum(i-1,j,prefixSum)+getPrefixSum(i,j-1,prefixSum)-getPrefixSum(i-1,j-1,prefixSum);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                answer[i][j]=getPrefixSum(i+k,j+k,prefixSum)+getPrefixSum(i-k-1,j-k-1,prefixSum)-getPrefixSum(i-k-1,j+k,prefixSum)-getPrefixSum(i+k,j-k-1,prefixSum);
            }
        }
        return answer;
        
    }
};