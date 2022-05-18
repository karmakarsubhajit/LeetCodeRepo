class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
    {
        vector<vector<int>> v(rows*cols, vector<int>(2,0));
        int curr_row = rStart;
        int curr_col = cStart;
        
        int f = 1;
        int len = 0;
        int dir = 0;
        
        v[0][0]=rStart;
        v[0][1]=cStart;
        
        if(rows*cols==1)
            return v;
        
        
        vector<vector<int>> vec{{0,1},{1,0},{0,-1},{-1,0}};
        
        while(f<(rows*cols))
        {
            if(dir==0 || dir==2)
                len++;
            for(int i=0;i<len;i++)
            {
                curr_row+=vec[dir][0];
                curr_col+=vec[dir][1];
                if(curr_row>=0 && curr_row<rows && curr_col>=0 && curr_col<cols)
                {
                    v[f][0]=curr_row;
                    v[f][1]=curr_col;
                    f++;
                }
            }
            dir=(dir+1)%4;   
        }
        return v;
    }
};