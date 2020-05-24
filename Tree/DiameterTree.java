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


class DiameterTree
{
    Node root;


    int diameter(Node root)
    {
        /* base case if tree is empty */
        if (root == null)
            return 0;

        /* get the height of left and right sub trees */
        int lheight = height(root.left);
        int rheight = height(root.right);

        /* get the diameter of left and right subtrees */
        int ldiameter = diameter(root.left);
        int rdiameter = diameter(root.right);

        return Math.max(lheight + rheight + 1,
                        Math.max(ldiameter, rdiameter));

    }

    int diameter()
    {
        return diameter(root);
    }


    static int height(Node node)
    {
        /* base case tree is empty */
        if (node == null)
            return 0;

        /* If tree is not empty then height = 1 + max of left
           height and right heights */
        return (1 + Math.max(height(node.left), height(node.right)));
    }

    public static void main(String args[])
    {

        DiameterTree tree = new DiameterTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("The diameter of given binary tree is : "
                           + tree.diameter());
    }
}
