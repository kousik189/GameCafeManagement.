#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 1000

// Structure to hold customer info
struct Customer {
    char name[50];
    int hours;
    char membership[10]; // Added for VIP status
};

struct Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

// Define multiple username-password pairs
char validUsers[][20] = {"kousik", "moon", "fahim"};
char validPasswords[][20] = {"KA189", "moon123", "fahim123"};
int userCount = 3;  // Number of users

// Function declarations
int addCustomer();
int showCustomers();
int searchCustomer();
int calculateBill();

int main() {
    char username[20], password[20];

    // Login system
    printf("Welcome to the Gaming Cafe Management System!\n");
    printf("Username: kousik  password: KA189\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int loggedIn = 0;  // Flag to track login success

    // Check credentials against all valid pairs
    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, validUsers[i]) == 0 && strcmp(password, validPasswords[i]) == 0) {
            loggedIn = 1;
            break;  // Exit loop if a match is found
        }
    }

    if (!loggedIn) {
        printf("Access denied. Please try again.\n");
        return 0;
    }

    printf("Access granted. Welcome, %s!\n", username);

    int choice;
    do {
        // Display menu
        printf("\n===== Gaming Cafe Menu =====\n");
        printf("1. Add a new customer\n");
        printf("2. Show all customers\n");
        printf("3. Search customer by name\n");
        printf("4. Calculate bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: showCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: calculateBill(); break;
            case 5: printf("Exiting the system... Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Add a new customer
int addCustomer() {
    if (customerCount < MAX_CUSTOMERS) {
        printf("Enter customer name: ");
        scanf("%s", customers[customerCount].name);
        printf("Enter hours played: ");
        scanf("%d", &customers[customerCount].hours);
        printf("Enter membership type (VIP/Regular): ");
        scanf("%s", customers[customerCount].membership);

        printf("Customer added successfully!\n");
        customerCount++;
        return 1;
    } else {
        printf("Customer list is full!\n");
        return 0;
    }
}

// Show all customers
int showCustomers() {
    if (customerCount == 0) {
        printf("No customers to display!\n");
        return 0;
    } else {
        printf("\nCurrent Customers:\n");
        for (int i = 0; i < customerCount; i++) {
            printf("%d. %s - %d hours - %s membership\n", i + 1, customers[i].name, customers[i].hours, customers[i].membership);
        }
        return 1;
    }
}

// Search for a customer
int searchCustomer() {
    char searchName[50];
    printf("Enter customer name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, searchName) == 0) {
            printf("Customer found!\nName: %s\nHours played: %d\nMembership: %s\n", customers[i].name, customers[i].hours, customers[i].membership);
            return i;
        }
    }
    printf("Customer not found.\n");
    return -1;
}

// Calculate bill with advanced discounts
int calculateBill() {
    char billName[50];
    printf("Enter customer name: ");
    scanf("%s", billName);

    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, billName) == 0) {
            int hours = customers[i].hours;
            float rate = 5.0;
            float total = hours * rate;
            float discount = 0.0;

            // Apply VIP discount
            if (strcmp(customers[i].membership, "VIP") == 0) {
                discount += 0.3 * total;
            }

            // Time-based discount
            if (hours > 10) discount += 0.2 * total;
            else if (hours > 5) discount += 0.1 * total;

            // Weekend discount
            char day[10];
            printf("Enter the day of the week: ");
            scanf("%s", day);
            if (strcmp(day, "Saturday") == 0 || strcmp(day, "Sunday") == 0) {
                discount += 0.15 * total;
            }

            total -= discount;

            printf("\nCalculating bill for %s...\n", customers[i].name);
            printf("Hours played: %d\n", hours);
            printf("Base rate: $%.2f/hour\n", rate);
            printf("Subtotal: $%.2f\n", hours * rate);
            printf("Discount applied: $%.2f\n", discount);
            printf("Total: $%.2f\n", total);
            return 1;
        }
    }
    printf("Customer not found.\n");
    return 0;
}
