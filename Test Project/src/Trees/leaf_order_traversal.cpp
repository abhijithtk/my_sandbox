#include<stdio.h>
#include<limits.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

#define ROW 5
#define COL 5

typedef struct node
{
    char data;
    struct node *left, *right;
}Node;


/* Utility function to create a new Binary Tree node */
struct node* newNode (char data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp; 
}
   

int leafTraversal(Node *root, vector<string>& v) {
    if(root) {
        int level1 = leafTraversal(root->left,v);
        int level2 = leafTraversal(root->right,v);
        if(root->left == NULL && root->right == NULL) {
                v[0].push_back(root->data);
            return 0;        
        }
        int level = max(level1,level2);
        if(level != -1) {
            v[level + 1].push_back(root->data); 
            return level + 1;
        }           
    }
    return -1;
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%c ", node->data);
 
    /* now recur on right child */
    printInorder (node->right);
}

// Driver program
int main()
{
    Node *root = newNode('a');
    root->left = newNode('k');
    root->right = newNode('j');
    root->left->left = newNode('o');
    root->right->right = newNode('p');    
    root->right->left = newNode('h');
    root->right->left->right = newNode('t');
    root->right->left->left = newNode('q');
    root->right->left->left->right = newNode('b');
    root->right->left->left->right->left = newNode('r');
    vector<string> v(20);
    leafTraversal(root,v);
    for(int i = 0; i < 20; i++) {
        cout << v[i] << endl;
    }
    //printInorder(root);
    return 0;
}
