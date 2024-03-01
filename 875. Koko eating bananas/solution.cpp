class Solution {
public:

    int helpMe(vector<int> &piles,long long n)
    {
        int sum = 0;
        for(auto x:piles)
        {
            sum += x/n;
            if(x%n) sum++;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());

        int mid=1;
        while(l<=r)
        {
            mid = (l+r)/2;
            int sum = helpMe(piles,mid);

            if((mid==1 || helpMe(piles,mid-1)>h) && sum<=h) return mid;
            else if(sum<=h) r=mid-1;
            else l=mid+1;
        }
        
        return mid;
    }
};

