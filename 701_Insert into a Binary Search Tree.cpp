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

// Solution 1
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( !root ) {
            root = new TreeNode( val );
            return root;
        }
        TreeNode* curr_node = root;
        TreeNode* prev_node = curr_node;
        while( curr_node ){
            prev_node = curr_node;
            curr_node = ( val < curr_node->val ) ? 
                curr_node->left : curr_node->right;
        }
        if( val < prev_node->val ) prev_node->left = new TreeNode( val );
        else prev_node->right = new TreeNode( val );
        
        return root;
    }
};

// Solution 2: Referred to discussions. Use Recursion!
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( !root ) return new TreeNode( val );
        if( val < root->val ) root->left = insertIntoBST( root->left, val );
        else root->right = insertIntoBST( root->right, val );
        
        return root;
    }
};
