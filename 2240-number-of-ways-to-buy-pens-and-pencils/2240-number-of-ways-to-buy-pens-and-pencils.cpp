class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        long long int ans = 0;
        int temp = total/cost2;
        for(int i=0;i<=temp;i++)
        {
            ans+=(total-i*cost2)/cost1+1;
        }
        return ans;
    }
};