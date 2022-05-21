class Solution {
public:
    int max(int p, int l)
    {
        if(p>l)
            return p;
        return l;
    }
    
    vector<string> printVertically(string s) 
    {
        int l = s.length();
        vector<string> arr;
        string temp="";
        int i = 0;
        int mx = 0;
        
        while(i<=l)
        {
            if(i==l || s[i]==' ')
            {
                arr.push_back(temp);
                mx = max(mx, temp.length());
                temp="";
                i++;
            }
            else
            {
                temp+=s[i];
                i++;
            }
        }
        
        vector<string> ans;
        for(int p=0;p<mx;p++)
        {
            temp = "";
            for(i=0;i<arr.size();i++)
            {
                if(arr[i].length()>p)
                    temp+=(arr[i][p]);
                else
                {
                    temp+=" ";    
                }
            }    
            if(temp[temp.length()-1]==' ')
            {
                int x = temp.length()-1;
                while(x!=-1)
                {
                    if(temp[x]==' ')
                        x--;
                    else
                        break;
                }
                temp=temp.substr(0,x+1);
            }
            
            ans.push_back(temp);
            temp="";
        }
        
        
        
        return ans;
    }
};