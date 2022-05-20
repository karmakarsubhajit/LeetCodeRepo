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
                int temp =stoi(word); 
                if(prev>=temp)
                {
                    return false;
                    
                }
                prev=temp;
            }
        }
        return true;
    }
};