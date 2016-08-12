/**
有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离。
给定二叉树的根节点root，请返回所求距离。
*/
//典型的二进制编码题，算出叶子节点二进制编码，再比编码，计算后缀长度和
#include <iostream>
#include <string>

class TreeNode
{
public:
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int value)
    {
        this->value = value;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

class Tree
{
private:
    int min = 99999;
    int max = 0;
    std::string str_max;
    std::string str_min;

public:
    void PreOrder(TreeNode* t,std::string ch,std::string codec)
    {
        codec = codec + ch;
        if(t->leftChild == nullptr && t->rightChild == nullptr)//已经到达叶子节点
        {
            //std::cout<<codec<<std::endl;
            if(this->max < t->value)
            {
                this->max = t->value;
                this->str_max = codec;
            }
            if(this->min > t->value)
            {
                this->min = t->value;
                this->str_min = codec;
            }
        }
        else
        {
            if(t->leftChild != nullptr)
            {
                PreOrder(t->leftChild,"z",codec);
            }
            if(t->rightChild != nullptr)
            {
                PreOrder(t->rightChild,"y",codec);
            }
        }
    }

    int GetDistance(TreeNode* treeNode)
    {
        std::string codec;
        PreOrder(treeNode,"T",codec);
        //std::cout<<str_max<<std::endl;
        //std::cout<<str_min<<std::endl;
        int min_len  = str_max.length() > str_min.length() ? str_min.length():str_max.length();
        int i;
        for(i=0; i<min_len;i++)
        {
            if(str_max[i] != str_min[i])
            {
                break;
            }
        }
        int dist = str_max.length() - i + str_min.length() - i;
        return dist;
    }
};

int main()
{
    TreeNode* treeNode1 = new TreeNode(1);
    TreeNode* treeNode2 = new TreeNode(2);
    TreeNode* treeNode3 = new TreeNode(3);
    TreeNode* treeNode5 = new TreeNode(5);
    treeNode1->leftChild = treeNode2;
    treeNode1->rightChild = treeNode3;
    treeNode2->rightChild = treeNode5;

    Tree* t = new Tree();
    int dist = t->GetDistance(treeNode1);
    std::cout<<dist<<std::endl;

    delete treeNode5;
    delete treeNode3;
    delete treeNode2;
    delete treeNode1;
    delete t;
    return 0;
}
