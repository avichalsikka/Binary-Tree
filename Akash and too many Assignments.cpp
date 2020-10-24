    #include <bits/stdc++.h>
#define ll  int
#define N 1000000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Sawlani
  *
  */
 int main()
 {
   int n;
   cin >>  n;
   int a[n+1][n+1];
   f(i,1,n)
   {
       f(j,1,n)
       {
           cin >> a[i][j];

       }
   }
   if(n==1)
   {
       cout << a[1][1] << endl;
       return 0;
   }
   if(n==2)
   {

       cout << a[1][1] << " "  <<  a[1][2] <<  " " <<  a[2][2] << " " << a[2][1] << endl;
       return 0;
   }
    bool vis[n+1][n+1]={false};
    int x=1,y=1;
    bool rowr=true,rowl=false,columnu=false,columnd=false;
    int t1,t2;
    int cnt=0;
    while(true)
    {
        cnt++;
          vis[x][y]=true;
        cout <<  a[x][y] << " ";
        if(rowr)
        {
            t1=y+1;
            if(t1>n)
            {
                rowr=false;
                columnd=true;
                if(x+1<=n)
                    x+=1;

            }
            if(t1<=n&&!vis[x][t1])
            {
                y=t1;
            }
            if(t1<=n&&vis[x][t1])
            {
                rowr=false;
                columnd=true;
               if(x+1<=n&&!vis[x+1][y])
               {
                x+=1;
               }
               else
               {
                break;
               }
            }
        }
         else if(columnd)
        {
            t1=x+1;
            if(t1>n)
            {
                columnd=false;
                rowl=true;
                if(y-1>=1)
                    y-=1;

            }
            if(t1<=n&&!vis[t1][x])
            {
                x=t1;
            }
            if(t1<=n&&vis[x][t1])
            {
                columnd=false;
                rowl=true;
               if(y-1>=1&&!vis[x][y-1])
               {
                y-=1;
               }
               else
              {
               break;
              }
            }
        }
         else if(rowl)
        {
            t1=y-1;
            if(t1==0)
            {
                rowl=false;
                columnu=true;
                if(x-1>=1)
                    x-=1;

            }
            if(t1>=1&&!vis[x][t1])
            {
                y=t1;
            }
            if(t1<=n&&vis[x][t1])
            {
                rowl=false;
                columnu=true;
              if(x-1>=1&&!vis[x-1][y])
               {
                x-=1;
               }
                else
              {
               break;
              }
            }
        }
        else if(columnu)
        {
            t1=x-1;
            if(t1==0)
            {
                columnu=false;
                rowr=true;
                if(y+1<=n)
                    y+=1;

            }
            if(t1>=1&&!vis[t1][x])
            {
                x=t1;
            }
            if(t1>=1&&vis[x][t1])
            {
                rowr=true;
                columnu=false;
              if(y+1<=n&&!vis[x][y+1])
               {
                y+=1;
               }
                else
              {
               break;
              }
            }
        }
    }
 }
