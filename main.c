#include <stdio.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int available;
};

int main() {
    struct Book books[100];
    int count = 0;
    int choice, search, i;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= 100) {
                    printf("Library is full!\n");
                    break;
                }

                printf("Enter Book ID: ");
                if (scanf("%d", &books[count].id) != 1) {
                    printf("Invalid Book ID!\n");
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    break;
                }

                for (i = 0; i < count; i++) {
                    if (books[i].id == books[count].id)
                        break;
                }

                if (i < count) {
                    printf("Book ID already exists!\n");
                    break;
                }

                printf("Enter Book Name: ");
                scanf(" %49[^\n]", books[count].name);

                printf("Enter Author Name: ");
                scanf(" %49[^\n]", books[count].author);

                books[count].available = 1;
                count++;

                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No books available!\n");
                    break;
                }

                for (i = 0; i < count; i++) {
                    printf("\nBook ID: %d\n", books[i].id);
                    printf("Book Name: %s\n", books[i].name);
                    printf("Author: %s\n", books[i].author);
                    printf("Status: %s\n",
                        books[i].available ? "Available" : "Issued");
                }
                break;

            case 3:
                printf("Enter Book ID to Search: ");
                if (scanf("%d", &search) != 1) {
                    printf("Invalid Book ID!\n");
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    break;
                }

                for (i = 0; i < count; i++) {
                    if (books[i].id == search) {
                        printf("Book Found!\n");
                        printf("Book Name: %s\n", books[i].name);
                        printf("Author: %s\n", books[i].author);
                        printf("Status: %s\n",
                            books[i].available ? "Available" : "Issued");
                        break;
                    }
                }

                if (i == count)
                    printf("Book not found!\n");
                break;

            case 4:
                printf("Enter Book ID to Issue: ");
                if (scanf("%d", &search) != 1) {
                    printf("Invalid Book ID!\n");
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    break;
                }

                for (i = 0; i < count; i++) {
                    if (books[i].id == search) {
                        if (books[i].available) {
                            books[i].available = 0;
                            printf("Book issued successfully!\n");
                        } else {
                            printf("Book is already issued!\n");
                        }
                        break;
                    }
                }

                if (i == count)
                    printf("Book not found!\n");
                break;

            case 5:
                printf("Enter Book ID to Return: ");
                if (scanf("%d", &search) != 1) {
                    printf("Invalid Book ID!\n");
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    break;
                }

                for (i = 0; i < count; i++) {
                    if (books[i].id == search) {
                        if (!books[i].available) {
                            books[i].available = 1;
                            printf("Book returned successfully!\n");
                        } else {
                            printf("Book is already available!\n");
                        }
                        break;
                    }
                }

                if (i == count)
                    printf("Book not found!\n");
                break;

            case 6:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Choose 1 to 6.\n");
        }
    }

    return 0;
}
