import java.util.*;
import java.lang.*;

class Node 
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}

class CreateTree
{
    static ArrayList<Integer> result = new ArrayList<Integer>();
    public static void main (String[] args) {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
              arr[i] = sc.nextInt();
              
            ConstructBinaryTreeFromParentArray gfg = new ConstructBinaryTreeFromParentArray();
            Node root = gfg.createTree(arr, n);
            
            printLevelOrder(root);
            System.out.println();
        }
    }
    
    public static void printList(Node root)
    {
        while(root != null)
        {
            System.out.print(root.data + " ");
        }
    }
    
    public static void printLevelOrder(Node root)
    {
        int h = height(root);
        int i;
         for (i=1; i<=h; i++)
        {
        result.clear();
        printGivenLevel(root, i);
        Collections.sort(result);
        for(int j=0;j<result.size();j++)
            System.out.print(result.get(j) + " ");
        }
    }
    
    public static int height(Node root)
    {
        if(root == null)
          return 0;
          
        else
    {

        int lheight = height(root.left);
        int rheight = height(root.right);


        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
    }
    
    public static void printGivenLevel(Node node, int level)
    {
        if (node == null)
             return;
    if (level == 1)
        result.add(node.data);
    else if (level > 1)
    {
        printGivenLevel(node.left, level-1);
        printGivenLevel(node.right, level-1);
    }
    }
}


class ConstructBinaryTreeFromParentArray
{
   
    public static Node createTree(int arr[], int n)
    {
        HashMap<Integer , Node>hm = new HashMap<>();
        Node root = null;
        Node temp ;
        int i;
        
        for(i=0;i<n;i++){
            
            if(hm.get(i) == null){
                
                temp = new Node(i);
                hm.put(i , temp);
            }
            
            if(arr[i] == -1){
                root = hm.get(i);
            }
            
            // not root and parent of the node is not created
            else if(hm.get(arr[i]) == null){
                temp = new Node(arr[i]);
                
                temp.left = hm.get(i);
                
                hm.put(arr[i] , temp);
            }
            
            
            else {
                
                if(hm.get(arr[i]).left == null)
                {
                    hm.get(arr[i]).left = hm.get(i);
                }
                else{
                    hm.get(arr[i]).right = hm.get(i);
                }
            }
            
        }
        
        return root;
    }
    
}

