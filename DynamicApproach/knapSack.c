
/*Backpacing Problem - Given a set of objects S (each object with corresponding sizes and values), 
and a maximum size m, Find the set A, such that A?S, and the total size of the objects in A is less than or equal to m.*/


#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 128

void print_image(FILE *fptr);

int max(int a, int b) { 
		return (a > b)? a : b; 
}
		
int matrix[100][100] = {0};
int pickedItems[100][100] = {0};

// Returns the maximum value that can be put in a knapsack capacity 
int knapSack(int capacity, int nItems, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++){
        for (j=0;j<=capacity;j++){
            if (weights[i-1]<=j){
            	
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                
				if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                    pickedItems[i][j]=1;
                else
                    pickedItems[i][j]=-1;
            }
            else{
               	pickedItems[i][j] = -1;
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][capacity];

}

void printPickedItems(int nItems, int capacity, int weights[]){

    while (nItems>0){
        if (pickedItems[nItems][capacity]==1){
            printf("%d ",nItems-1);
            nItems--;
			capacity = capacity - weights[nItems];
        }
        else{
            nItems--;
        }
    }

}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

int input();
int main(){
	
	char *filename = "text.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
 	
 	int choice;
    printf("\t Menu\n");
    printf("\t1. Generate predefined weight and value\n");
    printf("\t2. User Input\n");
    printf("\t3. Exit\n");

	int predknapsackCap = 50;
    int predweights[] = {10, 20, 30};
   	int predvalues[] = {60, 100, 120};
    //0-1
    int prednItems = 3;
    
    int nItems;
    int weights[nItems];
    int values[nItems];
    int knapsackCap;
	int i;
	int items;
    		
    do{
    	printf("\n Enter choice: ");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1: 
    		printf("This is an example of the knapsack problem:\n");
    		printf("\nItem No.\t Weight \t Value");
  		    items = prednItems;
   			int i=0;
    	
			while(items!=0){
    			printf("\n%d  \t\t %d  \t\t %d", i, predweights[i], predvalues[i]);
    			items--;
    			i++;
			}
			
			printf("\n\nKnapsack Capacity: %d",predknapsackCap);
    		printf("\nMax value = %d", knapSack(predknapsackCap, prednItems,predweights,predvalues));
    		printf("\nItem Picks were: ");
    		printPickedItems(prednItems,predknapsackCap, predweights);
    		printf("\n");
    		break;
    		
    		case 2:
    		printf("\nEnter Knapsack Capacity:\n");
    		scanf("%d", &knapsackCap);
    		fflush(stdin);
    		
			printf("\nEnter the no. of items: ");
			scanf("%d",&nItems);
			fflush(stdin); 
			
			for(i=0;i<nItems;i++){
				printf("Enter the weight of Item no:%d: ",i);
				scanf("%d",&weights[i]);
			}
			for(i=0;i<nItems;i++){
				printf("Enter the value of Item no:%d: ",i);
				scanf("%d",&values[i]);
			}
			
			printf("\nItem No.\t Weight \t Value");
  		    items= nItems;
   			i=0;
    	
			while(items!=0){
    			printf("\n%d  \t\t %d  \t\t %d", i, weights[i], values[i]);
    			items--;
    			i++;
			}
			
				
			printf("\n\nKnapsack Capacity: %d",knapsackCap);
		    printf("\nMax value = %d", knapSack(knapsackCap, nItems,weights,values));
		    printf("\nItem Picks were: ");
		    printPickedItems(nItems,knapsackCap, weights);
		    printf("\n");
		    break;
		    
		    case 3:
		    	printf("Exit.\n");
		    	break;
		    default:
				printf("Please choose from the menu\n");	
		}
		
    }while(choice!=3);

	
	fclose(fptr);
    return 0;
}
