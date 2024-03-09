class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(!s.size()) return 0;
        unordered_map<char,int> um;

        int maxi = 1;
        int l=0;
        for(int i=1;i<s.size();i++)
        {
            if(um[s[i]] || s[i]==s[0])
            {
                l = max(l,um[s[i]]+1);
            }
            um[s[i]] = i;
            maxi = max(maxi,i-l+1);
        }

        return  maxi;
    }
};