#include <bits/stdc++.h> 
using namespace std; 

void numbersWith3Divisors(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    prime[0] = prime[1] = 0; 

    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
        // Update all multiples of p 
        for (int i=p*2; i<=n; i += p) 
            prime[i] = false; 
        } 
    } 

    // print squares of primes upto n. 
    cout << "Numbers with 3 divisors :\n"; 
    for (int i=0; i*i <= n ; i++) 
        if (prime[i]) 
        cout << i*i << " "; 
} 

int main() 
{ 
    // sieve(); 
    int n = 96; 
    numbersWith3Divisors(n); 

    return 0; 
} 
