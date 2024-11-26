#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[50];
    char author[50];
    struct Book *next;
} Book;

Book *head = NULL;

// Function to add a book
void addBook(int id, char title[], char author[]) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = head;
    head = newBook;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (head == NULL) {
        printf("No books in the library.\n");
        return;
    }
    Book *temp = head;
    printf("Books in the library:\n");
    while (temp != NULL) {
        printf("ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

// Function to search for a book by ID
void searchBook(int id) {
    Book *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book found! ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

// Function to delete a book by ID
void deleteBook(int id) {
    Book *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Book deleted successfully!\n");
}

int main() {
    int choice, id;
    char title[50], author[50];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                getchar(); // Consume newline
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter book author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline
                addBook(id, title, author);
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
