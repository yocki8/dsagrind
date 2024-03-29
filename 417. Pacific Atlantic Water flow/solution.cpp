class Solution {
public:

    void print(auto v)
    {
        for(auto x:v)
        {
            for(auto y:x) cout << y <<' ';
            cout << endl;
        }
        cout << endl;
    }
    void dfs(auto &mat, auto &vis,int i,int j)
    {
        if(vis[i][j]==1) return;

        int m = mat.size();
        int n = mat[0].size();

        vis[i][j] = 1;
        int dy[] = {0,0,1,-1};
        int dx[] = {1,-1,0,0};
        
        for(int c=0;c<4;c++)
        {
            
            int x = i+dy[c];
            int y = j+dx[c];
            
            if(x>=0 && y>=0 && x<m && y<n && mat[x][y]>=mat[i][j])
            {
                dfs(mat,vis,x,y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> out;
        vector<vector<int>> pac(m,vector<int>(n,0));
        vector<vector<int>> atl(m,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            dfs(heights,pac,0,i);
            dfs(heights,atl,m-1,i);
        }
        for(int i=0;i<m;i++)
        {
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,n-1);
        }

        // print(pac);
        // print(atl);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pac[i][j] && atl[i][j]) out.push_back({i,j});
            }
        }
        return out;
    }
};
