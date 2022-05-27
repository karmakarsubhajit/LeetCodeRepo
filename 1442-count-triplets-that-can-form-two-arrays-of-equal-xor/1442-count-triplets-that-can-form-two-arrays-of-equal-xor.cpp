class Solution 
{
public:
    int countTriplets(vector<int>& arr) 
    {
        int n = arr.size();
        int ans = 0;
        vector<int> pref(n+1,0);
        unordered_map<int,int> cnt;
        unordered_map<int,int> tot;
        
        
        for(int i=1;i<=n;i++)
        {
            pref[i] = pref[i-1]^arr[i-1];
        }
        
        
        for(int i=0;i<=n;i++)
        {
            ans+=cnt[pref[i]]*(i-1)-tot[pref[i]];
            cnt[pref[i]]++;
            tot[pref[i]]+=i;
        }
        
        return ans;
    }
};