
void writeBinaryTree(BinaryTree *p, ostream &out) {
  if (!p) {
    out << "# ";
  } else {
    out << p->data << " ";
    writeBinaryTree(p->left, out);
    writeBinaryTree(p->right, out);
  }
}

void readBinaryTree(BinaryTree *&p, ifstream &fin) {
  int token;
  bool isNumber;
  if (!readNextToken(token, fin, isNumber)) 
    return;
  if (isNumber) {
    p = new BinaryTree(token);
    readBinaryTree(p->left, fin);
    readBinaryTree(p->right, fin);
  }
}

// Below is for BST only. writing to file is a simple pre order write
void readBSTHelper(int min, int max, int &insertVal,
                   BinaryTree *&p, ifstream &fin) {
  if (insertVal > min && insertVal < max) {
    int val = insertVal;
    p = new BinaryTree(val);
    if (fin >> insertVal) {
      readBSTHelper(min, val, insertVal, p->left, fin);
      readBSTHelper(val, max, insertVal, p->right, fin);
    }
  }
}
 
void readBST(BinaryTree *&root, ifstream &fin) {
  int val;
  fin >> val;
  readBSTHelper(INT_MIN, INT_MAX, val, root, fin);
}
