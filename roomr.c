#include <stdio.h>
#include <string.h>

#define MAX 150
typedef char string50[51];
typedef char string501[501];


struct info{
    int ID;
    string50 first;
    string50 last;
    int year;
    string50 program;
    int month;	// Placeholder
    int date; 	// Placeholder
    int time;
    int nParticipants;
    string50 roomName;
    string501 desc;
    
    
    
};


int inputData(struct info *A, int n)
{
	int i, tempID;
	char choice;
	
	
	printf("Input ID Number (122XXXXX): ");
	scanf("%d", &tempID);
	
	for(i = 0; i < n; i++) // Check if they reserved rooms already
	{
		if(A[i].ID == tempID)
			dupe++;
	}
	
	if(dupe >= 3)
	{
		printf("\nYou've reserved the max amount of rooms.\n");
	}
	
	else
	{
		
	}
	
		
		
	
	
	
	
	printf(	"\nWould you like to reserve a room again?\n"
			"\tY/N\n");
	scanf("%c", choice);
	if(choice == 'Y' || choice == 'y')
		return 2;
	else
		return 1;
	

}


int main()
{
	struct info data[MAX];
	
	
	while(success == 2)
	{
		// success = inputData(struct info *A, int n);
	}
	
	




return 0;
}
