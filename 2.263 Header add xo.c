#include <stdio.h>
#include <stdlib.h>
#include"xo.h"

int checkWin(int game[][3], int player){
    if(

       (player==game[0][0]&&player==game[0][1]&&player==game[0][2]) ||
       (player==game[1][0]&&player==game[1][1]&&player==game[1][2]) ||
       (player==game[2][0]&&player==game[2][1]&&player==game[2][2]) ||
       (player==game[0][0]&&player==game[1][0]&&player==game[2][0]) ||
       (player==game[0][1]&&player==game[1][1]&&player==game[2][1]) ||
       (player==game[0][2]&&player==game[1][2]&&player==game[2][2]) ||
       (player==game[0][0]&&player==game[1][1]&&player==game[2][2]) ||
       (player==game[0][2]&&player==game[1][1]&&player==game[2][0]))

        return player;

    return -1;


}

void play(int game[][3]){
    int player = 1;
    int playerChoice = 0;
    int changed = 0; // should be bool
    int full=0;

     while(1){
        system("cls");
        displayGridDefault();
        printf("\n\n\n");
        displayGrid(game);

        printf("Player %d : ",player);
        scanf("%d",&playerChoice);
        changed=0
        ;
        switch(playerChoice){
        case 1:
            if(game[0][0]==-1){
                game[0][0]=player%2; // if player is one than it will be 1 or if 2 then it will be 0
                changed=1;}
            break;

        case 2:
            if(game[0][1]==-1){
                game[0][1]=player%2;
                changed=1;}
            break;

        case 3:
            if(game[0][2]==-1){
                game[0][2]=player%2;
                changed=1;}
            break;

        case 4:
            if(game[1][0]==-1){
                game[1][0]=player%2;
                changed=1;}
            break;

        case 5:
            if(game[1][1]==-1){
                game[1][1]=player%2;
                changed=1;}
            break;

        case 6:
            if(game[1][2]==-1){
                game[1][2]=player%2;
                changed=1;}
            break;

        case 7:
            if(game[2][0]==-1){
                game[2][0]=player%2;
                changed=1;}
            break;

        case 8:
            if(game[2][1]==-1){
                game[2][1]=player%2;
                changed=1;}
            break;

        case 9:
            if(game[2][2]==-1){
                game[2][2]=player%2;
                changed=1;}
            break;

        default:
            printf("Invalid Try again\n");
        }

        if(changed){
            int winner = checkWin(game, player%2);
            if(winner != -1) {
                system("cls");
                printf("Player %d is the winner!\n\n", winner?1:2);
                displayGrid(game);
                return;
            }

            player= player%2==1? 2:1;
            full++;
            if(full==9) {
                system("cls");
                displayGrid(game);
                printf("DRAW\n\n\n");
                return;
            }
        }


     }

}

void displayGridDefault(){
    for(int i=1; i<=9; i++)
        printf("\t%d\t|%s",i,(i%3==0?"\n":""));
}

 void displayGrid(int game[][3]){
     for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            switch(game[i][j]){   ///printf("\t%s",(game[i][j]==-1)?" ":((game[i][j]==0)?"O":"X"));
                case 1:
                    printf("\tX\t|");
                    break;
                case 0:
                    printf("\tO\t|");
                    break;
                case -1:
                    printf("\t \t|");
                    break;
                    }

        printf("\n");
     }


 }
