import java.util.*;
import java.io.*;

class Node {
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class TopView {

    /* 
    
    class Node 
        int data;
        Node left;
        Node right;
    */

    static class pair{
        int first , second ;
        pair(){

        }
        pair(int l , int r){
            first = l;
            second = r;
        }
    }
    static TreeMap<Integer , pair>m = new TreeMap<>();
    
    public static void topviewutil(Node node , int d , int l){
        if(node == null){
            return;
        }
        if(m.get(d) == null){
            m.put(d , new pair(node.data , l));
        }
        else if(m.get(d).second > l){
            m.put(d , new pair(node.data , l));
        }
        topviewutil(node.left , d-1 , l+1);
        topviewutil(node.right , d+1 , l+1);
    }
    public static void topView(Node root) {
      
      topviewutil(root , 0 , 0);
      
      for(Map.Entry<Integer , pair>it : m.entrySet() ){
          System.out.print(it.getValue().first + " ");
      }
    }

    public static Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root = null;
        while(t-- > 0) {
            int data = scan.nextInt();
            root = insert(root, data);
        }
        scan.close();
        topView(root);
    }   
}