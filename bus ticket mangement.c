#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define MAX_SEATS 40
#define ROWS 10
#define COLS 4
#define MAX_FEEDBACK 100
 float revenue=0 ;
      int total_seat=0;


typedef struct {
    int ticketID;
    char passengerName[50];
    int seatNumber;
    char phoneNumber[20];
    char paymentType[20];
    float basePrice;
    float totalPrice;
} Ticket;

// ticket  information
typedef struct {
    Ticket tickets[MAX_SEATS];
    int top;
} TicketStack;

//  route information using tree
typedef struct RouteNode {
    char origin[50];
    char destination[50];
    char schedule[20];
    struct RouteNode* left;
    struct RouteNode* right;
} RouteNode;

// Structure to hold feedback
typedef struct {
    char feedback[MAX_FEEDBACK][200];
    int count;
} FeedbackList;

// new route node
RouteNode* createRouteNode(const char* origin, const char* destination, const char* schedule) {
    RouteNode* newNode = (RouteNode*)malloc(sizeof(RouteNode));
    strcpy(newNode->origin, origin);
    strcpy(newNode->destination, destination);
    strcpy(newNode->schedule, schedule);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a route into the tree
RouteNode* insertRoute(RouteNode* root, const char* origin, const char* destination, const char* schedule) {
    if (root == NULL) {
        return createRouteNode(origin, destination, schedule);
    }

    if (strcmp(origin, root->origin) < 0) {
        root->left = insertRoute(root->left, origin, destination, schedule);
    } else {
        root->right = insertRoute(root->right, origin, destination, schedule);
    }
    return root;
}

// in-order
void  displayRoute(RouteNode* root){
   printf("\033[0;32mRoute: %s to %s, Schedule: %s  Ticket price : 250 BDT \033[0m\n", root->origin, root->destination, root->schedule);
 return;
}
void displayRoutes(RouteNode* root) {
    if (root != NULL) {
        displayRoutes(root->left);
        printf("Route: %s to %s, Schedule: %s\n", root->origin, root->destination, root->schedule);
        displayRoutes(root->right);
    }
}

// delete a route node
RouteNode* deleteRoute(RouteNode* root, const char* origin, const char* destination) {
    if (root == NULL) {
        return root;
    }

    // route to delete
    if (strcmp(origin, root->origin) < 0) {
        root->left = deleteRoute(root->left, origin, destination);
    } else if (strcmp(origin, root->origin) > 0) {
        root->right = deleteRoute(root->right, origin, destination);
    } else {

        if (strcmp(destination, root->destination) == 0) {

            if (root->left == NULL) {
                RouteNode* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                RouteNode* temp = root->left;
                free(root);
                return temp;
            }
            //  (smallest in the right subtree)
            RouteNode* temp = root->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            strcpy(root->origin, temp->origin);
            strcpy(root->destination, temp->destination);
            strcpy(root->schedule, temp->schedule);
            root->right = deleteRoute(root->right, temp->origin, temp->destination);
        } else {
            printf("Route not found.\n");
        }
    }
    return root;
}

// seating chart
void displaySeats(int seats[], int rows, int cols) {
    printf("Seating Chart:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int seatIndex = i * cols + j; // seat index
            if (seats[seatIndex] == 1) {
                printf("[X] ");
            } else {
                printf("[ ] "); // Empty seat
            }
        }
        printf("\n");
    }
    printf("\n");
}

// push a ticket onto the stack
void push(TicketStack* stack, Ticket ticket) {
    if (stack->top < MAX_SEATS) {
        stack->tickets[stack->top++] = ticket;
    } else {
        printf("Ticket stack is full!\n");
    }
}

//  ticket from the stack
void cancelTicket(TicketStack* stack, int ticketID, int seats[]) {
    for (int i = 0; i < stack->top; i++) {
        if (stack->tickets[i].ticketID == ticketID) {
            // Mark seat as empty
            seats[stack->tickets[i].seatNumber - 1] = 0;
            // Shift tickets down
            for (int j = i; j < stack->top - 1; j++) {
                stack->tickets[j] = stack->tickets[j + 1];
            }
            stack->top--;
            printf("Ticket with ID %d has been canceled successfully.\n", ticketID);
            return;
        }
    }
    printf("Ticket ID %d not found.\n", ticketID);
}

//  feedback
void giveFeedback(FeedbackList* feedbackList) {
    if (feedbackList->count < MAX_FEEDBACK) {
        printf("Enter your feedback: ");
        fgets(feedbackList->feedback[feedbackList->count], sizeof(feedbackList->feedback[feedbackList->count]), stdin);
        feedbackList->feedback[feedbackList->count][strcspn(feedbackList->feedback[feedbackList->count], "\n")] = 0; // Remove newline
        feedbackList->count++;
        printf("Thank you for your feedback!\n");
    } else {
        printf("Feedback list is full!\n");
    }
}

//  view all feedback
void viewFeedback(FeedbackList feedbackList) {
    if (feedbackList.count == 0) {
        printf("No feedback available.\n");
        return;
    }

    printf("Feedback received:\n");
    for (int i = 0; i < feedbackList.count; i++) {
        printf("%d. %s\n", i + 1, feedbackList.feedback[i]);
    }
}
// ticket check
void checkTicket(TicketStack* stack) {
    int id;
    printf("\nEnter your Ticket ID: ");
    scanf("%d", &id);
    for (int i = 0; i < stack->top; i++) {
        if (stack->tickets[i].ticketID == id) {
            printf("Ticket Found!\n");
            printf("Passenger: %s, Seat Number: %d, Phone: %s\n",
                   stack->tickets[i].passengerName, stack->tickets[i].seatNumber, stack->tickets[i].phoneNumber);

            return;
        }
    }
    printf("Ticket ID %d not found.\n", id);
}
void user_info(TicketStack* stack) {
    // Sort tickets based on seat numbers using Bubble Sort
    for (int i = 0; i < stack->top - 1; i++) {
        for (int j = 0; j < stack->top - i - 1; j++) {
            if (stack->tickets[j].seatNumber > stack->tickets[j + 1].seatNumber) {
                // Swap tickets[j] and tickets[j + 1]
                Ticket temp = stack->tickets[j];
                stack->tickets[j] = stack->tickets[j + 1];
                stack->tickets[j + 1] = temp;
            }
        }
    }

    // Display sorted user data
    printf("User Data (Sorted by Seat Number):\n");
    for (int i = 0; i < stack->top; i++) {
        printf("Passenger: %s, Seat Number: %d, Phone: %s, Payment Type: %s\n",
               stack->tickets[i].passengerName, stack->tickets[i].seatNumber,
               stack->tickets[i].phoneNumber, stack->tickets[i].paymentType);
        printf("\n");
    }
}
void printCurrentTime() {
    // Get the current time
    time_t current_time;
    time(&current_time);

    // Convert to local time format
    char* time_string = ctime(&current_time);

    // Print the current time in red color
    printf("\033[31mCurrent time: %s\033[0m", time_string);
    printf("\n");
}

// Main function
int main() {
    int seats[MAX_SEATS] = {0};
    TicketStack ticketStack = {.top = 0};
    Ticket ticket;
    RouteNode* routeTree = NULL;
    FeedbackList feedbackList = {.count = 0};

    routeTree = insertRoute(routeTree, "Dhaka", "Tangil", "10:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Rajshahi", "11:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Sylhet", "12:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Khulna", "1:00 PM");
    routeTree = insertRoute(routeTree, "Dhaka", "Barisal", "12:00 PM");

    int choice, userType;
    char adminPassword[20];
    const char* correctPassword = "420";

    while (1) {
        printf("====== Bus Ticket Management System ======\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userType);
        getchar();

        if (userType == 1) {
            printf("Enter admin password: ");
            fgets(adminPassword, sizeof(adminPassword), stdin);
            adminPassword[strcspn(adminPassword, "\n")] = 0; // Remove newline

            if (strcmp(adminPassword, correctPassword) != 0) {
                printf("Incorrect password. Access denied.\n");
                continue;
            }

            do {
                printf("\n====== Admin Menu ======\n");
                printf("1. Add Route\n");
                printf("2. Delete Route\n");
                printf("3. View Feedback\n");
                printf("4. Customer Information\n");
                printf("5. View Accounting Info\n");
                printf("6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                switch (choice) {
                    case 1: {
                        char origin[50], destination[50], schedule[20];
                        printf("Enter origin: ");
                        fgets(origin, sizeof(origin), stdin);
                        origin[strcspn(origin, "\n")] = 0;

                        printf("Enter destination: ");
                        fgets(destination, sizeof(destination), stdin);
                        destination[strcspn(destination, "\n")] = 0;

                        printf("Enter schedule time: ");
                        fgets(schedule, sizeof(schedule), stdin);
                        schedule[strcspn(schedule, "\n")] = 0;

                        routeTree = insertRoute(routeTree, origin, destination, schedule);
                        printf("Route added successfully.\n");
                        break;
                    }

                    case 2: {
                        char origin[50], destination[50];
                        printf("Enter origin: ");
                        fgets(origin, sizeof(origin), stdin);
                        origin[strcspn(origin, "\n")] = 0;

                        printf("Enter destination: ");
                        fgets(destination, sizeof(destination), stdin);
                        destination[strcspn(destination, "\n")] = 0;

                        routeTree = deleteRoute(routeTree, origin, destination);
                        break;
                    }
                    case 3:
                        viewFeedback(feedbackList);
                        break;
                    case 4:
                        user_info(&ticketStack);
                        break;
                    case 5: {
                        printf("- -- - - - - - - - - - - -");
                        printf("\nTotal seats booked: %d", total_seat);
                        printf("\nTotal revenue: %.2f\n", revenue);
                        break;
                    }
                    case 6:
                        break;
                }
            } while (choice != 6);
        } else if (userType == 2) {
            do {
                printf("\nMenu:\n");
                printf("1. Display Routes\n");
                printf("2. Book Ticket\n");
                printf("3. Cancel Ticket\n");
                printf("4. View Seats\n");
                printf("5. Give Feedback\n");
                printf("6. View Feedback\n");
                printf("7. Check Ticket\n");
                printf("8. About and Support\n");
                printf("9. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                switch (choice) {
                    case 1:
                        if (routeTree == NULL) {
                            printf("No routes available.\n");
                        } else {
                            printCurrentTime();
                            printf("Available Routes:\n");
                            displayRoute(routeTree);
                            printf("Upcoming Routes:\n");
                            displayRoutes(routeTree);
                        }
                        break;

                    case 2: {
                        printf("Enter passenger name: ");
                        fgets(ticket.passengerName, sizeof(ticket.passengerName), stdin);
                        ticket.passengerName[strcspn(ticket.passengerName, "\n")] = 0;

                        printf("Enter phone number: ");
                        fgets(ticket.phoneNumber, sizeof(ticket.phoneNumber), stdin);
                        ticket.phoneNumber[strcspn(ticket.phoneNumber, "\n")] = 0;

                        printf("\nSpecial Discount:\nBkash and Nogod have a 10%% discount.\n\n");

                        printf("Enter payment type (e.g., Visa, Bkash, Nogod, Rocket): ");
                        fgets(ticket.paymentType, sizeof(ticket.paymentType), stdin);
                        ticket.paymentType[strcspn(ticket.paymentType, "\n")] = 0;

                        printf("Enter ticket base price: ");
                        scanf("%f", &ticket.basePrice);
                        getchar();

                        printf("Choose a seat (1 to %d): ", MAX_SEATS);
                        scanf("%d", &ticket.seatNumber);
                        getchar();

                        if (ticket.seatNumber < 1 || ticket.seatNumber > MAX_SEATS || seats[ticket.seatNumber - 1] == 1) {
                            printf("Seat is unavailable or invalid.\n");
                            break;
                        }

                        seats[ticket.seatNumber - 1] = 1;
                        ticket.ticketID = ticketStack.top + 2023 + 1;

                        if (strcmp(ticket.paymentType, "Bkash") == 0 || strcmp(ticket.paymentType, "Nogod") == 0) {
                            ticket.totalPrice = ticket.basePrice * 0.90;
                            printf("10%% discount applied! Total price: %.2f\n", ticket.totalPrice);
                        } else {
                            ticket.totalPrice = ticket.basePrice;
                            printf("No discount applied. Total price: %.2f\n", ticket.totalPrice);
                        }

                        push(&ticketStack, ticket);
                        total_seat++;
                        revenue += ticket.totalPrice;
                        printf("Ticket booked successfully! Your Ticket ID is %d.\n", ticket.ticketID);
                        printf("\n- - - - - - - - - - - RECEIPT - - - - - - - -\n");
                        printf("Dear user,\nTicket booked successfully!\n");
                        printf("Ticket ID: DB-%d, Seat Number: %d\n", ticket.ticketID, ticket.seatNumber);
                        printf("Base Price: %.2f BDT\n", ticket.basePrice);
                        printf("Discounted Price: %.2f BDT\n", ticket.totalPrice);
                        printf("\nStay with our Dream Bus Service\n");
                        printf("For any information, call +880-134-567-98\n");
                        printf("Thank you! :)\n");
                        printf("-- --- --- ---- ---- --- --- ---- --- --- -- --- --- - -- ");
                        break;
                    }

                    case 3: {
                        int ticketID;
                        printf("Enter Ticket ID to cancel: ");
                        scanf("%d", &ticketID);
                        cancelTicket(&ticketStack, ticketID, seats);
                        break;
                    }

                    case 4:
                        displaySeats(seats, ROWS, COLS);
                        break;

                    case 5:
                        giveFeedback(&feedbackList);
                        break;

                    case 6:
                        checkTicket(&ticketStack);
                        break;

                    case 7: {
                        printf("\n--- -- --- --- Dream Bus Service - - - - - - - -\n");
                        printf("Counter: Counter #5, Dhaka Bus Terminal\n");
                        printf("Mobile: +8801712345678\n");
                        printf("Address: 123, Main Road, Dhaka, Bangladesh\n\n");

                        printf("Routes and Schedules:\n");
                        printf("-----------------------------------\n");
                        printf("Route: Dhaka to Chittagong\n");
                        printf("Schedule: 10:00 AM\n");
                        printf("Counter: Counter #5, Dhaka Bus Terminal\n");
                        printf("Mobile: +8801712345678\n");
                        printf("Address: 123, Main Road, Dhaka, Bangladesh\n\n");

                        printf("-----------------------------------\n");
                        printf("Route: Dhaka to Sylhet\n");
                        printf("Schedule: 2:00 PM\n");
                        printf("Counter: Counter #5, Dhaka Bus Terminal\n");
                        printf("Mobile: +8801712345678\n");
                        printf("Address: 123, Main Road, Dhaka, Bangladesh\n\n");

                        printf("-----------------------------------\n");
                        printf("Route: Dhaka to Rajshahi\n");
                        printf("Schedule: 5:00 PM\n");
                        printf("Counter: Counter #5, Dhaka Bus Terminal\n");
                        printf("Mobile: +8801712345678\n");
                        printf("Address: 123, Main Road, Dhaka, Bangladesh\n");
                    }
                    break;

                    case 8:
                        break;

                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }

            } while (choice != 9);
        } else if (userType == 3) {
            printf("-- Good bye --\n");
            return 0;
        }
    }
    return 0;
}
