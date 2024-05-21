#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5

typedef struct {
     char name[50];
      int rollNo;
      float marks[MAX_SUBJECTS];
       } Student;

       int main() {
        int classSize, i, j;
        float totalMarks = 0.0, classAverage;
     printf("Enter the total number of students in the class (up to 50): ");
                scanf("%d", &classSize);
               if (classSize > MAX_STUDENTS || classSize < 1) {
printf("Invalid class size. Exiting...\n");
return 1;
 }
Student class[classSize];
for (i = 0; i < classSize; i++) {
printf("\nStudent %d:\n", i + 1);
printf("Enter name: ");
scanf("%s", class[i].name);
printf("Enter roll number: ");
scanf("%d", &class[i].rollNo);
if (class[i].rollNo < 1 || class[i].rollNo > classSize) {
printf("Invalid roll number. Exiting...\n");
return 1;
}
for (j = 0; j < MAX_SUBJECTS; j++) {
printf("Enter mark for subject %d: ", j + 1);
scanf("%f", &class[i].marks[j]);
if (class[i].marks[j] < 0 || class[i].marks[j] > 100) {
printf("Invalid mark. Exiting...\n");
return 1;
}
}
}
for (i = 0; i < classSize; i++) {
for (j = 0; j < MAX_SUBJECTS; j++) {
totalMarks += class[i].marks[j];
}
}
classAverage = totalMarks / (classSize * MAX_SUBJECTS);
printf("\nStudent Data and Statistics:\n");
printf("Name\tRoll No\tMarks\tTotal\tAverage\n");
for (i = 0; i < classSize; i++) {
printf("%s\t%d\t", class[i].name, class[i].rollNo);
for (j = 0; j < MAX_SUBJECTS; j++) {
printf("%.2f\t", class[i].marks[j]);
}
totalMarks = 0.0;
for (j = 0; j < MAX_SUBJECTS; j++) {
totalMarks += class[i].marks[j];
}
printf("%.2f\t%.2f\n", totalMarks, totalMarks / MAX_SUBJECTS);
}
int highestAverageIndex = 0, lowestAverageIndex = 0;
float highestAverage = class[0].marks[0], lowestAverage = class[0].marks[0];
for (i = 0; i < classSize; i++) {
float average = 0.0;
for (j = 0; j < MAX_SUBJECTS; j++) {
average += class[i].marks[j];
}
average /= MAX_SUBJECTS;
if (average > highestAverage) {
highestAverage = average;
highestAverageIndex = i;
}
if (average < lowestAverage) {
lowestAverage = average;
lowestAverageIndex = i;
}
}
printf("Student with highest average: %s (Roll No. %d)\n", class[highestAverageIndex].name, class[highestAverageIndex].rollNo);
printf("Student with lowest average: %s (Roll No. %d)\n", class[lowestAverageIndex].name, class[lowestAverageIndex].rollNo);
return 0;
