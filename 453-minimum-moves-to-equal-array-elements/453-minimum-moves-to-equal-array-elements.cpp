class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int n = nums.size();
        long long int ans = 0;
        int mn = nums[0];
        for(auto it:nums)
        {
            ans+=it;
            mn=min(mn, it);
        }
        ans-=n*mn;
        
        return ans;
    }
};