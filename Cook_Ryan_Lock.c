#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CODE_LENGTH 4
#define RANGE 10
#define TRIES 10

int main() {
    srand(time(NULL));

    int code[CODE_LENGTH];
    for (int i = 0; i < CODE_LENGTH; i++) {
        code[i] = rand() % RANGE;
    }

    int remaining_tries = TRIES;
    int num_correct;
    int num_misplaced;
    int input_int[CODE_LENGTH];
    char input[CODE_LENGTH + 1];

    while (remaining_tries > 0) {
        printf("%d tries remaining. What is the code? ", remaining_tries);
        scanf("%s", input);

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        for (int i = 0; input[i] != '\0'; i++) {
            input_int[i] = input[i] - '0';
        }

        num_correct = 0;
        num_misplaced = 0;
        for (int i = 0; i < CODE_LENGTH; i++) {
            if (input_int[i] == code[i]) {
                num_correct++;
            } else {
                for (int j = 0; j < CODE_LENGTH; j++) {
                    if (input_int[i] == code[j] && i != j) {
                        num_misplaced++;
                        break;
                    }
                }
            }
        }

        if (num_correct == CODE_LENGTH) {
            printf("Congratulations! You have guessed the code.\n");
            break;
        }

        remaining_tries--;
        printf("You have %d tries remaining.\n", remaining_tries);
        if (num_correct > 0) {
            printf("You have %d correct digits.\n", num_correct);
        }
        if (num_misplaced > 0) {
            printf("You have %d misplaced digits.\n", num_misplaced);
        }
        printf("\n");
    }

    if (remaining_tries == 0) {
        printf("You have run out of tries. The code was: ");
        for (int i = 0; i < CODE_LENGTH; i++) {
            printf("%d ", code[i]);
        }
        printf(".\n");
    }

    return 0;
}
