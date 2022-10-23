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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    vector < vector < int >> ans ;

    if(root == NULL) return ans;
        
    
    queue < TreeNode*> q;
    
    q.push(root); 
    int flag = 0;    
        
    while(!q.empty())
    {
        
        int x = q.size();
        flag++;
        vector < int > level ;
        for( int i =0 ; i < x ; i++)
        {  TreeNode* t = q.front();
           level.push_back(t->val);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
            if(flag%2==0)
            {
                reverse (level.begin(), level.end());
            }
       ans.push_back(level);
        
    }
    
    return ans ;
    }
};