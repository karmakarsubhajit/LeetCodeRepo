class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        int ans = 0;
        int n = cost.size();
        sort(cost.begin(), cost.end());
        
        for(int i=n-1;i>=0;i-=3)
        {
            ans+=cost[i];
            if(i>=1)
                ans+=cost[i-1];
        }
        return ans;
    }
};