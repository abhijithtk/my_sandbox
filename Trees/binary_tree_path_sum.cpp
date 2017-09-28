#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
};

bool isFirst = true;

void printNode(Node* node) {
  if (node == NULL) return;

  cout << "(";
  printNode(node->left);

  cout << node->value;

  printNode(node->right);
  cout << ")";
}

Node* createNode(int value) {
  Node* node;

  node = new Node();
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void deleteNodeAll(Node* node) {
  if (node->left) {
    deleteNodeAll(node->left);
    delete node->left;
  }
  
  if (node->right) {
    deleteNodeAll(node->right);
    delete node->right;
  }
}

void findSumInStack(vector<Node*>& stack, int sum) {
  int i, j, l, s;

  l = stack.size() - 1;
  s = 0;
  for (i = l; i >= 0; i--) {
    s += stack[i]->value;
    if (s == sum) {
      if (isFirst == false) {
        cout << ", {";
      } else {
        isFirst = false;
        cout << "{";
      }
      for (j = i; j < l; j++) {
        cout << stack[j]->value << ", ";
      }
      cout << stack[l]->value;
      cout << "}";
    }
  }
}

void searchBTreeSum(Node* node, vector<Node*>& stack, int sum) {
  if (node == NULL) return;

  stack.push_back(node);

  findSumInStack(stack, sum);

  searchBTreeSum(node->left, stack, sum);
  searchBTreeSum(node->right, stack, sum);

  stack.pop_back();
}

int main(int argc, char* argv[]) {
  Node* root;
  vector<Node*> stack;

  root = createNode(2);
  root->left = createNode(3);
  root->right = createNode(5);

  root->left->left = createNode(4);
  root->left->right = createNode(8);

  root->right->left = createNode(6);
  root->right->right = createNode(-2);

  root->right->right->right = createNode(2);

  printNode(root);
  cout << "\n";

  searchBTreeSum(root, stack, 10);
  cout << "\n";

  deleteNodeAll(root);
  delete root;

  return 0;
}
