/*
   Given a binary tree, find the maximum path sum.
 */

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Node
{
        int singlePath; // the max sum of this node with left child or right child
        int bothPath;  //  the max sum of this node with left child and right child
};

int max(int a,int b)// get the maximum of a and b
{
        return a>b?a:b;
}

class Solution {
        public:
                int maxPathSum(TreeNode* root) {
                        if(!root) // if root is NULL return 0;
                        {
                                return 0;
                        }
                        Node rootNode = maxOfNode(root); 
                        return max(rootNode.singlePath,rootNode.bothPath);
                }

                // the the max single path and max both path;
                Node maxOfNode(TreeNode* root)
                {
                        Node node = {INT_MIN,INT_MIN};
                        if(root)
                        {
                                //get max path of left child and right child recursively 
                                Node left = maxOfNode(root->left); 
                                Node right = maxOfNode(root->right);
                                node.singlePath = root->val + max(max(0,left.singlePath),right.singlePath); // max single path is the maximum of this val or val with left child or val with right child's single path
                                // max both path is maximum of left both path or right both path or this val with left single path with right single path
                                node.bothPath = max(max(root->val + max(0,left.singlePath) + max(0,right.singlePath),left.bothPath),right.bothPath);
                        }
                        return node;
                }
};

int main()
{
        int vex[7] = {-2,4,3,2,-2,5,3};
        TreeNode* t1 = new TreeNode(-2);
        TreeNode* t2 = new TreeNode(4);
        TreeNode* t3 = new TreeNode(3);
        TreeNode* t4 = new TreeNode(2);
        TreeNode* t5 = new TreeNode(-2);
        TreeNode* t6 = new TreeNode(5);
        TreeNode* t7 = new TreeNode(3);
        t1->left = t2;
        t1->right = t3;
        t2->left = t4;
        t2->right = t5;
        t3->left = t6;
        t3->right = t7;
        Solution* s = new Solution();
        int maxPath = s->maxPathSum(t1);
        cout<<maxPath<<endl;
        return 0;
}
