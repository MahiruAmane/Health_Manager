#include <stdio.h>
#include <string.h>
// Inclusion Of Header Files
#include "bmi.h"

// Function To Calculate BMI & Give Personalized Exercise Recommendations
void calculateBmi()
{
    Health h;

    printf("\n");
    
    float bmi;
    float min_weight;
    float max_weight;

    // Ask For User Weight (In Kg)
    do
    {
        printf("Please Enter Your Current Weight (In Kg) : ");
        scanf("%f", &h.user_weight);

    } while (h.user_weight < 10 || h.user_weight > 250);
    
    // Ask For User Height (In M)
    do
    {
        printf("Please Enter Your Current Height (In M) : ");
        scanf("%f", &h.user_height);

    } while (h.user_height < 0.75 || h.user_height > 2.50);

    printf("\n--------------------------------------------------------- Body Mass Index Calculator --------------------------------------------------------------");
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
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
    Exercise e;

    // Ask For User Target Weight (In Kg)
    do
    {
        printf("\nPlease Enter Your Goal Weight (In Kg) : ");
        scanf("%f", &e.goal_weight);

    } while (e.goal_weight < 10 || e.goal_weight > 250 && e.goal_weight == h.user_weight); // Target Weight Cannot Be Same As Current Weight

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

    printf("\n");
    printf("-------------------------------------------------------------- PERSONALIZED EXERCISE RECOMMENDATION -----------------------------------------------");
    printf("\nExercises For The Legs Are As Follows : \n");
    printf("\n");
    int squats = 0;

    for (int i = 1; i <= days; i++)
    {
        squats = squats + 10;
    }
    printf("Please Complete %d Squats (2 Sets) Every Day For The Next %d Days\n", squats, days);

    int lunges = 0;

    for (int i = 1; i <= days; i++)
    {
        lunges = lunges + 4;
    }
    printf("Please Complete %d Lunges Per Leg (3 Sets) Every Day For The Next %d Days\n", lunges, days);

    int lift = 0;

    for (int i = 1; i <= days; i++)
    {
        lift = lift + 2;
    }
    printf("Please Complete %d Dead Lifts (2 Sets) Every Day For The Next %d Days\n", lift, days);

    printf("\n");
    printf("Exercises For The Chest Are As Follows : \n");
    printf("\n");

    int ups = 0;

    for (int i = 1; i <= days; i++)
    {
        ups = ups + 5;
    }
    printf("Please Complete %d Push Ups (2 Sets) Every Day For The Next %d Days\n", ups, days);

    int fly = 0;

    for (int i = 1; i <= days; i++)
    {
        fly = fly + 4;
    }
    printf("Please Complete %d Chest Fly's (3 Sets) Every Day For The Next %d Days\n", fly, days);

    printf("\n");
    printf("Exercises For The Arms Are As Follows : \n");
    printf("\n");

    int curls = 0;

    for (int i = 1; i <= days; i++)
    {
        curls = curls + 5;
    }
    printf("Please Complete %d Bicep Curls (3 Sets) Every Day For The Next %d Days\n", curls, days);

    int dips = 0;

    for (int i = 1; i <= days; i++)
    {
        dips = dips + 8;
    }
    printf("Please Complete %d Tricep Dips (2 Sets) Every Day For The Next %d Days\n", dips, days);

    printf("\n");
    printf("Exercises For The Full Body Are As Follows : \n");
    printf("\n");

    int burp = 0;

    for (int i = 1; i <= days; i++)
    {
        burp = burp + 3;
    }
    printf("Please Complete %d Burpees (3 Sets) Every Day For The Next %d Days\n", burp, days);

    int jacks = 0;

    for (int i = 1; i <= days; i++)
    {
        jacks = jacks + 12;
    }
    printf("Please Complete %d Jumping Jacks (2 Sets) Every Day For The Next %d Days\n", jacks, days);

    printf("\n");
    printf("Exercises For The Core Are As Follows : \n");
    printf("\n");

    int plank = 0;

    for (int i = 1; i <= days; i++)
    {
        plank = plank + 15;
    }
    printf("Please Complete %d Seconds Of Planks (3 Sets) Every Day For The Next %d Days\n", plank, days);

    int climb = 0;

    for (int i = 1; i <= days; i++)
    {
        climb = climb + 7;
    }
    printf("Please Complete %d Mountain Climbers (2 Sets) Every Day For The Next %d Days\n", climb, days);

    int leg = 0;

    for (int i = 1; i <= days; i++)
    {
        leg = leg + 6;
    }
    printf("Please Complete %d Leg Raises (3 Sets) Every Day For The Next %d Days\n", leg, days);

    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
}