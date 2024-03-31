class Solution {
public:

    void visu(auto &v,int L,int l,int r)
    {
        for(auto x:v) cout << x <<' ';
        cout << endl;
        for(int i=0;i<v.size();i++)
        {
            if(i==L && i==l && i==r) cout << '*';
            else if(i==l && i==L) cout << '+';
            else if(i==l) cout << 'l';
            else if(i==L) cout << 'L';
            else if(i==r) cout << 'r';
            else cout <<' ';
            cout << ' ';
        }

        cout << endl <<endl;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;

        int n = nums.size();
        int r = 0;
        int lNear = 0;
        int lFar = 0;

        int cnt = 0;
        while(r<n)
        {
            um[nums[r]]++;

            // visu(nums,lFar,lNear,r);

            if(um.size()>k)
            {
                while(um.size()>k)
                {
                    um[nums[lNear]]--;
                    if(um[nums[lNear]]==0) um.erase(nums[lNear]);
                    lNear++;
                }

                lFar = lNear;
            }

            while(um[nums[lNear]]>1)
            {
                um[nums[lNear]]--;
                if(um[nums[lNear]]==0) um.erase(nums[lNear]);
                lNear++;
            }
            // visu(nums,lFar,lNear,r);
            // cout <<endl;

            if(um.size()==k)
            cnt += (lNear-lFar+1);
            r++;
        }

        return cnt;
    }
};
