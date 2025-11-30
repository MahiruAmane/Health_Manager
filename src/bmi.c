/*
    File Name : bmi.c
    Description : This File Contains The Implementation Of Functions To Calculate BMI & Provide Exercise Recommendations.
*/

#include <stdio.h>
#include <string.h>
// Inclusion Of Header Files
#include "bmi.h"

// Function To Print Exercise Plan For A Given Muscle Group
void printData(const char* group_title, ExerciseInfo exercises[], int num_exercises, int days) 
{
    printf("\nExercises For The %s Are As Follows : \n\n", group_title);

    // Loop Through Each Exercise And Print The Plan
    for (int i = 0; i < num_exercises; i++) 
    {
        int total_amount = exercises[i].base_amount_per_day * days;

        printf("Please Complete %d %s Of %s (%d Sets) Every Day For The Next %d Days\n", 
        total_amount, exercises[i].unit, exercises[i].name, exercises[i].sets, days);
    }
}

static void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function To Calculate BMI & Give Personalized Exercise Recommendations
void calculateBmi()
{
    Health h;

    printf("\n");
    
    float bmi;
    float min_weight;
    float max_weight;

    // Ask For User Weight (In Kg)
    while (1)
    {
        printf("Please Enter Your Current Weight (In Kg) : ");
        if (scanf("%f", &h.user_weight) == 1 && h.user_weight >= 10 && h.user_weight <= 250) 
        {
            break;
        }
        clearInputBuffer();
        printf("Weight Must Be Between 10 Kg & 250 Kg\n");
    }
    
    // Ask For User Height (In M)
    while (1)
    {
        printf("Please Enter Your Height (In Meters) : ");
        if (scanf("%f", &h.user_height) == 1 && h.user_height >= 0.5 && h.user_height <= 2.5) 
        {
            break;
        }
        clearInputBuffer();
        printf("Height Must Be Between 0.5 M & 2.5 M\n");
    }

    printf("\n-------------------------- BMI CALCULATOR ------------------------------");
    // Calculation Of BMI Using Inline Function (Safer Than Macros)
    bmi = BMI(h.user_weight, h.user_height);
    printf("\nYou Calculated Body Mass Index (BMI) Is : %.2f\n", bmi);

    // Calculation Of Healthy Weight Range Using Inline Functions (Safer Than Macros)
    min_weight = WEIGHT(18.5, h.user_height);
    max_weight = WEIGHT(24.9, h.user_height);

    // BMI Categorization Logic
    if (bmi < 18.5)
    {
        printf("Your Body Mass Index (BMI) Indicates That You Are In The Underweight Category\n");
        strcpy(h.category,"Underweight");
    }
    else if (bmi <= 24.9)
    {
        printf("Your Body Mass Index (BMI) Indicates That You Are In The Normal Category\n");
        strcpy(h.category,"Normal");
    }
    else if (bmi <= 29.9)
    {
        printf("Your Body Mass Index (BMI) Indicates That You Are In The Overweight Category\n");
        strcpy(h.category,"Overweight");

    }
    else if (bmi <= 34.9)
    {
        printf("Your Body Mass Index (BMI) Indicates That You Are In The Obese Class I Category\n");
        strcpy(h.category,"Obese Class I");

    }
    else if (bmi <= 39.9)
    {
        printf("Your Body Mass Index (BMI) Indicates That You Are In The Obese Class II Category\n");
        strcpy(h.category,"Obese Class II");
    }
    else if (bmi > 39.9)
    {
        printf("Your Body Mass Index (BMI) Indicates That You Are In The Obese Class III Category\n");
        strcpy(h.category,"Obese Class III");
        printf("Your Body Mass Index Is Extremely High, Please Consult a Doctor\n");
    }

    printf("\nThe Healthy Weight Range According To Your Height Is Between %.2f Kg & %.2f Kg\n", min_weight, max_weight);
    printf("------------------------------------------------------------------------\n");

    Exercise e;

    // Ask For User Target Weight (In Kg)
    while (1)
    {
        printf("\nPlease Enter Your Target Weight (In Kg) : ");
        if (scanf("%f", &e.goal_weight) == 1 && e.goal_weight >= 10 && e.goal_weight <= 250 && e.goal_weight != h.user_weight) 
        {
            break;
        }
        clearInputBuffer();
        printf("Weight Must Be Between 10 Kg & 250 Kg and Not Equal To Current Weight\n");
    }

    // Ask For User Activity Level
    printf("\nWhat Is Your Baseline Activity Level ?\n");
    printf("(1) Not Very Active - Spend Most Of The Day Sitting (Example - Desk Job)\n");
    printf("(2) Lightly Active - Spend a Good Part Of The Day On Your Feet (Example - Teacher)\n");
    printf("(3) Active - Spend a Good Part Of The Day Doing Some Physical Activity (Example - Food Server)\n");
    printf("(4) Very Active - Spend a Good Part Of The Day Doing Some Heavy Physical Activity (Example - Carpenter)\n");
    printf("\n");
    printf("Please Enter Your Baseline Activity Level : ");
    scanf("%d", &e.activity_level);

    switch (e.activity_level)
    {
        case 1:
        {
            strcpy(e.activity_label, "Not Very Active");
            break;
        }
        case 2:
        {
            strcpy(e.activity_label, "Lightly Active");
            break;
        }
        case 3:
        {
            strcpy(e.activity_label, "Active");
            break;
        }
        case 4:
        {
            strcpy(e.activity_label, "Very Active");
            break;
        }
        default:
        {
            printf("Please Choose a Valid Option From The Choices Mentioned Above\n");
        }
    }

    // Recommendation Logic For Weight Goal Plan
    if (e.goal_weight > h.user_weight && strcmp(h.category, "Underweight") == 0)
    {
        printf("Recommended Weight Goal - Gain Weight\n");
    }
    else if (e.goal_weight < h.user_weight && (strcmp(h.category, "Obese Class I") == 0 || strcmp(h.category, "Obese Class II") == 0))
    {
        printf("Recommended Weight Goal - Lose Weight\n");
    }
    else
    {
        printf("Recommended Weight Goal - Maintain Weight\n");
    }

    printf("\n");

    // Ask The User For Their Preferred Weight Goal Plan
    printf("Please Select One Of The Following Goals\n");
    printf("(1) Gain Weight\n");
    printf("(2) Lose Weight\n");
    printf("(3) Maintain Weight\n");
    printf("\n");
    printf("Please Enter Your Goal (Recommended Will Provide Better Results) : ");
    scanf("%d", &e.goal_type);

    switch (e.goal_type)
    {
        case 1:
        {
        strcpy(e.goal_label, "Gain Weight");
        break;  
        }
        case 2:
        {
            strcpy(e.goal_label, "Lose Weight");
            break;
        }
        case 3:
        {
            strcpy(e.goal_label, "Maintain Weight");
            break;
        }
        default:
        {
            printf("Please Choose a Valid Option From The Choices Mentioned Above\n");
        }
    }

    int days = 0;

    if (e.goal_type == 1)
    {
        if (e.activity_level == 1)
        {
            days = 4;
        }
        else if (e.activity_level == 2)
        {
            days = 3;
        }
        else if (e.activity_level == 3)
        {
            days = 2;
        }
        else if (e.activity_level == 4)
        {
            days = 1;
        }
    }
    else if (e.goal_type == 2)
    {
        if (e.activity_level == 1)
        {
            days = 6;
        }
        else if (e.activity_level == 2)
        {
            days = 5;
        }
        else if (e.activity_level == 3)
        {
            days = 4;
        }
        else if (e.activity_level == 4)
        {
            days = 3;
        }
    }
    else if (e.goal_type == 3)
    {
        if (e.activity_level == 1)
        {
            days = 5;
        }
        else if (e.activity_level == 2)
        {
            days = 4;
        }
        else if (e.activity_level == 3)
        {
            days = 3;
        }
        else if (e.activity_level == 4)
        {
            days = 2;
        }
    }

    printf("\n");

    // Exercise Recommendation Logic
    if (days > 0)
    {
        printf("Your Personalized One Week Exercise Plan Lasting %d Days Is Designed To Help You Make Effective Progress\n", days);

    }
    
    ExerciseInfo leg_exercises[] = 
    {
        { "Squats", "Reps", 10, 2 },
        { "Lunges Per Leg", "Reps", 4, 3 },
        { "Dead Lifts", "Reps", 2, 2 }
    };

    ExerciseInfo chest_exercises[] = 
    {
        { "Push Ups", "Reps", 5, 2 },
        { "Chest Fly's", "Reps", 4, 3 }
    };

    ExerciseInfo arm_exercises[] = 
    {
        { "Bicep Curls", "Reps", 5, 3 },
        { "Tricep Dips", "Reps", 8, 2 }
    };

    ExerciseInfo full_body_exercises[] = 
    {
        { "Burpees", "Reps", 3, 3 },
        { "Jumping Jacks", "Reps", 12, 2 }
    };

    ExerciseInfo core_exercises[] = 
    {
        { "Planks", "Seconds", 15, 3 },
        { "Mountain Climbers", "Reps", 7, 2 },
        { "Leg Raises", "Reps", 6, 3 }
    };

    printf("\n");
    printf("----------------- PERSONALIZED EXERCISE RECOMMENDATION -----------------\n");

    // Print Exercise Plans For Each Muscle Group
    printData("Legs", leg_exercises, sizeof(leg_exercises)/sizeof(leg_exercises[0]), days);
    printData("Chest", chest_exercises, sizeof(chest_exercises)/sizeof(chest_exercises[0]), days);
    printData("Arms", arm_exercises, sizeof(arm_exercises)/sizeof(arm_exercises[0]), days);
    printData("Full Body", full_body_exercises, sizeof(full_body_exercises)/sizeof(full_body_exercises[0]), days);
    printData("Core", core_exercises, sizeof(core_exercises)/sizeof(core_exercises[0]), days);
    
    printf("------------------------------------------------------------------------\n");
    
}