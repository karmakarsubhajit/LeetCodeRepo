class ATM 
{
    public:
        vector<long long int> amt{0,0,0,0,0};
        vector<int> val{20,50,100,200,500};

    ATM() 
    {
        
    }
    
    void deposit(vector<int> banknotesCount) 
    {
        for(int i=0;i<5;i++)
        {
            amt[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) 
    {
        int i = 4;
        vector<long long int> temp = amt;
        vector<int> ans(5,0);
        while(amount>0 && i>=0)
        {
            if(amt[i]!=0)
            {
                int c= amount/val[i];
                if(amt[i]<c)
                    c=amt[i];
                
                amount-=c*val[i];
                amt[i]-=c;
                ans[i]=c;
            }
            i--;
        }
        if(amount==0)
            return ans;
        amt=temp;
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */