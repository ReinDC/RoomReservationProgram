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
#include "dataValidation.h"

#define MAX 9999
typedef char string20[21];
typedef char string1000[1001];

struct data{
    struct person{
        int ID;
        string20 firstName;
        string20 lastName;
        int year;
        string20 course;
        int max_reserve;
    }data;
    string1000 roomDesc;
    string20 Day;
};

struct room{
    int roomNum;
    int roomType;
    int date; 
    string20 timeslot;
    int status;
    int capacity;
};

void initializeRooms(struct Room *A, int numRooms)
{
    char roomNames[][10] = {"Y0101", "Y0102", "Y0103", "Y0104", "Y0105", "Y0106", "Y0101", "Y0101", "Y0101", "Y0101"};
    char roomTypes[][20] = {"classroom", "classroom", "classroom", "classroom", "classroom", "classroom", "seminar room", "seminar room", "training room", "auditorium"};
    int roomCapacities[] = {30, 30, 30, 30, 30, 30, 80, 80, 100, 150};

    for (int i = 0; i < numRooms; i++) {
        strcpy(rooms[i].name, roomNames[i]);
        strcpy(rooms[i].type, roomTypes[i]);
        rooms[i].capacity = roomCapacities[i];
        rooms[i].status = 1;
    }
}




/**************************************************************************
    Description : Function for inputting credentials and reservation

    @param :  struct data *A, struct room *B,int n
    @return :  successInput
***************************************************************************/
int Input_Form(struct data *A, struct room *B,int n)//STATUS: 
{

    string20 tempfirstName, templastName, tempCourse, roomType; // Just in case they cancel whenever
    string1000 tempDesc;
    
    int tempID, tempYear, tempDate, successRT = 0, choiceRT, tempRType, successInput = 0, choiceReserve;
    int monthCurrent, dateCurrent, yearCurrent; //Current date
    int tempMonth, tempDate, tempYear;

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
    
    printf("Enter current date (DD/MM/YYYY): "); // 07/27/23
    scanf("%d/%d/%d",&monthCurrent,&dateCurrent,&yearCurrent);
        
    printf("Enter date of reservation (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&tempMonth,&tempDate,&tempYear);

    if((monthCurrent >= 1 && monthCurrent <= 12 && dateCurrent >= 1 && dateCurrent <= 31) && (tempMonth >= 1 && tempMonth <= 12 && tempDate >= 1 && tempDate <= 31)) // Check if input is valid
        {
            if(yearCurrent < tempYear || (monthCurrent < tempMonth && yearCurrent < tempYear) || (monthCurrent < tempMonth && dateCurrent < tempDate && yearCurrent < tempYear))// Check if the date the user input is valid
                printf("Valid date");		
            
            else
                printf("Invalid date");
        }
        
        else
                printf("Invalid input");

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
        B[n].date = tempDate;
        strcpy(B[n].timeslot, tempTime);
        B[n].roomType = tempRType;
        strcpy(A[n].roomDesc, tempDesc);
        
    }

    else
    {
        printf("Canceling the reservation...");
        getch();
    }
    



    return successInput; // To add to the array of structs
}

/**************************************************************************
    Description : Displays All Reservations depending on the User ID

    @param :  struct data *A,struct room *B, int ID, int n, int d
***************************************************************************/
void display_Reservations(struct data *A,struct room *B, int ID, int n, int d)//Status: INCOMPLETE
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
						"     Building: Br. Andrew Gonzalez Hall\n", j, B[i].timeslot, B[i].date, A[i].Day, B[i].roomNum); 
				j++;
			}
	}
	printf("[~] Cancel");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

/**************************************************************************
    Description : Reserving another time slot 

    @param :  struct room *B
***************************************************************************/
void Add_Time_Condition(struct room *B)// Status: INCOMPLETE
{
    int num_choice;
    struct data s; //temp
    //display_rooms(struct data info[]);

    printf("Select Vacant Time slot (MTHF: 1-6) (WS: 1-3)");
    scanf("%d", num_choice);
    
    if(B[num_choice].status == 0)
    {
        
        B[num_choice].status = 1;
    }
    else if(B[num_choice].status == 1)
        printf("This Time Slot is Currently unavailable");

    
    /*
        In case the activity will use more than 1.5hrs on specific days,
        they can reserve an additional time slot (must be consecutive time slot)
    */
}

/**************************************************************************
    Description : Cancelling Reservation

    @param :  struct data *A,struct room *B, int n
    @return : successRemove
***************************************************************************/
int Cancel_Reservation(struct data *A,struct room *B, int n)//Status: INCOMPLETE
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
			j++;
		}
	}


	display_Reservations(A,B, ID, n, arrT[0]);
    
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
            B[i].roomNum =  B[i+1].roomNum;
            B[i].roomType =  B[i+1].roomType;
		}
	}
}

/**************************************************************************
    Description : Changing existing timeslot Reservation

    @param :  struct data *A, struct room *B, int n
***************************************************************************/
void Change_Room_Reservation(struct data *A, struct room *B, int n)//Status: UNSURE
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
			j++;
		}
	}


	display_Reservations(A,B, ID, n, arrT[0]);
    
	printf("Select a reservation to Change: ");
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
            B[i].roomNum =  B[i+1].roomNum;
            B[i].roomType =  B[i+1].roomType;
		}
	}
    /*
        A bit like Cancel Reservation but just editing status and ownership.
    */
}

/**************************************************************************
    Description : Displaying rooms

    @param :  struct data *A, struct room *B, int n, int ID, int d
***************************************************************************/
void display_rooms(struct data *A, struct room *B, int n, int ID, int d)
{
    int i, j = 1;
    string20 stat;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Reservation/s for: %s %s\n", A[d].data.firstName, A[d].data.lastName);

    
	for(i = 0; i < n; i++)
	{
		if(ID == A[i].data.ID)
		{
            if(B[i].status == 0)
                strcpy(stat,"Available");
            else
                strcpy(stat,"Unavailable");

            printf(	"[%d] Timeslot: %s\n"
                    "     Date and day: %s %c\n"
                    "     Room: %s\n"
                    "     Status: %s"
                    "     Building: Br. Andrew Gonzalez Hall\n", j, B[i].timeslot, B[i].date, A[i].Day, B[i].roomNum, stat); //undeclared variables
            j++;
        }
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

/**************************************************************************
    Description : Admin Module

    @param : 
***************************************************************************/
int adminMenu(int dateM, int dateD, int dateY, char *dayT)
{
    system("cls");
    int choice;
    do
    {
        printf( "\nWhat do you want to do?\t Date: %d/%d/%d \t Day: %s\n"
                "[1] Remove a reservation\n"
                "[2] Change a reservation\n"
                "[3] Edit a reservation\n"
                "[5] Complete a reservation\n"
                "[6] Go back to main menu\n", dateM, dateD, dateY, dayT);
        printf("Input choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 6)
            printf("Invalid input. Please choose from the list.\n");

    } while(choice < 1 || choice > 6);
        
    return choice;
}

void initializeRooms(struct Room *A, int numRooms) // Since kunti lang naman saatin 
{
    char roomNames[][10] = {"Y0101", "Y0102", "Y0103", "Y0104", "Y0105", "Y0106", "Y0107", "Y0108", "Y0109", "Y0110"};
    char roomTypes[][20] = {"Classroom", "Classroom", "Classroom", "Classroom", "Classroom", "Classroom", "Seminar room", "Seminar room", "Training room", "Auditorium"};
    int roomCapacities[] = {30, 30, 30, 30, 30, 30, 80, 80, 100, 150};

    for (int i = 0; i < numRooms; i++) {
        strcpy(rooms[i].name, roomNames[i]);
        strcpy(rooms[i].type, roomTypes[i]);
        rooms[i].capacity = roomCapacities[i];
        rooms[i].status = 1;
    }
}

int main()
{
    // Main menu variables
    int mainChoice, exit = 0, pCheck = 0;
    string20 correctP = "Password", inputP;
    struct Room rooms[10];
    struct Reservation data[MAX];


	
    // Date and day variables
    int dateM, dateD, dateY, date, dateCheck = 0, dayCheck = 0;
    char dayT[4];
    do
    {
        printf("Enter todays date(MM/DD/YY): ");
        date = scanf("%2d/%2d/%2d", &dateM, &dateD, &dateY);

        if (date != 3 || getchar() != '\n')
        {
            dateM = 0;
            dateD = 0;
            dateY = 0;
            printf("Invalid date format. Please enter the date in MM/DD/YY format.\n");
        }
        
        else
        {
            dateCheck = dateValid(dateM, dateD, dateY);

            if(dateCheck == 0)
            {
                dateM = 0;
                dateD = 0;
                dateY = 0;
                printf("Invalid date. Please input a proper date.\n");
            }
                
        }
            
            
        


    } while(dateCheck != 1); // Date input

    do {
        printf("\nEnter the day today (Mon, Tue, Wed..., Sat): ");
        scanf("%3s", dayT);

        if (dayT[0] >= 'a' && dayT[0] <= 'z') 
            dayT[0] = dayT[0] - 32;
        // Consume leftover characters in the input buffer, including the newline character
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        dayCheck = dayValid(dayT);

        if (dayCheck == 0) {
            printf("Invalid day. Input a day from Mon to Sat only. No reservations for Sun.\n");
        }

    } while (dayCheck != 1); // Day input
    

    system("cls");
    
    do
    {
        printf("\nWhat would you like to do?\t Date: %d/%d/%d \t Day: %s\n", dateM, dateD, dateY, dayT);

        printf( "[1] Book a reservation\n"
                "[2] Cancel a reservation\n"
                "[3] Change a reservation\n"
                "[4] Admin module\n"
                "[5] Exit program\n");
        printf("Input choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice)
        {
        case 1:
            printf("You chose 1");
            break;
        case 2:
            printf("You chose 2");
            break;
        case 3:
            printf("You chose 3");
            break;
        case 4:
            while(pCheck != 1)
            {
                password(inputP);
                if(strcmp(correctP, inputP) == 0 || inputP[0] == '\0') // Password
                    pCheck = 1;
                else
                    printf("Wrong password. Please try again.");
            }

            if(pCheck == 1)
                adminMenu(dateM, dateD, dateY, dayT);
            
            break;
        case 5:
            printf("Thank you for using our program!");
            exit = 1;
            break;
        
        default:
            printf("Invalid input. Please choose from the given list.");
            break;
        }
    } while(exit != 1);
	
    return 0;
}

