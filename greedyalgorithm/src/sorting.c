#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int arr1[10];

void SelectionSort(int arr1[], FILE *,int size);
void timestamp();

int main(){
		

	int i,m,s;
	FILE *ifp, *fwrite1;

	ifp = fopen("numbers.dat", "r");
	fwrite1 = fopen("mselection.out", "w");

	 if( ifp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }


    for(i=0;(fscanf(ifp, "%d ",&m)==1);i++){
    	arr1[i]=m;
		printf("%d ",m);
	}
		
		//printf("in");
		printf("\n");
		timestamp();
		SelectionSort(arr1,fwrite1,i);
		
    fclose(ifp);
    fclose(fwrite1);
	return 0;
}


void SelectionSort(int arr1[],  FILE *fwrite1, int size){
	int locate;
	int i,j,temp,z,smallIn;
	int min;
	//int size=10;

	for(i=0;i<size;i++){
        min = arr1[i]; 
		for(j=i;j<size;j++){
			if(min >= arr1[j]){
				min = arr1[j];
				locate = j;
			}
		}

			if(i != locate)
            {
                temp=arr1[i];
                arr1[i]= min;
				arr1[locate]= temp;
            }

	}

	for(i = 0; i < size; i++){
        fprintf(fwrite1,"%d ", arr1[i]);
  		printf("%d ", arr1[i]);
  	}
  	printf("\n");
    timestamp();
}


void timestamp(){
    time_t ltime;
    ltime=time(NULL); 
    printf("%s",asctime( localtime(&ltime) ) );
}

//time complexity: O(n^2)