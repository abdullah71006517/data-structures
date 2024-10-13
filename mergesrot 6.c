#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100

// Structure to store student details
struct Student {
    char name[20];
    int id;
};

// Function to merge two halves
void merge(struct Student arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    struct Student temp[100]; // Temporary array for merging

    // Merging the two halves into the temporary array temp[]
    while (i <= mid && j <= high) {
        if (arr[i].id <= arr[j].id) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copying remaining elements from the left half, if any
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copying remaining elements from the right half, if any
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array arr[]
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// Function to perform Merge Sort on the array of students based on ID
void mergeSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);        // Sort first half
        mergeSort(arr, mid + 1, high);   // Sort second half
        merge(arr, low, mid, high);      // Merge the two halves
    }
}

int main() {

    int n;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
   struct Student students[n];
    // Input student details
    for (int i = 0; i < n; i++) {
        printf("Enter name and ID for student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].id);
    }

    // Sort the array using Merge Sort
    mergeSort(students, 0, n - 1);

    // Output sorted student details
    printf("\nStudents sorted by ID in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, ID: %d\n", students[i].name, students[i].id);
    }

    return 0;
}

