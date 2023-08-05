#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
//Recursive Method:
int nbonacci(int n,int k)
{
    //base case
    if(k<=n)
    {
        return 1;
    }
    if(dp[n][k] != 0)
    {
        return dp[n][k];
    }
    //recursive formula:
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum += nbonacci(n,k-i);

    }
    dp[n][k] = sum;
    return sum;

}
int main()
{
int n,k;
cin>>n>>k;
cout<<nbonacci(n,k)<<endl;
return 0;

}
/*
1 1 1 1 4 7 13 25  49 94 181 349

*/