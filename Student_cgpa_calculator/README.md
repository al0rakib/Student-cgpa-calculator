
# University CGPA Calculator (C Language)

This C program calculates the CGPA of university students based on:
- The best two scores out of three class tests (CTs)
- Attendance performance
- Final exam marks

It's designed specifically for use in academic grading systems where continuous assessment and final exams are combined.

## 📂 Project Files

- `cgpa_calculator.c`: Main C program implementing the CGPA calculation logic
- `inputfile.txt`: Sample input data with student names, roll numbers, CT scores, attendance, and exam scores
- `README.md`: This documentation

## ✅ How to Compile and Run

1. Open terminal or command prompt.
2. Compile the code:
   ```bash
   gcc cgpa_calculator.c -o cgpa_calc
   ```
3. Run the program:
   ```bash
   ./cgpa_calc
   ```

The program reads from `inputfile.txt` and creates `output.txt` with each student's name and calculated CGPA.

## 📌 Sample Input (inputfile.txt)

```
mimi 1931001 10 12 14 65 150
miraz 1931002 12 14 16 65 200
sadia 1931003 16 18 20 52 155
```

## 📌 Sample Output (output.txt)

```
mimi 2.750
miraz 3.583
sadia 3.533
```

## 🎓 Use Case

This project is ideal for university coursework or automated grading tools where CGPA needs to be derived from multiple components of evaluation.

## 🧮 CGPA Evaluation Logic

The CGPA is calculated based on the following components:

### 1. Class Tests (60 Marks)
- Out of three class test scores, the best two are selected.
- These are scaled to contribute a maximum of 60 marks.

### 2. Attendance (30 Marks)
- Based on attendance out of 65 total classes:
  | Attendance (%) | Marks |
  |----------------|-------|
  | ≥ 90%          | 30    |
  | ≥ 85%          | 27    |
  | ≥ 80%          | 24    |
  | ≥ 75%          | 21    |
  | ≥ 70%          | 18    |
  | ≥ 65%          | 15    |
  | < 65%          | 12    |

### 3. Final Exam (210 Marks)
- The final exam score is added directly to the total.

### 4. CGPA Conversion (Out of 300 Total Marks)
| Percentage (%) | CGPA  |
|----------------|-------|
| ≥ 80%          | 4.00  |
| ≥ 75%          | 3.75  |
| ≥ 70%          | 3.50  |
| ≥ 65%          | 3.25  |
| ≥ 60%          | 3.00  |
| ≥ 55%          | 2.75  |
| ≥ 50%          | 2.50  |
| ≥ 45%          | 2.25  |
| ≥ 40%          | 2.00  |
| < 40%          | 0.00  |
