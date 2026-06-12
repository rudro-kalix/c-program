# Complaint Management System

This is a simple C console project. It stores complaints in a file and lets an admin manage them.

## Main Work

User can:

- Add Complaint
- Check Status

Admin can:

- Add Complaint
- View All
- Search
- Update Status
- Delete
- Pending Complaints
- Solved Complaints

## Admin Password

Default password:

```text
admin123
```

The password is saved in:

```text
admin.txt
```

If the file is missing, the program creates it.

## Data File

Complaints are saved in:

```text
complaints.dat
```

So the data stays after closing the program.

## C Rules Used

### File Handling

The program uses:

```c
fopen()
fread()
fwrite()
fprintf()
fscanf()
fclose()
```

`complaints.dat` uses binary file work with `fread()` and `fwrite()`.

`admin.txt` uses text file work with `fprintf()` and `fscanf()`.

### Structure

One complaint is stored using a structure:

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

### Functions

The code is not written only inside `main()`. It has small functions like:

```c
add()
check()
search()
status()
del()
showstat()
usermenu()
adminmenu()
```

### Control Flow And Validation

The program uses:

- `if`
- `switch`
- `while`
- `do while`

It checks wrong menu choices, empty text, wrong number input, wrong password, and wrong complaint ID.

### Arrays And Strings

The complaint list works like an array:

```c
Complaint *a;
```

The program uses string functions:

```c
strlen()
strcmp()
strcpy()
```

### Pointers And Memory

The list is created with:

```c
malloc()
```

And released with:

```c
free()
```

The code also uses pointer parameters:

```c
int *n
Complaint *c
```

## Run

Compile:

```bash
gcc complaint_system.c -o complaint_system
```

Run:

```bash
complaint_system.exe
```

## Demo

1. Run the program.
2. Choose User.
3. Add a complaint.
4. Remember the complaint ID.
5. Check status using the ID.
6. Go back and choose Admin.
7. Enter `admin123`.
8. Search or view the complaint.
9. Update status to Solved.
10. Open Solved Complaints.
11. Exit and run again to show that data is saved.
