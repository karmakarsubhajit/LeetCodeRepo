class Solution {
public:
    int compute(int i)
    {
        int sm = 0;
        while(i!=0)
        {
            sm+=i%10;
            i=i/10;
        }
        return sm%2==0;
    }
    
    int countEven(int num) 
    {
        int ans = 0;
        for(int i=1;i<=num;i++)
        {
            if(compute(i)==1)
                ans++;
        }
        return ans;
    }
};