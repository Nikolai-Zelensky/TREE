#include <iostream>
using namespace std;

struct tnode
{
    int field;           
    struct tnode* left;  
    struct tnode* right; 
};

void treeprint(tnode* tree)
{
    if (tree != NULL) {      
        treeprint(tree->left);  
        cout << tree->field << " "; 
        treeprint(tree->right); 
    }
}

struct tnode* addnode(int x, tnode* tree) {
    if (tree == NULL)     
    {
        tree = new tnode; 
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

void freemem(tnode* tree)
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
    struct tnode* root = 0;
    system("chcp 1251");
    system("cls");
    int a;            
    
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