class Solution {
public:

    void dfs(auto& board, int i, int j) {
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j]!='O') return;

        board[i][j] = '@';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        for(int i=0;i<m;i++)
        {
            dfs(board,i,0);
            dfs(board,i,n-1);
        }

        for(int j=0;j<n;j++)
        {
            dfs(board,0,j);
            dfs(board,m-1,j);
        }

        for(auto &x: board)
        {
            for(auto &y:x)
            {
                if(y=='O') y='X';
                if(y=='@') y='O';
            }
        }

    }
};