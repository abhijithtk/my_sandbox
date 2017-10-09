#include<stdio.h>
#include<limits.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <queue>

using namespace std;
const int MAX = 120;

class Node{
    int key;
    int value;
    public:
    Node(int key, int value) : key(key), value(value){ }
    int getKey() { return key;}
    int getValue() { return value;}
    int set(int m_value) {value = m_value; return 0;}
};

class HashTable {
    list<Node> *arr;    
    public:
    HashTable() { arr =  new list<Node>[MAX];}
    ~HashTable() { delete [] arr; }
    int put(int key, int value);
    int get(int key);
};

int HashTable::put(int key, int value) {
    int tmpkey = key%MAX;
    Node n(key,value);
    if(arr[tmpkey].size() == 0) {
        arr[tmpkey].push_back(n);
        return 0;
    }
    list<Node>::iterator lit;
    for(lit = arr[tmpkey].begin(); lit != arr[tmpkey].end(); lit++) {
        cout << "key=" << lit->getKey() << endl;
        if(lit->getKey() == key)
            return lit->set(value);
    }        
    arr[tmpkey].push_back(n);
    return 0;
}

int HashTable::get(int key) {
    int tmpkey = key%MAX;
    list<Node>::iterator lit;
    for(lit = arr[tmpkey].begin(); lit != arr[tmpkey].end(); lit++) {
        cout << "key=" << lit->getKey() << endl;
        if(lit->getKey() == key)
            return lit->getValue();
    }
    return 0;
}
int main() {
    HashTable h;
    h.put(10,10);
    h.put(130,130);
    h.put(8,8);
    h.put(128,128);
    h.put(40,40);
    h.put(1,1);
    h.put(0,0);
    h.put(10,20);
    cout << h.get(10) << endl;
    return 0;
}
