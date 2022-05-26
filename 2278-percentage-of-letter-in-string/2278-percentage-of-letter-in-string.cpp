class Solution {
public:
    int percentageLetter(string s, char letter) 
    {
        int p = 0;
        
        for(auto ch:s)
        {
            if(ch==letter)
                p++;
        }
        return (p*100)/s.length();
    }
};