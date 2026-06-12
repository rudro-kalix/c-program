# Complaint Management System

This is project option 15 from the SE133 CEP list.

The project is a simple C console program. It helps users submit complaints and lets an admin check, search, update, delete, and separate complaints by status. The program saves all complaint records in a file named `complaints.dat`, so the data is not lost when the program closes.

## Project Idea

In real life, people may complain about water, electricity, road, internet, or other service problems. If these complaints are only written on paper, they can be lost or forgotten. This system keeps the complaints in one place.

The system has two sides:

- User side
- Admin side

The user can submit a complaint and later check the complaint status using the complaint ID. The admin can manage all complaints.

## Main Features

- User can file a new complaint.
- Every complaint gets a unique complaint ID.
- User can check complaint status by entering the ID.
- Admin can add a complaint.
- Admin can view all complaints.
- Admin can search complaints.
- Admin can update complaint status.
- Admin can assign or change a team while updating status.
- Admin can delete wrong or test complaints.
- Admin can view only pending complaints.
- Admin can view only solved complaints.

## How The System Works

When the program starts, it first reads old complaint data from `complaints.dat`. If the file does not exist, the program starts with an empty list.

Then the main menu appears:

```text
1. User
2. Admin
0. Exit
```

If someone chooses `User`, they can file a complaint or check complaint status.

If someone chooses `Admin`, the program asks for the admin password. The password is:

```text
admin123
```

After the correct password, the admin menu appears:

```text
1. Add Complaint
2. View All
3. Search
4. Update Status
5. Delete
6. Pending Complaints
7. Solved Complaints
0. Back
```

When a new complaint is added, the program gives it an ID automatically. The first complaint ID starts from `1001`. The next complaints become `1002`, `1003`, and so on.

Each complaint stores:

- Complaint ID
- User name
- Phone number
- Category
- Problem details
- Status
- Assigned team
- Date

New complaints start with this status:

```text
Pending
```

The team starts as:

```text
Not assigned
```

The admin can later change the status to:

```text
Pending
In Progress
Solved
Rejected
```

While updating the status, the admin can also assign a team, such as `Electric Team`, `Water Team`, or `Maintenance Team`.

## Code Section Explanation

This section explains the code in simple words.

### Header Files

At the top of the code, these header files are used:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
```

Simple meaning:

- `stdio.h` is used for input, output, and file work.
- `stdlib.h` is used for functions like `atoi`.
- `string.h` is used for string work like comparing and copying text.
- `time.h` is used to save the current date with a complaint.

### Constant Values

The code uses:

```c
#define MAX 300
#define NAME 60
#define TEXT 220
#define FILE_NAME "complaints.dat"
```

Simple meaning:

- The system can store up to 300 complaints at one time.
- Name and description text sizes are fixed.
- All records are saved in `complaints.dat`.

### Structure

The main data structure is:

```c
typedef struct {
    int id;
    char name[NAME];
    char phone[30];
    char cat[50];
    char details[TEXT];
    char status[25];
    char team[50];
    char date[20];
} Complaint;
```

This works like a form. One `Complaint` contains all information about one complaint. Instead of keeping ID, name, phone, and status separately, the structure keeps them together.

### Input Functions

The code has helper functions for taking input.

`readText()` takes text input from the user. It also checks that the user does not leave the field empty.

`readNum()` takes number input. It keeps asking again if the user types something that is not a number.

These functions make the program more stable and easier to use.

### File Handling

The program uses two important functions for file work:

```c
int load(Complaint list[])
void save(Complaint list[], int n)
```

`load()` runs when the program starts. It opens `complaints.dat` and reads all old complaints into the program.

`save()` runs after adding, updating, or deleting complaints. It writes the latest complaint list into `complaints.dat`.

This is why the records stay saved even after closing the program.

### ID Generation

The function `nextId()` checks the current highest complaint ID and returns the next ID.

Example:

- If there is no complaint, first ID is `1001`.
- If the last ID is `1001`, next ID is `1002`.
- If the last ID is `1002`, next ID is `1003`.

This prevents duplicate complaint IDs.

### Searching

The function `find()` searches by complaint ID.

The function `searchComplaint()` is used in the admin menu. It can search by:

- ID
- name
- phone
- category
- status

If a match is found, the complaint details are shown.

### Showing Complaint Details

The function `showOne()` prints one complaint in a clean format.

It shows:

- ID
- name
- phone
- category
- details
- status
- team
- date

The function `listAll()` uses `showOne()` repeatedly to show every complaint.

### Adding Complaints

The function `addComplaint()` adds a new complaint.

It asks for:

- name
- phone
- category
- problem description

Then the program automatically adds:

- complaint ID
- status as `Pending`
- team as `Not assigned`
- current date

After that, it saves the complaint to the file.

### Updating Status

The function `setStatus()` is used by the admin.

The admin enters a complaint ID. If the ID exists, the admin can choose a new status:

```text
1. Pending
2. In Progress
3. Solved
4. Rejected
```

After choosing the status, the program asks whether the admin wants to assign or change the team. This covers the requirement of assigning resolution teams.

### Deleting Complaints

The function `removeItem()` deletes a complaint using the complaint ID.

If the ID is found, the program removes that record from the array and saves the updated list to the file.

### Pending And Solved Lists

The admin menu has:

```text
6. Pending Complaints
7. Solved Complaints
```

`Pending Complaints` shows only complaints with `Pending` status.

`Solved Complaints` shows only complaints with `Solved` status.

This helps the admin quickly understand which problems still need work and which problems are already finished.

### Menus

The program has three main menu functions:

- `main()` shows the first menu.
- `userMenu()` shows the user options.
- `adminMenu()` shows the admin options.

The menus use `switch` statements. A `switch` checks the user's choice and runs the correct function.

## C Concepts Used

This project uses the required C concepts:

- File handling: `fopen`, `fread`, `fwrite`, `fclose`
- Structure: `Complaint`
- Array of structures: `Complaint list[MAX]`
- Functions: separate functions for input, file work, add, search, update, delete, and menus
- Control flow: `if`, `else`, `switch`, loops
- Validation: empty input checking, number input checking, password checking, ID checking
- Strings: `strcmp`, `strcpy`, `strlen`
- Pointers: `Complaint *c`, `int *n`, and array passing to functions

## How To Run

Compile:

```bash
gcc complaint_system.c -o complaint_system
```

Run on Windows:

```bash
complaint_system.exe
```

Admin password:

```text
admin123
```

## Short Class Demo Flow

1. Start the program.
2. Choose the user menu.
3. File a complaint.
4. Note the complaint ID.
5. Check the complaint status using that ID.
6. Go back and open the admin menu.
7. Enter password `admin123`.
8. View all complaints.
9. Search the complaint by ID.
10. Update the status to `Solved`.
11. Assign a team when the program asks.
12. Open solved complaints and show that the complaint is now solved.
13. Exit the program.
14. Run the program again and show that the data is still saved.

## What To Say If Asked

This project is a complaint tracking system. Users can submit complaints and check their complaint status. Admins can manage the complaints by adding, viewing, searching, updating, deleting, and checking pending or solved complaints. Every complaint is stored in a structure, and all records are saved in a file using C file handling.

If the teacher asks about improvement, say that a future version could add separate user accounts, priority levels, CSV export, and a better password system.
