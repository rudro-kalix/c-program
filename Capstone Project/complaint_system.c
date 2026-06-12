#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300
#define NAME_SIZE 60
#define TEXT_SIZE 200
#define DATA_FILE "complaints.dat"
#define PASS_FILE "admin.txt"

typedef struct {
    int id;
    char name[NAME_SIZE];
    char phone[30];
    char category[40];
    char details[TEXT_SIZE];
    char status[20];
} Complaint;

void removeNewLine(char text[]) {
    int len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

void readText(char message[], char text[], int size) {
    printf("%s", message);
    fgets(text, size, stdin);
    removeNewLine(text);

    while (strlen(text) == 0) {
        printf("This cannot be empty. Enter again: ");
        fgets(text, size, stdin);
        removeNewLine(text);
    }
}

int readNumber(char message[]) {
    char line[30];
    int number;

    printf("%s", message);
    fgets(line, sizeof(line), stdin);

    while (sscanf(line, "%d", &number) != 1) {
        printf("Please enter a number: ");
        fgets(line, sizeof(line), stdin);
    }

    return number;
}

void pauseScreen() {
    char temp[10];
    printf("\nPress Enter to continue...");
    fgets(temp, sizeof(temp), stdin);
}

int loadComplaints(Complaint list[]) {
    FILE *file;
    int count;

    file = fopen(DATA_FILE, "rb");
    if (file == NULL) {
        return 0;
    }

    fread(&count, sizeof(int), 1, file);
    if (count < 0 || count > MAX) {
        fclose(file);
        return 0;
    }

    fread(list, sizeof(Complaint), count, file);
    fclose(file);
    return count;
}

void saveComplaints(Complaint list[], int count) {
    FILE *file = fopen(DATA_FILE, "wb");

    if (file == NULL) {
        printf("Could not save file.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(list, sizeof(Complaint), count, file);
    fclose(file);
}

int getNextId(Complaint list[], int count) {
    int i, lastId = 1000;

    for (i = 0; i < count; i++) {
        if (list[i].id > lastId) {
            lastId = list[i].id;
        }
    }

    return lastId + 1;
}

int findComplaint(Complaint list[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (list[i].id == id) {
            return i;
        }
    }

    return -1;
}

void showComplaint(Complaint *c) {
    printf("--------------------------------------------\n");
    printf("ID       : %d\n", c->id);
    printf("Name     : %s\n", c->name);
    printf("Phone    : %s\n", c->phone);
    printf("Category : %s\n", c->category);
    printf("Details  : %s\n", c->details);
    printf("Status   : %s\n", c->status);
}

void addComplaint(Complaint list[], int *count) {
    Complaint c;

    if (*count >= MAX) {
        printf("Storage is full.\n");
        return;
    }

    c.id = getNextId(list, *count);
    readText("Your name: ", c.name, NAME_SIZE);
    readText("Phone number: ", c.phone, sizeof(c.phone));
    readText("Category: ", c.category, sizeof(c.category));
    readText("Problem details: ", c.details, TEXT_SIZE);
    strcpy(c.status, "Pending");

    list[*count] = c;
    (*count)++;
    saveComplaints(list, *count);

    printf("\nComplaint saved successfully.\n");
    printf("Your complaint ID is %d.\n", c.id);
}

void checkComplaint(Complaint list[], int count) {
    int id = readNumber("Enter complaint ID: ");
    int position = findComplaint(list, count, id);

    if (position == -1) {
        printf("Complaint not found.\n");
    } else {
        showComplaint(&list[position]);
    }
}

void viewAllComplaints(Complaint list[], int count) {
    int i;

    if (count == 0) {
        printf("No complaints available.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        showComplaint(&list[i]);
    }
}

void updateStatus(Complaint list[], int count) {
    int id = readNumber("Enter complaint ID: ");
    int position = findComplaint(list, count, id);
    int choice;

    if (position == -1) {
        printf("Complaint not found.\n");
        return;
    }

    printf("\n1. Pending\n2. In Progress\n3. Solved\n4. Rejected\n");
    choice = readNumber("Choose new status: ");

    switch (choice) {
        case 1:
            strcpy(list[position].status, "Pending");
            break;
        case 2:
            strcpy(list[position].status, "In Progress");
            break;
        case 3:
            strcpy(list[position].status, "Solved");
            break;
        case 4:
            strcpy(list[position].status, "Rejected");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    saveComplaints(list, count);
    printf("Status updated.\n");
}

void viewPendingComplaints(Complaint list[], int count) {
    int i, found = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].status, "Pending") == 0) {
            showComplaint(&list[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No pending complaints.\n");
    }
}

int adminLogin() {
    FILE *file;
    char savedPassword[30] = "admin123";
    char typedPassword[30];

    file = fopen(PASS_FILE, "r");

    if (file == NULL) {
        file = fopen(PASS_FILE, "w");
        if (file != NULL) {
            fprintf(file, "admin123\n");
            fclose(file);
        }
    } else {
        fscanf(file, "%29s", savedPassword);
        fclose(file);
    }

    readText("Admin password: ", typedPassword, sizeof(typedPassword));

    if (strcmp(typedPassword, savedPassword) == 0) {
        return 1;
    }

    printf("Wrong password.\n");
    return 0;
}

void userMenu(Complaint list[], int *count) {
    int choice;

    do {
        printf("\nUser Menu\n");
        printf("1. Make complaint\n2. Check complaint\n0. Back\n");
        choice = readNumber("Choice: ");

        switch (choice) {
            case 1:
                addComplaint(list, count);
                pauseScreen();
                break;
            case 2:
                checkComplaint(list, *count);
                pauseScreen();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                pauseScreen();
        }
    } while (choice != 0);
}

void adminMenu(Complaint list[], int *count) {
    int choice;

    if (adminLogin() == 0) {
        return;
    }

    do {
        printf("\nAdmin Menu\n");
        printf("1. View all\n2. Update status\n3. View pending\n0. Back\n");
        choice = readNumber("Choice: ");

        switch (choice) {
            case 1:
                viewAllComplaints(list, *count);
                pauseScreen();
                break;
            case 2:
                updateStatus(list, *count);
                pauseScreen();
                break;
            case 3:
                viewPendingComplaints(list, *count);
                pauseScreen();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                pauseScreen();
        }
    } while (choice != 0);
}

int main() {
    Complaint *list;
    int count, choice;

    list = (Complaint *) malloc(MAX * sizeof(Complaint));
    if (list == NULL) {
        printf("Memory problem. Program cannot start.\n");
        return 1;
    }

    count = loadComplaints(list);

    do {
        printf("\nComplaint Management System\n");
        printf("1. User\n2. Admin\n0. Exit\n");
        choice = readNumber("Choice: ");

        switch (choice) {
            case 1:
                userMenu(list, &count);
                break;
            case 2:
                adminMenu(list, &count);
                break;
            case 0:
                saveComplaints(list, count);
                printf("Data saved. Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free(list);
    return 0;
}
