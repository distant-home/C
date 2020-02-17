#include <stdio.h>
#include <math.h>
int main()
{
	void dotree(int *ap,int *bp,int a,int *b,int m,int n);
	int n,m=0;
	scanf("%d",&n);	
	int N=pow(2,n);
	int a[n],b[N];
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	dotree(a,b,a[0],&b[0],m,n);
	
	printf("%d ",a[0]);
	for(int i=1;i<N;i++) if(b[N]!=a[0]) printf("%d ",b[i]);
}

void dotree(int *ap,int *bp,int a,int *b,int m,int n)
{
	m=2*m;
	*b=a;
	int i;
	for(i=1;i<n;i++)
	{
		if(*(ap+i) < *(ap+i-1)) dotree(ap,bp,*(ap+i),&b[m+1],m,n);
		else if(*(ap+i) > *(ap+i-1)) dotree(ap,bp,*(ap+i),&b[m+2],m,n);
	}
}
