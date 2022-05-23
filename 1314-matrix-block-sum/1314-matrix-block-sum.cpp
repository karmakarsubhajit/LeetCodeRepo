class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int r=i-k;r<=i+k;r++)
                {
                    for(int c=j-k;c<=j+k;c++)
                    {
                        if(r>=0 && r<m && c>=0 && c<n)
                            answer[i][j]+=mat[r][c];
                    }
                }
            }
        }
        return answer;
    }
};