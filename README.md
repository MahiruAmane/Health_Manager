# Health Management System In C

## 📑 Project Summary

The **Health Management System** Is a Modular C Based Program That Allows Users To 

- 📁 Add, View And Delete Basic Health Records.
- 🩺 Calculate **Body Mass Index (BMI)** Using Safer Inline Functions (Compared To Macros).
- 📈 Categorize BMI Into Standard Health Ranges (Underweight, Normal, Overweight & Obese I–III).
- 🤸 Provides Personalized Exercise Recommendations Based on BMI Category, Activity Level & Weight Goal Plan.

This **Project** Illustrates How **Record Management** And **Health Guidance** Can Seamlessly Integrate Into a Unified System.

---

## ✨ Features

- 🗂️ **Record Management** — Add, Display And Delete User Records With Persistent Storage.  
- 🧮 **BMI Calculation** — Compute Body Mass Index (BMI) And Categorize According To Standard Health Ranges.  
- 🏋️ **Exercise Recommendations** — Personalized Plans Based On BMI, Activity Level And Weight Goal Plan.  
- ✅ **Input Validation** — Ensures Realistic Values For Age, Weight And Height.  
- 📦 **Modular Design** — Separate `.c` and `.h` Files For Better Clarity And Maintainability.  

---

## ⚙️ Compilation & Execution

To **Compile** This **Program**
```bash
gcc src/main.c src/basic_data.c src/bmi.c -I include -o health_system
```

To **Execute** This **Program**
```bash
./health_system
```

---

## 📂 Directory Structure

```
📂 / 
├── 📂 src/ (All .c Files — main.c, basic_data.c, bmi.c) 
├── 📂 include/ (All .h - Files — basic_data.h, bmi.h) 
├── 📂 docs/  
├── 📂 assets/ 
├── 📄 README.md
├── 📄 sample_input.txt
```

---

## 🧠 Concepts Demonstrated

- 🏗️ **Structures & Functions** — Used To Define Health Records And Organize Related Operations.
- 💾 **File Operations** — (`fopen`, `fwrite`, `fread`, `remove`, `rename`) For Persistent Storage & Record Management.
- 🔗 **Pointer Based String Manipulation** — Handling User Input And String Operations Efficiently.
- 📦 **Modular Programming Using Header Files** - Separating Interfaces `.h` From Implementations `.c` Files.
- 🧾 **Menu Driven Program Design** — Guiding Users Through Options With a Clear Interface.
- 🛡️ **Use Of Inline Functions** — Safer BMI & Weight Calculations Compared To Macros.

---

## 🚀 Future Work

- 🍎 **Dietary Recommendations Based** on Body Mass Index (BMI).
- 🗄️ **Database Integration** For Persistent Storage.
- 🏃 **Expanded Exercise Library** With Intensity Scaling.
- 🌐 **GUI Or Web Interface** For Better Usability.

---

## ⚠️ Limitations

- 🚫 **No Dynamic Memory Allocation** — Records Are Handled Using Static Structures & Arrays Only.  
- 📉 **Limited Exercise Recommendation Library** — Suggestions Are Basic And Not Comprehensive For All BMI Categories Or Fitness Goals.  
- 📄 **Records Stored In Plain Text Files** — No Database Integration, Which Limits Scalability And Advanced Querying.  
- 🔄 **Single User Focus** — The System Does Not Yet Support Multiple User Accounts Or Concurrent Record Management.  
- 🎨 **Console Based Interface Only** — No Graphical User Interface (GUI) Or Web Interface For Improved Usability.

---

## 👥 Team Details

- 🌸 **Member** - MahiruAmane.
- 🧭 **Note** — This Project Was Completed **Individually**. 

---

## 📚 References
- 🚫 No External References Were Used In The Development Of This Project.  
- ✍️ All Code And Documentation Were Created Independently.

---

## 🧮 Evaluation Weightage

| **Criteria**                     | **Marks** | **Description**                                         |
|----------------------------------|-----------|---------------------------------------------------------|
| Problem Definition & Design      | 15        | Clarity Of Objectives, Logic & Design.                  |
| Implementation & Coding Style    | 20        | Modularity, Readability, Comments & Correctness.        |
| Documentation Quality            | 15        | Completeness Of The Report Inside The `/docs` Folder.   |
| GitHub Usage & Collaboration     | 20        | Structure, Commit Activity & Correctness Of Repository. |
| Originality And Creativity       | 10        | Novelty Of Idea & Low Similarity Scores.                |
| Execution & Output Validity      | 20        | Correctness Of Output & Runtime Behavior.               |

This **Project (Health Management System)** Meets All The Required Criteria Outlined In The Above Mentioned Rubric.

---