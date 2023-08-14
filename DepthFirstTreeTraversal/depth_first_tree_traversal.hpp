/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:

    void create_graph(TreeNode* cur_node, std::unordered_map<int, std::unordered_set<int>>& graph)
    {
        if (cur_node->left)
        {
            graph[cur_node->val].insert(cur_node->left->val);
            graph[cur_node->left->val].insert(cur_node->val);
            create_graph(cur_node->left, graph);
        }

        if (cur_node->right)
        {
            graph[cur_node->val].insert(cur_node->right->val);
            graph[cur_node->right->val].insert(cur_node->val);
            create_graph(cur_node->right, graph);
        }
    }

    void solve(int cur_elem, std::unordered_map<int, std::unordered_set<int>>& graph, std::vector<bool>& visited, int cur_distance, int k, std::vector<int>& result)
    {
        if (cur_distance == k)
            result.push_back(cur_elem);

        for (auto& neighbour : graph[cur_elem])
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                solve(neighbour, graph, visited, cur_distance + 1, k, result);
            }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map<int, std::unordered_set<int>> graph;
        create_graph(root, graph);

        std::vector<bool> visited(501);
        visited[target->val] = true;
        std::vector<int> result;

        solve(target->val, graph, visited, 0, k, result);

        return result;
    }
};
