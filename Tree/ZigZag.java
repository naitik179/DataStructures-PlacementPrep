import java.util.*;
import java.util.HashMap;
import java.io.*;

    class Node
    {
        int data;
        Node left,right;
        Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
    }
		
public class GFG2
{
    static Node buildTree(String str){
        
        if(str.length()==0 || str.charAt(0)=='N'){
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
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    
	public static void inorder(Node root)
	{
	    if(root==null)
	    return;
	    inorder(root.left);
	    System.out.print(root.data);
	    inorder(root.right);
	}
     /* Drier program to test above functions */
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
    
	        while(t > 0){
	            String s = br.readLine();
    	    	Node root = buildTree(s);
        	    Zigzag g = new ZigZag();
			
			    g.zigZagTraversal(root) ;
			    
			    System. out. println();  
    			
                t--;
            
        }
	}
}


class ZigZag
{
    
	void zigZagTraversal(Node root)
	{
	    
	   if(root == null){
              return;
          }
          else{
              Stack<Node>s1 = new Stack<>();
              Stack<Node>s2 = new Stack<>();
              
              s1.push(root);
              
              while(!s1.isEmpty() || !s2.isEmpty()){
                  
                  
                  while(!s1.isEmpty()){
                      Node temp = s1.peek();
                      s1.pop();
                      System.out.print(temp.data+" ");
                      
                      
                      if(temp.left!=null){
                          s2.push(temp.left);
                      }
                      
                      if(temp.right != null){
                          s2.push(temp.right);
                      }
                  }
                  
                  while(!s2.isEmpty()){
                      Node temp = s2.peek();
                      s2.pop();
                      System.out.print(temp.data+" ");
                      
                      if(temp.right!=null){
                          s1.add(temp.right);
                      }
                      
                      if(temp.left != null){
                          s1.add(temp.left);
                      }
                  }
              }
      }
	}
}