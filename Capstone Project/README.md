# Complaint Management System

## Project Functionality

This project is a simple complaint management system written in C.

The program has two parts:

1. User
2. Admin

The user can:

- Add a new complaint
- Check complaint status using complaint ID

The admin can:

- Add Complaint
- View All Complaints
- Search Complaint
- Update Status
- Delete Complaint
- View Pending Complaints
- View Solved Complaints

The program saves complaint data in:

```text
complaints.dat
```

The admin password is saved in:

```text
admin.txt
```

Default admin password:

```text
admin123
```

If `admin.txt` is missing, the program creates it automatically.

## Code Explanation Step By Step

### 1. Header Files

The program starts with:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

`stdio.h` is used for input, output, and file handling.

`stdlib.h` is used for `malloc()`, `free()`, and `atoi()`.

`string.h` is used for string functions like `strlen()`, `strcmp()`, and `strcpy()`.

### 2. Constants

The code uses:

```c
#define MAX 300
#define NM 60
#define TXT 200
#define DATA "complaints.dat"
#define PASS "admin.txt"
```

`MAX` means the program can store up to 300 complaints.

`NM` is used for name size.

`TXT` is used for problem details size.

`DATA` is the complaint data file.

`PASS` is the admin password file.

### 3. Structure

The structure is:

```c
typedef struct {
    int id;
    char name[NM];
    char phone[30];
    char cat[40];
    char info[TXT];
    char stat[20];
} Complaint;
```

This structure stores one complaint.

Each complaint has:

- ID
- Name
- Phone
- Category
- Details
- Status

### 4. Removing New Line

The function `cutnl()` removes the extra newline from text input.

When `fgets()` takes input, it also stores Enter as `\n`. This function removes that.

### 5. Taking Text Input

The function `getstr()` takes text input from the user.

It also checks if the user entered empty text. If the input is empty, it asks again.

### 6. Taking Number Input

The function `getnum()` takes number input.

It uses `sscanf()` to check if the user entered a valid number.

If the user enters letters instead of a number, it asks again.

### 7. Pause Function

The function `wait()` pauses the screen.

It lets the user read the result before going back to the menu.

### 8. Loading Complaints

The function `load()` opens `complaints.dat` in binary read mode.

```c
fp = fopen(DATA, "rb");
```

If the file does not exist, the function returns `0`.

If the file exists, it reads:

1. Total number of complaints
2. All complaint records

Then it closes the file.

### 9. Saving Complaints

The function `save()` opens `complaints.dat` in binary write mode.

```c
fp = fopen(DATA, "wb");
```

It writes:

1. Total number of complaints
2. All complaint records

Then it closes the file.

This keeps data saved after the program closes.

### 10. Creating Complaint ID

The function `nextid()` checks all existing complaint IDs.

It finds the biggest ID and returns the next one.

Example:

If the biggest ID is `1002`, the next ID will be `1003`.

### 11. Finding A Complaint

The function `find()` searches a complaint by ID.

If the ID is found, it returns the position of that complaint in the array.

If the ID is not found, it returns `-1`.

### 12. Showing One Complaint

The function `show()` prints all information of one complaint.

It receives a pointer:

```c
Complaint *c
```

So it uses the arrow operator:

```c
c->id
```

### 13. Adding Complaint

The function `add()` adds a new complaint.

First, it checks if the storage is full.

Then it takes:

- Name
- Phone
- Category
- Problem details

The status is automatically set to:

```text
Pending
```

Then the complaint is added to the array and saved in the file.

### 14. Checking Complaint Status

The function `check()` asks for a complaint ID.

It calls `find()` to search the complaint.

If found, it shows the complaint.

If not found, it prints `Not found`.

### 15. Viewing All Complaints

The function `showall()` shows every complaint in the array.

If there is no complaint, it prints a message.

### 16. Searching Complaint

The function `search()` can search by:

- ID
- Name
- Phone
- Category
- Status

It compares text using `strcmp()`.

It converts the search text to number using `atoi()` for ID search.

### 17. Updating Status

The function `status()` updates complaint status.

The admin enters a complaint ID first.

Then the admin chooses:

```text
1. Pending
2. In Progress
3. Solved
4. Rejected
```

The selected status is copied using `strcpy()`.

Then the updated data is saved in the file.

### 18. Deleting Complaint

The function `del()` deletes a complaint by ID.

After finding the complaint, the later records are shifted one position left.

Then the total complaint number is reduced by one.

Finally, the updated list is saved.

### 19. Showing Pending Or Solved Complaints

The function `showstat()` shows complaints by status.

For pending complaints, the program sends:

```c
showstat(a, *n, "Pending");
```

For solved complaints, the program sends:

```c
showstat(a, *n, "Solved");
```

### 20. Admin Login

The function `login()` checks the admin password.

It tries to open `admin.txt`.

If the file does not exist, it creates the file and writes:

```text
admin123
```

If the file exists, it reads the password using `fscanf()`.

Then it compares the typed password with the saved password using `strcmp()`.

### 21. User Menu

The function `usermenu()` shows the user menu.

The options are:

```text
1. Add Complaint
2. Check Status
0. Back
```

The menu uses a `switch` statement to run the selected option.

### 22. Admin Menu

The function `adminmenu()` starts with admin login.

If the password is wrong, it returns to the main menu.

If the password is correct, it shows:

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

This menu also uses a `switch` statement.

### 23. Main Function

The `main()` function starts the program.

It creates memory for complaints using:

```c
malloc()
```

Then it loads old complaints from the file.

After that, it shows the main menu:

```text
1. User
2. Admin
0. Exit
```

When the user exits, the program saves the data again.

At the end, it releases memory using:

```c
free()
```
