#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxUsers 10 
#define MaxNameLengh 20
#define MaxPasswordLengh 20

struct User {
    char name[MaxNameLengh];
    char password[MaxPasswordLengh];
};

struct User users[MaxUsers];
int userCount = 0;

int registration() {
    if (userCount >= MaxUsers) {
        printf("Maximum user limit reached.\n");
        return 0;
    }

    struct User newUser;

    printf("Enter a username (up to %d characters): ", MaxNameLengh);
    scanf("%s", newUser.name);

    printf("Enter a password (up to %d characters): ", MaxPasswordLengh);
    scanf("%s", newUser.password);

    users[userCount++] = newUser;

    printf("User registered successfully.\n");

    return 1;
}

int authentication() {
    char username[MaxNameLengh];
    char password[MaxPasswordLengh];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("User authentication successful.\n");
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;
    int isRunning = 1;

    while (isRunning) {
        printf("1. Register\n");
        printf("2. Authenticate\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                isRunning = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}