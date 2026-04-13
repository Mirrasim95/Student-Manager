# 📘 Student Manager (C Console Application)

## 📌 Description

**Student Manager** is a simple console-based application written in C for managing a list of students.

The application allows you to:

- add students
- view all students
- delete a student
- update student information

All data is stored in a file called `students.txt`.

---

## ⚙️ Features

### 🔹 1. Add User

Adds a new student to the file  
Data format:

```
Name Age
```

### 🔹 2. Show Users

Reads the file and displays all students:

```
1. Name: Ali, Age: 20
2. Name: Elnur, Age: 25
```

### 🔹 3. Delete User

- Displays the list of students
- Removes the selected user
- Rewrites the file

### 🔹 4. Update User

- Displays the list of students
- Allows editing name and age
- Rewrites the file

### 🔹 5. Exit

Closes the application

---

## 🧠 Concepts Used

- struct — data structure (Student)
- File handling:
  - fopen
  - fscanf
  - fprintf
  - fclose
- Input validation:
  - isdigit
  - scanf checking
- Loops (while, for)
- Arrays

---

## 📂 Data Structure

```c
struct Student {
    char name[30];
    int age;
};
```

---

## 📄 Data File

The file `students.txt` is created automatically.

Example:

```
Ali 20
Orxan 22
Elnur 19
```

---

## ▶️ How to Run

### 1. Compile:

```bash
gcc student-manager.c -o app
```

### 2. Run:

```bash
./app
```

(Windows)

```
app.exe
```

---

## ⚠️ Limitations

- Maximum 100 students (fixed-size array)
- Names cannot contain spaces (scanf("%s"))
- Limited input validation for long strings

---

## 🚀 Possible Improvements

- Support full names (use fgets)
- Dynamic memory (malloc)
- Search functionality
- Sorting
- Store data in CSV / JSON format
- Better input validation

---

## 💡 Notes

- Delete and update operations rewrite the entire file
- EOF is used to detect end of file
- getchar() is used to clear input buffer
