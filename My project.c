#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for Account, Book, Member, and Fine
struct Account
{
    char username[50];
    char password[50];
    struct Account* next;
};

struct Book
{
    char title[100];
    char author[100];
    char genre[50];
    int available;
    struct Book* next;
};

struct Member
{
    int member_id;
    char name[100];
    struct Member* next;
    struct Book* borrowed_books;
};

struct Fine
{
    int member_id;
    int amount;
    struct Fine* next;
};

// Global linked lists to store accounts, books, members, and fines
struct Account* accounts = NULL;
struct Book* books = NULL;
struct Member* members = NULL;
struct Fine* fines = NULL;

// Function to load accounts from a file (if it exists)
void loadAccountsFromFile()
{
    FILE* file = fopen("accounts.txt", "r");
    if (file == NULL)
    {
        return; // File does not exist
    }

    char username[50];
    char password[50];

    while (fscanf(file, "%s %s", username, password) == 2)
    {
        struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
        strcpy(newAccount->username, username);
        strcpy(newAccount->password, password);
        newAccount->next = accounts;
        accounts = newAccount;
    }

    fclose(file);
}

// Function to save accounts to a file
void saveAccountsToFile()
{
    FILE* file = fopen("accounts.txt", "w");
    if (file == NULL)
    {
        printf("Error: Unable to save account data.\n");
        return;
    }

    struct Account* current = accounts;
    while (current != NULL)
    {
        fprintf(file, "%s %s\n", current->username, current->password);
        current = current->next;
    }

    fclose(file);
}
// Function to create an "accounts.txt" file
void createAccountsFile()
{
    FILE* file = fopen("accounts.txt", "w");
    if (file == NULL)
    {
        printf("Error: Unable to create accounts.txt file.\n");
        return;
    }
    fclose(file);
}

// Function to create an account
void createAccount(char username[], char password[])
{
    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    strcpy(newAccount->username, username);
    strcpy(newAccount->password, password);
    newAccount->next = accounts;
    accounts = newAccount;

    saveAccountsToFile();
    printf("Account created successfully.\n");
}

// Function to authenticate a user
int authenticateUser(char username[], char password[])
{
    struct Account* current = accounts;
    while (current != NULL)
    {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0)
        {
            return 1; // Authentication successful
        }
        current = current->next;
    }
    return 0; // Authentication failed
}

// Function to add a book
void addBook(char title[], char author[], char genre[], int copies)
{
    for (int i = 0; i < copies; i++)
    {
        struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
        strcpy(newBook->title, title);
        strcpy(newBook->author, author);
        strcpy(newBook->genre, genre);
        newBook->available = 1;
        newBook->next = books;
        books = newBook;
    }
    printf("Book(s) added successfully.\n");
}

// Function to display books
void displayBooks()
{
    struct Book* current = books;
    printf("Books in the library:\n");
    while (current != NULL)
    {
        printf("Title: %s\nAuthor: %s\nGenre: %s\nAvailability: %s\n\n",
               current->title, current->author, current->genre,
               current->available ? "Available" : "Not Available");
        current = current->next;
    }
}

// Function to register a member
void registerMember(int member_id, char name[])
{
    struct Member* newMember = (struct Member*)malloc(sizeof(struct Member));
    newMember->member_id = member_id;
    strcpy(newMember->name, name);
    newMember->next = members;
    newMember->borrowed_books = NULL;
    members = newMember;
    printf("Member registered successfully.\n");
}
// Function to borrow a book
void borrowBook(int member_id, char title[])
{
    struct Book* current = books;
    while (current != NULL)
    {
        if (strcmp(current->title, title) == 0 && current->available)
        {
            // Book found and available for borrowing
            current->available = 0;

            // Find the member by member_id
            struct Member* member = members;
            while (member != NULL)
            {
                if (member->member_id == member_id)
                {
                    // Add the book to the member's borrowed_books list
                    struct Book* borrowedBook = (struct Book*)malloc(sizeof(struct Book));
                    strcpy(borrowedBook->title, title);
                    strcpy(borrowedBook->author, current->author);
                    strcpy(borrowedBook->genre, current->genre);
                    borrowedBook->available = 0;
                    borrowedBook->next = member->borrowed_books;
                    member->borrowed_books = borrowedBook;
                    printf("Book \"%s\" borrowed successfully.\n", title);
                    return;
                }
                member = member->next;
            }
        }
        current = current->next;
    }
    printf("Book \"%s\" not available for borrowing.\n", title);
}

// Function to return a book
void returnBook(int member_id, char title[])
{
    // Find the member by member_id
    struct Member* member = members;
    while (member != NULL)
    {
        if (member->member_id == member_id)
        {
            struct Book* current = member->borrowed_books;
            struct Book* prev = NULL;
            while (current != NULL)
            {
                if (strcmp(current->title, title) == 0)
                {
                    // Book found in member's borrowed books
                    // Mark the book as available
                    struct Book* bookInLibrary = books;
                    while (bookInLibrary != NULL)
                    {
                        if (strcmp(bookInLibrary->title, title) == 0)
                        {
                            bookInLibrary->available = 1;
                            break;
                        }
                        bookInLibrary = bookInLibrary->next;
                    }

                    // Remove the book from member's borrowed_books list
                    if (prev != NULL)
                    {
                        prev->next = current->next;
                    }
                    else
                    {
                        member->borrowed_books = current->next;
                    }

                    free(current);
                    printf("Book \"%s\" returned successfully.\n", title);
                    return;
                }
                prev = current;
                current = current->next;
            }
            printf("Book \"%s\" not found in the member's borrowed books.\n", title);
            return;
        }
        member = member->next;
    }
    printf("Member with ID %d not found.\n", member_id);
}

int main()
{
    printf("LIBRARY MANAGEMENT SYSTEM\n");

    // Load accounts from a file (if it exists)
    loadAccountsFromFile();

    char username[50];
    char password[50];
    int choice;
    int loggedIn = 0;

    do
    {
        // Main menu options
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter your desired username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);
            createAccount(username, password);
            break;
        case 2:
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);

            if (authenticateUser(username, password))
            {
                printf("Login successful!\n");
                loggedIn = 1;
            }
            else
            {
                printf("Login failed. Invalid username or password.\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

        // If the user is logged in, display library options
        if (loggedIn)
        {
            int libraryChoice;
            do
            {
                printf("\nLibrary Options:\n");
                printf("1. Add Book\n");
                printf("2. Display Books\n");
                printf("3. Register Member\n");
                printf("4. Borrow Book\n");
                printf("5. Return Book\n");
                printf("6. Logout and Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &libraryChoice);

                switch (libraryChoice)
                {
                case 1:
                {
                    char title[100], author[100], genre[50];
                    int copies;
                    printf("Enter book title: ");
                    scanf("%s", title);
                    printf("Enter book author: ");
                    scanf("%s", author);
                    printf("Enter book genre: ");
                    scanf("%s", genre);
                    printf("Enter number of copies: ");
                    scanf("%d", &copies);
                    addBook(title, author, genre, copies);
                    break;
                }
                case 2:
                    displayBooks();
                    break;
                case 3:
                {
                    int member_id;
                    char memberName[100];
                    printf("Enter member ID: ");
                    scanf("%d", &member_id);
                    printf("Enter member name: ");
                    scanf("%s", memberName);
                    registerMember(member_id, memberName);
                    break;
                }
                case 4:
                {
                    int member_id;
                    char bookTitle[100];
                    printf("Enter member ID: ");
                    scanf("%d", &member_id);
                    printf("Enter book title to borrow: ");
                    scanf("%s", bookTitle);
                    borrowBook(member_id, bookTitle);
                    break;
                }
                case 5:
                {
                    int member_id;
                    char bookTitle[100];
                    printf("Enter member ID: ");
                    scanf("%d", &member_id);
                    printf("Enter book title to return: ");
                    scanf("%s", bookTitle);
                    returnBook(member_id, bookTitle);
                    break;
                }
                case 6:
                    printf("Logging out...\n");
                    loggedIn = 0;
                    break;
                default:
                    printf("Invalid choice.\n");
                }
            }
            while (libraryChoice != 6);
        }
    }
    while (choice != 3);


    return 0;
}
