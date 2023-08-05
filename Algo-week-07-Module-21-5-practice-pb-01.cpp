/*


#include<bits/stdc++.h>
using namespace std;

int tri(int n)
{
    if(n==1 || n==3 || n==2 )
    return 1;
    else
    return tri(n-1) + tri(n-2) + tri(n-3);
}
int main()
{
    int n;
    cin>>n;
    cout<<tri(n)<<endl;
    return 0;

}
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=1,b=1,c=1,t;
    if(n==0 || n==1 || n==2)
    return 1;
    else
    {
        for(int i=3;i<=n;i++)
        {
            t = a+ b+c;
            a=b;
            b=c;
            c=t;
        }
        return c;
    }
}