// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

struct box{
    int area;
    int l;
    int h;
    int w;
    box(int A=0,int H=0,int n1=0,int n2=0)
    {
        area=A;
        h=H;
        l=n1;
        w=n2;
    };
};

bool comparator(struct box a,struct box b)
{
    return a.area>b.area;
}

bool comp(struct box a,struct box b)
{
    if(a.area>b.area&&((a.l>b.l&&a.w>b.w)||(a.w>b.l&&a.l>b.w)))
        return true;
    return false;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    struct box *a=new struct box[3*n];
    for(int i=0;i<n;i++)
    {
        //one orientation
        a[3*i].h=height[i];
        a[3*i].w=width[i];
        a[3*i].l=length[i];
        a[3*i].area=width[i]*length[i];
        // 2nd
        a[3*i+1].h=width[i];
        a[3*i+1].w=height[i];
        a[3*i+1].l=length[i];
        a[3*i+1].area=height[i]*length[i];
        ///3rd
        a[3*i+2].h=length[i];
        a[3*i+2].w=width[i];
        a[3*i+2].l=height[i];
        a[3*i+2].area=height[i]*width[i];
    }
    sort(a,a+3*n,comparator);
    
    int *dp=new int[3*n];
    int ans=0;
    for(int i=0;i<3*n;i++)
    {
        dp[i]=a[i].h;
        for(int j=0;j<i;j++)
        {
            if(comp(a[j],a[i])&&dp[i]<dp[j]+a[i].h)
                dp[i]=dp[j]+a[i].h;
        }
        if(dp[i]>ans)
            ans=dp[i];
    }
    delete[] dp;
    delete[] a;
    return ans;
}