#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
  char name[50];
  int roll_number;
  int subject_grades[5];
  float total_grade;
  float average_grade;
  struct Student* next;
};
int main() {
  struct Student* head = NULL;
  struct Student* current = NULL;
  int i = 0;
  while (1) {
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter student name: ");
    scanf("%s", new_student->name);
    printf("Enter student roll number: ");
    scanf("%d", &(new_student->roll_number));
    printf("Enter student subject grades: ");
    for (i = 0; i < 5; i++) {
      scanf("%d", &(new_student->subject_grades[i]));
    }
    new_student->next = NULL;
    if (head == NULL) {
      head = new_student;
      current = new_student;
    } else {
      current->next = new_student;
      current = new_student;
    }
    printf("Do you want to enter another student? (yes/no): ");
    char response[5];
    scanf("%s", response);
    if (strcmp(response, "no") == 0) {
      break;
    }
  }
  // Calculate total grade for each student
     current = head;
       while (current!= NULL) {
           current->total_grade = 0;
               for (i = 0; i < 5; i++) {
                     current->total_grade += current->subject_grades[i];
                         }
                             // Calculate average grade for each student
                                 current->average_grade = current->total_grade / 5;
                                     current = current->next;
                                       }
                                         // Display table
                                           printf("\nStudent Name\tRoll Number\tSubject 1\tSubject 2\tSubject 3\tSubject 4\tSubject 5\tTotal Marks\tAverage Marks\n");
                                             current = head;
                                               while (current!= NULL) {
                                                   printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n", current->name, current->roll_number,
                                                              current->subject_grades[0], current->subject_grades[1], current->subject_grades[2],
                                                                         current->subject_grades[3], current->subject_grades[4], current->total_grade,
                                                                                    current->average_grade);
                                                                                        current = current->next;
                                                                                          }
                                                                                            return 0;
                                                                                            }