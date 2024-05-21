#include <stdio.h>

void bubble_sort(int array[], int n, int* min, int* max) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
		temp = array[j];
		array[j] = array[j+1];
		array[j+1] = temp;
		}
	}
}
*min = array[0];
*max = array[n-1];
}
int main() {
    int array[10], min, max, i;
printf("Enter 10 integers:\n");
for (i = 0; i < 10; i++) {
	printf("Enter integer %d:", i+1);
	scanf("%d", &array[i]);
}
bubble_sort(array, 10, &min, &max);
printf("Sorted list: [");
for (i = 0; i < 10; i++) {
printf("%d", array[i]);
if (i<9) printf(",");
}
printf("]\n");
printf("Min value: %d\n",min);
printf("Max value: %d\n", max);
return 0;
}
