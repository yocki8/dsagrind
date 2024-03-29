class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> qu;

        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) qu.push({i,j});
            }
        }

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int pre = 0;
        int cnt = 2;

        while(!qu.empty() && pre!=qu.size())
        {
            int size = qu.size();
            pre = size;
            cnt++;
            while(size--)
            {
                int i = qu.front()[0];
                int j = qu.front()[1];
                qu.pop();

                for(int o=0;o<4;o++)
                {
                    int x = i+dx[o];
                    int y = j+dy[o];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]>=2 && grid[x][y]<cnt) grid[i][j]=cnt;
                }

                if(grid[i][j]==1) qu.push({i,j});
            }
        }

        if(qu.empty()) return cnt-2;
        else return -1;

    }
};