#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_LEN 128


void print_image(FILE *fptr);

int dynamic(int deno[],int amount, int len);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a ); 
}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}


int main(){
	//int deno[] = {1,3,5};
	//int deno[] = {1, 2, 5, 10, 20, 50,100,500,1000};
	//int amount = 93;
	//int amount =11;
	//int n = 3;
	
	char *filename = "coinchange.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
	
	int amount,n,i,result;
	
	printf("Enter the amount: ");
	scanf("%d", &amount);
	printf("Enter total number of currency: ");
	scanf("%d", &n);

	int deno[n];

	printf("Enter all currenct values: ");
	for(i = 0; i<n; i++){
		scanf("%d",&deno[i]);
	}

	//qsort(deno, n, sizeof(int), cmpfunc);

	printf("The number of ways you can represent %d is", amount);
	result = dynamic(deno,amount,n);
	printf(" %d", result);

	fclose(fptr);
	return 0;
}


int dynamic(int deno[], int amount, int n){
	int i=0, j;
	
	int solution[n+1][amount+1];
	
	
	solution[0][0]=1;
	
	for(i=1;i<=amount;i++){
		solution[0][i] = 0;
	}
	
	  
    for(i=1; i<=n; i++) 
        for(j=0; j<=amount; j++) {
        	if(j<deno[i-1]){
        		solution[i][j] = solution[i-1][j];
			}
        	else{
        		solution[i][j] = solution[i][j-deno[i-1]] + solution[i-1][j];
        		//printf("solution: %d", solution[i][j]);
        	}
        	//printf("solution: %d \n", solution[i][j]);
		}
             
 	//coinSet(deno,solution,amount); 
 	//print(deno, j);
    return solution[n][amount]; 
    
    
	printf("\n");


}




