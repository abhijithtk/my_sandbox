/*
*
* @ author nishit patira
*/
class Node
{
    int data;
    Node left, right;

    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}

public class Solution {

    private static boolean v1 = false;
    private static boolean v2 = false;
    Node root;
    public static void main(String[] args) {

        Solution tree = new Solution();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);
        tree.root.left.right.right = new Node(8);
        Node probableLCA = findLCA(tree.root, 5, 8);
        if(v1 && v2){
            System.out.println("LCA is : " + probableLCA.data);
        }
        else if( v1 && ! v2){
            System.out.println("Second element is not present in the tree");
        } else if( !v1 && v2){
            System.out.println("First element is not present in the tree");
        } else {
            System.out.println("Both elements not present in the tree.");
        }

    }

    private static Node findLCA(Node root, int n1, int n2) {

        Node temp = null;
        if (root == null) {
            return null;
        }
        if (root.data == n1) {
            v1 = true;
            temp = root;
        }
        if(root.data == n2){
            v2 = true;
            temp = root;
        }
        Node leftLCA = findLCA(root.left, n1, n2);
        Node rightLCA = findLCA(root.right, n1, n2);
        if(temp != null){
            return temp;
        }
        if (leftLCA == null && rightLCA == null) {
            return null;
        } else if (leftLCA != null && rightLCA != null) {
            return root;
        } else {
            return leftLCA == null ? rightLCA : leftLCA;
        }
    }
}

