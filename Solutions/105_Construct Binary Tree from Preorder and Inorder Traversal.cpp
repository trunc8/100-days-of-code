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
    void buildLeftTree( TreeNode* root, const vector<int>& preorder, int& index, vector<int> inorder ){
        if( inorder.size()==0 ){
            return;
        }
        index++;
        root->left = new TreeNode( preorder.at(index) );
        root = root->left;
        int boundary;
        for( int i=0; i<inorder.size(); i++ ){
            if( inorder.at(i) == preorder.at(index) ){
                boundary = i;
                break;
            }
        }
        vector<int> left_inorder( inorder.begin(), inorder.begin()+boundary );
        vector<int> right_inorder( inorder.begin()+boundary+1, inorder.end() );
        buildLeftTree( root, preorder, index, left_inorder );
        buildRightTree( root, preorder, index, right_inorder );
        return;
    }
    void buildRightTree( TreeNode* root, const vector<int>& preorder, int& index, vector<int> inorder ){
        if( inorder.size()==0 ){
            return;
        }
        index++;
        root->right = new TreeNode( preorder.at(index) );
        root = root->right;
        int boundary;
        for( int i=0; i<inorder.size(); i++ ){
            if( inorder.at(i) == preorder.at(index) ){
                boundary = i;
                break;
            }
        }
        vector<int> left_inorder( inorder.begin(), inorder.begin()+boundary );
        vector<int> right_inorder( inorder.begin()+boundary+1, inorder.end() );
        buildLeftTree( root, preorder, index, left_inorder );
        buildRightTree( root, preorder, index, right_inorder );
        return;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* soln = new TreeNode( preorder.front() );
        TreeNode* root = soln;
        int index = 0;
        int boundary;
        for( int i=0; i<inorder.size(); i++ ){
            if( inorder.at(i) == preorder.at(index) ){
                boundary = i;
                break;
            }
        }
        vector<int> left_inorder( inorder.begin(), inorder.begin()+boundary );
        vector<int> right_inorder( inorder.begin()+boundary+1, inorder.end() );
        buildLeftTree( root, preorder, index, left_inorder );
        buildRightTree( root, preorder, index, right_inorder );
        return soln;
    }
};
