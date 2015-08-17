int findValueClosestToX(TreeNode root, int x)
{
	if(root==null) return null;
	if(x==root) return root.val;
	if(x-root>;0)
	{
		if(root.right!=null)
		{
			int valReturn = findClosestToX(root.right,x);
			return (Math.Abs(x-valReturn) > x-root.val ? root.val :valReturn );
		}
		else{
			return root.val;
		}
	}
	else{
		if(root.left!=null){
			int valReturn = findClosestToX(root.left,x);
			return (Math.Abs(x-valReturn) > x-root.val ? root.val :valReturn );
		}
		else{
			return root.val;
		}
	}
}
