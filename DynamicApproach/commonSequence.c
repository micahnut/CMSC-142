
#include<stdio.h>
#include<string.h>
#define MAX_LEN 128


void print_image(FILE *fptr);

void findLCSSubStr(char *X, char *Y, int XLen, int YLen);

char x[20];
char y[20];
int s,t,xLen,yLen;

int max(int a, int b) {
	return (a > b)? a : b;
}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}


void findLCSSubStr(char *X, char *Y, int XLen, int YLen) {
	//table for storing lengths of longest common
	int L[XLen + 1][YLen + 1];
	int r, c, len;
	
	//r = row
	// c = col
	
	// find the length of the LCS 
	for(r = 0; r <= XLen; r++) {

		for(c = 0; c <= YLen; c++) {

			if(r == 0 || c == 0) {
				L[r][c] = 0;
			} else if(X[r - 1] == Y[c - 1]) {
				L[r][c] = L[r - 1][c - 1] + 1;
			} else {
				L[r][c] = max(L[r - 1][c], L[r][c - 1]);
			}
		}
	}


	r = XLen;
	c = YLen;
	len = L[r][c]; //store the length of longest common substring 

	char LCS[len+1]; //for printing 

	LCS[len] = '\0'; //to know the string has ended

	while(r > 0 && c > 0) {
		if(X[r - 1] == Y[c - 1]) {

			LCS[len - 1] = X[r - 1];

			len--;
			r--;
			c--;
		} else if(L[r - 1][c] > L[r][c - 1]) {
			r--;
		} else {
			c--;
		}

	}

	//print result
	printf("Length of the longest common subsequence: %d\n", L[XLen][YLen]);
	printf("Longest Common Subsequence: %s\n", LCS);
}

void findlcs(){
		
		    //length of the sequences
			xLen = strlen(x);
			yLen = strlen(y);
			int length;
			int result[xLen + 1][yLen + 1];
			
			// find the length of the LCS 
			for(s = 0; s <= xLen; s++) {
		
				for(t = 0; t <= yLen; t++) {
		
					if(s == 0 || t == 0) {
						result[s][t] = 0;
					} else if(x[s - 1] == y[t - 1]) {
						result[s][t] = result[s - 1][t - 1] + 1;
					} else {
						result[s][t] = max(result[s - 1][t], result[s][t - 1]);
					}
				}
			}
			
	
	s = xLen;
	t = yLen;
	length = result[s][t]; //store the length of longest common substring 

	char LCS2[length+1]; //for printing 

	LCS2[length] = '\0'; //to know the string has ended

	while(s > 0 && t > 0) {
		if(x[s - 1] == y[t - 1]) {

			LCS2[length - 1] = x[s - 1];

			length--;
			s--;
			t--;
		} else if(result[s - 1][t] > result[s][t - 1]) {
			s--;
		} else {
			t--;
		}

	}
	
	//print result
	printf("Length of the longest common subsequence: %d\n", result[xLen][yLen]);
	printf("Longest Common Subsequence: %s\n", LCS2);		
			
}

int main(void) {
	
	char *filename = "LCS.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
	
	int choice;
    printf("\t Menu\n");
    printf("\t1. Generate a LCS problem\n");
    printf("\t2. User Input\n");
    printf("\t3. Exit\n");
	
	
	
	do{
    	printf("\n Enter choice: ");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1: 
    		printf("This is an example of a Longest Common Subsequence problem:\n");
    		
    		
			
			//the two sequences
			char X[] = "GATCA";
			char Y[] = "GACCA";
		
			//length of the sequences
			int XLen = strlen(X);
			int YLen = strlen(Y);
			
			printf("\nFirst sequence: %s", X);
			printf("\nSecond sequence: %s\n", Y);
					
			findLCSSubStr(X, Y, XLen, YLen);
			
    		
    		printf("\n");
    		break;
    		
    		case 2:
    			printf("Please enter the sequences \n");
    			
	    		printf("\nEnter First Sequence: ");
	    		scanf("%s", &x);
	    		fflush(stdin);
	    		
				printf("\nEnter Second Sequence: ");
				scanf("%s",&y);
				fflush(stdin); 
				
				printf("\n");
				findlcs();
				
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
