#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node 
{
    int d;
    struct node * l;
    struct node * r;
}Node;

Node* insert(Node* x, int d)
{
    if(x == NULL)
    {
        x = new Node;
        x->d = d;
        x->l = NULL;
        x->r = NULL;
        return x;
    }
    if(x->d <= d)
    {
        x->r = insert(x->r,d);
    }
    if(x->d > d)
    {
        x->l = insert(x->l,d);   
    }
    return x;
}

void printLevelOrder(Node *x, vector<int> s)
{
    if(x) {
        if(x->l) {
            s.push_back(x->l->d);
            printLevelOrder(x->l,s);
        }
        if(x->l == NULL && x->r == NULL) {
            for(int i = 0; i < s.size(); i++) {
                cout << " " << s[i];
            }
            cout << endl;
        }
        s.pop_back();
        if(x->r) {
            s.push_back(x->r->d);
            printLevelOrder(x->r,s);
        }
    }
}

int main() {
    Node* x = insert(x, 5);
    insert(x, 3);
    insert(x, 7);
    insert(x, 2);
    insert(x, 1);
    insert(x, 6);
    insert(x, 8);
    insert(x, 9);
    vector<int> v;
    v.push_back(5);
    printLevelOrder(x,v);
	return 0;
}

/*
       5
    3     7
  2    6   8
1            9
*/
