node* kthSmallestElement(node *root, int *k)
{
    if(root != NULL)
    {
        node* result = kthSmallestElement(root->left,k);
        if(result)
            return result;
        *k = *k - 1;
        if(*k == 0)
           return root;
        return kthSmallestElement(root->right,k);
    }
    return NULL;
}
