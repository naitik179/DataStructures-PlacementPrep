int Solution::solve(int A) {
    
    int c=0;
    if(A == 0)
    {
    return 0;
    }
    while(A > 0)
    {
    if(A % 2==0)
    {
    c++;
    A = A/2;
    }
    else
    {
    break;
    }
    }
    return c;
}
