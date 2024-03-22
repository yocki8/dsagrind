
class Solution {
  public:
  
    void recur(Node* root, int i,vector<int> &v)
    {
        if(root==NULL) return;
        
        if(i==v.size()) v.push_back(root->data);
        else v[i] += root->data;
        
        recur(root->left,i+1,v);
        recur(root->right,i,v);
        
    }
    
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        vector<int> v;
        
        recur(root,0,v);
        return v;
    }
};