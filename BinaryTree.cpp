#include <iostream>
#define ArraySize 10
using namespace std;

template <class T>
class TreeNode
{
public:
    T value;
    TreeNode *leftNode;
    TreeNode *rightNode;
    TreeNode(T j)
    {
        this->value = j;
        this->leftNode = NULL;
        this->rightNode = NULL;
    }
};

template <class K>
class BinaryTree
{
public:
    TreeNode<K> *rootNode;
    BinaryTree(K data[ArraySize])
    {
        rootNode = NULL;
        for (int i = 0; i < ArraySize; i++)
        {
            AddNodeToTree(data[i]);
        }
    }

    void AddNodeToTree(K data)
    {
        if (rootNode == NULL)
        {
            rootNode = new TreeNode<K>(data);
            return;
        }
        TreeNode<K> *currentNode = rootNode;
        while (true)
        {
            if (data < currentNode->value)
            {
                if (currentNode->leftNode == nullptr)
                {
                    currentNode->leftNode = new TreeNode<K>(data);
                    return;
                }
                else
                    currentNode = currentNode->leftNode;
            }
            else
            {
                if (currentNode->rightNode == nullptr)
                {
                    currentNode->rightNode = new TreeNode<K>(data);
                    return;
                }
                else
                    currentNode = currentNode->rightNode;
            }
        }
    }

    void inorder(TreeNode<K> *node)
    {
        if (node != NULL)
        {
            inorder(node->leftNode);
            cout << node->value << endl;
            inorder(node->rightNode);
        }
    }

    void preorder(TreeNode<K> *node)
    {
        if (node != NULL)
        {
            cout << node->value << endl;
            preorder(node->leftNode);
            preorder(node->rightNode);
        }
    }

    void postorder(TreeNode<K> *node)
    {
        if (node != NULL)
        {
            postorder(node->leftNode);
            postorder(node->rightNode);
            cout << node->value << endl;
        }
    }
};

int main()
{
    int inp[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "No." << i + 1 << " data: ";
        cin >> inp[i];
    }
    BinaryTree<int> bT(inp);
    cout << "\ninoreder:" << endl;
    bT.inorder(bT.rootNode);
    cout << "\npreorder:" << endl;
    bT.preorder(bT.rootNode);
    cout << "\npostorder:" << endl;
    bT.postorder(bT.rootNode);
    return 0;
}
