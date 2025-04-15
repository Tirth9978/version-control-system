# 🚀 Version Control System in C++  

---

## 📌 Overview

Welcome to the **Version Control System!**  
We are the **🧙‍♂️ Bitwise Wizards**, and we have developed a fully functional version control system using **C++**.  
This project replicates core functionalities of tools like **Git**, allowing users to:

- 🗂️ Manage file versions  
- 🔍 Track changes  
- 🔄 Revert to previous states  

—all within a custom-built system designed from scratch.

---

## 🗂️ File Structure

## File Structure
```
📦 Tetris_Game
 └── 💚 Sec                    → Code Files 
        └── main.cpp
        └── commitNode.cpp
        └── gitClass.cpp

 └── 💚 README.md              → Project documentation

```

---

## Project Overview 

Here we have used the ` int main(int argc, char * argv[]) ` . This project is inspired by Git . This project supports committing changes and can be used with Git, which is a major advantage that many developers appreciate.

---

## 	Data Structure Used


| Feature                   | Data Structure Used            |
|---------------------------|-------------------------------|
| Commit history            | Singly Linked List            |
| File selection for staging| Array of strings              |
| File system operations    | Filesystem library (iterator) |
| Commit/message storage    | String                        |

And we have used the object oriented programming (OOPs). 

---
## 🚀 Project Source

Explore the main source files of this project:

📁 **Src/**  
&nbsp;&nbsp;&nbsp;&nbsp;📄 [`main.cpp`](./Src/main.cpp) — Entry point of the project with the main logic.  
&nbsp;&nbsp;&nbsp;&nbsp;📄 [`commitNode.cpp`](./Src/commitNode.cpp) — Handles commit node structure and logic.  
&nbsp;&nbsp;&nbsp;&nbsp;📄 [`gitClass.cpp`](./Src/gitClass.cpp) — Contains the core Git-related class implementations.

---

## Improvement We did 

previously the old code doesn't work on the `./git --help`.We Implement it in the project 

---

## How to Run 

```
g++ -o git main.cpp
```
You Should me in that folder where source files are there . 

```
./git init
```
To initialize the repo . Here instead of using the git , You can use the hole path if are in the other folder . 