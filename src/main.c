/*
    File Name : main.c
    Description : Main Program File Handling User Interaction & Menu Navigation.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Inclusion Of Header Files
#include "basic_data.h"
#include "bmi.h"

// Clears The Console Screen Depending On The Operating System
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Displays The Main Menu Options For The Health Management System
void printMenu()
{
    printf("\n================== HEALTH MANAGEMENT SYSTEM ==================\n");
    printf("---------------------- RECORD MANAGEMENT ---------------------\n");
    printf("1. Add New User Record\n");
    printf("2. Display All Records\n");
    printf("3. Delete Records\n");
    printf("\n------------------ EXERCISE RECOMMENDATION -------------------\n");
    printf("4. Calculate BMI & Get Recommendations\n");
    printf("\n---------------------------- SYSTEM --------------------------\n");
    printf("5. Exit Program\n");
    printf("==============================================================\n");
}

/*
Entry Point Of The Health Management System.
Handles User Input, Executes Menu Options & Loops Until Termination.
*/
int main()
{
    int menu_choice;
    char choice[8];

    do
    {
        clearScreen();
        printMenu();

        printf("Please Enter Your Choice From The Options Mentioned Above : ");
        if (scanf("%d", &menu_choice) != 1)
        {
            printf("Program Terminated Automatically Due To Invalid User Input\n\n");
            return 0;
        }

        switch (menu_choice)
        {
            case 1:
            {
                addRecord(); // Add a New Record
                break;
            }
            case 2:
            {
                displayRecord(); // Display All Available Records
                break;
            }
            case 3:
            {
                deleteRecord(); // Deletes One (By Id) Or All Available Records
                break;
            }
            case 4:
            {
                calculateBmi(); // Calculates BMI & Gives Personalized Exercise Recommendations
                break;
            }
            case 5:
            {
                printf("Program Terminated Successfully\n\n");
                return 0;
            }
            default:
            {
                printf("Please Choose a Valid Option From The Choices Mentioned Above\n\n");
            }
        }
        
        // Removes Newline Created By (scanf)
        getchar();
        
        // Ask User If They Want To Continue Or Not
        printf("\nDo You Want To Perform Another Action Using This Program (Yes/No) : ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0'; // Removes Newline

        if (strcmp(choice, "No") == 0 || strcmp(choice, "no") == 0)
        {
            printf("Program Terminated Successfully\n\n");
            return 0;
        }
        else if (strcmp(choice, "Yes") != 0 && strcmp(choice, "yes") != 0)
        {
            printf("Program Terminated Automatically Due To Invalid User Input\n\n");
            return 0;
        }

    } while (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0);

    return 0;
}