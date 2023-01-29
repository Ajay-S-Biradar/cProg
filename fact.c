#include<stdio.h>
int fact(int n){
while(n>1)
return(fact(n-1)*n);
}
int main(){
int n;
scanf("%d",&n);

int ans = fact(n);

printf("%d",ans);
return 0;
}
