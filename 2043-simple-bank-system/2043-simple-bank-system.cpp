class Bank {
public:
    vector<long long> baln;
    int n;
    Bank(vector<long long>& balance) 
    {
        n = balance.size();
        baln = balance;
    }
    
    bool transfer(int account1, int account2, long long money) 
    {
        if(account1>n || account2>n || account1<=0 || account2<=0 || baln[account1-1]<money)
            return false;
        baln[account2-1]+=money;
        baln[account1-1]-=money;
        return true;
    }
    
    bool deposit(int account, long long money) 
    {
        if(account>n || account<=0)
            return false;
        baln[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) 
    {
        if(account>n || account<=0 || baln[account-1]<money)
            return false;
        baln[account-1]-=money;
        return true;
    }
};


/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */