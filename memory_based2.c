#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    FILE* word;
    word = fopen("words.txt", "r");

    if (word == NULL)
    {
        printf("The file is not opened, ERROR 101");
        exit(0);
    }


    char words[20][25];
    int i = 0;

    srand(time(NULL));
    while (i<20)
    {
        int yes = rand()%2;
        if(yes == 1){
            fflush(stdin);
            fgets(words[i], 25, word);
            i++;    
        }
        else{
            char c = 'a';
            while(c != '\n'){
                c = getc(word);
            }
        }
    }

    for(int i = 0; i<20; i++){
        printf("%d. %s", i+1, words[i]);
    }

    sleep(2);
    system("cls");

    int guess = 20;
    int score = 0;

    while(guess != 0){
        int correct = 0;
        char user_word[25];
        printf("Enter any word you remember: ");
        scanf("%s", user_word);
        int len = strlen(user_word);
        user_word[len] = '\n';
        user_word[len+1] = '\0';
        for(int i = 0; i<20; i++){
            if(strcmp(user_word, words[i]) == 0){
                correct = 1;
                printf("You guessed the word right!!\n");
                score++;
                break;
            }
        }

        if(correct == 0){
            printf("You guessed the wrong word.\n");
        }
        guess--;
        printf("No of guesses left: %d\n", guess);
        
    }
    printf("Your score is: %d", score);

    fclose(word);
    return 0;
}