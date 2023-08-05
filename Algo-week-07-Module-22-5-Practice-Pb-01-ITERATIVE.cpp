#include<bits/stdc++.h>
using namespace std;
int nbonacci(int n,int k)
{
    int dp[k+1];
    //Initialize first n to 1
    for(int i =0;i<n;i++)
    {
        dp[i] = 1;
    }
    //calculate the remaining number by adding the previous n number:
    for(int i=n;i<=k;i++)
    {
        dp[i] = 0;
        for(int j=1;j<=n;j++)
        {
            dp[i] += dp[i-j];
        }
    }
    return dp[k];
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<nbonacci(n,k)<<endl;
}
/*
4 8
 
 out: 25
 
*/