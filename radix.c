#include<stdio.h> 
#include<stdlib.h>
int getmax(int arr[],int size){
	int max = arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>max)
			max =arr[i];
	}
	return max;
}

void countsort(int arr[],int size,int div){
	int output[size];
	int count[10] = {0};
	
	for(int i=0;i<size;i++)
		count[(arr[i]/div)%10]++;
	for(int i=1;i<10;i++)
		count[i]+= count[i-1];
	for(int i=size-1;i>=0;i--){
		output[count[(arr[i]/div)%10] -1] = arr[i];
		count[(arr[i]/div)%10]--;
	}
	for(int i=0;i<size;i++)
		arr[i] = output[i];
	
}

void radixsort(int arr[],int size){
	int m= getmax(arr,size);
	for(int div=1;m/div >0;div=div*10){
		countsort(arr,size,div);
	}
}

int main(){

int arr[] = {234,456,345,45,78,8,90,14};
int n = 8;
int count = 0;
radixsort(arr,n);
for(int i=0;i<n;i++){
	printf("%d ",arr[i]) ;
}
}
