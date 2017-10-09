void printReverseBFS(Node *root) {
    queue<Node *> q;
    q.push(root);
    vector<vector<int> >v;
    while(1) {
        int size = q.size();
        if(size == 0) {
            break;
        }
        vector<int> v1;
        while(size){
            Node *tmp = q.front();
            q.pop();
            size--;
            if(tmp) {
                //cout << " " << tmp->key;
                v1.push_back(tmp->key);
                q.push(tmp->left);
                q.push(tmp->right);
            }                            
        }
        if(v1.size()) {
            v.push_back(v1);       
        }
        //cout << endl;
    }
    for(int i = v.size() - 1; i >= 0; i--) {
        for(int j = v[i].size() - 1; j >=0;  j--) {
            cout << " " << v[i][j];
        }
        cout << endl;
    }
}
