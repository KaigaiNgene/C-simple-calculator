#include <stdio.h>
#include <stdbool.h>

double Balance = 1000.00;

bool login(void) {
    int PIN;

    for (int count = 0; count < 3; count++) {
        printf("Enter 4-digit PIN: ");
        scanf("%d", &PIN);

        if (PIN == 1234) {
            return true;
        } else {
            printf("Wrong PIN. Try again. (Attempts left: %d)\n", 2 - count);
        }
    }

    printf("Attempts exceeded. Login failed.\n");
    return false;
}

void checkBalance(void) {
    printf("\nThe current Balance is: $%.2f\n", Balance);
}

double Deposit(double amount) {
    if (amount > 0.0) {
        Balance += amount;
        printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, Balance);
    } else {
        printf("Invalid deposit amount. Must be greater than zero.\n");
    }
    return Balance;
}

double Withdraw(double amount) {
    if (amount <= 0.0) {
        printf("Invalid withdrawal amount. Must be greater than zero.\n");
    } else if (amount > Balance) {
        printf("Balance insufficient. Current Balance: $%.2f\n", Balance);
    } else {
        Balance -= amount;
        printf("Successfully withdrew $%.2f. Remaining Balance: $%.2f\n", amount, Balance);
    }
    return Balance;
}

int main(void) {
    int choice;
    double amount;

    // Terminate if 3 attempts fail
    if (!login()) {
        return 1;
    }

    printf("\nLogin successful! Welcome to the ATM.\n");

    do {
        printf("\n=========================\n");
        printf("        ATM MENU         \n");
        printf("=========================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("=========================\n");

        printf("Select a choice between 1-4: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                printf("How much do you want to Deposit?: ");
                scanf("%lf", &amount);
                Deposit(amount);
                break;
            case 3:
                printf("How much do you want to Withdraw?: ");
                scanf("%lf", &amount);
                Withdraw(amount);
                break;
            case 4:
                printf("Thank you. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select an option from 1 to 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
