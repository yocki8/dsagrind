class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int maxi = 0;
        for(char ch='A';ch<='Z';ch++)
        {
            int l = 0;
            int storeK = k;
            for(int i=0;i<n;i++)
            {
                if(s[i]!=ch)
                {
                    if(k==0)
                    {
                        while(l<n && s[l]==ch) l++;
                        l++;
                        k = 1;
                    } 

                    k--;
                }
                maxi = max(maxi,i-l+1);
            }

            k = storeK;
        }

        return maxi;
    }
};