class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long maxi = -1;
        long long sum = nums[0]+nums[1];
        for(int i=2;i<n;i++)
        {
            if(sum>nums[i])
            {
                maxi = max(maxi,sum+nums[i]);
            }

            sum += nums[i];
        }

        return maxi;
    }
};

// 1 1 2 3 5 12 50
