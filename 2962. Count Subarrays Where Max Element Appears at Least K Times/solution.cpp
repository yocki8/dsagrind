class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int m = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        vector<int> v;
        for(int i=0;i<m;i++) if(nums[i]==maxi) v.push_back(i);  // 1st step

        int n = v.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int l=i;
            int r = l+k-1;
            if(r>=n) break;// 2nd step

            long long left = v[l]-(l-1<0 ? -1 : v[l-1]);  //3rd step
            long long right = m-v[r];

            sum += left*right; //4th step
        }

        return sum;

    }
};


/*

#approach

1. push all index of max element in a vector (v)
2. check if the i+k-1<[v.size()]
3. iterate this (v) and in each index check for index i+k-1, Now we have [vi] and [vr]
4. now add into (sum) the product of [vi]-[vi-1] .if i-1 exist and n-[vr];
*/

