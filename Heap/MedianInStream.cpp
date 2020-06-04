#include <bits/stdc++.h>
using namespace std;

class FindMedian
{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		double median; //Stores current median
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		void balanceHeaps(); //Method used by insertHeap
};

// Function to insert heap
void FindMedian::insertHeap(int &x)
{
	// Your code here
	if(max.size() == 0){
	    max.push(x);
	    median = x;
	    return;
	}
	if(max.size() > min.size()){
	    if(x < max.top()){
	        min.push(max.top());
	        max.pop();
	        max.push(x);
	    }
	    else{
	        min.push(x);
	    }
	    
	    median = (max.top() + min.top())/2;
	}
	else
       {
           if(x<=max.top())
             max.push(x);
           else
            {
            	// **** order of sequence is importanr 1 push in the min then push the max element from the max heap plus pop ***
                min.push(x);
                max.push(min.top());
                min.pop();
            }
            median=max.top();
       }
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
	// Your code here
	return ;
}

// Function to return getMedian
double FindMedian::getMedian()
{
	// Your code here
	return median;
}

int main()
{
    int n, x;
	FindMedian Ans;
	cin >> n;
	for(int i = 1;i<= n; ++i)
	{
		cin >> x;
		Ans.insertHeap(x);
	    cout << floor(Ans.getMedian()) << endl;
	}
	// }
	return 0;
} 