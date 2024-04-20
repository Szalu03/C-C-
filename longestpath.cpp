#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        int maxLen = 1;
        for(auto dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix, dp, x, y);
            maxLen = max(maxLen, len);
        }
        dp[i][j] = maxLen;
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(matrix, dp, i, j));
            }
        }
        return maxLen;
    
}


int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int result = longestIncreasingPath(matrix);
    cout << "The length of the longest increasing path in the matrix is: " << result << endl;
    return 0;
}
