#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    char filename[] = "buffered.txt";
    int i;
    clock_t start, end;
    // Loop one million times
     fp = fopen(filename, "w");
     if (fp == NULL){
     perror("Error opening file");
     return 1;
   }

   start = clock();
   for( i=0; i < 1000000; i++){
   fprintf(fp, "13 characters written to buffered.txt\n");
   printf("%d: 13 characters written to buffered.txt\n",i);
   fflush(fp);
}
fclose(fp);
end = clock();
double time_elapsed = (end - start + 0.0)/CLOCKS_PER_SEC; 
printf("Buffered IO Time Elapsed: %f seconds\n", time_elapsed);
return 0;
  }
