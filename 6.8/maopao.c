#include <stdio.h>
int num,i,j,n;
int flag=0;
int main(){
	int a[10]={2,6,3,4,8,5,9,0,1,7};
for(i=0;i<9;i++){
	for(j=0;j<9-i;j++){
		if(a[j]>a[j+1]){
			a[j]=a[j]+a[j+1];
			a[j+1]=a[j]-a[j+1];
			a[j]=a[j]-a[j+1];
			flag=1;
}
}
}
for(n=0;n<10;n++){
printf("%d",a[n]);
}
printf("\n");
return 0;
}
