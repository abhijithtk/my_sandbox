#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
void printAll(string st) {
    cout << st[0] << st.size()-2 << st[st.size()-1] << endl;
    for(unsigned int i=st.size()-3; i>=1; i--) {
        for(unsigned int k=0; k<=st.size()-2-i; k++)
            cout << st.substr(0,k+1) << i << st.substr(i+k+1) << endl;
    }
    cout << st << endl;
}

typedef struct node {
  int d;
  struct node* n;
}N;

N* reverse(N *t)
{
  
    return NULL;
}

void insertLL(N **h, int d)
{
    N* t =  new N;
    t->d = d;
    t->n = NULL;
  
    if(*h == NULL)
    {
        *h = t;
    }
    else {
        N *n = *h;
        *h = t; 
        t->n = n;
    }
}

void print(N *c)
{
    N *t = c;
    cout << "ASD" << endl;
    while(t != NULL)
    {
        cout << t->d << endl;
        t = t->n;
    }
}

N* merge(N* a, N* b)
{
    N temp;
    N* tail = &temp;
    
    while(a != NULL && b != NULL)
    {
        if(a->d >= b->d)
        {
            tail->n = a;
            a = a->n;
        }
        else 
        {
            tail->n = b;
            b = b->n;
        }
        tail = tail->n;
    }
    if(a)
        tail->n = a;
    if(b)
        tail->n = b;
    return temp.n;
}

void reverse(N **h)
{
    N* c = *h;
    if(c == NULL || c->n == NULL)
        return;
  
    N*  p = NULL;
    while(c != NULL)
    {
        N* t = c->n;
        c->n = p;
        p = c;
        c = t;
    }
    *h = p;
}

void del(N **h, int x)
{
    N *c = *h;
    N *p = NULL;
    while(c !=  NULL)
    {
        if(c->d == x && p == NULL)
        {
            N* t = c->n;
            free(c);
            *h = t;
        }
        else if (c->d == x)
        {
            N* t = c->n;
            p->n = c->n;
            free(c);
            c = t;
        }
        else 
        {
          p = c;
          c = c->n;
        }
    }
  
}

void deleteDups(N **h)
{
    N *c = *h;
    N *p = NULL;
    while(c != NULL && c->n != NULL)
    {
        if(c->d == c->n->d)
        {
            if(p == NULL)
            {
                N* t = c->n;
                free(*h);
                *h = t;
            }
            else
            {
                N* t = c->n;
                free(c);
                p->n = t;
                c = t;
            }
        }
        else
        {
            p = c;
            c = c->n;
        }
    }
}
  

int main() {
  printAll("careercup");
  N* head = NULL;

  insertLL(&head, 10);
  insertLL(&head, 11);
  insertLL(&head, 12);
  insertLL(&head, 13);
  insertLL(&head, 14);
  N* h2 = NULL;
  insertLL(&h2, 10);
  insertLL(&h2, 13);
  insertLL(&h2, 14);
  insertLL(&h2, 15);
  insertLL(&h2, 16);
  print(head);
  print(h2);
  N* m = merge(head,h2);
  print(m);
  reverse(&m);
  print(m);
  //deleteDups(&m);
  del(&m,16);
  print(m);
  return 0;
}

