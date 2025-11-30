/*
    File Name : basic_data.h
    Description : This Header File Contains The Definition Of The Record Structure And The Prototypes For Functions
                  That Handle Adding, Displaying, And Deleting User Records.
*/

#ifndef BASIC_DATA_H
#define BASIC_DATA_H

// Represents a User Record Containing Basic Personal Details
typedef struct 
{
    char user_name[32];   // Name (Max 31 Characters + Null Terminator)
    char user_gender[16]; // Gender (Male/Female)
    int user_age;         // Age (Years)
    int user_id;          // ID Number
} Record;

// Adds a New Record
void addRecord(void);

// Displays All Available Records
void displayRecord(void);

// Deletes One Record (By ID) Or All Available Records
void deleteRecord(void);

#endif // BASIC_DATA_H