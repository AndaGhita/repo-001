
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int game (int anvandare , int datorn);

int main()
{   
    //variabel declaration 

    int n; 
 
    int you, computer, result;

    int player1 = 0; 
    int player2 = 0;
    int player_score;

   

    printf("STEN SAX PASE\n");
    printf("=============\n");

    while(10){

    printf("Ditt drag (Sten=0/Sax=1/Pase=2) : ");

    //input från användaren
    scanf("%d", &you);
 
    // Väljer random nummer
    
    srand(time(NULL));
 
    // Gör random nummer mindre än 100, dividerat med 100
    n = rand() % 100;
 
    // Att använda enkel sannolikhet 100 är grovt fördelat mellan sten,sax och pase
   
    if (n < 33){


        // 0  betecknar sten
        computer = 0;
        printf("Datorn drar sten\n");

    }
 
    else if (n > 33 && n < 66)
    {
         // 1  betecknar sax
        computer = 1;
        printf("Datorn drar sax\n");

    }
    else
    {

        // 2  betecknar pase
        computer = 2;
        printf("Datorn drar pase\n");

    }
    
   
    // Funktion ring för att spela spelet
    result = game(you, computer);
 
    if (result == -1) 
    {
        printf("Oavgjort!!\n");
    }
    else if (result == 1) 
    {

        printf("Du vann draget\n");
        player_score = player1++; //öka den första spelaren

        if(player1 == 10)
        {
            printf("Du vann!!");
            break;
        }
    }
    else {

        printf("Datorn vann draget\n");
        player_score = player2++; //öka den andra spelaren

        if(player2 == 10)
        {
            printf("Datorn vann!!");
            break;
        }
    }
        
 
  printf("Poangstallning (du-datorn): %d - %d\n ", player1, player2); 

    }

    return 0;
}
int Game (int anvandare , int datorn ){

    
    // Om både användaren och datorn har valt samma sak
    if (anvandare == datorn)
        return -1;
 
    // Om användarens val är sten och datorns val är papper
    if (anvandare == 0 && datorn == 2)
        return 0;
 
    // Om användarens val är papper och datorns val är sten
    else if (anvandare == 2 && datorn == 0) return 1;
 
    // Om användarens val är sten och datorns val är sax
    if (anvandare == 0 && datorn == 1)
        return 1;
 
    // Om användarens val är sax och datorns val är sten
    else if (anvandare == 1 && datorn == 0)
        return 0;
 
    // Om användarens val är papper och datorns val är sax
    if (anvandare == 2 && datorn == 1)
        return 0;
 
    // Om användarens val är sax och datorns val är papper
    else if (anvandare == 1 && datorn == 2)
        return 1;
        
}
