class DetectCycle
{
    
    static boolean iscyclic(int i, boolean[] visited,boolean[] instack , ArrayList<ArrayList<Integer>> adj )
    {
        
        if(instack[i] == true){
            return true;
        }
        if(visited[i] == true){
            return false;
        }
        
        visited[i] = true;
        instack[i] = true;
        
        
        List<Integer> children = adj.get(i);
        
        for (Integer c: children)
            if (iscyclic(c, visited, instack , adj))
                return true;
                
        instack[i] = false;
    
        return false;
        
    }
    static boolean isCyclic(ArrayList<ArrayList<Integer>> adj, int V)
    {
        // add your code here
        
        boolean[] visited = new boolean[V];
        boolean[] instack = new boolean[V];
    
        for(int i=0;i<V;i++){
            visited[i] = false;
            instack[i] = false;
        }
    
        for(int i=0;i<V;i++){
             if(iscyclic(i , visited , instack , adj)){
                 return true;
             }
        }
    
        return false;
    }
}
