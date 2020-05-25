import java.util.LinkedList; 
import java.util.Queue; 
public class Deletion { 
    
    // Binary Tree Node
    static class Node { 
        int key; 
        Node left, right; 
        
        // constructor 
        Node(int key){ 
            this.key = key; 
            left = null; 
            right = null; 
        } 
    } 
    
    static Node root; 
    static Node temp = root; 
    
    // Function to perform Inorder traversal
    // of a binary tree
    static void inorder(Node temp) 
    { 
        if (temp == null) 
            return; 
    
        inorder(temp.left); 
        System.out.print(temp.key+" "); 
        inorder(temp.right); 
    } 
    
    // Function to delete the given deepest node 
    // (d_node) in binary tree 
    static void deleteDeepest(Node root, Node todelete) 
    {
        Queue<Node> q = new LinkedList<Node>(); 
        q.add(root); 
    
        // Do level order traversal until last node 
        Node temp; 
        while(!q.isEmpty()) 
        { 
            temp = q.peek(); 
            q.remove(); 
    
            if (temp.right!=null) 
            { 
                if (temp.right == todelete) 
                { 
                    temp.right = null; 
                    todelete = null; 
                    return; 
                } 
                else
                    q.add(temp.right); 
            } 
    
            if (temp.left!=null) 
            { 
                if (temp.left == todelete) 
                { 
                    temp.left=null; 
                    todelete = null; 
                    return; 
                } 
                else
                    q.add(temp.left); 
            } 
        } 
    } 
    
  
    static void deletion(Node root, int key) 
    { 
        Queue<Node> q = new LinkedList<Node>(); 
        q.add(root); 
    
        Node temp = null; 
        Node key_node = null; 
    
        // Do level order traversal to find deepest 
        // node(temp) and node to be deleted (key_node) 
        while (!q.isEmpty()) 
        { 
            temp = q.peek(); 
            q.remove(); 
    
            if (temp.key == key) 
                key_node = temp; 
    
            if (temp.left!=null) 
                q.add(temp.left); 
    
            if (temp.right!=null) 
                q.add(temp.right); 
        } 
    
        int x = temp.key; 
        deleteDeepest(root, temp); 
        key_node.key = x; 
    } 

    public static void main(String args[]) 
    { 
        // Create the following Binary Tree
        //            10
        //         /      \
        //        11       9
        //       /  \     / \
        //      7    12  15  8  
        root = new Node(10); 
        root.left = new Node(11); 
        root.left.left = new Node(7); 
        root.left.right = new Node(12);
        root.right = new Node(9); 
        root.right.left = new Node(15); 
        root.right.right = new Node(8); 
    
        System.out.print( "Inorder traversal before Deletion:"); 
        inorder(root); 
    
        int key = 11; 
        deletion(root, key); 
    
        System.out.print("\nInorder traversal after Deletion:"); 
        inorder(root); 
    } 
} 