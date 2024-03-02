/*
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), elements = grid[0].size();
        int answer = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < elements; j++) {
                if (grid[i][j] == 1) {
                    answer += 4;
                    //down
                    if (i + 1 < rows && grid[i + 1][j] == 1) {
                        answer--;
                    }
                    // up
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        answer--;
                    }
                    // left
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        answer--;
                    }
                    //right
                    if (j + 1 < elements && grid[i][j + 1] == 1) {
                        answer--;
                    }
                }

            }
        }
        return answer;
    }
};


int main()
{
    int n, m;
    cin >> n >> m;

    vector < vector <int> > grid(n, vector <int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution Solution;
    int check = Solution.islandPerimeter(grid);
    cout << check;
}