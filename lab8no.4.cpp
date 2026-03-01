#include <stdio.h>

void sortArray(int arr[], int size);

int main() {
    
    int scores[4] = {65, 80, 45, 90}; 
    int best3[3];
    int i;

    
    sortArray(scores, 4);

    
    for (i = 1; i < 4; i++) {
        best3[i - 1] = scores[i];
    }

    
    printf("Best 3 Scores: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", best3[i]);
    }
    printf("\n");

    return 0;
}


void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}