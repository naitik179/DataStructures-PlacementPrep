import java.util.Scanner;
import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
	int data;
	Node left,right;
	
	Node(int d)
	{
		data = d;
		left = right = null;		
	}
}

class BinarySearchTree
{
     static Node insert(Node node, int data)
    {
     if (node == null)
     {
            return (new Node(data));
    } else 
        {
             
            /* 2. Otherwise, recur down the tree */
            if (data <= node.data)
            {
                node.left = insert(node.left, data);
            } else 
            {
                node.right = insert(node.right, data);
            }
 
            /* return the (unchanged) node pointer */
            return node;
        }
    
    }
    
    
    
         public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node root = null;
            
            while(n-- > 0)
            {
                int data = sc.nextInt();
                root = insert(root, data);
            }
            
            int old_key = sc.nextInt();
            int new_key = sc.nextInt();
            ChangeKey gfg = new ChangeKey();
             
            root =  gfg.changeKey(root, old_key, new_key);
             inorder(root);
             System.out.println();
        }
    }
    
  static void inorder(Node root)
    {
        if(root != null)
         {
        inorder(root.left);
		System.out.print(root.data + " ");
		inorder(root.right);
         }
    }
    

}

class ChangeKey
{
    
    
    List<Integer> list=new ArrayList<>();
    Node changeKey(Node root, int old_key, int new_key)
    {
       inorder(root,list);
       //System.out.println(list);
      int index=list.indexOf(old_key);
       list.add(index,new_key);
      Collections.sort(list);
      int index1=list.indexOf(old_key);
      list.remove(index1);
     
       BinarySearchTree bst=new BinarySearchTree();
       Node node=new Node(list.get(0));
       for(int i=1;i<list.size();i++)
       bst.insert(node,list.get(i));
       
       return node;
    }
    void inorder(Node root,List<Integer>list)
    {
        if(root==null)
          return;
        inorder(root.left,list);
        list.add(root.data);
        inorder(root.right,list);
    }
   
}