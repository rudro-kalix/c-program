#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 300
#define NAME 60
#define TEXT 220
#define FILE_NAME "complaints.dat"

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

void trim(char s[])
{
    int n = strlen(s);

    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

void readText(char msg[], char out[], int size)
{
    printf("%s", msg);
    fgets(out, size, stdin);
    trim(out);

    while (strlen(out) == 0) {
        printf("This field cannot be empty. Try again: ");
        fgets(out, size, stdin);
        trim(out);
    }
}

int readNum(char msg[])
{
    char line[30];
    int num;

    printf("%s", msg);
    fgets(line, sizeof(line), stdin);

    while (sscanf(line, "%d", &num) != 1) {
        printf("Enter a number: ");
        fgets(line, sizeof(line), stdin);
    }

    return num;
}

void waitKey()
{
    char tmp[8];

    printf("\nPress Enter to continue...");
    fgets(tmp, sizeof(tmp), stdin);
}

void today(char out[])
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(out, 20, "%Y-%m-%d", t);
}

int load(Complaint list[])
{
    FILE *fp;
    int n = 0;

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        return 0;
    }

    while (n < MAX && fread(&list[n], sizeof(Complaint), 1, fp) == 1) {
        n++;
    }

    fclose(fp);
    return n;
}

void save(Complaint list[], int n)
{
    FILE *fp;
    int i;

    fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        printf("File could not be saved.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fwrite(&list[i], sizeof(Complaint), 1, fp);
    }

    fclose(fp);
}

int nextId(Complaint list[], int n)
{
    int i, last = 1000;

    for (i = 0; i < n; i++) {
        if (list[i].id > last) {
            last = list[i].id;
        }
    }

    return last + 1;
}

int find(Complaint list[], int n, int id)
{
    int i;

    for (i = 0; i < n; i++) {
        if (list[i].id == id) {
            return i;
        }
    }

    return -1;
}

void line()
{
    printf("------------------------------------------------------------\n");
}

void showOne(Complaint *c)
{
    line();
    printf("ID       : %d\n", c->id);
    printf("Name     : %s\n", c->name);
    printf("Phone    : %s\n", c->phone);
    printf("Category : %s\n", c->cat);
    printf("Details  : %s\n", c->details);
    printf("Status   : %s\n", c->status);
    printf("Team     : %s\n", c->team);
    printf("Date     : %s\n", c->date);
}

void addComplaint(Complaint list[], int *n)
{
    Complaint c;

    if (*n >= MAX) {
        printf("Storage is full.\n");
        return;
    }

    c.id = nextId(list, *n);
    readText("Your name: ", c.name, NAME);
    readText("Phone number: ", c.phone, sizeof(c.phone));
    readText("Category (electric/water/road/other): ", c.cat, sizeof(c.cat));
    readText("Describe the problem: ", c.details, TEXT);

    strcpy(c.status, "Pending");
    strcpy(c.team, "Not assigned");
    today(c.date);

    list[*n] = c;
    (*n)++;
    save(list, *n);

    printf("\nComplaint submitted.\n");
    printf("Your complaint ID is %d. Keep it for status checking.\n", c.id);
}

void checkStatus(Complaint list[], int n)
{
    int id = readNum("Enter complaint ID: ");
    int pos = find(list, n, id);

    if (pos == -1) {
        printf("No complaint found with this ID.\n");
        return;
    }

    showOne(&list[pos]);
}

void listAll(Complaint list[], int n)
{
    int i;

    if (n == 0) {
        printf("No complaints found.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        showOne(&list[i]);
    }
}

void listStatus(Complaint list[], int n, char status[])
{
    int i, found = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(list[i].status, status) == 0) {
            showOne(&list[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching complaint found.\n");
    }
}

void listSolved(Complaint list[], int n)
{
    int i, found = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(list[i].status, "Solved") == 0 ||
            strcmp(list[i].status, "Resolved") == 0) {
            showOne(&list[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No solved complaint found.\n");
    }
}

void searchComplaint(Complaint list[], int n)
{
    char key[60];
    int i, id, found = 0;

    readText("Search ID, name, phone, category or status: ", key, sizeof(key));
    id = atoi(key);

    for (i = 0; i < n; i++) {
        if (list[i].id == id ||
            strcmp(list[i].name, key) == 0 ||
            strcmp(list[i].phone, key) == 0 ||
            strcmp(list[i].cat, key) == 0 ||
            strcmp(list[i].status, key) == 0) {
            showOne(&list[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching complaint found.\n");
    }
}

void setStatus(Complaint list[], int n)
{
    int id = readNum("Complaint ID: ");
    int pos = find(list, n, id);
    int ch;
    char ans[10];

    if (pos == -1) {
        printf("Complaint not found.\n");
        return;
    }

    printf("\n1. Pending\n");
    printf("2. In Progress\n");
    printf("3. Solved\n");
    printf("4. Rejected\n");
    ch = readNum("Choose new status: ");

    switch (ch) {
        case 1:
            strcpy(list[pos].status, "Pending");
            break;
        case 2:
            strcpy(list[pos].status, "In Progress");
            break;
        case 3:
            strcpy(list[pos].status, "Solved");
            break;
        case 4:
            strcpy(list[pos].status, "Rejected");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("Assign/change team? (y/n): ");
    fgets(ans, sizeof(ans), stdin);
    trim(ans);

    if (ans[0] == 'y' || ans[0] == 'Y') {
        readText("Team name: ", list[pos].team, sizeof(list[pos].team));
    }

    save(list, n);
    printf("Status updated.\n");
}

void removeItem(Complaint list[], int *n)
{
    int id = readNum("Complaint ID to delete: ");
    int pos = find(list, *n, id);
    int i;

    if (pos == -1) {
        printf("Complaint not found.\n");
        return;
    }

    for (i = pos; i < *n - 1; i++) {
        list[i] = list[i + 1];
    }

    (*n)--;
    save(list, *n);
    printf("Complaint deleted.\n");
}

void adminMenu(Complaint list[], int *n)
{
    char pass[30];
    int ch;

    readText("Admin password: ", pass, sizeof(pass));
    if (strcmp(pass, "admin123") != 0) {
        printf("Wrong password.\n");
        return;
    }

    do {
        printf("\nAdmin Menu\n");
        line();
        printf("1. Add Complaint\n");
        printf("2. View All\n");
        printf("3. Search\n");
        printf("4. Update Status\n");
        printf("5. Delete\n");
        printf("6. Pending Complaints\n");
        printf("7. Solved Complaints\n");
        printf("0. Back\n");

        ch = readNum("Choice: ");

        switch (ch) {
            case 1:
                addComplaint(list, n);
                waitKey();
                break;
            case 2:
                listAll(list, *n);
                waitKey();
                break;
            case 3:
                searchComplaint(list, *n);
                waitKey();
                break;
            case 4:
                setStatus(list, *n);
                waitKey();
                break;
            case 5:
                removeItem(list, n);
                waitKey();
                break;
            case 6:
                listStatus(list, *n, "Pending");
                waitKey();
                break;
            case 7:
                listSolved(list, *n);
                waitKey();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                waitKey();
        }
    } while (ch != 0);
}

void userMenu(Complaint list[], int *n)
{
    int ch;

    do {
        printf("\nUser Menu\n");
        line();
        printf("1. Make a complaint\n");
        printf("2. Check complaint status\n");
        printf("0. Back\n");

        ch = readNum("Choice: ");

        switch (ch) {
            case 1:
                addComplaint(list, n);
                waitKey();
                break;
            case 2:
                checkStatus(list, *n);
                waitKey();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                waitKey();
        }
    } while (ch != 0);
}

int main()
{
    Complaint list[MAX];
    int n;
    int ch;

    n = load(list);

    do {
        printf("\nComplaint Management System\n");
        line();
        printf("1. User\n");
        printf("2. Admin\n");
        printf("0. Exit\n");

        ch = readNum("Choice: ");

        switch (ch) {
            case 1:
                userMenu(list, &n);
                break;
            case 2:
                adminMenu(list, &n);
                break;
            case 0:
                save(list, n);
                printf("Data saved. Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 0);

    return 0;
}
