/*
 * FloodFillAlgorithm.cpp
 * 
 * Problem: Given a 2D screen, starting pixel (sr, sc) and a new color,
 * fill the connected area with the new color (4-directionally).
 *
 * Commonly used in image editing, pathfinding, and maze algorithms.
 *
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m) (due to recursion/stack)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor) {
        int n = image.size(), m = image[0].size();
        if (sr < 0 || sc < 0 || sr >= n || sc >= m) return;
        if (image[sr][sc] != oldColor) return;

        image[sr][sc] = newColor;

        dfs(image, sr+1, sc, newColor, oldColor);
        dfs(image, sr-1, sc, newColor, oldColor);
        dfs(image, sr, sc+1, newColor, oldColor);
        dfs(image, sr, sc-1, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image; // no change needed
        dfs(image, sr, sc, newColor, oldColor);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Updated Image:\n";
    for (auto &row : result) {
        for (int pixel : row)
            cout << pixel << " ";
        cout << endl;
    }
    return 0;
}
