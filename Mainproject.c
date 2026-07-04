#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_WORDS 20
#define MAX_WORD_LEN 30

int main() {
 int choice, i;
 char sentences[5][100] = {
    "The quick brown fox jumps over the lazy dog",
    "Programming in C is fun and highly rewarding",
    "Practice makes a person perfect in every aspect",
    "Consistency is the key to unlocking success",
    "Beautiful days are built with small productive steps."
};

printf("\n=== Welcome to Typing Speed & Accuracy Checker ===\n\n");
printf("Choose a sentence to test your typing:\n");
 for(i=0;i<5;i++) {
  printf("%d. %s\n",i+1,sentences[i]);
}

printf("\nEnter your choice (1-5): ");
scanf("%d",&choice);
 if(choice<1 || choice>5) {
  printf("Invalid choice! Exiting...\n");
return 1;
}

 while(getchar()!='\n'); 

 char target[100];
 strcpy(target,sentences[choice-1]);
printf("\n--- Start Typing ---\n");
printf("Target:\n%s\n\n", target);
printf("Press ENTER and Start typing immediately\n");
 getchar();

clock_t start_time = clock();
 char typed[150];
 fgets(typed, sizeof(typed), stdin);
 typed[strcspn(typed, "\n")] = '\0';
clock_t end_time = clock();

double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

if(total_time <= 0)
    total_time = 0.01;

char target_words[MAX_WORDS][MAX_WORD_LEN];
char typed_words[MAX_WORDS][MAX_WORD_LEN];
    
int target_count = 0, typed_count = 0;

char *token = strtok(target, " ");
while(token != NULL && target_count < MAX_WORDS) {
    strcpy(target_words[target_count++], token);
    token = strtok(NULL, " ");
}

token = strtok(typed, " ");
while(token != NULL && typed_count < MAX_WORDS) {
    strcpy(typed_words[typed_count++], token);
    token = strtok(NULL, " ");
}

int correct_words = 0;
int total_chars_typed = 0;

int limit = (target_count < typed_count) ? target_count : typed_count;
 for(int i = 0; i < limit; i++) {
  if(strcmp(target_words[i], typed_words[i]) == 0) {
    correct_words++;
}
}

 for(int i = 0; i < typed_count; i++) {
  total_chars_typed += strlen(typed_words[i]);
}
total_chars_typed += (typed_count >0) ? (typed_count -1) : 0; 

double minutes = total_time / 60.0;
double cpm = total_chars_typed / minutes;
double wpm = (total_chars_typed / 5.0) / minutes; 
int total_words;

if(target_count > typed_count)
    total_words = target_count;
else
    total_words = typed_count;

double accuracy = ((double)correct_words / total_words) * 100.0;

printf("\n================>> RESULT <<================\n");
printf("Total Time Taken                 : %.2f seconds\n", total_time);
printf("Your CPM (Characters Per Minute) : %.2f \n", cpm);
printf("Your WPM (Words Per Minute)      : %.2f \n", wpm);
printf("Accuracy                         : %.2f%%\n", accuracy);
printf("Words Matched                    : %d out of %d\n", correct_words, target_count);
printf("<<------------------------------------------>>\n");

return 0;
}