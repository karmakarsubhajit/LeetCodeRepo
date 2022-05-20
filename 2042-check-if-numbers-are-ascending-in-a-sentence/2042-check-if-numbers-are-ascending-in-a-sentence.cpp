class Solution {
public:
    bool areNumbersAscending(string s) 
    {
        istringstream ss(s);
        string word;
        int prev = -1;
        
        while(ss>>word)
        {
            if(isdigit(word[0]))
            {
                if(prev>=stoi(word))
                {
                    return false;
                    
                }
                prev=stoi(word);
            }
        }
        return true;
    }
};