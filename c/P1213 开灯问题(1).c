#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int a[1000],i,j;
        for(i=0;i<n;i++)
        a[i]=0;
        for(i=1;i<=k;i++)
        {
            for(j=0;j<n;j++)
            {
                if((j+1)%i==0)
                a[j]=!a[j];
            }
        }
        for(i=0;i<n;i++)
        if(a[i]==0)
        printf("%d ",i+1);
        printf("\n");
    }
}