import java.util.*;
import java.lang.*;
import java.io.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t =sc.nextInt();
        while(t-- > 0)
        {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int nov = sc.nextInt();
            int edg  =sc.nextInt();
            for(int i = 0; i < nov; i++)
                list.add(i, new ArrayList<Integer>());
                
            for(int i = 1; i <= edg; i++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            
            ArrayList<Integer> res = new Traversal().dfs(list, nov);
            for (int i = 0; i < res.size (); i++) 
                System.out.print (res.get(i) + " ");
            System.out.println();
        }
    }
}

class Traversal
{
    static ArrayList<Integer> ans = new ArrayList<Integer>();
    static ArrayList<Integer> DFSUtil(int v,boolean visited[] ,ArrayList<ArrayList<Integer>> g)
    {
        // Mark the current node as visited and print it
        visited[v] = true;
        ans.add(v);

        // Recur for all the vertices adjacent to this vertex
        Iterator i = g.get(v).listIterator();
        while (i.hasNext())
        {
            int n = (int)i.next();
            if (!visited[n])
                DFSUtil(n, visited , g);
        }
        return ans;
    }
    static ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> g, int N)
    {
       // add your code herea
       ans.clear();
       boolean visited[] = new boolean[N];
       return DFSUtil(0 , visited , g);
    }
}

