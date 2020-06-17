import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Main {
    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String s = br.readLine().trim();
            Node root = buildTree(s);
            String[] ab = br.readLine().trim().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);

            GfG g = new GfG();
            System.out.println(g.findDist(root, a, b));
        }
    }
}
// } Driver Code Ends


// FUNCTION CODE
/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
   Node(int item)    {
        data = item;
        left = right = null;
    }
} */

/* Should return minimum distance between a and b
   in a tree with given root*/
class GfG {
    public static int findlength(Node node , int a){
        int x = 0;
        if(node == null){
            return 0;
        }
            if((node.data == a ) || ((x = findlength(node.left , a)) > 0 ) || ((x = findlength(node.right , a)) > 0))
            {
                return x+1;
            }
            return 0;
    }
    public static Node findlca(Node node , int a ,int b){
        if(node == null){
            return node;
        }
        
        if(node.data == a || node.data == b){
            return node;
        }
        
        Node leftlca = findlca(node.left , a , b);
        Node rightlca = findlca(node.right , a, b);
        
        if(leftlca != null && rightlca != null){
            return node;
        }
        return (leftlca != null) ? leftlca : rightlca;
    }
    int findDist(Node root, int a, int b) {
        // Your code here
        if(root == null){
            return 0;
        }
        
        int lena = findlength(root , a) -1;
        int lenb = findlength(root , b) -1;
        Node lcanode = findlca(root , a , b);
        int lcadata = lcanode.data;
        int lcalength = findlength(root , lcadata) -1;
        
        return (lena + lenb -2*lcalength);
    }
}