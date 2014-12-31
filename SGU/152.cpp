#include<stdio.h>
const int MAXN=10000+9;
int a[MAXN],ans[MAXN];

int main(){
	#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        freopen("output.txt","w",stdout);
	#endif
        int n,i,sum=0;
        scanf("%d",&n);
        for(i=0;i<n;++i){
                scanf("%d",a+i);
                sum+=a[i];
        }
        int t=0;
        for(i=0;i<n;++i){
                t+=a[i]*100%sum;
                a[i]=a[i]*100/sum;
                if(t>=sum)
                        ++a[i],t-=sum;
        }
        for(i=0;i<n-1;++i)
                printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
        return 0;
}