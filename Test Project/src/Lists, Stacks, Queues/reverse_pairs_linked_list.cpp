#include <iostream>
#include <queue>

using namespace std;


typedef struct node {
  struct node *l;
  struct node *r;
  struct node *n;
  int d;
}N;


// To execute C++, please define "int main()"
N* getNode(int x)
{
    N *n = new N;
    n->d = x;
    n->l = n->r = NULL;
    return n;
}

void printList(N *n)
{
  
  while(n != NULL)
  {
      cout << n->d << ", ";
      n = n->n;
  }
  cout << endl;
}

void reverse(N **n)
{
    if(*n == NULL)
        return;
  
    N *p = NULL;
    N *c = *n;
  
    while( c != NULL && c->n != NULL)
    {
        cout << "!! " << c->d << endl;
        if(p == NULL)
        {
            *n = c->n;
            N *t = c->n->n;
            (*n)->n = c;
            c->n = t;
            p = c;
            c = t;
          
        }
        else 
        {
            p->n  = c->n;
            N *t = c->n->n;
            c->n->n = c;
            c->n = t;
            p = c;
            c = t;
        }
    }
}
int main() {
  N *n = getNode(10);
  n->n = getNode(5);
  n->n->n = getNode(15);
  n->n->n->n = getNode(15123);
  n->n->n->n->n = getNode(15123333);
  n->n->n->n->n->n = getNode(145);
  n->n->n->n->n->n->n = getNode(1555);
  printList(n);
  reverse(&n);
  printList(n);
  return 0;
}
