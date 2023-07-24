/****************************************************************************** 
This is to certify that this project is my own & partners work, based on  
my/our personal efforts in studying and applying the concepts learned. I/we 
have constructed the functions and their respective algorithms and 
corresponding code by me (and my partner). The program was run, tested, and  
debugged by my own efforts. I further certify that I have not copied in  
part or whole or otherwise plagiarized the work of other students and/or  
persons.  
<Rein Dela Cruz> - <12206032> - <S12>  
<Frederick Garcia> - <12206970> - <S11>  
******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

/*
? Needed info about the users
* First & Last name
* ID Number
* Year & Program
* Date & Time fro Reservation
* Number of Participants
* Room to Reserved (preferred)
* Description of the Activity (short)
*/

#define MAX 9999
typedef char string20[21];
typedef char string1000[1001];


struct data{
    string20 buildingName;
    struct person{
        int ID;
        string20 firstName;
        string20 lastName;
        int year;
        string20 course;
        int max_reserve;
    }data;
    struct room{
        int roomNum;
        int roomType;
        string20 Day;
        int date; // (MMDDYY)
        string20 timeslot;
        int status;
        int capacity;
    }rooms;
    string1000 roomDesc;
};


/*
    TODO: Declare necessary variable names
*/
int Input_Form(struct data *A, int n)
{

    string20 tempfirstName, templastName, tempCourse, roomType; // Just in case they cancel whenever
    string1000 tempDesc;
    
    int tempID, tempYear, tempDate, successRT = 0, choiceRT, tempRType, successInput = 0, choiceReserve;

    printf("Input ID Number: ");
    scanf("%d",tempID); 

    printf("Input first name: ");
    gets(tempfirstName);

    printf("Input last name: ");
    gets(templastName);

    printf("Input year: ");
    scanf("%d", tempYear);

    printf("Input prgram (CS-ST18): ");
    gets(tempCourse);
    
    printf("Inpute date of reservation: (MMDDYY)");
    scanf("%d", tempDate);

    while(successRT == 0)
    {
        
        printf( "Select a room to reserve"
                "[1] Classroom (Capacity: 30)"
                "[2] Seminar Room (Capacity: 80)"
                "[3] Auditorium (Capacity: 100)"
                "[4] Training Room (Capacity: 50)");
        scanf("%d", &choiceRT);
        
        if(choiceRT >= 1 || choiceRT <= 4)
        {
           tempRType = choiceRT;
           switch (choiceRT)
           {
            case 1:
                strcpy(roomType, "Classroom");
                break;

            case 2:
                strcpy(roomType, "Seminar Room");
                break;
                
            case 3:
                strcpy(roomType, "Auditorium");
                break;

            case 4:
                strcpy(roomType, "Training Room");
                break;
           
           }
        }

        else
            printf("Invalid input, try again.");
    }

    printf("Short description for the activity: ");
    gets(tempDesc);

    printf("Are you sure you want to reserve?\t Date: %d");
    printf( "ID: %d\n"
            "Name: %s %s\n"
            "Year & Course: %d & %s\n"
            "Date: %d\n" 
            "Time: %s\n"
            "Room Type: %s\n"
            "Description: %s\n", tempID, tempfirstName, templastName, tempYear, tempCourse, tempDate, tempTime, roomType, tempDesc);
    printf( "[1] Reserve the room"
            "[2] Cancel the reservation");
    scanf("%d", choiceReserve);
    
    if(choiceReserve == 1)
    {
        successInput = 1;
        A[n].data.ID = tempID;
        strcpy(A[n].data.firstName, tempfirstName);
        strcpy(A[n].data.lastName, templastName);
        A[n].data.year = tempYear;
        strcpy(A[n].data.course, tempCourse);
        A[n].rooms.date = tempDate;
        strcpy(A[n].rooms.timeslot, tempTime);
        A[n].rooms.roomType = tempRType;
        strcpy(A[n].roomDesc, tempDesc);
        
    }

    else
    {
        printf("Canceling the reservation...");
        getch();
    }
    



    return successInput; // To add to the array of structs
}

void display_Reservations(struct data *A, int ID, int n, int d)
{
	int i, j = 1;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Reservation/s for: %s %s\n", A[d].data.firstName, A[d].data.lastName);

	for(i = 0; i < n; i++)
	{
		if(ID == A[i].data.ID)
			{
				printf(	"[%d] Timeslot: %s\n"
						"     Date and day: %s %c\n"
						"     Room: %s\n"
						"     Building: Br. Andrew Gonzalez Hall\n", j, A[i].rooms.timeslot, A[i].rooms.date, A[i].rooms.Day, A[i].rooms.roomNum); //undeclared variables
				j++;
			}
	}
	printf("[~] Cancel");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void Add_Time_Condition(struct data *A)
{
    int num_choice;
    struct data s; //temp
    //display_rooms(struct data info[]);

    printf("Select Vacant Time slot (MTHF: 1-6) (WS: 1-3)");
    scanf("%d", num_choice);
    
    if(A[num_choice].rooms.status == 0)
    {
        
        A[num_choice].rooms.status = 1;
    }
    else if(A[num_choice].rooms.status == 1)
        printf("This Time Slot is Currently unavailable");

    
    /*
        In case the activity will use more than 1.5hrs on specific days,
        they can reserve an additional time slot (must be consecutive time slot)
    */
}

int Cancel_Reservation(struct data *A, int n)
{
	int successRemove = 0, i, j, ID, arrT[2], choiceR;


	printf("Input ID: ");
	scanf("%d", &ID);

	j = 0;

	for(i = 0; i < n; i++)
	{
		if(ID == A[i].data.ID)
		{
			arrT[j] = i;
			j++
		}
	}


	display_Reservations(A, ID, n, arrT[0]);
    
	printf("Select a reservation to cancel: ");
	scanf("%d", &choiceR);

	if(choiceR >= 1 || choiceR <= 3)
	{
		for(i = arrT[choiceR - 1]; i < n; i++)
		{
			A[i].data.ID = A[i+1].data.ID;
			strcpy(A[i].data.firstName, A[i+1].data.firstName);
			strcpy(A[i].data.lastName, A[i+1].data.lastName);
			A[i].data.year = A[i+1].data.year;
			strcpy(A[i].data.course, A[i+1].data.course);
            A[i].rooms.roomNum =  A[i+1].rooms.roomNum;
            A[i].rooms.roomType =  A[i+1].rooms.roomType;
		}
	}
}

void Change_Room_Reservation()
{
    /*
        if room status == 0
    */
}

void display_rooms(struct data *A, int n, int ID, int d)
{
    int i, j = 1;
    string20 stat;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Reservation/s for: %s %s\n", A[d].data.firstName, A[d].data.lastName);

    
	for(i = 0; i < n; i++)
	{
		if(ID == A[i].data.ID)
		{
            if(A[i].rooms.status == 0)
                strcpy(stat,"Available");
            else
                strcpy(stat,"Unavailable");

            printf(	"[%d] Timeslot: %s\n"
                    "     Date and day: %s %c\n"
                    "     Room: %s\n"
                    "     Status: %s"
                    "     Building: Br. Andrew Gonzalez Hall\n", j, A[i].rooms.timeslot, A[i].rooms.date, A[i].rooms.Day, A[i].rooms.roomNum, stat); //undeclared variables
            j++;
        }
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


/*
    Program should check:
    - Conflicting date,time, timeslot
    - Max Reservations per reserver
    - Max capacity each room to be used

    Features
    - Once the program is terminated, all reservations transactions gets saved
    to a text file. On Program Start, reservations must be loaded from memory
    - Cancel Reservation
    - Change Room Reservation if the room requested is available
    - Add time if more than 1.5hrs on specific days(Add_Time_Condition)

    Bonus Pero Required pala
    - Produce a report on the room reservation per room(as text file)
    - Produce a report on the list of room reservations for a particular
    date(as text file)

*/

int main()
{
    struct data info[MAX];
    int records = 0, choiceMain, successInput, date;

    printf("Input date: (MMDDYY)");
    scanf("%d", date);
    
    system("cls");

    
    printf("What would you like to do?\t\t Date: %d\n ");
    printf( "[1] Book a reservation\n"
            "[2] Cancel a reservation\n"
            "[3] Change a reservation\n"
            "[4] Exit program", date);
    scanf("%d", choiceMain);

    switch(choiceMain)
    {
        case 1:
            successInput = Input_Form(info, records);
            if(successInput != 0)
                records += successInput;
            break;
        case 2:
            Cancel_Reservation(info, records);
            break;
        case 3:
            Change_Room_Reservation();
            break;
        default:
            printf("Thank you for using our program!");
            getch(); // Para di magexit agad
    }

    return 0;
}

