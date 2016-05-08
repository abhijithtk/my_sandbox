#include <iostream>
#include <queue>

using namespace std;


typedef struct node {
  struct node *l;
  struct node *r;
  int d;
}N;

void LO(N *r)
{
  if(r == NULL)
    return;
  std::queue<N *> q;
  q.push(r);
  
  int cl = 1;
  int nl = 0;
  
  while(!q.empty())
  {
      N* t = q.front();
      q.pop();
      cl--;
      if(t != NULL)
      {
              cout << ", " << t->d;
        q.push(t->l);
        q.push(t->r);
        nl+= 2;
      }
      if(cl == 0)
      {
          cout << endl;
          cl = nl;
          nl = 0;
      }
  }
  
}

// To execute C++, please define "int main()"
N* getNode(int x)
{
    N *n = new N;
    n->d = x;
    n->l = n->r = NULL;
    return n;
}

int main() {
  //for (int i = 0; i < 5; i++) {
  //  cout << "Hello, World\n";
  // }
  N *n = getNode(10);
  n->l = getNode(5);
  n->r = getNode(15);
  n->r->l = getNode(150);
  n->r->r = getNode(215);
  n->l->r = getNode(1556);
  n->l->l = getNode(145);
  n->l->l->l = getNode(15123);
  n->l->l->l->l = getNode(15123333);
  n->l->l->r = getNode(115);
  n->r->r->r = getNode(1);
  LO(n);
  return 0;
}

################################################################
#include <iostream>
#include <queue>

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

void printLevelOrder(Node *x)
{
    std::queue<Node*> q;
    q.push(x);
    while(1)
    {
        int size = q.size();
        if(size == 0)
            return;
        while(size)
        {
            Node *tmp = q.front();
            q.pop();
            cout  << tmp->d;
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
            size--;
        }
        cout << endl;
    }
}

void printZigZagLevelOrder(Node *x)
{
    std::queue<Node*> q;
    q.push(x);
    bool dir = false;
    while(1)
    {
        int size = q.size();
        if(size == 0)
            return;
        vector<int> v;
        while(size)
        {
            Node *tmp = q.front();
            q.pop();
            v.push_back(tmp->d);
            //cout  << " " << tmp->d;
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
            size--;
        }
        if(dir) {
                for(int i = v.size() - 1; i >= 0; i--) {
                cout << " " << v[i];
            }   
        }
        else {
                for(int i = 0; i < v.size(); i++) {
                cout << " " << v[i];
            }   
        }
        dir ^= 1;
        cout << endl;
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
    printLevelOrder(x);
	return 0;
}

