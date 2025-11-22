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
    printf("\n----------------------------------------------------------- HEALTH MANAGEMENT SYSTEM -------------------------------------------------------------\n\n");
    printf("------------------------------------------------------------ RECORD MANAGEMENT CHOICES ------------------------------------------------------------\n");
    printf("\nPlease Select Option (1) To Add a New User Record\n");
    printf("Please Select Option (2) To Display All The Available Records\n");
    printf("Please Select Option (3) To Delete Some Available Records\n\n");
    printf("--------------------------------------------------------- EXERCISE RECOMMENDATION CHOICE ----------------------------------------------------------\n");
    printf("\nPlease Select Option (4) To Calculate Body Mass Index (BMI) & Get Exercise Recommendations\n\n");
    printf("----------------------------------------------------------- PROGRAM TERMINATION CHOICE ------------------------------------------------------------\n");
    printf("\nPlease Select Option (5) To Start Termination Of This Program\n\n");
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