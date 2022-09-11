#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

char square[10] = {'\0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkWin();
void drawBoard(char *, char *, int);
int scoreboard(char *, char *);
int match = 1, pl1=0, pl2=0;
int main(){
    system("color 80");
    char name[3][20];
    int player = 1, i, choice;
    char mark;
    system("cls");
    printf("\n\n\t\t\tTIC TAC TOE \n\nPlayer 1(RED), enter your name - ");
    gets(name[1]);
    fflush(stdin);
    printf("Player 2(BLUE), enter your name - ");
    gets(name[2]);
    fflush(stdin);
    int loop=0;
do{
        square[1] ='1';
        square[2] ='2';
        square[3] ='3';
        square[4] ='4';
        square[5] ='5';
        square[6] ='6';
        square[7] ='7';
        square[8] ='8';
        square[9] ='9';
        do{
        player = (player % 2) ? 1 : 2;
        drawBoard(name[1], name[2], player);
        if(player == 1){
            system("color 4F");
        }
        else{
            system("color 1F");
        }
        printf("%s, enter the choice: ", name[player]);
        scanf("%d", &choice);
        mark=(player ==1) ? 'X' : '0';
        if(choice == 1 && square[1] == '1'){
            square[1]=mark;
        }
        else if(choice == 2 && square[2] == '2'){
            square[2]=mark;
        }
        else if(choice == 3 && square[3] == '3'){
            square[3]=mark;
        }
        else if(choice == 4 && square[4] == '4'){
            square[4]=mark;
        }
        else if(choice == 5 && square[5] == '5'){
            square[5]=mark;
        }
        else if(choice == 6 && square[6] == '6'){
            square[6]=mark;
            }
        else if(choice == 7 && square[7] == '7'){
            square[7]=mark;
        }
        else if(choice == 8 && square[8] == '8'){
            square[8]=mark;
        }
        else if(choice == 9 && square[9] == '9'){
            square[9]=mark;
        }
        else {
            printf("Invalid Option !\nPress any key to continue....\n");
            player--;
            getch();
        }
        i=checkWin();
        player++;

    }while(i == -1);

    drawBoard(name[1], name[2], player);
    system("color 80");
    if(i==1){
        printf("\a==>%s won!!!\nPress any key to continue....\n", name[--player]);
        getch();
        if(player==1){
            pl1++;
        }
        else{
            pl2++;
        }
        loop = scoreboard(name[1], name[2]);
    }
    else{
        printf("==>Game draw\nPress any key to continue....\n");
        getch();
        loop = scoreboard(name[1], name[2]);
    }
}while(loop!=0);
    printf("\n\n\n\t\t\t\t\t\t\tGame by Pranav Bisaria\nPress any key to continue....\n");
    getch();
    return 0;
}

int checkWin(){
    if(square[1]  == square[2] && square[2] == square[3]){
        return 1;
    }
    else if(square[4]  == square[5] && square[5] == square[6]){
        return 1;
    }
    else if(square[7]  == square[8] && square[8] == square[9]){
        return 1;
    }
    else if(square[1]  == square[4] && square[4] == square[7]){
        return 1;
    }
    else if(square[2]  == square[5] && square[5] == square[8]){
        return 1;
    }
    else if(square[3]  == square[6] && square[6] == square[9]){
        return 1;
    }
    else if(square[1]  == square[5] && square[5] == square[9]){
        return 1;
    }
    else if(square[3]  == square[5] && square[5] == square[7]){
        return 1;
    }
    else if ((square[1] != '1') && (square[2] != '2') && (square[3] != '3') && (square[4] != '4') && (square[5] != '5') && (square[6] != '6') && (square[7] != '7') && (square[8] != '8') && (square[9] != '9')){
        return 0;
    }
    else{
        return -1;
    }
}

void drawBoard(char *player1, char *player2, int player){
    system("cls");
    printf("\n\n\t\t\t\tTIC TAC TOE \n\t\t\t\tMatch %d\n\n", match);
    printf("\t%s (RED) (X) \t-\t %s (BLUE) (0) \n\n\n", player1, player2);

    if(player==1){
        printf("\t      |      |      \n");
        printf("\t  %c   |  %c   |  %c  \n", square[1], square[2], square[3]);
        printf("\t______|______|______\n");
        printf("\t      |      |      \n");
        printf("\t  %c   |  %c   |  %c  \n", square[4], square[5], square[6]);
        printf("\t______|______|______\n");
        printf("\t      |      |      \n");
        printf("\t  %c   |  %c   |  %c  \n", square[7], square[8], square[9]);
        printf("\t      |      |      \n");
    }

    else{
        printf("\t\t\t\t\t\t      |      |      \n");
        printf("\t\t\t\t\t\t  %c   |  %c   |  %c  \n", square[1], square[2], square[3]);
        printf("\t\t\t\t\t\t______|______|______\n");
        printf("\t\t\t\t\t\t      |      |      \n");
        printf("\t\t\t\t\t\t  %c   |  %c   |  %c  \n", square[4], square[5], square[6]);
        printf("\t\t\t\t\t\t______|______|______\n");
        printf("\t\t\t\t\t\t      |      |      \n");
        printf("\t\t\t\t\t\t  %c   |  %c   |  %c  \n", square[7], square[8], square[9]);
        printf("\t\t\t\t\t\t      |      |      \n");
    }

}

int scoreboard(char *player1, char *player2){
    char choice='0';
    system("cls");
    fflush(stdin);
    printf("Press 1 to rematch, and any other key to exit!!\n");
    scanf("%c", &choice);
    if(choice=='1'){
        match++;
        return 1;
    }
    else{
    system("cls");
    printf("\n\n\t\t\t\tTIC TAC TOE \n\n\t\t\t\tScore Board\n\n\n");
    printf("\n\n\t%s\t:\t%d\t\t%s\t:\t%d", player1, pl1, player2, pl2);
    return 0;
    }
}