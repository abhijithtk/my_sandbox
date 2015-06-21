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
