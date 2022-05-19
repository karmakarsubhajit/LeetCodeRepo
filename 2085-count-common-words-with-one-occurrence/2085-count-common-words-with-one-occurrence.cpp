class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        unordered_map<string,int> mp1;
        
        for(auto it:words1)
        {
            mp1[it]++;
        }
        for(auto it:words2)
        {
            if(mp1[it]<2)
                mp1[it]--;
        }
        
        int ans=0;
        
        for(auto it:mp1)
        {
            if(it.second==0)
                ans++;
        }
        return ans;
    }
};