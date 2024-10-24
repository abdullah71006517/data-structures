#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 40         // Total number of seats
#define ROWS 10              // Number of rows
#define COLS 4               // Number of columns
#define MAX_FEEDBACK 100     // Maximum feedback messages
 float revenue=0 ;
      int total_seat=0;


typedef struct {
    int ticketID;
    char passengerName[50];
    int seatNumber;           //
    char phoneNumber[20];
    char paymentType[20];     //
    float basePrice;
    float totalPrice;
} Ticket;


typedef struct {
    Ticket tickets[MAX_SEATS];
    int top;
} TicketStack;

// Structure to hold route information
typedef struct RouteNode {
    char origin[50];
    char destination[50];
    char schedule[20];
    struct RouteNode* left;   // Left child
    struct RouteNode* right;  // Right child
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

// Function to display all routes in-order
void displayRoutes(RouteNode* root) {
    if (root != NULL) {
        displayRoutes(root->left);
        printf("Route: %s to %s, Schedule: %s\n", root->origin, root->destination, root->schedule);
        displayRoutes(root->right);
    }
}

// Function to delete a route node
RouteNode* deleteRoute(RouteNode* root, const char* origin, const char* destination) {
    if (root == NULL) {
        return root;
    }

    // Traverse the tree to find the route to delete
    if (strcmp(origin, root->origin) < 0) {
        root->left = deleteRoute(root->left, origin, destination);
    } else if (strcmp(origin, root->origin) > 0) {
        root->right = deleteRoute(root->right, origin, destination);
    } else {
        // Found the node to delete
        if (strcmp(destination, root->destination) == 0) {
            // Node with only one child or no child
            if (root->left == NULL) {
                RouteNode* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                RouteNode* temp = root->left;
                free(root);
                return temp;
            }
            // Node with two children: get the inorder successor (smallest in the right subtree)
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

// Function to display the seating chart
void displaySeats(int seats[], int rows, int cols) {
    printf("Seating Chart:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int seatIndex = i * cols + j; // Calculate seat index
            if (seats[seatIndex] == 1) {
                printf("[X] "); // Booked seat
            } else {
                printf("[ ] "); // Empty seat
            }
        }
        printf("\n"); // New line after each row
    }
    printf("\n");
}

// Function to push a ticket onto the stack
void push(TicketStack* stack, Ticket ticket) {
    if (stack->top < MAX_SEATS) {
        stack->tickets[stack->top++] = ticket; // Add ticket to stack
    } else {
        printf("Ticket stack is full!\n");
    }
}

// Function to delete a ticket from the stack
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

// Function to give feedback
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

// Function to view all feedback
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

    printf("User Data:\n");

    for (int i = 0; i < stack->top; i++) {
        printf("Passenger: %s, Seat Number: %d, Phone: %s,  payment type:%s\n",
               stack->tickets[i].passengerName, stack->tickets[i].seatNumber, stack->tickets[i].phoneNumber,  stack->tickets[i].paymentType);
        printf("\n");  // To print a new line between users
    }
}


// Main function
int main() {
    int seats[MAX_SEATS] = {0}; // 0 for empty, 1 for booked
    TicketStack ticketStack = {.top = 0}; // Initialize ticket stack
    Ticket ticket; // Create a Ticket variable for booking
    RouteNode* routeTree = NULL; // Pointer to the root of the route tree
    FeedbackList feedbackList = {.count = 0}; // Initialize feedback list

    // Predefined routes for testing
    routeTree = insertRoute(routeTree, "Dhaka", "Chittagong", "08:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Rajshahi", "09:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Sylhet", "10:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Khulna", "11:00 AM");
    routeTree = insertRoute(routeTree, "Dhaka", "Barisal", "12:00 PM");

    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Display Routes\n");
        printf("2. Add Route\n");
        printf("3. Delete Route\n");
        printf("4. Book Ticket\n");
        printf("5. Cancel Ticket\n");
        printf("6. View Seats\n");
        printf("7. Give Feedback\n");
        printf("8. View Feedback\n");
        printf("9. Exit");
        printf("\n10. Check Ticket\n");
        printf("11.customer inforamation\n");
        printf(" 12.account part \n13.about and support  \n");

  printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1: // Display Routes
                if (routeTree == NULL) {
                    printf("No routes available.\n");
                } else {
                    printf("Available Routes:\n");
                    displayRoutes(routeTree);
                }
                break;

            case 2: { // Add Route
                char origin[50], destination[50], schedule[20];
                printf("Enter origin: ");
                fgets(origin, sizeof(origin), stdin);
                origin[strcspn(origin, "\n")] = 0; // Remove newline

                printf("Enter destination: ");
                fgets(destination, sizeof(destination), stdin);
                destination[strcspn(destination, "\n")] = 0; // Remove newline

                printf("Enter schedule time: ");
                fgets(schedule, sizeof(schedule), stdin);
                schedule[strcspn(schedule, "\n")] = 0; // Remove newline

                routeTree = insertRoute(routeTree, origin, destination, schedule);
                printf("Route added successfully.\n");
                break;
            }

            case 3: { // Delete Route
                char origin[50], destination[50];
                printf("Enter origin: ");
                fgets(origin, sizeof(origin), stdin);
                origin[strcspn(origin, "\n")] = 0; // Remove newline

                printf("Enter destination: ");
                fgets(destination, sizeof(destination), stdin);
                destination[strcspn(destination, "\n")] = 0; // Remove newline

                routeTree = deleteRoute(routeTree, origin, destination);
                break;
            }

            case 4: { // Book Ticket
    printf("Enter passenger name: ");
    fgets(ticket.passengerName, sizeof(ticket.passengerName), stdin);
    ticket.passengerName[strcspn(ticket.passengerName, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(ticket.phoneNumber, sizeof(ticket.phoneNumber), stdin);
    ticket.phoneNumber[strcspn(ticket.phoneNumber, "\n")] = 0; // Remove newline

    // Display special discount information for Bkash and Nogod
    printf("\nSpecial Discount:\nBkash and Nogod have a 10%% discount.\n\n");

    printf("Enter payment type (e.g., Visa, Bkash, Nogod, Rocket): ");
    fgets(ticket.paymentType, sizeof(ticket.paymentType), stdin);
    ticket.paymentType[strcspn(ticket.paymentType, "\n")] = 0; // Remove newline

    printf("Enter ticket base price: ");
    scanf("%f", &ticket.basePrice);
    getchar(); // Consume newline character

    printf("Choose a seat (1 to %d): ", MAX_SEATS);
    scanf("%d", &ticket.seatNumber);
    getchar(); // Consume newline character

    // Check if seat is available
    if (ticket.seatNumber < 1 || ticket.seatNumber > MAX_SEATS || seats[ticket.seatNumber - 1] == 1) {
        printf("Seat is unavailable or invalid.\n");
        break;
    }

    seats[ticket.seatNumber - 1] = 1; // Mark seat as booked
    ticket.ticketID = ticketStack.top + 1; // Generate ticket ID

    // Apply discount logic
    if (strcmp(ticket.paymentType, "Bkash") == 0 || strcmp(ticket.paymentType, "Nogod") == 0) {
        ticket.totalPrice = ticket.basePrice * 0.90; // Apply 10% discount
        printf("10%% discount applied! Total price: %.2f\n", ticket.totalPrice);
    } else {
        ticket.totalPrice = ticket.basePrice;
        printf("No discount applied. Total price: %.2f\n", ticket.totalPrice);
    }

    // Add the ticket to the stack
    push(&ticketStack, ticket);
    total_seat++;  // Increment total booked seat count
    revenue += ticket.totalPrice;  // Add to total revenue
   printf("Ticket booked successfully! Your Ticket ID is %d.\n", ticket.ticketID);
                printf("\n- - - - - - - - - - - RECEIPT - - - - - - - -\n");
    printf("Dear user,\nTicket booked successfully!\n");
    printf("Ticket ID: %d, Seat Number: %d\n", ticket.ticketID, ticket.seatNumber);
    printf("Base Price: %.2f BDT\n", ticket.basePrice);
    printf("Discounted Price: %.2f BDT\n", ticket.totalPrice);
    printf("\nStay with our Dream Bus Service\n");
    printf("For any information, call +880-134-567-98\n");
    printf("Thank you! :)\n");
    printf("-- --- --- ---- ---- --- --- ---- --- --- -- --- --- - -- ");
    break;
}




            case 5: { // Cancel Ticket
                int ticketID;
                printf("Enter Ticket ID to cancel: ");
                scanf("%d", &ticketID);
                cancelTicket(&ticketStack, ticketID, seats); // Cancel ticket
                break;
            }

            case 6: // View Seats
                displaySeats(seats, ROWS, COLS);
                break;

            case 7: // Give Feedback
                giveFeedback(&feedbackList);
                break;

            case 8: // View Feedback
                viewFeedback(feedbackList);
                break;

            case 9: // Exit
                printf("Exiting program...\n");
                exit(0);
case 10:checkTicket(&ticketStack);
                break;
                case 11:user_info(&ticketStack);break;
                case 12: {
                    printf( "- -- - - - - - - - - - - -");
                printf("\n total  seat book: %d",total_seat);
                printf("\n total revenue : %.2f",revenue);
                printf("\n");
                } break;
case 13: {
    printf("dream Bus Service\n");
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




            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

