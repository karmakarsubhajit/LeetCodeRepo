class Solution {
public:
    bool areNumbersAscending(string s) 
    {
        int l = s.length();
        int ans = 0;
        int i = 0;
        int prev = -1;
        while(i<l)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                i++;
                continue;   
            }
            else if(s[i]==' ')
            {
                i++;
                continue;
            }
            else
            {
                int j = i;
                while(i<l && s[i]>='0' && s[i]<='9')
                {
                    i++;
                }
                int curr = stoi(s.substr(j,i-j));
                if(curr<=prev)
                    return false; 
                prev=curr;
            }
        }
        return true;
    }
};