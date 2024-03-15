class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);

        for(int i=0;i<n;i++)
        {
            if(i==0) pre[i]=nums[i];
            else pre[i] = nums[i]*pre[i-1];
        }

        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1) suf[i]=nums[i];
            else suf[i] = nums[i]*suf[i+1];
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int preN = (i==0 ? 1 : pre[i-1]);
            int sufN = (i==n-1 ? 1 : suf[i+1]);
            ans[i] = preN*sufN;
        }

        return ans;
    }
};