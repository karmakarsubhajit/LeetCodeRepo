class Solution {
public:
    
    int getTime(string p)
    {
        int ans = stoi(p.substr(0,2))*60+stoi(p.substr(3));
        return ans;
    }
    
    
    int convertTime(string current, string correct) 
    {
        int t1 = getTime(current);
        int t2 = getTime(correct);
        int diff = abs(t2-t1);
        int ans = 0;
        vector<int> den{60,15,5,1};
        int i=0;
        while(i!=4)
        {
            ans+=diff/den[i];
            diff%=den[i++];
        }
        return ans;
    }
};