#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() == true)
			return 0;

		int m = grid.size();
		int n = grid[0].size();
		int ans = 0;

		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				ans += grid[y][x] - '0';
				dfs(grid, x, y, m, n);
			}
		}
		return ans;
	}

private:
	void dfs(vector<vector<char>>&grid, int x, int y, int m, int n) {
		if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
			return;
		grid[y][x] = '0';
		dfs(grid, x + 1, y, m, n);
		dfs(grid, x - 1, y, m, n);
		dfs(grid, x, y + 1, m, n);
		dfs(grid, x, y - 1, m, n);
	}
};

int main()
{
	vector<vector<char> > grid(5, vector<char>(5));
	grid[0][0] = '1'; grid[0][1] = '1'; grid[0][2] = '0'; grid[0][3] = '1'; grid[0][4] = '1';
	grid[1][0] = '1'; grid[1][1] = '1'; grid[1][2] = '0'; grid[1][3] = '1'; grid[1][4] = '1';
	grid[2][0] = '0'; grid[2][1] = '0'; grid[2][2] = '1'; grid[2][3] = '0'; grid[2][4] = '0';
	grid[3][0] = '0'; grid[3][1] = '1'; grid[3][2] = '0'; grid[3][3] = '1'; grid[3][4] = '1';
	grid[4][0] = '1'; grid[4][1] = '0'; grid[4][2] = '1'; grid[4][3] = '1'; grid[4][4] = '1';

	Solution objSol;
	int ans = objSol.numIslands(grid);

	cout << "number of islands = " << ans << endl;

	system("pause");

	return 0;
}
