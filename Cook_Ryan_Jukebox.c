#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define max_files 10
#define max_length 1000

int main() {
    FILE *files[max_files];
    char *lines[max_files];
    size_t line_lens[max_files];
    int num_files = 0;
    int i, choice;
    char title[max_length];
    /*Open lyrics file*/
    files[num_files] = fopen("city_of_stars.txt", "r");
    if (files[num_files] != NULL) {
        lines[num_files] = malloc(max_length);
        num_files++;
    }
    files[num_files] = fopen("roommates.txt", "r");
    if (files[num_files] != NULL) {
        lines[num_files] = malloc(max_length);
        num_files++;
    }
    files[num_files] = fopen("good_news.txt", "r");
    if (files[num_files] != NULL) {
        lines[num_files] = malloc(max_length);
        num_files++;
    }
    files[num_files] = fopen("everytime.txt", "r");
    if (files[num_files] != NULL) {
        lines[num_files] = malloc(max_length);
        num_files++;
    }
    files[num_files] = fopen("night.txt", "r");
    if (files[num_files] != NULL) {
        lines[num_files] = malloc(max_length);
        num_files++;
    }
    /*Menu for user to choose song*/
    printf("Welcome to Ryan Cook's Lyric Jukebox\n");
    printf("Please select an track from the list below: \n");
    for (i = 0; i < num_files; i++) {
        if (fgets(title, max_length, files[i]) != NULL) {
            size_t len = strlen(title);
            if (len > 0 && title[len - 1] == '\n') {
                title[len - 1] = '\0';
            }
        } else {
            title[0] = '\0';
        }
        printf("%d: %s\n", i + 1, title);
    }
    printf("\n");
    /*Scans user choice and prints lyrics*/
    scanf("%d", &choice);
    if (choice >= 1 && choice <= num_files) {
        rewind(files[choice - 1]);
        while(getline(&lines[choice - 1], &line_lens[choice - 1], files[choice - 1]) != -1) {
            printf("%s", lines[choice - 1]);
	    sleep(1);
        }
    } else {
        printf("Invalid Choice\n");
    }
   
 
   for (i = 0; i < num_files; i++) {
        free(lines[i]);
        fclose(files[i]);
    }
    return 0;
}
