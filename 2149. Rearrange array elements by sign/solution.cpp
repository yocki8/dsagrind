class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> ret(n);

        for(auto x:nums){
            if(x>=0) ret[pos] = x,pos+=2;
            else ret[neg] = x,neg+=2;
        }

        return ret;
    }
};