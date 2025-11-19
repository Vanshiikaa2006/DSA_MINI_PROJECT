#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[20];
};

struct Contact contacts[MAX];
int count = 0;

// Add a contact
void addContact() {
    if(count == MAX) {
        printf("Contact list full!\n");
        return;
    }
    printf("Enter Name: ");
    scanf("%s", contacts[count].name);
    printf("Enter Phone: ");
    scanf("%s", contacts[count].phone);
    count++;
    printf("Contact added successfully!\n");
}

// Display all contacts
void displayContacts() {
    if(count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

// Search contact
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            printf("Contact Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Delete contact
void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, name) == 0) {
            for(int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Main menu
int main() {
    int choice;

    while(1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
