#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

int login(void)
{
    char username[30], password[20];
    FILE *log;
    log = fopen("loginindex.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct login l;
    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username: ");
    fgets(username, 30, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("\nPassword: ");
    fgets(password, 20, stdin);
    password[strcspn(password, "\n")] = '\0';
    while (fread(&l, sizeof(l), 1, log))
    {
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
        {
            printf("\nSuccessful Login\n");
            fclose(log);
            return 1;
        }
        else
        {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            fclose(log);
            return 0;
        }
    }
}

int registration(void)
{
    char firstname[15];
    FILE *log;
    log = fopen("loginindex.txt", "w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct login l;
    printf("\nWelcome to your online course provider. We need to enter some details for registration.\n\n");
    printf("\nEnter First Name:\n");
    fgets(l.fname, sizeof(l.fname), stdin);
    printf("\nEnter Surname:\n");
    fgets(l.lname, sizeof(l.lname), stdin);
    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");
    printf("\nEnter Username:\n");
    scanf("%s", l.username);
    printf("\nEnter Password:\n");
    scanf("%s", l.password);
    fwrite(&l, sizeof(l), 1, log);
    fclose(log);
    printf("\nConfirming details...\n...\nWelcome, %s!\n\n", firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getchar();
    system("CLS");
    int x = login();
    return x;
}

int performLogin()
{
    int option;
    printf("\t\t\tWelcome to Indian Railways\n");
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d", &option);
    getchar();
    if (option == 1)
    {
        system("CLS");
        registration();
    }
    else if (option == 2)
    {
        system("CLS");
        int x = login();
    }
}

int PNR = 695630;
int wait = 50;

typedef struct seat
{
    int pnr;
    int tickets;
    char pass_name[20];
    struct seat *link;
    struct seat *prev;
    char source[20];
    char destination[20];
} seat;

typedef struct wagon
{
    struct wagon *next;
    int avl_seat;
    char name[3];
    seat *seats;
} wagon;

typedef struct train
{
    char name[20];
    int train_no;
    wagon *B1, *B2;
} train;

typedef struct waiting
{
    int pnr;
    int tickets;
    char pass_name[20];
    struct waiting *link;
    struct waiting *prev;
    char source[20];
    char destination[20];
} waiting;

typedef struct wait1
{
    int pnr;
    int tickets;
    char pass_name[20];
    struct wait1 *link;
    struct wait1 *prev;
    char source[20];
    char destination[20];
} wait1;

typedef struct wait2
{
    int pnr;
    int tickets;
    char pass_name[20];
    struct wait2 *link;
    struct wait2 *prev;
    char source[20];
    char destination[20];
} wait2;

typedef struct wait3
{
    int pnr;
    int tickets;
    char pass_name[20];
    struct wait3 *link;
    struct wait3 *prev;
    char source[20];
    char destination[20];
} wait3;

wagon *head;
wagon *current;

seat *s1, *s2;
wait1 *f1, *r1;
wait2 *f2, *r2;
wait3 *f3, *r3;

void insert(train *my_train, int tickets)
{
    if (tickets <= my_train->B1->avl_seat)
    {
        my_train->B1->seats = malloc(sizeof(seat));
        seat *temp = s1;
        if (temp == NULL)
        {
            my_train->B1->seats->pnr = PNR;
            my_train->B1->seats->tickets = tickets;
            my_train->B1->avl_seat -= tickets;
            printf("\nEnter Passenger Name:");
            scanf("%s", my_train->B1->seats->pass_name);
        check1:
            printf("\nEnter Boarding Statiion Name:");
            scanf("%s", my_train->B1->seats->source);
            printf("\nEnter Destination Station Name:");
            scanf("%s", my_train->B1->seats->destination);
            if ((strcmp(my_train->B1->seats->source, "mumbai") != 0 && strcmp(my_train->B1->seats->destination, "delhi") != 0) &&
                (strcmp(my_train->B1->seats->source, "mumbai") != 0 && strcmp(my_train->B1->seats->destination, "surat") != 0) &&
                (strcmp(my_train->B1->seats->source, "surat") != 0 && strcmp(my_train->B1->seats->destination, "delhi") != 0))
            {
                printf("Wrong Source or Destination name.");
                goto check1;
            }

            my_train->B1->seats->link = NULL;
            my_train->B1->seats->prev = NULL;
            s1 = my_train->B1->seats;
        }
        else
        {
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            my_train->B1->seats->pnr = PNR;
            my_train->B1->seats->tickets = tickets;
            my_train->B1->avl_seat -= tickets;
            printf("\nEnter Passenger Name:");
            scanf("%s", my_train->B1->seats->pass_name);
        check2:
            printf("\nEnter Boarding Statiion Name:");
            scanf("%s", my_train->B1->seats->source);
            printf("\nEnter Destination Station Name:");
            scanf("%s", my_train->B1->seats->destination);
            if ((strcmp(my_train->B1->seats->source, "mumbai") != 0 && strcmp(my_train->B1->seats->destination, "delhi") != 0) &&
                (strcmp(my_train->B1->seats->source, "mumbai") != 0 && strcmp(my_train->B1->seats->destination, "surat") != 0) &&
                (strcmp(my_train->B1->seats->source, "surat") != 0 && strcmp(my_train->B1->seats->destination, "delhi") != 0))
            {
                printf("Wrong Source or Destination name.");
                goto check2;
            }
            scanf("%s", my_train->B1->seats->pass_name);
            temp->link = my_train->B1->seats;
            my_train->B1->seats->link = NULL;
            my_train->B1->seats->prev = temp;
        }
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\nPNR Number:%d", my_train->B1->seats->pnr);
        printf("\nPassenger Name:%s", my_train->B1->seats->pass_name);
        printf("\nTrain Name:%s", my_train->name);
        printf("\nTrain Number:%d", my_train->train_no);
        printf("\nTotal No. Of tickets:%d", my_train->B1->seats->tickets);
        printf("\nBoarding Station Name:%s", my_train->B1->seats->source);
        printf("\nDestination Station Name:%s", my_train->B1->seats->destination);
        printf("\nStatus: Confirm Ticket");
        printf("\nCoach Name:%s", my_train->B1->name);
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
    }
    else if (tickets <= my_train->B2->avl_seat)
    {
        my_train->B2->seats = malloc(sizeof(seat));
        seat *temp = s2;
        if (temp == NULL)
        {
            my_train->B2->seats->pnr = PNR;
            my_train->B2->seats->tickets = tickets;
            my_train->B2->avl_seat -= tickets;
            printf("\nEnter Passenger Name:");
            scanf("%s", my_train->B2->seats->pass_name);
        check3:
            printf("\nEnter Boarding Statiion Name:");
            scanf("%s", my_train->B2->seats->source);
            printf("\nEnter Destination Station Name:");
            scanf("%s", my_train->B2->seats->destination);
            if ((strcmp(my_train->B2->seats->source, "mumbai") != 0 && strcmp(my_train->B2->seats->destination, "delhi") != 0) &&
                (strcmp(my_train->B2->seats->source, "mumbai") != 0 && strcmp(my_train->B2->seats->destination, "surat") != 0) &&
                (strcmp(my_train->B2->seats->source, "surat") != 0 && strcmp(my_train->B2->seats->destination, "delhi") != 0))
            {
                printf("Wrong Source or Destination name.");
                goto check3;
            }
            scanf("%s", my_train->B2->seats->pass_name);
            my_train->B2->seats->link = NULL;
            my_train->B2->seats->prev = NULL;
            s2 = my_train->B2->seats;
        }
        else
        {
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            my_train->B2->seats->pnr = PNR;
            my_train->B2->seats->tickets = tickets;
            my_train->B2->avl_seat -= tickets;
            printf("\nEnter Passenger Name:");
            scanf("%s", my_train->B2->seats->pass_name);
        check4:
            printf("\nEnter Boarding Statiion Name:");
            scanf("%s", my_train->B2->seats->source);
            printf("\nEnter Destination Station Name:");
            scanf("%s", my_train->B2->seats->destination);
            if ((strcmp(my_train->B2->seats->source, "mumbai") != 0 && strcmp(my_train->B2->seats->destination, "delhi") != 0) &&
                (strcmp(my_train->B2->seats->source, "mumbai") != 0 && strcmp(my_train->B2->seats->destination, "surat") != 0) &&
                (strcmp(my_train->B2->seats->source, "surat") != 0 && strcmp(my_train->B2->seats->destination, "delhi") != 0))
            {
                printf("Wrong Source or Destination name.");
                goto check4;
            }
            scanf("%s", my_train->B2->seats->pass_name);
            temp->link = my_train->B2->seats;
            my_train->B2->seats->link = NULL;
            my_train->B2->seats->prev = temp;
        }
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\nPNR Number:%d", my_train->B2->seats->pnr);
        printf("\nPassenger Name:%s", my_train->B2->seats->pass_name);
        printf("\nTrain Name:%s", my_train->name);
        printf("\nTrain Number:%d", my_train->train_no);
        printf("\nTotal No. Of tickets:%d", my_train->B2->seats->tickets);
        printf("\nBoarding Station Name:%s", my_train->B2->seats->source);
        printf("\nDestination Station Name:%s", my_train->B2->seats->destination);
        printf("\nStatus: Confirm Ticket");
        printf("\nCoach Name:%s", my_train->B2->name);
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
    }
    PNR++;
}

void insert_waiting(int tickets, train *my_train)
{
    if (wait - tickets >= 0)
    {
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\nAll Tickets are booked inside the train. Do you want to get a ticket in the waiting list?");
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

        printf("\n\nIf You Want To purchase tickets in the waiting list then press 1.\nEnter Your Choice:");
        int c;
        scanf("%d", &c);
        if (c != 1)
            return;
        else
        {
            waiting *ptr = malloc(sizeof(waiting));
        station:
            printf("Enter Boarding Station:");
            scanf("%s", ptr->source);
            printf("Enter destination Station:");
            scanf("%s", ptr->destination);
            if ((strcmp(ptr->source, "mumbai") == 0 && strcmp(ptr->destination, "delhi") == 0) &&
                (strcmp(ptr->source, "surat") == 0 && strcmp(ptr->destination, "delhi") == 0) &&
                (strcmp(ptr->source, "mumbai") == 0 && strcmp(ptr->destination, "surat") == 0))
            {

                if (strcmp(ptr->source, "mumbai") == 0 && strcmp(ptr->destination, "delhi") == 0)
                {
                    wait1 *temp = malloc(sizeof(wait1));
                    temp->pnr = PNR;
                    temp->tickets = tickets;
                    wait -= tickets;
                    strcpy(temp->source, ptr->source);
                    strcpy(temp->destination, ptr->destination);
                    printf("\nEnter Passenger Name:");
                    scanf("%s", temp->pass_name);

                    if (f1 == NULL)
                    {
                        temp->link = NULL;
                        temp->prev = NULL;
                        f1 = temp;
                        r1 = temp;
                    }
                    else
                    {
                        temp->link = NULL;
                        temp->prev = r1;
                        r1->link = temp;
                        r1 = temp;
                    }

                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Tickets details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPNR:%d ", temp->pnr);
                    printf("\nPassenger Name:%s ", temp->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nNumber of tickets  booked:%d ", temp->tickets);
                    printf("\nBoarding Station:%s ", temp->source);
                    printf("\nDestination Station:%s ", temp->destination);
                    printf("\nStatus: Waiting Ticket");
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*---------------------------------------*-");
                    PNR++;
                    return;
                }
                else if (strcmp(ptr->source, "surat") == 0 && strcmp(ptr->destination, "delhi") == 0)
                {
                    wait2 *temp = malloc(sizeof(wait2));
                    temp->pnr = PNR;
                    temp->tickets = tickets;
                    wait -= tickets;
                    strcpy(temp->source, ptr->source);
                    strcpy(temp->destination, ptr->destination);
                    printf("\nEnter Passenger Name:");
                    scanf("%s", temp->pass_name);
                    if (f2 == NULL)
                    {
                        temp->link = NULL;
                        temp->prev = NULL;
                        f2 = temp;
                        r2 = temp;
                    }
                    else
                    {
                        temp->link = NULL;
                        temp->prev = r2;
                        r2->link = temp;
                        r2 = temp;
                    }

                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Tickets details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPNR:%d ", temp->pnr);
                    printf("\nPassenger Name:%s ", temp->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nNumber of tickets  booked:%d ", temp->tickets);
                    printf("\nBoarding Station:%s ", temp->source);
                    printf("\nDestination Station:%s ", temp->destination);
                    printf("\nStatus: Waiting Ticket");
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    PNR++;
                    return;
                }
                else if (strcmp(ptr->source, "mumbai") == 0 && strcmp(ptr->destination, "surat") == 0)
                {
                    wait3 *temp = malloc(sizeof(wait3));
                    temp->pnr = PNR;
                    temp->tickets = tickets;
                    wait -= tickets;
                    strcpy(temp->source, ptr->source);
                    strcpy(temp->destination, ptr->destination);
                    printf("\nEnter Passenger Name:");
                    scanf("%s", temp->pass_name);

                    if (f3 == NULL)
                    {
                        temp->link = NULL;
                        temp->prev = NULL;
                        f3 = temp;
                        r3 = temp;
                    }
                    else
                    {
                        temp->link = NULL;
                        temp->prev = r3;
                        r3->link = temp;
                        r3 = temp;
                    }

                    printf("\n-*-*-*-*-*-*-*-*-*-------------Tickets details--------------");
                    printf("\nPNR:%d ", temp->pnr);
                    printf("\nPassenger Name:%s ", temp->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nNumber of tickets booked:%d ", temp->tickets);
                    printf("\nBoarding Station:%s ", temp->source);
                    printf("\nDestination Station:%s ", temp->destination);
                    printf("\nStatus: Waiting Ticket");
                    printf("\n-----------------------------------");
                    PNR++;
                    return;
                }
            }
            else
            {
                printf("\nInvalid Source and Destination combination given.");
                goto station;
            }
        }
    }
    else if (wait == 0)
    {
        printf("\n-----------------Alert------------------");
        printf("\n----------------*All Seats Full*---------------");
        printf("\n--------------------------------------");
        return;
    }
    else
    {
        printf("\n-----------------Alert*------------------");
        printf("\n---------Total Remaining Seats In Waiting List is:%d--------", wait);
        printf("\n-----------------------------------------------");

        return;
    }
}

void book_ticket(train *my_train)
{
    int tickets;
    printf("\nEnter Total Tickets:");
    scanf("%d", &tickets);
    if (tickets <= my_train->B1->avl_seat || tickets <= my_train->B2->avl_seat)
    {
        insert(my_train, tickets);
    }
    else
        insert_waiting(tickets, my_train);
}

void checktoinsert(train *my_train, int flag, int go)
{
    if (flag == 0)
    {
        if (go == 1)
        {
            while (f1 != NULL && (f1->tickets <= my_train->B1->avl_seat || f1->tickets <= my_train->B2->avl_seat))
            {
                if (f1->tickets <= my_train->B1->avl_seat)
                {
                    seat *temp = s1;
                    seat *ptr = malloc(sizeof(seat));
                    if (temp == NULL)
                    {
                        my_train->B1->seats = ptr;
                        s1 = ptr;
                    }
                    else
                    {
                        while (temp->link != NULL)
                        {
                            temp = temp->link;
                        }
                        temp->link = ptr;
                        ptr->prev = temp;
                    }
                    ptr->pnr = f1->pnr;
                    ptr->tickets = f1->tickets;
                    strcpy(ptr->pass_name, f1->pass_name);
                    strcpy(ptr->source, f1->source);
                    strcpy(ptr->destination, f1->destination);
                    ptr->link = NULL;
                    wait += f1->tickets;
                    wait1 *pt;
                    pt = f1;
                    f1 = f1->link;
                    if (f1 != NULL)
                    {
                        f1->prev = NULL;
                    }
                    free(pt);
                    my_train->B1->avl_seat -= ptr->tickets;
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                    printf("\nBooking Confirmed for PNR number:%d", ptr->pnr);
                    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPassenger Name:%s", ptr->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nTotal No. Of tickets:%d", ptr->tickets);
                    printf("\nPassenger Boarding Station:%s", ptr->source);
                    printf("\nPassenger Destination Station:%s", ptr->destination);
                    printf("\nStatus: Confirm Ticket");
                    printf("\nCoach Name:%s", my_train->B1->name);
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                }
            }
        }
        else if (go == 2)
        {
            while (f2 != NULL && (f2->tickets <= my_train->B1->avl_seat || f2->tickets <= my_train->B2->avl_seat))
            {
                if (f2->tickets <= my_train->B1->avl_seat)
                {
                    seat *temp = s1;
                    seat *ptr = malloc(sizeof(seat));
                    if (temp == NULL)
                    {
                        my_train->B1->seats = ptr;
                        s1 = ptr;
                    }
                    else
                    {
                        while (temp->link != NULL)
                        {
                            temp = temp->link;
                        }
                        temp->link = ptr;
                        ptr->prev = temp;
                    }
                    ptr->pnr = f2->pnr;
                    ptr->tickets = f2->tickets;
                    strcpy(ptr->pass_name, f2->pass_name);
                    strcpy(ptr->source, f2->source);
                    strcpy(ptr->destination, f2->destination);
                    ptr->link = NULL;
                    wait += f2->tickets;
                    wait2 *pt;
                    pt = f2;
                    f2 = f2->link;
                    if (f2 != NULL)
                    {
                        f2->prev = NULL;
                    }
                    free(pt);
                    my_train->B1->avl_seat -= ptr->tickets;
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                    printf("\nBooking Confirmed for PNR number:%d", ptr->pnr);
                    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPassenger Name:%s", ptr->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nTotal No. Of tickets:%d", ptr->tickets);
                    printf("\nPassenger Boarding Station:%s", ptr->source);
                    printf("\nPassenger Destination Station:%s", ptr->destination);
                    printf("\nStatus: Confirm Ticket");
                    printf("\nCoach Name:%s", my_train->B1->name);
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                }
            }
        }
        else if (go == 3)
        {
            while (f3 != NULL && (f3->tickets <= my_train->B1->avl_seat || f3->tickets <= my_train->B2->avl_seat))
            {
                if (f2->tickets <= my_train->B1->avl_seat)
                {
                    seat *temp = s1;
                    seat *ptr = malloc(sizeof(seat));
                    if (temp == NULL)
                    {
                        my_train->B1->seats = ptr;
                        s1 = ptr;
                    }
                    else
                    {
                        while (temp->link != NULL)
                        {
                            temp = temp->link;
                        }
                        temp->link = ptr;
                        ptr->prev = temp;
                    }
                    ptr->pnr = f3->pnr;
                    ptr->tickets = f3->tickets;
                    strcpy(ptr->pass_name, f3->pass_name);
                    strcpy(ptr->source, f3->source);
                    strcpy(ptr->destination, f3->destination);
                    ptr->link = NULL;
                    wait += f3->tickets;
                    wait3 *pt;
                    pt = f3;
                    f3 = f3->link;
                    if (f3 != NULL)
                    {
                        f3->prev = NULL;
                    }
                    free(pt);
                    my_train->B1->avl_seat -= ptr->tickets;
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                    printf("\nBooking Confirmed for PNR number:%d", ptr->pnr);
                    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPassenger Name:%s", ptr->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nTotal No. Of tickets:%d", ptr->tickets);
                    printf("\nPassenger Boarding Station:%s", ptr->source);
                    printf("\nPassenger Destination Station:%s", ptr->destination);
                    printf("\nStatus: Confirm Ticket");
                    printf("\nCoach Name:%s", my_train->B1->name);
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                }
            }
        }
    }
    else if (flag == 1)
    {
        if (go == 1)
        {
            while (f1 != NULL && (f1->tickets <= my_train->B1->avl_seat || f1->tickets <= my_train->B2->avl_seat))
            {
                if (f1->tickets <= my_train->B2->avl_seat)
                {
                    seat *temp = s1;
                    seat *ptr = malloc(sizeof(seat));
                    if (temp == NULL)
                    {
                        my_train->B2->seats = ptr;
                        s1 = ptr;
                    }
                    else
                    {
                        while (temp->link != NULL)
                        {
                            temp = temp->link;
                        }
                        temp->link = ptr;
                        ptr->prev = temp;
                    }
                    ptr->pnr = f1->pnr;
                    ptr->tickets = f1->tickets;
                    strcpy(ptr->pass_name, f1->pass_name);
                    strcpy(ptr->source, f1->source);
                    strcpy(ptr->destination, f1->destination);
                    ptr->link = NULL;
                    wait += f1->tickets;
                    wait1 *pt;
                    pt = f1;
                    f1 = f1->link;
                    if (f1 != NULL)
                    {
                        f1->prev = NULL;
                    }
                    free(pt);
                    my_train->B2->avl_seat -= ptr->tickets;
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                    printf("\nBooking Confirmed for PNR number:%d", ptr->pnr);
                    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPassenger Name:%s", ptr->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nTotal No. Of tickets:%d", ptr->tickets);
                    printf("\nPassenger Boarding Station:%s", ptr->source);
                    printf("\nPassenger Destination Station:%s", ptr->destination);
                    printf("\nStatus: Confirm Ticket");
                    printf("\nCoach Name:%s", my_train->B2->name);
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                }
            }
        }
        else if (go == 2)
        {
            while (f2 != NULL && (f2->tickets <= my_train->B1->avl_seat || f2->tickets <= my_train->B2->avl_seat))
            {
                if (f2->tickets <= my_train->B2->avl_seat)
                {
                    seat *temp = s1;
                    seat *ptr = malloc(sizeof(seat));
                    if (temp == NULL)
                    {
                        my_train->B2->seats = ptr;
                        s1 = ptr;
                    }
                    else
                    {
                        while (temp->link != NULL)
                        {
                            temp = temp->link;
                        }
                        temp->link = ptr;
                        ptr->prev = temp;
                    }
                    ptr->pnr = f2->pnr;
                    ptr->tickets = f2->tickets;
                    strcpy(ptr->pass_name, f2->pass_name);
                    strcpy(ptr->source, f2->source);
                    strcpy(ptr->destination, f2->destination);
                    ptr->link = NULL;
                    wait += f2->tickets;
                    wait2 *pt;
                    pt = f2;
                    f2 = f2->link;
                    if (f2 != NULL)
                    {
                        f2->prev = NULL;
                    }
                    free(pt);
                    my_train->B2->avl_seat -= ptr->tickets;
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                    printf("\nBooking Confirmed for PNR number:%d", ptr->pnr);
                    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPassenger Name:%s", ptr->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nTotal No. Of tickets:%d", ptr->tickets);
                    printf("\nPassenger Boarding Station:%s", ptr->source);
                    printf("\nPassenger Destination Station:%s", ptr->destination);
                    printf("\nStatus: Confirm Ticket");
                    printf("\nCoach Name:%s", my_train->B2->name);
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                }
            }
        }
        else if (go == 3)
        {
            while (f3 != NULL && (f3->tickets <= my_train->B1->avl_seat || f3->tickets <= my_train->B2->avl_seat))
            {
                if (f2->tickets <= my_train->B1->avl_seat)
                {
                    seat *temp = s1;
                    seat *ptr = malloc(sizeof(seat));
                    if (temp == NULL)
                    {
                        my_train->B2->seats = ptr;
                        s1 = ptr;
                    }
                    else
                    {
                        while (temp->link != NULL)
                        {
                            temp = temp->link;
                        }
                        temp->link = ptr;
                        ptr->prev = temp;
                    }
                    ptr->pnr = f3->pnr;
                    ptr->tickets = f3->tickets;
                    strcpy(ptr->pass_name, f3->pass_name);
                    strcpy(ptr->source, f3->source);
                    strcpy(ptr->destination, f3->destination);
                    ptr->link = NULL;
                    wait += f3->tickets;
                    wait3 *pt;
                    pt = f3;
                    f3 = f3->link;
                    if (f3 != NULL)
                    {
                        f3->prev = NULL;
                    }
                    free(pt);
                    my_train->B2->avl_seat -= ptr->tickets;
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Alert*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                    printf("\nBooking Confirmed for PNR number:%d", ptr->pnr);
                    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*Ticket Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                    printf("\nPassenger Name:%s", ptr->pass_name);
                    printf("\nTrain Name:%s", my_train->name);
                    printf("\nTrain Number:%d", my_train->train_no);
                    printf("\nTotal No. Of tickets:%d", ptr->tickets);
                    printf("\nPassenger Boarding Station:%s", ptr->source);
                    printf("\nPassenger Destination Station:%s", ptr->destination);
                    printf("\nStatus: Confirm Ticket");
                    printf("\nCoach Name:%s", my_train->B2->name);
                    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                }
            }
        }
    }
}

void find_wait(train *my_train, char sor[], char des[], int flag)
{
    if (strcmp(sor, "mumbai") == 0 && strcmp(des, "delhi") == 0)
        checktoinsert(my_train, flag, 1);
    if (strcmp(sor, "surat") && strcmp(des, "delhi"))
        checktoinsert(my_train, flag, 2);
    else
        checktoinsert(my_train, flag, 3);
}

void delete_ticket(train *my_train)
{
    int src;
    printf("\nEnter Your PNR number to cancel tickets:");
    scanf("%d", &src);

    seat *temp = s1, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->pnr == src)
        {
            if (temp == s1)
            {
                s1 = temp->link;
                if (s1 != NULL)
                {
                    s1->prev = NULL;
                }
            }
            else
            {
                prev->link = temp->link;
                if (temp->link != NULL)
                {
                    temp->link->prev = prev;
                }
            }
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Canceled Tickets Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            printf("\nPNR:%d ", temp->pnr);
            printf("\nPassenger name:%s ", temp->pass_name);
            printf("\nNumber of tickets booked:%d ", temp->tickets);
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            my_train->B1->avl_seat = my_train->B1->avl_seat + temp->tickets;
            find_wait(my_train, temp->source, temp->destination, 0);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->link;
    }
    temp = s2, prev = NULL;
    while (temp != NULL)
    {
        if (temp->pnr == src)
        {
            if (temp == s2)
            {
                s2 = temp->link;
                if (s2 != NULL)
                {
                    s2->prev = NULL;
                }
            }
            else
            {
                prev->link = temp->link;
                if (temp->link != NULL)
                {
                    temp->link->prev = prev;
                }
            }
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Deleted Tickets Details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            printf("\nPNR:%d ", temp->pnr);
            printf("\nPassenger name:%s ", temp->pass_name);
            printf("\nNumber of tickets booked:%d ", temp->tickets);
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            my_train->B2->avl_seat = my_train->B2->avl_seat + temp->tickets;
            find_wait(my_train, temp->source, temp->destination, 1);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->link;
    }
    printf("\nNo Tickets Found With This PNR number\n");
    return;
}

void view_tickets(train *my_train)
{
    int src;
    printf("\nEnter Your PNR number to view ticket details:");
    scanf("%d", &src);
    int flag = 0;

    seat *temp = s1;
    while (temp != NULL)
    {
        if (temp->pnr == src)
        {
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Tickets details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            printf("\nPNR:%d ", temp->pnr);
            printf("\nPassenger Name:%s ", temp->pass_name);
            printf("\nTrain Name:%s", my_train->name);
            printf("\nTrain Number:%d", my_train->train_no);
            printf("\nNumber of tickets booked:%d ", temp->tickets);
            printf("\nStatus: Confirm Ticket");
            printf("\nCoach Name:%s", my_train->B1->name);
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            return;
        }
        temp = temp->link;
    }

    temp = s2;
    while (temp != NULL)
    {
        if (temp->pnr == src)
        {
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Tickets details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            printf("\nPNR:%d ", temp->pnr);
            printf("\nPassenger Name:%s ", temp->pass_name);
            printf("\nTrain Name:%s", my_train->name);
            printf("\nTrain Number:%d", my_train->train_no);
            printf("\nNumber of tickets booked:%d ", temp->tickets);
            printf("\nStatus: Confirm Ticket");
            printf("\nCoach Name:%s", my_train->B2->name);
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*---------------------------------------*-");
            return;
        }
        temp = temp->link;
    }
    wait1 *w_temp = f1;
    while (w_temp != NULL)
    {
        if (w_temp->pnr == src)
        {
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Tickets details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            printf("\nPNR:%d ", w_temp->pnr);
            printf("\nPassenger Name:%s ", w_temp->pass_name);
            printf("\nTrain Name:%s", my_train->name);
            printf("\nTrain Number:%d", my_train->train_no);
            printf("\nNumber of tickets booked:%d ", w_temp->tickets);
            printf("\nBoarding Station:%s", w_temp->source);
            printf("\nDestination Station:%s", w_temp->destination);
            printf("\nStatus: Waiting Ticket");
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            return;
        }
        w_temp = w_temp->link;
    }

    wait2 *w2_temp = f2;
    while (w2_temp != NULL)
    {
        if (w2_temp->pnr == src)
        {
            printf("\n-*-*-*-*-*-*-*-*-*------------Tickets details--------------");
            printf("\nPNR:%d ", w2_temp->pnr);
            printf("\nPassenger Name:%s ", w2_temp->pass_name);
            printf("\nTrain Name:%s", my_train->name);
            printf("\nTrain Number:%d", my_train->train_no);
            printf("\nNumber of tickets booked:%d ", w2_temp->tickets);
            printf("\nBoarding Station:%s", w2_temp->source);
            printf("\nDestination Station:%s", w2_temp->destination);
            printf("\nStatus: Waiting Ticket");
            printf("\n-----------------------------------");
            return;
        }
        w2_temp = w2_temp->link;
    }
    wait3 *w3_temp = f3;
    while (w3_temp != NULL)
    {
        if (w3_temp->pnr == src)
        {
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Tickets details*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
            printf("\nPNR:%d ", w3_temp->pnr);
            printf("\nPassenger Name:%s ", w3_temp->pass_name);
            printf("\nTrain Name:%s", my_train->name);
            printf("\nTrain Number:%d", my_train->train_no);
            printf("\nNumber of tickets booked:%d ", w3_temp->tickets);
            printf("\nBoarding Station:%s", w3_temp->source);
            printf("\nDestination Station:%s", w3_temp->destination);
            printf("\nStatus: Waiting Ticket");
            printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-----------------------------------*-");
            return;
        }
        w3_temp = w3_temp->link;
    }
    printf("\nNo Tickets Found With This PNR Number\n");
}

void view_trainroute()
{
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*Train Route*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
    printf("\n\t\t|=|📻 - Last Stop Delhi");
    printf("\n\t\t|=|");
    printf("\n\t\t|=|🛑 - Surat");
    printf("\n\t\t|=|");
    printf("\n\t\t🚉    - Start Mumbai");
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
}

void options(train *my_train)
{
    printf("\nSelect 1. to book ticket\nSelect 2. to cancel ticket\nSelect 3. to view booked ticket\nSelect 4. to view train route\nSelect any other number to go back.\n");
    int ch;
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        book_ticket(my_train);
        break;
    case 2:
        delete_ticket(my_train);
        break;
    case 3:
        view_tickets(my_train);
        break;
    case 4:
        view_trainroute();
        break;
    default:
        break;
    }
}

int main()
{
    if (performLogin())
    {
        train *my_train;
        my_train = malloc(sizeof(train));
        my_train->train_no = 12951;
        strcpy(my_train->name, "Rajdhani Express");
        my_train->B1 = malloc(sizeof(wagon));
        my_train->B2 = malloc(sizeof(wagon));
        strcpy(my_train->B1->name, "B1");
        strcpy(my_train->B2->name, "B2");
        my_train->B1->avl_seat = 16;
        my_train->B2->avl_seat = 16;
        my_train->B1->next = my_train->B2;
        my_train->B2->next = NULL;
        head = my_train->B1;
        current = head;
        printf("\t\t\t\t\t\tWelcome To Railway Ticket Booking System");
        int choice = 1;
        while (choice == 1)
        {
            printf("\nClick 1. to View Options\nClick any other number to Exit\n");
            printf("Enter your Choice: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                options(my_train);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        printf("Login unsuccessful.\n");
    }
    return 0;
}