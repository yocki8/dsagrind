class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        long long ans = 0;
        long long j = 1;
        for(int i=left;i!=0;i = i>>1)
        {
            if(i&1 && left/j==right/j) ans+=j;
            j *= 2;
        }

        return ans;
    }
};