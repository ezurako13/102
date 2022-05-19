#include <stdio.h>
#include <conio.h>

int main()
{
	//printf("\033[XA"); // Move up X lines;
	//printf("\033[XB"); // Move down X lines;
	//printf("\033[XC"); // Move right X column;
	//printf("\033[XD"); // Move left X column;
	//printf("\033[2J"); // Clear screen
	//printf("\033[8;5Hhello"); // Move to (8, 5) and output hello
	//gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

	int ch;

	//while ((ch = _getch()) != 'q');
	//{
	//	printf("%d", ch);
	//	printf("\n");
	//}

    while ((ch = _getch()) != 27) /* 27 = Esc key */
    {
        printf("%d", ch);
        if (ch == 0 || ch == 224)
            printf (", %d", _getch()); 
        printf("\n");
    }

    printf("ESC %d\n", ch);


	return 0;
}