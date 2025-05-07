//Author:Ismael Portillo
//Purspose:project finallll 




#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD "sound"
#define MAX_TRIES 6
#define WORD_LENGTH 5

void analyzeGuess(char guess[], const char target[]) {
    char result[WORD_LENGTH + 1];
    char hint[WORD_LENGTH + 1];
    int used[WORD_LENGTH] = {0};
	
    	    for (int i = 0; i < WORD_LENGTH; i++) {
        result[i] = guess[i];
        hint[i] = ' ';
    	}
            for (int i = 0; i < WORD_LENGTH; i++) {
            if (guess[i] == target[i]) {
            result[i] = toupper(guess[i]);
            used[i] = 1;
        }
        }
            for (int i = 0; i < WORD_LENGTH; i++) {
            if (guess[i] != target[i]) {
            for (int j = 0; j < WORD_LENGTH; j++) {
            if (!used[j] && guess[i] == target[j]) {
                    hint[i] = '^';
                    used[j] = 1;
            break;
        }
        }
        }
    	}
    result[WORD_LENGTH] = '\0';
    hint[WORD_LENGTH] = '\0';
    printf("%s\n", result);
    printf("%s\n", hint);
	}
    int main() {
    char guess[WORD_LENGTH + 1];
    int attempt;
    	printf("===== WORDLE in C =====\n");
            for (attempt = 0; attempt < MAX_TRIES; attempt++) {
        printf("GUESS %d! Enter your guess: ", attempt + 1);
        scanf("%5s", guess);
            for (int i = 0; i < WORD_LENGTH; i++) {
            guess[i] = tolower(guess[i]);
        }
        analyzeGuess(guess, WORD);

            if (strcmp(guess, WORD) == 0) {
            for (int i = 0; i < WORD_LENGTH; i++) {
                guess[i] = toupper(guess[i]);
        }
            guess[WORD_LENGTH] = '\0';
        printf("		=========================\n");
        printf("			%s\n", guess);
        printf("		You won in %d guesses!\n", attempt + 1);
        printf("			Nice!\n");
            break;
        }
    	}

    return 0;
}


