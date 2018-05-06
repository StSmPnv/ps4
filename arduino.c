/*
 ============================================================================
 Name        : arduino.c
 Author      : AdSm
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
	int i;
	char cislo = 0;
	char pozicia = 0;
	unsigned char positionNum[5];
	char* guess = (char*) calloc(5, sizeof(char));
	bool succes = false;
	char pokusy = 10;

	srand(time(NULL));
	for (i = 0; i < 4; i++) {
		positionNum[i] = ((unsigned char) rand() % 10) + 0x30;
	}
	positionNum[i] = '\0';
	printf("%s", positionNum);
	printf("\n");
	printf("Welcome to game Mastermid\n"
			"Your goal is to guess my secret combination.\n"
			"I'm thinking a number:");

	while (!succes && (pokusy != 0)) {
		printf("\nYour guess: ");
		scanf("%s", guess);
		pozicia = 0;
		cislo = 0;
		for (i = 0; i < 4; i++) {
			if (positionNum[i] == guess[i]) {
				pozicia++;
			} else {
				for (int j = 0; j < 4; j++) {
					if ((positionNum[i]) == guess[j]) {
						cislo++;
					}
				}
			}

		}
		printf("%d. %s %dA%dB", (11 - pokusy) ,guess, pozicia, cislo);
		if (pozicia == 4) {
			succes = true;
		}
		pokusy--;
	}

	if (succes == true) {
		printf("\nCongatulation! You won in %d guesses.\n", 10 - pokusy);
	} else {
		printf("\nLooser! My secret combination was %s.\n", positionNum);
	}

	free(guess);
	return 0;
}
