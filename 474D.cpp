 #include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MOD=1000000007;
int a[100000+10],i,k,t,x,y,ans;

main()
{
 scanf("%d%d",&t,&k);
 for ( i=0;i<k;i++ )
  a[i]=1;
 for ( i=k;i<=100000;i++ )
  a[i]=(a[i-1]+a[i-k])%MOD;
 for ( i=1;i<=100000;i++ )
  {
   a[i]+=a[i-1];
   a[i]%=MOD;
  }
 while ( t-- )
  {
   scanf("%d%d",&x,&y);
   ans=a[y]-a[x-1];
   if ( ans<0 ) ans+=MOD;
   printf("%d\n",ans);
  }
}
