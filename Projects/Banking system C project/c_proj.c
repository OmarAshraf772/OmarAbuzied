# include<stdio.h>
# include<stdlib.h>
# include "STD_TYPES.h"
# include <string.h>
# include <time.h>


typedef struct {
    u8 Name[50];
    u8 address[50];
    u8 nationalID[14];
    u8 age;
    u32 accountID;
	u8 Guardian_name[50];
    u8 guardianNationalID[14];
    u8 accountStatus[20];
    f32 balance;
    char* password;
} Bank_Account;

typedef struct {
    u8 username[8];
    u8 password[8];
} Admin;

Admin admin_user = {"admin", "pass"};
Bank_Account accounts[100];
u16 numAccounts = 0;
u32 accountID;

void create_Account();
char* generatePassword(u8 length);
void openAccount();
void makeTransaction(s8 accountIndex);
void changeAccountStatus(u16 accountIndex, u8 newStatus);
void getCash(u16 accountIndex);
void deposit_in_account(u16 accountIndex);
void changeAccountPassword(u8 accountIndex);
void clientMainMenu(u8 accountIndex);
void adminWindow();
void clientWindow();


void main(void){
	
u8 choice;

    do {
        printf("\nWelcome to the Banking System!\n");

        printf("\nMain Menu\n");
        printf("1. Admin Window\n");
        printf("2. Client Window\n");
        printf("3. Exit the System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                adminWindow();
                break;
            case 2:
                clientWindow();
                break;
            case 3:
                printf("\nExiting the system...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);
}

void create_Account() {
    Bank_Account newAccount;
	fflush(stdin);
	printf("\nCreate New Account\n");
    printf("Enter Full Name: ");
    fgets(newAccount.Name, 50, stdin);
    printf("Enter Full Address: ");
    fgets(newAccount.address, 50, stdin);
    printf("Enter National ID: ");
    fgets(newAccount.nationalID, 14, stdin);
    printf("Enter Age: ");
    scanf("%ld", &newAccount.age);
	fflush(stdin);

    if (newAccount.age < 21) {
		printf("Enter Guardian Name: ");
        fgets(newAccount.Guardian_name,50, stdin);
        printf("Enter Guardian National ID: ");
        fgets(newAccount.guardianNationalID,14, stdin);
    }

    printf("Enter Balance: ");
    scanf("%f", &newAccount.balance);
	fflush(stdin);

    // Generate account ID automatically
    newAccount.accountID = 1000000000 + numAccounts + 1;

    // Set account status to Active by default
    strcpy(newAccount.accountStatus, "Active");
	
	
	printf("\nAccount ID: %ld\n",newAccount.accountID);
	char* pass = generatePassword(8);
    if (pass != NULL) {
		strcpy(newAccount.password,pass);
        free(pass); 
    }
	printf("\nAccount status is: %s\n",newAccount.accountStatus);

    
    accounts[numAccounts] = newAccount;
    numAccounts++;

    printf("\nNew account created successfully.\n");
	printf("Generated password: %s\n", accounts[0].password);
	return;
}

char* generatePassword(u8 length) {
    char* password = (char*)malloc((length + 1) * sizeof(u8)); 
    if (password == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    srand(time(NULL));
	
    u8 i;
    for (i = 0; i < length; i++) {
        u8 randomChoice = rand() % 2; 

        if (randomChoice == 0) {
            
            password[i] = '0' + (rand() % 10);
        } else {
         
            u8 lowercase = rand() % 2; 

            if (lowercase == 0) {
                // Generate a lowercase letter
                password[i] = 'a' + (rand() % 26);
            } else {
                // Generate an uppercase letter
                password[i] = 'A' + (rand() % 26);
            }
        }
    }

    password[length] = '\0'; 
    return password;
}

void openAccount() {
    u32 accountID;
    u8 stat;
    printf("\nOpen Existing Account\n");
    printf("Enter Bank Account ID: ");
    scanf("%d", &accountID);

    s8 accountIndex = -1;
    for (u8 i = 0; i < numAccounts; i++) {
        if (accounts[i].accountID == accountID) {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex != -1) {

            int choice;

            do {
                printf("\nExisting Account Main Menu\n");
                printf("1. Make Transaction\n");
                printf("2. Change Account Status\n");
                printf("3. Get Cash\n");
                printf("4. Deposit in Account\n");
                printf("5. Return to Admin Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        makeTransaction(accountIndex);
                        break;
                    case 2:
					   
						printf("Choose Account Status\n: ");
						printf("1- Active\n2-Restricted\n3-Closed\n ");
						printf("Your choice: ");
						scanf("%d",&stat);
                        changeAccountStatus(accountIndex,stat);
                        break;
                    case 3:
                        getCash(accountIndex);
                        break;
                    case 4:
                        deposit_in_account(accountIndex);
                        break;
                    case 5:
                        printf("Returning to Admin Main Menu...\n");
                        return;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }
            } while (1);
       
        }
     else {
        printf("Account not found. Please check the account ID and try again.\n");
    }
}
void makeTransaction(s8 accountIndex) {
    u32 targetAccountID;
	s8 targetAccountIndex;
    f32 amount;

    printf("\nMake Transaction\n");
    printf("Enter Recipient Bank Account ID: ");
    scanf("%d", &targetAccountID);
    printf("Enter amount of money: ");
    scanf("%f", &amount);

    
        if (amount > accounts[accountIndex].balance) {
            printf("Insufficient balance. Transaction cannot be completed.\n");
            return;
        }
 
	if (strcmp(accounts[accountIndex].accountStatus, "Restricted") == 0 ||
        strcmp(accounts[accountIndex].accountStatus, "Closed") == 0) {
        printf("Your account is restricted or closed. Transaction cannot be completed.\n");
        return;
    }

     targetAccountIndex = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountID == targetAccountID) {
            targetAccountIndex = i;
            break;
        }
    }

    if (targetAccountIndex == -1) {
        printf("Recipient account not found. Transaction cannot be completed.\n");
        return;
    }

    if (strcmp(accounts[targetAccountIndex].accountStatus, "Restricted") == 0 ||
        strcmp(accounts[targetAccountIndex].accountStatus, "Closed") == 0) {
        printf("Recipient account is restricted or closed. Transaction cannot be completed.\n");
        return;
    }
  
        accounts[accountIndex].balance -= amount;
        accounts[targetAccountIndex].balance += amount;
  

    printf("\n\nTransaction completed successfully.\n");
	printf("\nRemaining Balance: %f\n",accounts[accountIndex].balance);
	
}

void changeAccountStatus(u16 accountIndex, u8 newStatus) {
    if (accountIndex < 0 || accountIndex >= numAccounts) {
        printf("Invalid account index. Account status cannot be changed.\n");
        return;
    }

    switch (newStatus) {
        case 1:
            strcpy(accounts[accountIndex].accountStatus, "Active");
            break;
        case 2:
            strcpy(accounts[accountIndex].accountStatus, "Restricted");
            break;
        case 3:
            strcpy(accounts[accountIndex].accountStatus, "Closed");
            break;
        default:
            printf("Invalid account status code. Account status cannot be changed.\n");
            return;
    }

    printf("\nAccount status changed successfully.\n");
	printf("\nNew Status: %s",accounts[accountIndex].accountStatus);
}
void getCash(u16 accountIndex) {
    f32 Amount;

    printf("\nGet Cash\n");
    printf("Enter the cash amount you want to withdraw: ");
    scanf("%f", &Amount);

    if (Amount > accounts[accountIndex].balance) {
        printf("Insufficient balance. Process cannot be completed.\n");
        return;
    }

    accounts[accountIndex].balance -= Amount;
    printf("Cash operation successful.\n");
	printf("\nRemaining Balance: %f\n",accounts[accountIndex].balance);
}
void deposit_in_account(u16 accountIndex) {
    f32 Amount;

    printf("\nDeposit in Account\n");
    printf("Enter the cash amount you want to deposit: ");
    scanf("%f", &Amount);

    accounts[accountIndex].balance += Amount;
    printf("Deposit operation successful.\n");
	printf("\nAccount Balance: %f\n",accounts[accountIndex].balance);
}

void changeAccountPassword(u8 accountIndex) {
    char oldPassword[9];
    char newPassword[9];

    printf("\nChange Account Password\n");
    printf("Enter old password: ");
    scanf("%8s", oldPassword);
    printf("Enter new password: ");
    scanf("%8s", newPassword);
    if (strcmp(accounts[accountIndex].password, oldPassword) == 0) {
        strncpy(accounts[accountIndex].password, newPassword, 8);
        accounts[accountIndex].password[8] = '\0';
        printf("Password changed successfully.\n");
    } else {
        printf("Incorrect old password. Password change failed.\n");
    }
}
void clientMainMenu(u8 accountIndex) {
    u8 Clientchoice;

    do {
        printf("\nClient Main Menu\n");
        printf("1. Make a Transaction\n");
        printf("2. Change Account Password\n");
        printf("3. Get Cash\n");
        printf("4. Deposit in account\n");
        printf("5. Exit the Client Window\n");
        printf("Enter your choice: ");
        scanf("%d", &Clientchoice);

        switch (Clientchoice) {
            case 1:
                makeTransaction(accountIndex);
                break;
            case 2:
                changeAccountPassword(accountIndex);
                break;
            case 3:
                getCash(accountIndex);
                break;
            case 4:
                deposit_in_account(accountIndex);
                break;
            case 5:
                printf("Exiting the Client Window...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);
}
void adminWindow() {
    u8 username[20];
    u8 admin_password[20];
    u8 adminChoice;

    printf("\nAdmin Window\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", admin_password);

    if (strcmp(username, admin_user.username) == 0 && strcmp(admin_password, admin_user.password) == 0) {
        while (adminChoice != 3) {
            printf("\nAdmin Main Menu\n");
            printf("1. Create New Account\n");
            printf("2. Open Existing Account\n");
            printf("3. Exit the Admin Window\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
                case 1:
                    create_Account();
                    break;
                case 2:
                    openAccount();
                    break;
                case 3:
                    printf("Returning to the Window Selection...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    } else {
        printf("Invalid username or password. Access denied.\n");
    }
}

void clientWindow() {
    u8 clientPassword[8];

    printf("\nClient Window\n");
    printf("Enter Bank Account ID: ");
    scanf("%ld", &accountID);

    s8 accountIndex = -1;
    for (u8 i = 0; i < numAccounts; i++) {
        if (accounts[i].accountID == accountID) {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex != -1) {
        printf("Enter Account Password: ");
        scanf("%s", clientPassword);

        if (strcmp(accounts[accountIndex].password, clientPassword) == 0) {
            clientMainMenu(accountIndex);
        } else {
            printf("Incorrect password. Access denied.\n");
        }
    } else {
        printf("Account not found. Please check the account ID and try again.\n");
    }
}