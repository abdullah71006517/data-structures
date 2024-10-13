#include <stdio.h>
#include <string.h>



int main() {
    int size;
    printf("how much entry student ?");
    scanf("%d",&size);
    char name[size][20];
    int a[size];


    for (int i = 0; i < size; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", name[i]);
        printf("Enter ID for %s: ", name[i]);
        scanf("%d", &a[i]);
    }


    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;


                char tempName[20];
                strcpy(tempName, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tempName);
            }
        }
    }


    printf("\nSorted list:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d\tName: %s\n", a[i], name[i]);
    }

    return 0;
}
