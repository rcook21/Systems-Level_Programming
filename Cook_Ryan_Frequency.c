# include <stdio.h>
# include <ctype.h>
# define alphabet_size 26

int main(){
FILE *file = fopen("sys7.txt", "r");
if(file == NULL) {
perror("Error opening file");
return 1;
}
int frequency[alphabet_size] = {0};
int maxFrequency = 0;
char mostFrequent;

int c;
while ((c = fgetc(file)) != EOF){
if (isalpha(c)){ //makes sure character is in alphabet
c = tolower(c); //makes lowercase
frequency[c - 'a']++;
if (frequency[c-'a']>maxFrequency){
maxFrequency = frequency[c - 'a'];
mostFrequent = c;
}
}
}
fclose(file);
printf("The most frequent character is '%c'. I appeared %d time\n", mostFrequent, maxFrequency);
return 0;
}
