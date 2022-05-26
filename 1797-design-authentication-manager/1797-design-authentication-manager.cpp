class AuthenticationManager 
{
    public:
    unordered_map<string,int> mp;
    int tm;
    AuthenticationManager(int timeToLive) 
    {
        tm = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) 
    {
        mp[tokenId]=currentTime;
    }
    
    void renew(string tokenId, int currentTime) 
    {
        if(mp.find(tokenId)==mp.end())
            return;
        int c = mp[tokenId];
        if(c+tm<=currentTime)
            mp.erase(tokenId);
        else
            mp[tokenId]=currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) 
    {
        int c=0;
        for(auto it:mp)
        {
            if(it.second+tm>currentTime)
                c++;
        }
        return c;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */