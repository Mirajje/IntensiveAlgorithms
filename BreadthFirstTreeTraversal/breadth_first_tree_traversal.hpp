/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return std::vector<std::vector<int>>();

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> queue;
        queue.push(root);
        int level = 0;
        while (!queue.empty())
        {
            result.push_back(std::vector<int>());
            int amount = queue.size();
            for (int i = 0; i < amount; ++i)
            {
                auto elem = queue.front();
                queue.pop();
                result[level].push_back(elem->val);
                if (elem->left)
                    queue.push(elem->left);

                if (elem->right)
                    queue.push(elem->right);
            }

            ++level;
        }

        return result;
    }
};
