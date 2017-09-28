#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
void printTree(Node *root) {
    if(root) {
        printTree(root->left);
        cout << root->data << endl;
        printTree(root->right);
    }
}


void printVerticalOrder(Node *root, int level, map<int, vector<int> > &m) {
    if(root) {
        printVerticalOrder(root->left, level + 1 , m);
        cout << root->data  << ",level=" << level << endl;
        if(m.find(level) == m.end()) {
            vector<int> v;
            v.push_back(root->data);
            m.insert(pair<int, vector<int> >(level,v));
        }
        else {
            m[level].push_back(root->data);
        }
        printVerticalOrder(root->right, level - 1, m);
    }
}

void printMap(map<int, vector<int> > &m) {
    map<int, vector<int> >::iterator mit;
    for(mit= m.begin(); mit != m.end(); mit++) {
        vector<int>::iterator vit;
        for(vit = mit->second.begin(); vit != mit->second.end(); vit++) {
            cout << " " << *vit;
        }
        cout << endl;
    }
}

/* Driver program to test above functions*/
int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    //printTree(root);
    map<int,vector<int> > m;
    printVerticalOrder(root,0,m);
    printMap(m);
    return 0;
}
