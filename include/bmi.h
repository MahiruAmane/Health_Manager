#ifndef BMI_H
#define BMI_H

// Inline Functions For BMI Calculations (Safer Than Macros)
static inline float BMI(float weight, float height_m) 
{
    return weight / (height_m * height_m);
}

// Inline Function For Healthy Weight Calculations (Safer Than Macros)
static inline float WEIGHT(float bmi, float height_m) 
{
    return bmi * height_m * height_m;
}

// Represents a User Record Containing Basic Health Details
typedef struct 
{
    float user_weight;   // Weight (In Kg)
    float user_height;   // Height (In M)
    char category[32];   // BMI Category (Normal, Overweight, etc.)
} Health;

// Represents a User Record Containing Exercise & Fitness Goal Information
typedef struct 
{
    float goal_weight;        // Target Weight (In Kg)
    int activity_level;       // Activity Level (Very Active, Lightly Active, etc.)
    int goal_type;            // Goal type (Gain, Lose, etc.)
    char activity_label[32];  // Activity Level Description
    char goal_label[32];      // Target Weight Description
} Exercise;

// Represents Exercise Information For Recommendations
typedef struct 
{
    const char* name;            // Name Of The Exercise
    const char* unit;            // Unit Of Measurement (Reps/Seconds)
    int base_amount_per_day;     // Base Amount To Perform Per Day
    int sets;                    // Number Of Sets
} ExerciseInfo;

// Calculates BMI Based On User Data & Prints Exercise Recommendations
void calculateBmi(void);

#endif // BMI_H