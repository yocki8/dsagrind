class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) 
    {
        sort(p.begin(),p.end());

        int n = p.size();
        int cnt=0;
        int i=1;
        int mini = p[0][1];

        do
        {
            while(i!=n && mini>=p[i][0])
            {
                mini = min(p[i][1],mini);
                i++;
            }
            
            cnt++;
            if(i<n) mini = p[i][1];
            
        }while(i<n);

        return cnt;    
    }

};