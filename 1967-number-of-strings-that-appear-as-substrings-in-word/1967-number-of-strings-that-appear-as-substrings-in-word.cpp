class Solution {
public:
    
    bool isSubs(string s, string word)
    {
        if(word.length()<s.length())
            return false;
        for(int i=0;i<=word.length()-s.length();i++)
        {
            if(word.substr(i,s.length())==s)
                return true;
        }
        return false;
    }
    
    
    int numOfStrings(vector<string>& patterns, string word) 
    {
        int n = patterns.size();
        int ans = 0;
        for(auto it:patterns)
        {
            if(isSubs(it,word)==true)
                ans++;
        }
        return ans;
    }
};