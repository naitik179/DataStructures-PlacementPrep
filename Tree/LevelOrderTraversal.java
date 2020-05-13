import java.util.*;
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

public class LevelOrderTraversal {
    
	Node root; 

	LevelOrderTraversal() 
	{ 
		root = null; 
    } 

    int height(Node node){

        int ans ;
        if(node == null){
            return 0;
        }
        else{

            int l = height(node.left);
            int r = height(node.right);

            ans = Math.max(l,r) +1;
        }

        return ans;
    }

    public void printthislevel(Node node , int level){

        if(node == null){
            return ;
        }

        if(level == 1){
            System.out.print(node.data + " ");
        }

        else if(level > 1){

            printthislevel(node.left, level-1);
            printthislevel(node.right, level -1);
        }
    }
    

        void printlevelorder(Node node){

        int h = height(node);


        for(int i=1;i<=h;i++){
            printthislevel(node, i);
        }
    }

    public static void main(String args[]) 
    { 
       LevelOrderTraversal tree = new LevelOrderTraversal(); 
       tree.root= new Node(1); 
       tree.root.left= new Node(2); 
       tree.root.right= new Node(3); 
       tree.root.left.left= new Node(4); 
       tree.root.left.right= new Node(5); 
         
       System.out.println("Level order traversal of binary tree is "); 
       tree.printlevelorder(tree.root); 
    } 

}
