class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        int mn = nums[0];
        for(auto it:nums)
        {
            mn=min(mn, it);
        }
        for(auto it:nums)
        {
            ans+=it-mn;
        }
        return ans;
    }
};