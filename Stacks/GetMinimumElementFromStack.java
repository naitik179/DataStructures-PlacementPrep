// { Driver Code Starts
import java.util.*;



class Get_Min_From_Stack
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T>0)
		{
			int q = sc.nextInt();
			GfG g = new GfG();
			while(q>0)
			{
				int qt = sc.nextInt();
				
				if(qt == 1)
				{
					int att = sc.nextInt();
					g.push(att);
					//System.out.println(att);
				}
				else if(qt == 2)
				{
					System.out.print(g.pop()+" ");
				}
				else if(qt == 3)
				{
					System.out.print(g.getMin()+" ");
				}
			
			q--;
			}
			System.out.println();
		T--;
		}
		
	}
}


class GfG
{
    int minEle;
    Stack<Integer> s = new Stack<>();

    /*returns min element from stack*/
    int getMin()
    {
        if(s.isEmpty())
        {
            return -1;
        }
        else{
            return minEle;    
        }
	    
    }
    
    /*returns poped element from stack*/
    int pop()
    {
        if(s.empty()){
            return -1;
        }
	    int top = s.peek();
	    if(top <= minEle){
	        int top1 = minEle;
	        top = s.pop();
	        minEle = 2*minEle - top;
	        
	        return top1;
	    }
	    else{
	        s.pop();
	        return top;
	    }
    }

    /*push element x into the stack*/
    void push(int x)
    {
        if(s.empty()){
            s.push(x);	
            minEle = x;
        }
        else if(x >= minEle){
            s.push(x);
        }
            
        else{
            s.push(2*x - minEle);
            minEle = x;
        }
    }	
}

