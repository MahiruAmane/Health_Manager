/*
    File Name : basic_data.c
    Description : This File Contains All The Functions Related To Basic Data Operations
                  Such As Adding, Displaying, And Deleting Records.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Inclusion Of Header Files
#include "basic_data.h"

// Function To Add a New Record
void addRecord()
{
    Record r;

    printf("\n--------------------------- ADD A NEW RECORD ---------------------------\n");
    
    // Removes Newline For Usage Of (fgets)
    getchar();
    
    // Input Name
    do
    {
        printf("Please Enter Your Name : ");
        fgets(r.user_name, sizeof(r.user_name), stdin);
        r.user_name[strcspn(r.user_name, "\n")] = '\0';

    } while (strlen(r.user_name) == 0);

    // Input Gender
    do
    {
        printf("Please Enter Your Gender (Male/Female): ");
        fgets(r.user_gender, sizeof(r.user_gender), stdin);
        r.user_gender[strcspn(r.user_gender, "\n")] = '\0';

    } while (strcmp(r.user_gender, "Male") != 0 && strcmp(r.user_gender, "Female") != 0);

    // Input Age
    do
    {
        printf("Please Enter Your Age : ");
        scanf("%d", &r.user_age);

    } while (r.user_age < 15);
    
    // Input ID
    printf("Please Enter Your Identification Number : ");
    scanf("%d", &r.user_id);
    
    FILE *file = fopen("records.txt", "a");

    if (file == NULL)
    {
        printf("There Was An Error Opening The File\n");
        return;
    }

    // Adds User Inputed Data Inside a File
    fprintf(file, "%s,%s,%d,%d\n", r.user_name, r.user_gender, r.user_age, r.user_id);

    fclose(file);
    
    printf("------------------------------------------------------------------------\n");
    printf("The Records Have Been Saved Sucessfully\n");
}

// Function To Display All Available Records
void displayRecord()
{

    printf("\n---------------------------- DISPLAY RECORDS ---------------------------\n");

    char line[100];
    char display_name[32];
    char display_gender[16];
    int display_age;
    int display_id;
    int empty = 0;

    FILE *file = fopen("records.txt", "r");

    if (file == NULL) 
    {
        printf("There Was An Error Opening The File\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) 
    {
        if (strlen(line) <= 1)
        {
            continue;
        }

        sscanf(line, "%[^,],%[^,],%d,%d", display_name, display_gender, &display_age, &display_id);
        printf("------------------------------------------------------------------------\n");
        printf("The Name You Entered Was : %s\n", display_name);
        printf("The Gender You Entered Was : %s\n", display_gender);
        printf("The Age You Entered Was : %d\n", display_age);
        printf("The ID You Entered Was : %d\n", display_id);
        printf("------------------------------------------------------------------------\n");
        empty = empty + 1;
    }

    // Check For How Many Records Are Found
    if (empty == 0)
    {
        printf("There Was No Data To Display\n");
    }
    else
    {
        printf("Total User Records Found Are As Follows : %d\n", empty);
    }

    fclose(file);
}

// Function To Delete One (By ID) Or All Available Records
void deleteRecord()
{

    printf("\n---------------------------- DELETE RECORDS ----------------------------\n");

    int delete_choice;

    printf("Please Select Option (1) To Delete a User Record By Their Identification Number\n");
    printf("Please Select Option (2) To Delete All The Available User Records\n");
    printf("\n");
    printf("Please Enter Your Choice From The Options Mentioned Above : ");

    scanf("%d", &delete_choice);

    // Checks The File To Delete One Record (By ID)
    if (delete_choice == 1)
    {
        int delete_id;
        printf("Please Enter The ID Of The Record You Want To Delete : ");
        scanf("%d", &delete_id);

        FILE *file = fopen("records.txt", "r");
        FILE *temp = fopen("temp.txt", "w");

        if (file == NULL || temp == NULL) 
        {
            printf("There Was An Error Opening The File\n");
            return;
        }

        char line[100];
        int found = 0;
        int found_id;

        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%*[^,],%*[^,],%*d,%d", &found_id);

            if (found_id == delete_id) 
            {
                found = 1;
                continue;  
            }

            fputs(line, temp);
        }

        fclose(file);
        fclose(temp);

        remove("records.txt");
        rename("temp.txt", "records.txt");

        printf("\n");
        
        if (found)
        {
            printf("The Record Has Been Successfully Deleted\n");
        }
        else
        {
            printf("The Mentioned ID Was Not Found\n");
        }
    }

    else if (delete_choice == 2)
    {
        FILE *file = fopen("records.txt", "w"); // Clears All Data Inside The File
        if (file == NULL) 
        {
            printf("There Was An Error Opening The File\n");
            return;
        }
        fclose(file);

        printf("All Of The User Records Have Been Successfully Deleted\n");
    }
    else
    {
        printf("Please Choose a Valid Option From The Choices Mentioned Above\n");
    }
}