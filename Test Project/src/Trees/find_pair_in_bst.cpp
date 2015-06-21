void findPair(node* root, int sum, int &a, int &b)
{
	a = -1;
	b = -1;
	// Base case '0' or '1' node in tree.
	if((!root) || (!root->left && !root->right))
		return;
	node* n1 = root, *n2 = root;
	stack<node*> p,q;
	while(true)
	{
		if(n1)
		{
			p.push(n1);
			n1 = n1->left;
		}
		else if(n2)
		{
			q.push(n2);
			n2 = n2->right;
		}
		else if(!p.empty() && !q.empty())
		{
			n1 = p.top();
			n2 = q.top();
			// tree is already traversed
			if(n1->data > n2->data) 
				return;			
			int cur_sum = n1->data + n2->data;
			if(cur_sum == sum)
			{
				// found desired numbers
				a = n1->data;
				b = n2->data;
				return;
			}
			else if(cur_sum < sum)
			{
				// move in forward direction
				p.pop();
				n1 = n1->right;
				n2 = NULL;
			}
			else
			{
				// move in backward direction
				q.pop();
				n2 = n2->left;
				n1 = NULL;
			}
		}
		else
			return;
	}
}
