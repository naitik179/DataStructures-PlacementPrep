/*


Remove duplicate elements from sorted Array
Given a sorted array A of size N. The function remove_duplicate takes two arguments . The first argument is the sorted array A[ ] and the second argument is 'N' the size of the array and returns the size of the new converted array A[ ] with no duplicate element.


*/

int remove_duplicate(int A[],int N)
{
    int i=0;
    int flen=N;
    int j=1;
    for(int i=1;i<N;i++)
    {
        if(A[i] == A[i-1])
        {
            continue;
        }
        else{
            A[j]=A[i];
            j++;
        }
    }
    return j;
}