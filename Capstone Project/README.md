# Complaint Management System

This is a simple beginner-level C console project for a Complaint Management System.

The program lets a user submit a complaint and check its status. An admin can view all complaints, update complaint status, and view pending complaints.

## Main Features

- User can make a complaint.
- User can check a complaint using the complaint ID.
- Admin can log in using a password.
- Admin can view all complaints.
- Admin can update complaint status.
- Admin can view pending complaints.
- Complaint data is saved in a file, so it stays after closing the program.

## Admin Password

The default admin password is:

```text
admin123
```

The program stores this password in:

```text
admin.txt
```

If `admin.txt` does not exist, the program creates it automatically.

## Files Used

```text
complaints.dat
admin.txt
```

`complaints.dat` stores complaint records using binary file handling.

`admin.txt` stores the admin password using text file handling.

## C Concepts Used

### File Handling

The project uses:

```c
fopen()
fread()
fwrite()
fprintf()
fscanf()
fclose()
```

`complaints.dat` uses `fread()` and `fwrite()`.

`admin.txt` uses `fprintf()` and `fscanf()`.

### Structure

The project uses a structure named `Complaint`.

```c
typedef struct {
    int id;
    char name[NAME_SIZE];
    char phone[30];
    char category[40];
    char details[TEXT_SIZE];
    char status[20];
} Complaint;
```

This keeps all information about one complaint together.

### Functions

The program is divided into small functions, such as:

```c
addComplaint()
checkComplaint()
viewAllComplaints()
updateStatus()
viewPendingComplaints()
userMenu()
adminMenu()
```

This keeps the code easier to read.

### Control Flow And Validation

The program uses:

- `if` and `else`
- `switch`
- `while`
- `do while`

It also checks:

- Empty text input
- Wrong number input
- Wrong admin password
- Invalid complaint ID
- Invalid menu choice

### Arrays And Strings

The program stores complaints in an array:

```c
Complaint *list;
```

The project also uses string functions:

```c
strlen()
strcmp()
strcpy()
```

### Pointers And Memory Management

The project uses a pointer for the complaint list:

```c
Complaint *list;
```

Memory is created using:

```c
malloc()
```

Memory is released using:

```c
free()
```

The project also uses pointer parameters like:

```c
int *count
Complaint *c
```

## How To Run

Compile:

```bash
gcc complaint_system.c -o complaint_system
```

Run on Windows:

```bash
complaint_system.exe
```

## Demo Flow

1. Run the program.
2. Choose `User`.
3. Make a complaint.
4. Remember the complaint ID.
5. Check the complaint using that ID.
6. Go back and choose `Admin`.
7. Enter password `admin123`.
8. View all complaints.
9. Update the complaint status to `Solved`.
10. Exit the program.
11. Run the program again and show that the data is still saved.
