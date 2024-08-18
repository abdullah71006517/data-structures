

/*Declare an Array, take Size, Elements dynamically. Delete a 2
even element from last position. If the array has only 1 even
element insert 2 element in the middle & very next index. If
there is no even element, then delete middle indexed element
and insert a new element to the very next index of the middle
index. [Take elements for insertion dynamically]. You have to
count the number of odd even element in the array to solve this
problem.*/
#include <stdio.h>

int main() {
    int size, even = 0;
    printf("Enter your size: ");
    scanf("%d", &size);

    int a[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)
            even++;
    }

    if (even >= 2) {

        int dlt = 2;
        for (int i = size - 1; i >= 0; i--) {
            if (a[i] % 2 == 0) {
                for (int j = i; j < size - 1; j++) {
                    a[j] = a[j + 1];
                }
                size--;
                dlt--;
                if (dlt == 0)
                    break;
            }
        }
    } else if (even == 1) {
        int n1, n2;
        printf("Input 2 elements: ");
        scanf("%d %d", &n1, &n2);

        int middle = size / 2;
        for (int i = size; i > middle; i--) {
            a[i + 1] = a[i - 1];
        }
        a[middle] = n1;
        a[middle + 1] = n2;
        size += 2;
    } else {
        int newElement;
        printf("Enter a new element: ");
        scanf("%d", &newElement);

        int middle = size / 2;
        for (int i = middle; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size--;
        for(int i=size-1;i>middle+1 ;i--){
            (a[i] =a[i-1]);
        }
      a[middle+1]=newElement;
      size++;
    }


    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

