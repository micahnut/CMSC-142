#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

void findMin(int deno[],int amount, int len);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a ); 
}


int main(){
	//int deno[] = {1,3,5};
	//int deno[] = {1, 2, 5, 10, 20, 50,100,500,1000};
	//int amount = 93;
	//int amount =11;
	//int n = 3;
	int amount,n,i;
	
	printf("Enter the amount: ");
	scanf("%d", &amount);
	printf("Enter total number of currency: ");
	scanf("%d", &n);

	int deno[n];

	printf("Enter all currency values: ");
	for(i = 0; i<n; i++){
		scanf("%d",&deno[i]);
	}

	qsort(deno, n, sizeof(int), cmpfunc);

	printf("The selected currency values are: \n");
	findMin(deno,amount,n);

	return 0;
}


void findMin(int deno[], int amount, int n){
	int i=0;

	while(i<n){
		if(amount>=deno[i]){
			while(amount>= deno[i]){
				amount = amount - deno[i];
				printf("%d ",deno[i]);
			}
		}
		else{
			i++;
		}
	}
	printf("\n");


}

//time complexity: O(n) n denotes the money
