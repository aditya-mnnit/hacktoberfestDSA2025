// Problem: Maximum Width of a Binary Tree
// Given the root of a binary tree, return the maximum width of the tree.
// The width of a level is defined as the number of nodes between the leftmost and rightmost non-null nodes in the level (including null nodes in between).

// Input:
//         1
//       /   \
//      3     2
//     / \     \
//    5   3     9

// Output: 4

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    long long maxWidth = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        long long levelMin = q.front().second;
        long long first, last;
        for (int i = 0; i < size; i++)
        {
            long long currIndex = q.front().second - levelMin;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
                first = currIndex;
            if (i == size - 1)
                last = currIndex;
            if (node->left)
                q.push({node->left, 2 * currIndex + 1});
            if (node->right)
                q.push({node->right, 2 * currIndex + 2});
        }
        maxWidth = max(maxWidth, last - first + 1);
    }

    return (int)maxWidth;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << "Maximum Width of Binary Tree: " << widthOfBinaryTree(root) << endl;
    return 0;
}
