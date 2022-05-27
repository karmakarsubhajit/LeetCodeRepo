class Solution 
{
public:
    int countTriplets(vector<int>& arr) 
    {
        int n = arr.size();
        int ans = 0;
        
        unordered_map<int,int> cnt;
        unordered_map<int,int> tot;
        
        int pref = 0;
        for(int i=0;i<=n;i++)
        {
            if(i==0)
                pref=0;
            else
                pref = pref^arr[i-1];
            ans+=cnt[pref]*(i-1)-tot[pref];
            cnt[pref]++;
            tot[pref]+=i;
        }
        
        return ans;
    }
};