class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int currMin = prices[0];
        int maxi = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            currMin = min(currMin,prices[i]);
            maxi = max(maxi,prices[i]-currMin);
        }

        return maxi;
    }
};