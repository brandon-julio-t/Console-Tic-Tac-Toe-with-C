#pragma warning(disable: 4996)
#include <stdlib.h>
#include <stdio.h>

int main() {

	// Game constants

	const char PLAYER_ONE_SIGN = 'X';
	const char PLAYER_TWO_SIGN = 'O';
	const char EMPTY = NULL;
	const int LENGTH = 3;

	// Game variables

	int round = 0;
	int isPlayerOneTurn = 1;
	char playBoard[3][3] = {
		{ NULL, NULL, NULL },
		{ NULL, NULL, NULL },
		{ NULL, NULL, NULL }
	};

	while (round < 9) {

		int coordinateOfX = -1;
		int coordinateOfY = -1;

		while (coordinateOfX < 1 // Coordinate X
			|| coordinateOfX > 3 // is between 1 and 3
			|| coordinateOfY < 1 // Coordinate Y
			|| coordinateOfY > 3 // is between 1 and 3
			) {

			// 1. Print play board

			printf("Round: %d\n", round + 1);
			puts("  1 2 3");
			for (int row = 0; row < LENGTH; row++) {
				printf("%d ", row + 1);

				for (int col = 0; col < LENGTH; col++) {
					printf("%c ", playBoard[row][col]);
				}

				printf("\n");
			}
			
			// 2. Get coordinates input

			char playerSign = isPlayerOneTurn ? PLAYER_ONE_SIGN : PLAYER_TWO_SIGN;

			printf("Coordinate of X for player '%c': ", playerSign);
			scanf("%d", &coordinateOfX);

			printf("Coordinate of Y for player '%c': ", playerSign);
			scanf("%d", &coordinateOfY);


			int row = coordinateOfY - 1;
			int col = coordinateOfX - 1;
			int locationIsEmpty = playBoard[row][col] == NULL;

			if (locationIsEmpty) {
				isPlayerOneTurn = !isPlayerOneTurn;
				playBoard[row][col] = playerSign;
			} else {
				coordinateOfX = -1;
				coordinateOfY = -1;
			}

		}

		// 3. Check winner

		char win1 = (playBoard[0][2] == playBoard[1][1] && playBoard[1][1] == playBoard[2][0]) ? playBoard[0][2] : NULL; // diagonal 1		/ 
		char win2 = (playBoard[0][0] == playBoard[1][1] && playBoard[1][1] == playBoard[2][2]) ? playBoard[0][0] : NULL; // diagonal 2		\
																												   
		char win3 = (playBoard[0][0] == playBoard[1][0] && playBoard[1][0] == playBoard[2][0]) ? playBoard[0][0] : NULL; // Vertical 1		|
		char win4 = (playBoard[0][1] == playBoard[1][1] && playBoard[1][1] == playBoard[2][1]) ? playBoard[0][1] : NULL; // Vertical 2		 |
		char win5 = (playBoard[0][2] == playBoard[1][2] && playBoard[1][2] == playBoard[2][2]) ? playBoard[0][2] : NULL; // Vertical 3		  |
																												   
		char win6 = (playBoard[0][0] == playBoard[0][1] && playBoard[0][1] == playBoard[0][2]) ? playBoard[0][0] : NULL; // Horizontal 1	`
		char win7 = (playBoard[1][0] == playBoard[1][1] && playBoard[1][1] == playBoard[1][2]) ? playBoard[1][0] : NULL; // Horizontal 2	-
		char win8 = (playBoard[2][0] == playBoard[2][1] && playBoard[2][1] == playBoard[2][2]) ? playBoard[2][0] : NULL; // Horizontal 3	_

		if (win1 || win2 || win3 || win4 || win5 || win6 || win7 || win8) {

			// 5. Announce winner

			char winner =
				win1 ? win1 :
				win2 ? win2 :
				win3 ? win3 :
				win4 ? win4 :
				win5 ? win5 :
				win6 ? win6 :
				win7 ? win7 :
				win8;

			printf("Winner: %c\n", winner);
			return 0;
		}

		// 4. Repeat

		round++;

	}

	// 5. Announce winner

	puts("No winner.");

}