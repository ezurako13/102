#include <stdio.h>
//#include <conio.h>
#include <termios.h>
#include <unistd.h>

/* reads from keypress, doesn't echo */

int _getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* reads from keypress, echoes */

int _getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


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

    while ((ch = _getch()) != 'q') /* 27 = Esc key */
    {
        printf("%d", ch);
        if (ch == 0 || ch == 224 || ch == 27)
            printf (", %d, %d", _getch(), _getch()); 
        printf("\n");
    }

    printf("ESC %d\n", ch);


	return 0;
}