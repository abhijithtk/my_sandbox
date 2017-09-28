// Return pointer to the kth largest
Node* kthlargest(Node* root, int &k)
{
	if( root == NULL )
		return NULL;
	else
	{
		Node* result = kthlargest(root->right, int k);
		if( result )
			return result;
		k--;
		if( k == 0 )
			return root;
		return kthlargest(root->left, k);
	}
}
