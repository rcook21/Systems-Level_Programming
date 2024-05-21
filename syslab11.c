 #include <stdio.h>

#define SIZE 10 // Define the size of the array

void sortArray(int array[], int size);
int findMinimum(int array[], int size);
int findMaximum(int array[], int size);

int main() {
    int numbers[SIZE];
    int i;

    // Input numbers
         for(i = 0; i < SIZE; i++) {
           printf("Please Enter Number %d: ", i + 1);
            scanf("%d", &numbers[i]);
                             }
    
      // Sorting the array
         sortArray(numbers, SIZE);
   
          // Printing the sorted array
            printf("\n[");
           for(i = 0; i < SIZE; i++) {
            printf("%d", numbers[i]);
             if (i < SIZE - 1) {
             printf(", ");
                                                                                     }
                                                                                         }
               printf("]\n");
    
           // Finding and printing the smallest and largest numbers
               int smallest = findMinimum(numbers, SIZE);
               int largest = findMaximum(numbers, SIZE);
                                                                                                             
                  printf("Largest: %d\n", largest);
                   printf("Smallest: %d\n", smallest);
    
                        return 0;
                                  }
    
                     void sortArray(int array[], int size) {
                         int i, j, temp;
                   for (i = 0; i < size - 1; i++) {
                     for (j = 0; j < size - i - 1; j++) {
                        if (array[j] > array[j + 1]) {
                           temp = array[j];
                      array[j] = array[j + 1];
                     array[j + 1] = temp;
                                                                                                                                                                                                                 }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                             }
    
                                                                                                                                                                                                                             int findMinimum(int array[], int size) {
                                                                                                                                                                                                                                 int min = array[0], i;
                                                                                                                                                                                                                                     for (i = 1; i < size; i++) {
                                                                                                                                                                                                                                             if (array[i] < min) {
                                                                                                                                                                                                                                                         min = array[i];
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                            return min;
                                                                                                                                                                                                                                                   }
   
                                                                                                                                                                                                                                  int findMaximum(int array[], int size) {
                                                                                                                                                                                                                                         int max = array[0], i;
                                                                                                                                                                                                                                       for (i = 1; i < size; i++) {
                                                                                                                                                                                                                                   if (array[i] > max) {
                                                                                                                                                                                                                                          max = array[i];
                                                                                                                                                                                                                                                           }
                                                                                                                                                                                                                                                         }
                                              
                                                                                                                                                                                                                         return max;
                                                                                                                                                                                                                                                                                                                     }
    
