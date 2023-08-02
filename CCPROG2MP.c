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
// gcc -Wall CCPROG2MP.c -o run.exe

#include <stdio.h>
#include <string.h> // String things
#include <conio.h> // getch();
#include <stdlib.h> // system("cls")
#include "dataValidation.c" // Validation functions

struct Reservation{
    int userID;   // User ID number
    string50 fullName; // User's full name
    string50 yearProgram; // Year and program of the user
    int dateM; // Reservation date 
    int dateD; // Reservation date
    int dateY; // Reservation date
    string50 timeSlot; // Time slot for the reservation
    int numParticipants; // Number of participants for the reservation
    string20 roomName; // Room name reserved
    string1000 activityDesc; // Description of the activity
};

struct Room{
    string20 name; // A0607
    string20 type; // Room type
    int capacity;  // Room capacity
    int status; // Availability status (1 if available, 0 if booked)
};

/**************************************************************************
    Description : User Inputs credentials

    @param : struct Reservation *A, int records, struct Room *B, char *dayT, int dateM, int dateD, int dateY 
    @return :  1
***************************************************************************/
int Input_form(struct Reservation *A, int records, struct Room *B, char *dayT, int dateM, int dateD, int dateY)
{
    char MTHF[][16] = {"09:15 - 10:45", "11:00 - 12:30", "12:45 - 14:15", "14:30 - 16:00", "16:15 - 17:45", "18:00 - 19:00"};
    char WS[][16] = {"09:00 - 12:00", "13:00 - 16:00", "16:15 - 19:15"};
    int timeC, i, day = 0, check = 0, choice, cant, dateCheck, mAllow = 0, index, count;
    int TdateM, TdateD, TdateY, TuserID, TnumP;
    char TroomN[10];

    system("cls");

    if((strcmp(dayT, "Mon") == 0) || (strcmp(dayT, "Tue") == 0) || (strcmp(dayT, "Thu") == 0) || (strcmp(dayT, "Fri") == 0))
        day = 1;


    while(check != 1)
    {
        printf("\nEnter your ID number: ");
        scanf("%d", &TuserID);

        if(TuserID < 10000000 || TuserID >= 20000000)
            printf("Invalid input. Please try again.\n");

        else if(TuserID > 10000000 && TuserID < 20000000)
        {
            count = countReserve(A, records, TuserID);
            if(count > 3)
            {
                A[records].userID = TuserID;
                check = 1;
            }
            else
            {
                printf("Cant have more than 3 reservations! Returning to main menu.");
                return 0;
            }
        }
    }
    

    printf("Enter your full name (First and Last Name): ");
    fgets(A[records].fullName, sizeof(A[records].fullName), stdin);

    int len = strlen(A[records].fullName);
    if (len > 0 && A[records].fullName[len - 1] == '\n')
        A[records].fullName[len - 1] = '\0';

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter your year and program: ");
    fgets(A[records].yearProgram, sizeof(A[records].yearProgram), stdin);
    
    len = strlen(A[records].yearProgram);
    if (len > 0 && A[records].yearProgram[len - 1] == '\n')
        A[records].yearProgram[len - 1] = '\0';

    check = 0;
    while (check != 1)
    {
        printf("Enter the date for the reservation (MM/DD/YY): ");
        int date = scanf("%d/%d/%d", &TdateM, &TdateD, &TdateY);

        if (date != 3 || getchar() != '\n')
        {
            TdateM = 0;
            TdateD = 0;
            TdateY = 0;
            printf("Invalid date format. Please enter the date in MM/DD/YY format.\n");
        }

        else
        {
            dateCheck = dateValid(TdateM, TdateD, TdateY);
            
            if(dateCheck == 0)
            {
                TdateM = 0;
                TdateD = 0;
                TdateY = 0;
                printf("Invalid date. Please enter a valid date.\n");
            }
            else
            {
                int dateCCheck = compareDate(dateM, dateD, dateY, TdateM, TdateD, TdateY);

                if(dateCCheck == 1)
                {
                    A[records].dateD = TdateD;
                    A[records].dateM = TdateM;
                    A[records].dateY = TdateY;
                    check = 1;
                }

                else
                {
                    TdateM = 0;
                    TdateD = 0;
                    TdateY = 0;
                    printf("Invalid date. Please enter a future date.\n");
                }
            }
                
        }
    }

    check = 0;
    while(check != 1)
    {
        printf("Choose a time slot\n");
        if(day == 1)
        {
            for(i = 0; i < 6; i++)
            {
                printf("[%d] %s\n", i+1, MTHF[i]);
            }
        }

        else
        {
            for(i = 0; i < 3; i++)
            {
                printf("[%d] %s\n", i+1, WS[i]);
            }
        }

        printf("Enter the time slot for the reservation: ");
        scanf("%d", &timeC);

        if((timeC < 1 || timeC > 6) && day == 1)
            printf("Invalid input. Please choose from the list.\n");
        else if((timeC < 1 || timeC > 3) && day == 0)
            printf("Invalid input. Please choose from the list.\n");
        else
            check = 1;
    }

    check = 0;
    choice = 0;
    cant = 0;
    while(check != 1)
    {
        printf( "Would your activity last for more than 1.5 hours?\n"
                "[1] Yes\n"
                "[2] No\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1 && day == 1) // MTHF slots, act > 1.5 hours
        {
            for (i = 0; i < records; i++)
            {
                if(strcmp(A[i].timeSlot, MTHF[timeC]) == 0 && day == 1 && (A[records].dateM == A[i].dateM && A[records].dateD == A[i].dateM && A[records].dateY == A[i].dateY))
                    cant = 1; // if the next time slot is not available
                else
                    cant = 0;
            }
        }

        
        else if(choice == 1 && day != 1)// WS slots, act > 1.5 hours
        {
            for (i = 0; i < records; i++)
            {
                if(strcmp(A[i].timeSlot, WS[timeC - 1]) == 0 && day == 1 && (A[records].dateM == A[i].dateM && A[records].dateD == A[i].dateM && A[records].dateY == A[i].dateY))
                    cant = 1; // if the next time slot is not available
                else
                    cant = 0;
            }
        }

        else
            cant = 1;


        switch(choice)
        {
            case 1:
                if(cant == 0)
                {
                    
                    if(day == 1)
                    {
                        if(timeC == 6)
                        {
                            printf("Last available time slot chosen. Can't reserve the next time slot.\n");
                            strcpy(A[records].timeSlot, MTHF[timeC-1]);
                        }
                            
                        else
                        {
                            printf("Reserving the next time slot.\n");
                            strcpy(A[records].timeSlot, MTHF[timeC-1]);
                            strcat(A[records].timeSlot, " & ");
                            strcat(A[records].timeSlot, MTHF[timeC]);
                        }
                    }

                    else
                    {
                        if(timeC == 3) // If the chose the last time slot
                        {
                            printf("Last available time slot chosen. Can't reserve the next time slot.\n");
                            strcpy(A[records].timeSlot, WS[timeC-1]);
                        }
                            
                        else
                        {
                            printf("Reserving the next time slot.\n");
                            strcpy(A[records].timeSlot, WS[timeC-1]);
                            strcat(A[records].timeSlot, " & ");
                            strcat(A[records].timeSlot, WS[timeC]);
                        }
                    }
                    check = 1;
                }

                else
                {
                    printf("Can't reserve the next time slot. Reserving just the chosen time slot");
                    if(day == 1)
                        strcpy(A[records].timeSlot, MTHF[timeC-1]);

                    else
                        strcpy(A[records].timeSlot, WS[timeC-1]);

                }
                break;

            case 2:
                if(day == 1)
                    strcpy(A[records].timeSlot, MTHF[timeC-1]);

                else
                    strcpy(A[records].timeSlot, WS[timeC-1]);

                check = 1;
                break;
                
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    

    check = 0;
    while(check != 1)
    {
        printf("Enter the number of participants: ");
        scanf("%d", &TnumP);

        if(TnumP > 150)
            printf("Capacity has reached our limit for all of our rooms! Please lessen the participants.\n");
        else
        {
            if(TnumP > 30)
                mAllow = 7;
            else if(TnumP > 80)
                mAllow = 9;
            else if(TnumP > 100)
                mAllow = 10;
            A[records].numParticipants = TnumP;
            check = 1;
        }


    }

    choice = 0;
    check = 0;
    while(check != 1)
    {
    
        printf("Enter the room name to reserve (Y0101 - Y0110): ");
        scanf("%s", TroomN);

        if (strlen(TroomN) != 5 || TroomN[0] != 'Y' || TroomN[1] != '0' || TroomN[2] != '1' || TroomN[3] >= '0' || TroomN[3] <= '1'
            || TroomN[4] >= '1' || TroomN[4] >= '9')
            printf("Invalid room name. Please choose between Y0101 - Y0110\n");
        
        int roomNumber = atoi(&TroomN[1]);

        if (roomNumber >= 101 && roomNumber <= 110) // Valid room name
        {
            if(mAllow == 0)
            {
                for(i = 0; i < records; i++)
                {
                    if(strcmp(A[i].roomName, TroomN) == 0 && (A[i].dateD == A[records].dateD && A[i].dateY == A[records].dateY && 
                        A[i].dateM == A[records].dateM) && (strcmp(A[i].timeSlot, A[records].timeSlot)))
                        index = 1;
                }
                if(index == 1)
                    printf("Room already reserved. Please try again.");
                else
                {
                    strcpy(A[records].roomName, TroomN);
                    printf("Room %s is reserved to your name.", A[records].roomName);
                    check = 1;
                }
            }

            else if(mAllow == 7)
            {
                for(i = 0; i < records; i++)
                {
                    if(strcmp(A[i].roomName, TroomN) == 0 && (A[i].dateD == A[records].dateD && A[i].dateY == A[records].dateY && 
                        A[i].dateM == A[records].dateM) && (strcmp(A[i].timeSlot, A[records].timeSlot)))
                        index = 1;
                }

                if(TroomN[4] >= '7' && index != 1)
                {
                    strcpy(A[records].roomName, TroomN);
                    printf("Room %s is reserved to your name.", A[records].roomName);
                    check = 1;
                }
                else
                    printf("Room already reserved. Please try again.");

            }

            else if(mAllow == 9)
            {
                for(i = 0; i < records; i++)
                {
                    if(strcmp(A[i].roomName, TroomN) == 0 && (A[i].dateD == A[records].dateD && A[i].dateY == A[records].dateY && 
                        A[i].dateM == A[records].dateM) && (strcmp(A[i].timeSlot, A[records].timeSlot)))
                        index = 1;
                }
                
                if((TroomN[4] == '9' || (TroomN[4] == '0' && TroomN[3] == '1')) && index != 1)
                {
                    strcpy(A[records].roomName, TroomN);
                    printf("Room %s is reserved to your name.", A[records].roomName);
                    check = 1;
                }
                else
                    printf("Room already reserved. Please try again.");

            }

        }
    }
    


    printf("Enter the description of the activity: ");
    scanf("%s", A[records].activityDesc);


    printf("Review of your reservation: ");
    printf("ID: %d", A[records].userID);
    printf("Name: %s", A[records].fullName);
    printf("Year & Program: %s", A[records].yearProgram);
    printf("Date: %d/%d/%d", A[records].dateM, A[records].dateD, A[records].dateY);
    printf("Time slot: %s", A[records].timeSlot);
    printf("Number of participants: %d", A[records].numParticipants);
    printf("Room: %s", A[records].roomName);
    printf("Description of the activity: %s", A[records].activityDesc);
    


    return 1;
}

/**************************************************************************
    Description: Initializing Rooms 

    @param : struct Room *A, int numRooms 
***************************************************************************/
void initializeRooms(struct Room *A, int numRooms) // Since kunti lang naman saatin 
{
    char roomNames[][10] = {"Y0101", "Y0102", "Y0103", "Y0104", "Y0105", "Y0106", "Y0107", "Y0108", "Y0109", "Y0110"};
    char roomTypes[][20] = {"classroom", "classroom", "classroom", "classroom", "classroom", "classroom", "Seminar room", "Seminar room", "Training room", "Auditorium"};
    int roomCapacities[] = {30, 30, 30, 30, 30, 30, 80, 80, 100, 150};

    for (int i = 0; i < numRooms; i++) {
        strcpy(A[i].name, roomNames[i]);
        strcpy(A[i].type, roomTypes[i]);
        A[i].capacity = roomCapacities[i];
        A[i].status = 1;
    }
}

/**************************************************************************
    Description : Displays Reservations Made by the User

    @param : struct Reservation *A, int records, int userID 
    @return :  int found
***************************************************************************/
int displayReservations(struct Reservation *A, int records, int userID)
{
    int found = 0;

    for (int i = 0; i < records; i++) {
        if (A[i].userID == userID) {
            if (found != 1) {
                printf("Reservations for UserID %d:\n", userID);
                found = 1;
            }

            printf("Reservation %d:\n", i + 1);
            printf("User ID: %d\n", A[i].userID);
            printf("Full Name: %s\n", A[i].fullName);
            printf("Year & Program: %s\n", A[i].yearProgram);
            printf("Date: %d/%d/%d\n", A[i].dateM, A[i].dateD, A[i].dateY);
            printf("Time Slot: %s\n", A[i].timeSlot);
            printf("Number of Participants: %d\n", A[i].numParticipants);
            printf("Room Name: %s\n", A[i].roomName);
            printf("Activity Description: %s\n", A[i].activityDesc);
            printf("\n");
        }
    }

    if (found != 1) {
        printf("No reservations found for UserID %d.\n", userID);
    }

    return found;
}

/**************************************************************************
    Description : Cancels Reservations Made by the user

    @param : struct Reservation *A, int records 
    @return :  int success
***************************************************************************/
int Cancel_Reservation(struct Reservation *A, int records)
{
	int i, j, ID, arrT[2], choiceR, check, cCheck = 0, success = 0;

    if(records == 0)
    {
        printf("No Records Found!");
        return;
    }

	printf("Input ID: ");
	scanf("%d", &ID);

	j = 0;

	for(i = 0; i < records; i++)
	{
		if(ID == A[i].userID)
		{
			arrT[j] = i;
			j++;
		}
	}

    check = displayReservations(A, records, ID);

    if(check == 1)
    {
        while(cCheck != 1)
        {
            printf("Select a reservation to cancel (4 to exit): ");
            scanf("%d", &choiceR);

            if(choiceR >= 1 || choiceR <= 3)
            {
                printf("Reservation #%d canceled", choiceR);
                for(i = arrT[choiceR - 1]; i < records - 1; i++)
                    A[i] = A[i + 1];
                success = 1;
            }

            else if(choiceR == 4)
            {
                printf("Going back to the main menu");
                cCheck = 1;
            }

            else
                printf("Invalid Input. Please choose from the list.");
        }
    }

    else
        printf("No reservations. Going back to the main menu.");
	

    return success;
}

/**************************************************************************
    Description : Counts the amount of reservations

    @param : struct Reservation *A, int records, int userID
    @return :  int count
***************************************************************************/
int countReserve(struct Reservation *A, int records, int userID) {
    int count = 0;

    for (int i = 0; i < records; i++) {
        if (A[i].userID == userID) {
            count++;
        }
    }

    return count;
}

/**************************************************************************
    Description : Changing the timeslot of reservation

    @param : struct Reservation *A, int records
***************************************************************************/
void change_Reservation(struct Reservation *A, int records)
{
    int i, j, ID, arrT[2], choiceR, check, cCheck = 0, success = 0;
    
    if(records == 0)
    {
        printf("No Records Found!");
        return;
    }

	printf("Input ID: ");
	scanf("%d", &ID);

	j = 0;

	for(i = 0; i < records; i++)
	{
		if(ID == A[i].userID)
		{
			arrT[j] = i;
			j++;
		}
	}

    check = displayReservations(A, records, ID);

    if(check == 1)
    {
        while(cCheck != 1)
        {
            printf("Select a reservation to cancel (4 to exit): ");
            scanf("%d", &choiceR);

            if(choiceR >= 1 || choiceR <= 3)
            {
                printf("Enter the new Full Name: ");
                scanf("%s", A[arrT[choiceR - 1]].fullName);
                
                printf("Enter the new Year & Program: ");
                scanf("%s", A[arrT[choiceR - 1]].yearProgram);

                printf("Enter the new Date: ");
                scanf("%d/%d/%d", &A[arrT[choiceR - 1]].dateM, &A[arrT[choiceR - 1]].dateD, &A[arrT[choiceR - 1]].dateY );

                printf("Enter the new Time Slot: ");
                scanf("%s", A[arrT[choiceR - 1]].timeSlot);

                printf("Enter the new Number of Participants: ");
                scanf("%d", &A[arrT[choiceR - 1]].numParticipants);

                printf("Enter the new Room Name: ");
                scanf("%s", A[arrT[choiceR - 1]].roomName);

                printf("Enter the new Activity Description: ");
                scanf("%s", A[arrT[choiceR - 1]].activityDesc);

                cCheck = 1;
            }

            else if(choiceR == 4)
            {
                printf("Going back to the main menu");
                cCheck = 1;
            }

            else
                printf("Invalid Input. Please choose from the list.");
        }

    }

}

/**************************************************************************
    Description : Admin Menu

    @param : int dateM, int dateD, int dateY, char *dayT
    @return :  choice
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

int main(){
    
    // Main menu variables
    int mainChoice, exit = 0, pCheck = 0, records = 0;
    string20 correctP = "Password", inputP;
    struct Room rooms[10];
    struct Reservation data[MAX];
    
    
    initializeRooms(rooms, 10);


    // Date and day variables
    int dateM, dateD, dateY, date, dateCheck = 0, dayCheck = 0;
    char dayT[4];
    do
    {
        printf("Enter todays date(MM/DD/YY): ");
        date = scanf("%d/%d/%d", &dateM, &dateD, &dateY);

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
        scanf("%s", dayT);

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
            records += Input_form(data, records, rooms, dayT, dateM, dateD, dateY);
            break;
        case 2:
            records -= Cancel_Reservation(data, records);
            break;
        case 3:
            change_Reservation(data, records);
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
