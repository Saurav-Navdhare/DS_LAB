#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
int size = 0;
int i = 0;
struct customer
{
    int accountno;
    long int phno;
    char name[50];
    float balance;
};
struct customer list[100];
void data(int);
void display(void);
void insert(int);
int find(int);
void deposit(int, int);
void withdraw(int, int);

void data(int n)
{
    int j;
    for (j = 0; j < n; j++)
    {
        printf("\nEnter data for the record no.%d", j + 1);
        printf("\nEnter accountno : ");
        scanf("%d", &list[size].accountno);
        printf("Enter name: ");
        scanf("%s", list[size].name);
        printf("Enter phone : ");
        scanf("%ld", &list[size].phno);
        list[size].balance = 0;
        size++;
    }
}
void display()
{
    int i;
    printf("\n\nA/c number\tName\tphone\tbalance\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t%s\t\t%ld\t%f\n", list[i].accountno, list[i].name, list[i].phno, list[i].balance);
    }
}
int find(int number)
{
    for (i = 0; i < size; i++)
    {
        if (list[i].accountno == number)
        {
            return i;
        }
    }
    return -1;
}
void deposit(int number, int amount)
{
    int i = find(number);
    if (i == -1)
    {
        printf("record not found\n");
    }
    else
    {
        list[i].balance += amount;
    }
}
void withdraw(int number, int amount)
{
    int i = find(number);
    if (i == -1)
    {
        printf("Record not found\n");
    }
    else if (list[i].balance < amount)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= amount;
    }
}

struct hash_record
{
    int acc_num; // Hash Table Fields
    char name[20];
    long pno;
    float balance;
}; // Declaring Array of Pointers to "SIZE" number of Bank Accounts
//(declaring Hash Table of SIZE entries)
struct hash_record *accounts[SIZE];
int hash(int acc_num) // Modulo Division Hash Function
{
    return acc_num % SIZE;
}
struct hash_record *hash_search(int acc_num)
{
    int index = hash(acc_num);   // get index for the corresponding Account Number
    if (accounts[index] != NULL) // if Account Number exists
        return accounts[index];
    return NULL;
}
void hash_create()
{
    int acc_num;
    char name[30];
    long pno;
    struct hash_record *item = (struct hash_record *)
        malloc(sizeof(struct hash_record)); // allocate memory for item
    printf("Enter accno, name, phone\n");
    scanf("%d %s %ld", &acc_num, name, &pno);
    item->acc_num = acc_num;
    strcpy(item->name, name);
    item->pno = pno;
    item->balance = 0;
    int index = hash(acc_num);   // get hash index corresponding to Account Number
    if (accounts[index] != NULL) // if Bank Account with Account Number already exists in the Hash Table
    {
        printf("A Bank Account with the Account Number %d", acc_num);
        printf(" already exists\n");
        return;
    }
    accounts[index] = item; // inserting new Bank Record at index
}
struct hash_record *hash_delete(int acc_num)
{
    int index = hash(acc_num); // get hash index corresponding to Account Number
    if (accounts[index] != NULL)
    {
        printf("\nBank Account with Account Number %d", acc_num);
        printf(" has been deleted\n");
        accounts[index] = NULL; // deleting Bank Account by assigning NULL
    }
    else
        printf("Bank Account not Found!\n");
    return NULL;
}
void hash_display()
{
    int i = 0;
    printf("----------------------------------------------------------------");
    printf("--------------------------------\n");
    printf("|Account Number\t|Name\t|Phone Number\t|Balance\t|\n");
    printf("----------------------------------------------------------------");
    printf("--------------------------------\n");
    for (i = 1; i < SIZE; i++) // traversing through the Hash Table
    {
        if (accounts[i] != NULL)
        {
            printf("|\t%d|\t%s|", accounts[i]->acc_num, accounts[i]->name);
            printf("\t%ld|", accounts[i]->pno);
            printf("\t%f|\n", accounts[i]->balance);
        }
    }
    printf("---------------------------------------------------------------");
    printf("---------------------------------\n");
}
void hash_deposit(int acc_num, float amt)
{
    accounts[acc_num]->balance += amt; // update balance in Bank Account
    printf("%f rupees has been deposited in your account\n", amt);
    printf("The balance in your account is: ");
    printf("%f rupees\n", accounts[acc_num]->balance);
    return;
    printf("Bank Account not Found!\n");
}
void hash_withdraw(int acc_num, float amt)
{
    if (accounts[acc_num]->balance > amt) // check if sufficient balance is present
    {
        accounts[acc_num]->balance -= amt; // update balance
        printf("%f rupees has been withdrawn in your account\n", amt);
        printf("The balance in your account is:");
        printf("%f rupees\n", accounts[acc_num]->balance);
    }
    else
    {
        printf("Unable to withdraw more than your balance.\n");
        printf("The balance in your account is:");
        printf("%f rupees\n", accounts[acc_num]->balance);
    }
}
int main()
{
    int selection;
    printf("\nBanking system types\n");
    printf("Enter 1 for banking system using queues and arrays\n");
    printf("Enter 2 for banking system using hash\n");
    printf("Your choice: ");
    scanf("%d", &selection);
    if (selection == 1)
    {
        int n, choice, accountno, amount, index;
        printf("Banking system\n\n");
        printf("Number of customer records you want to enter : ");
        scanf("%d", &n);
        data(n);
        do
        {
            printf("\nBanking system menu : \n");
            printf("press 1 to display all records.\n");
            printf("press 2 to search a record.\n");
            printf("press 3 to deposit amount.\n");
            printf("press 4 to withdraw amount.\n");
            printf("press 5 to create a new account\n");
            printf("press 6 to exit\n");
            printf("\nEnter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                display();
                break;
            case 2:
                printf("Enter account number to search : ");
                scanf("%d", &accountno);
                index = find(accountno);
                if (index == -1)
                {
                    printf("Record not found");
                }
                else
                {
                    printf("A/c no: %d\nName: %s\nPhone: %ld\nBalance: %f\n", list[index].accountno, list[index].name, list[index].phno, list[index].balance);
                }
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%d", &accountno);
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(accountno, amount);
                break;
            case 4:
                printf("Enter account number : ");
                scanf("%d", &accountno);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(accountno, amount);
                break;
            case 5:
                printf("Number of customer records you want to enter : ");
                scanf("%d", &n);
                data(n);
                break;
            }
        } while (choice != 6);
        return 0;
    }
    else
    {
        int ch, acc_num;
        float amt;
        struct hash_record *item;
        while (1)
        {
            printf("\n\nBANKING SYSTEM\n");
            printf("1. Withdraw\n2. Deposit\n3. Get Bank Account Details\n");
            printf("4. Create Bank Account\n5. Close Bank Account\n");
            printf("6. Display all Bank Accounts\n7. Exit\n");
            printf("Enter your choice\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("Enter Account Number:\n");
                scanf("%d", &acc_num);
                if (hash_search(acc_num) != NULL) // check if Account Number exists
                {
                    printf("Enter amount to withdraw:\n");
                    scanf("%f", &amt);
                    hash_withdraw(acc_num, amt); // Withdraw from Bank Account
                }
                else
                    printf("No Bank Account Found!");
                break;
            case 2:
                printf("Enter Account Number:\n");
                scanf("%d", &acc_num);
                if (hash_search(acc_num) != NULL) // check if Account Number exists
                {
                    printf("Enter amount to deposit:\n");
                    scanf("%f", &amt);
                    hash_deposit(acc_num, amt); // deposit to Bank Account
                }
                else
                    printf("No Bank Account Found!");
                break;
            case 3:
                printf("Enter Account Number:\n");
                scanf("%d", &acc_num);
                item = hash_search(acc_num); // get return value from hash_search and store in item
                if (item != NULL)            // if Account exists
                {
                    item = hash_search(acc_num);
                    printf("Bank Account Found!\n");
                    printf("Bank Account Details are:\n\n");
                    printf("------------------------------------------------\n");
                    printf("\n|Account Number\t|Name\t|Phone Number\t");
                    printf("|Balance\t|\n");
                    printf("------------------------------------------------\n");
                    printf("|\t%d|\t%s|", item->acc_num, item->name);
                    printf("|\t%ld|", item->pno);
                    printf("|\t%f|\n", item->balance);
                    printf("------------------------------------------------\n");
                }
                else
                    printf("Bank Account not Found!\n");
                break;
            case 4:
                hash_create(); // create Bank Account
                break;
            case 5:
                printf("Enter Account Number:\n");
                scanf("%d", &acc_num);
                hash_delete(acc_num); // delete Bank Account
                break;
            case 6:
                hash_display(); // Display all Bank Accounts' information
                break;
            case 7:
                exit(0);
            default:
                printf("Enter a valid choice\n");
            }
        }
    }
}