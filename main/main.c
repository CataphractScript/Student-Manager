#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include"../library/functions.h"


int main()
{
    FILE * sfptr; // student.dat file pointer
    FILE * gsfptr; // grades.dat file pointer

    puts("Welcome to my program...!");
    printf("\n");

    enum MENU chosen_option_menu;
    enum CHANGEINFOMENU chosen_option_CSI; // CSI : Change Student Info 
    enum PRINTINFOMENU chosen_option_PL; // PL : Print List

    choice command;

    do
    {
      command.cM = getcommand();
      command.c1 = 0;
      command.c2 = 0;

      // Main menu
      switch (command.cM)
      {
      case 1:
        chosen_option_menu = ADDS;
        break;

      case 2:
        chosen_option_menu = ADDSG;
        break;

      case 3:
        chosen_option_menu = RS;
        break;

      case 4:
        chosen_option_menu = CSI;
        break;

      case 5:
        chosen_option_menu = PSI;
        break;

      case 6: // Exit option.
        printf("\n");
        puts("have fun !");
        puts("See you later...");

        return 0;
      //   break;

      default:
        chosen_option_menu = ZERO;
        printf("\n");
        puts("Wrong Number");
        puts("Try again...");
        command.cM = 0;
        break;
      }

    }while (command.cM != 6);

    //To be continued... 
    return 0;
}