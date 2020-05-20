#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}

int maxHist(int row[],int C) 
{ 
    stack<int> result; 
  
    int top_val; 
    int max_area = 0; 
    int area = 0; 
  
    int i = 0; 
    while (i < C) { 
       
        if (result.empty() || row[result.top()] <= row[i]) 
            result.push(i++); 
  
        else { 
            top_val = row[result.top()]; 
            result.pop(); 
            area = top_val * i; 
  
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
            max_area = max(area, max_area); 
        } 
    } 
  
    while (!result.empty()) { 
        top_val = row[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
} 

int maxArea(int A[MAX][MAX], int n, int m) {
  
    int result = maxHist(A[0],m); 
  
    for (int i = 1; i < n; i++) { 
  
        for (int j = 0; j < m; j++) 
  
            if (A[i][j]) 
                A[i][j] += A[i - 1][j]; 
  
        result = max(result, maxHist(A[i] , m)); 
    } 
  
    return result; 
}
