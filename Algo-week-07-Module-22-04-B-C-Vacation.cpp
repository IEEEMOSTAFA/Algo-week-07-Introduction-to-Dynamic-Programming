/*
https://atcoder.jp/contests/dp/tasks/dp_c
Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of 
N days. For each 
i (
1≤i≤N), Taro will choose one of the following activities and do it on the 
i-th day:

A: Swim in the sea. Gain 
a 
i
​
  points of happiness.
B: Catch bugs in the mountains. Gain 
b 
i
​
  points of happiness.
C: Do homework at home. Gain 
c 
i
​
  points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1≤N≤10 
5
 
1≤a 
i
​
 ,b 
i
​
 ,c 
i
​
 ≤10 
4
 


-state: fun(n,x)  -> maximum happiness till day-n
                     if we pick task-x on day -n

  -recurance : fun(n,x) = max{
                           fun(n-1,y) where x! = y
                           + happiness[n][x]
  }                   
  -base case : fun(1,x) = happiness[n][x]



*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int happiness[N][4],dp[N][4];
int fun(int day,int current_task)
{
  //1.handle base case
  if(day == 1)
  {
    return happiness[day][current_task];
  }
  //2.if answer is already calculated return it
  if(dp[day][current_task] != -1)
  {
    return dp[day][current_task];
  }
  int max_profit = 0;
  //3.calculate the answer from smaller sub problems
  for(int last_task = 1;last_task <= 3;last_task++)
  {
    if(last_task != current_task)
    {
        int candidate_profit = fun(day - 1,last_task ) + happiness[day][current_task];
        max_profit = max(max_profit,candidate_profit);
    }
  }
  dp[day][current_task] = max_profit;
  return max_profit;

}
int main()
{
    int n; 
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        // int a,b,c;
        // cin>>a>>b>>c;
        // happiness[i][1] = a;
        // happiness[i][2] = b;
        // happiness[i][3] = c;
        //2 ta way te kora jai:::
        for(int j=1;j<=3;j++)
        {
            cin>>happiness[i][j];

        }



    }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=3;j++)
        {
            dp[i][j] = -1;
        }
      }
      int ans_1 = fun(n,1);
      int ans_2 = fun(n,2);
      int ans_3 = fun(n,3);
      cout << max({ans_1,ans_2,ans_3})<<endl;
      return 0;

}
/*
3
10 40 70
20 50 80
30 60 90
 out-210

1
100 10 1
out =100

7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1

out->46


*/