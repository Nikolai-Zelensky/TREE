#include <iostream>
#include <ctime>
using namespace std;


typedef struct treenode
{
    int field;           
    struct treenode* left;  
    struct treenode* right; 
}treenode;

void treeprint(treenode* tree)
{
    if (tree != NULL) {      
        treeprint(tree->left);  
        cout << tree->field << " "; 
        treeprint(tree->right); 
    }
}

struct treenode* addnode(int x, treenode* tree) {
    if (tree == NULL)     
    {
        tree = new treenode; 
        tree->field = x;   
        tree->left = NULL;
        tree->right = NULL; 
    }
    else     
        if (x < tree->field)   
            tree->left = addnode(x, tree->left); 
        else  
            tree->right = addnode(x, tree->right); 
    return(tree);
}

void freemem(treenode* tree)
{
    if (tree != NULL)    
    {
        freemem(tree->left);
        freemem(tree->right);
        delete tree;
    }
}

int main()
{
    struct treenode* root = 0;
    int a;            
    setlocale(LC_ALL, "Rus");
    for (int i = 0; i < 8; i++)
    {
        cout << "¬ведите узел " << i + 1 << ": ";
        cin >> a;
        root = addnode(a, root);
    }
    treeprint(root);
    freemem(root);
    cin.get();  cin.get();
    return 0;
}