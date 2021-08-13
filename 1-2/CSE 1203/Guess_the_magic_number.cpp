/* Magic number program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main(void)
{
    srand(time(0));

    int magic; /* magic number */
    int guess; /* user's guess */

    magic = rand()%101; /* generate the magic number */

    printf("Guess the magic number: ");
    scanf("%d", &guess);

    if(guess == magic)
        printf("** Right **\n");
    else
        printf("Wrong\n");

    printf("The Magic number was %d\n",magic);

    getch();
    return 0;
}
