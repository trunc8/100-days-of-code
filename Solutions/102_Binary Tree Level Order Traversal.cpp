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
        vector< vector<int> > level_order;
        if( !root ) return level_order;
        
        queue< pair<TreeNode*,int> > bfs_queue;
        int level = 0;
        bfs_queue.push( make_pair(root,level) );
        
        while( !empty(bfs_queue) ){
            TreeNode* node = bfs_queue.front().first;
            level = bfs_queue.front().second;
            bfs_queue.pop();
            
            if( level_order.size() < level+1 )
                level_order.push_back( vector<int>() );
            level_order.at(level).push_back( node->val );
            
            if( node->left )
                bfs_queue.push( make_pair(node->left, level+1) );
            if( node->right )
                bfs_queue.push( make_pair(node->right, level+1) );
        }
        return level_order;
    }
};
