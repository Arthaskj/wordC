#include <stdio.h>
  char fun(char tmp){
if(tmp<='Z'&&tmp>='A'){
	tmp=tmp+32;
}
else if(tmp>'Z'){
	tmp=tmp-32;
}

return tmp;
}

  int main(){
	char tmp;
	char num ;
printf("请输入一个字母：");
scanf("%c",&tmp);
num=fun(tmp);
printf("%c\n",num);
return 0;

}
