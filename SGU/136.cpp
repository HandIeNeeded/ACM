#include<stdio.h>
#include<math.h>

const int N=10000+9;
const double EPS=1e-6;

double x[N],y[N],ax[N],ay[N];
int main(){
       int n,i;
       scanf("%d",&n);
       for(i=1;i<=n;++i)
              scanf("%lf%lf",x+i,y+i);
       if(n&1){
              for(i=1;i<=n;++i)
                     if(i&1)
                            ax[1]+=x[i],ay[1]+=y[i];
                     else ax[1]-=x[i],ay[1]-=y[i];
              for(i=1;i<n;++i){
                     ax[i+1]=x[i]*2-ax[i];
                     ay[i+1]=y[i]*2-ay[i];
              }
       }
       else{
              ax[1]=-1.0,ay[1]=1.0;
              for(i=1;i<=n;++i){
                     ax[i+1]=x[i]*2-ax[i];
                     ay[i+1]=y[i]*2-ay[i];
              }
              if(ax[1]!=ax[n+1] || ay[1]!=ay[n+1]){
                     puts("NO");
                     return 0;
              }
       }
       puts("YES");
       for(i=1;i<=n;++i)
              printf("%.3lf %.3lf\n",ax[i],ay[i]);
       return 0;
}//解方程组，奇偶性讨论