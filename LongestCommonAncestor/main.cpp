#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(vector<TreeNode *> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		TreeNode* t = vec[i];
		cout<<t->val<<" ";
	}
	cout<<endl;
}


class Solution {
private:
    vector<TreeNode*> vec_p;
    vector<TreeNode*> vec_q;
    bool b_p;
    bool b_q;
public:
	
    void PreOrder(TreeNode* root,vector<TreeNode*> codec,TreeNode* p,TreeNode* q)
    {
        if(root!=NULL&& (!b_p||!b_q))
        {
            codec.push_back(root);
            if(root == p)
            {
                vec_p = codec;
                b_p = true;
                if(b_q)
                {
                    return;
                }
            }
            else if(root == q)
            {
                vec_q = codec;
                b_q = true;
                if(b_p)
                {
                    return;
                }
            }
            PreOrder(root->left,codec,p,q);
            PreOrder(root->right,codec,p,q);
        }
    }
	
	/*内存超过限制*/
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> codec;
		this->b_p = false;
		this->b_q = false;
        PreOrder(root,codec,p,q);
        int min_len = vec_p.size() < vec_q.size()?vec_p.size():vec_q.size();
        int i=0;
        for(i=0;i<min_len;i++)
        {
            if(vec_p[i] != vec_q[i])
            {
                break;
            }
        }
        return vec_p[i-1];
	}
	
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};

int main()
{
    TreeNode* treeNode0 = new TreeNode(0);
	TreeNode* treeNode1 = new TreeNode(1);
    TreeNode* treeNode2 = new TreeNode(2);
    TreeNode* treeNode3 = new TreeNode(3);
    TreeNode* treeNode4 = new TreeNode(4);
    TreeNode* treeNode5 = new TreeNode(5);
    TreeNode* treeNode6 = new TreeNode(6);
    TreeNode* treeNode7 = new TreeNode(7);
    TreeNode* treeNode8 = new TreeNode(8);
    treeNode3->left = treeNode5;
    treeNode3->right = treeNode1;
    treeNode5->left = treeNode6;
    treeNode5->right = treeNode2;
    treeNode2->left = treeNode7;
    treeNode2->right = treeNode4;
    treeNode1->left = treeNode0;
    treeNode1->right = treeNode8;
	
	
	Solution* s = new Solution();
	TreeNode* lcs = s->lowestCommonAncestor(treeNode3,treeNode5,treeNode1);
	
	cout<<lcs->val<<" left:"<<lcs->left->val<<" right:"<<lcs->right->val<<endl;
	
	/*delete treenode0......8*/
	delete treeNode0;
	delete treeNode1;
	delete treeNode2;
	delete treeNode3;
	delete treeNode4;
	delete treeNode5;
	delete treeNode6;
	delete treeNode7;
	delete treeNode8;
	delete s;
	
	return 0;
}