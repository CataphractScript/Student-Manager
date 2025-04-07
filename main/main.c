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
        // break;

      default:
        chosen_option_menu = ZERO;
        printf("\n");
        puts("Wrong Number");
        puts("Try again...");
        command.cM = 0;
        break;
      }


      switch (chosen_option_menu) // get new menu number
      {
      case ADDS:
        info addI; // temp
        grades addG; // temp

        GetStudentInfo(&addI, &addG);

        sfptr = fopen("../files/student.dat", "rb+");

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
        }

        fseek(sfptr, sizeof(info) * (addI.student_id - 1), SEEK_SET);
        fwrite(&addI, sizeof(info), 1, sfptr);
        fclose(sfptr);

        // copy grades from student.dat to grades.dat

        gsfptr = fopen("../files/grades.dat", "rb+");

        if (sfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        fseek(gsfptr, sizeof(grades) * (addG.student_id - 1), SEEK_SET);
        fwrite(&addG, sizeof(grades), 1, gsfptr);
        fclose(gsfptr);

        printf("\n");

        chosen_option_CSI = ZERO;

        break;

      case ADDSG:

        grades add_grades;
        temp add_ID;

        gsfptr = fopen("../files/grades.dat", "rb+");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &add_ID.enter_id);

        fseek(gsfptr, sizeof(grades) * (add_ID.enter_id - 1), SEEK_SET);
        fread(&add_grades, sizeof(grades), 1, gsfptr);

        AddStudentGrades(&add_grades);

        fseek(gsfptr, sizeof(grades) * (add_ID.enter_id - 1), SEEK_SET);
        fwrite(&add_grades, sizeof(grades), 1, gsfptr);

        fclose(gsfptr);

        break;
     
      case RS:

        temp SID; // SID : Student ID

        sfptr = fopen("../files/student.dat", "rb+");
        gsfptr = fopen("../files/grades.dat", "rb+");

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
          return 0;
        }

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &SID.enter_id);
          
        RemoveStudent(SID.enter_id, sfptr, gsfptr);

        fclose(sfptr);
        fclose(gsfptr);

        printf("\n");

        chosen_option_CSI = ZERO;
        
        break;

      case CSI:
        command.c1 = getcommand1();
        break;

      case PSI:
        command.c2 = getcommand2();
        break;
      }

      switch (command.c1) // convert num to enum value
      {
      case 0:
        break;

      case 1:
        chosen_option_CSI = CSN;
        command.c1 = 0;
        break;

      case 2:
        chosen_option_CSI = CSL;
        command.c1 = 0;
        break;

      case 3:
        chosen_option_CSI = CSA;
        command.c1 = 0;
        break;

      case 4:
        chosen_option_CSI = CSG;
        command.c1 = 0;
        break;

      case 5:
        chosen_option_CSI = RSG;
        command.c1 = 0;
        break;

      case 6: // Back to main menu option.
        chosen_option_CSI = ZERO1;
        command.c1 = 0;
        break;
    
      default:
        chosen_option_menu = ZERO1;
        printf("\n");
        puts("Wrong Number");
        puts("Try again...");
        command.c1 = 0;
        break;
      }

      switch (chosen_option_CSI)
      {
      case CSN:
        temp CN_ID;

        sfptr = fopen("../files/student.dat", "rb+"); // rb+ : read & write

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &CN_ID.enter_id);

        printf("Enter new name : ");
        scanf("%20s", &CN_ID.new_name);

        ChangeStudentName(CN_ID.new_name, CN_ID.enter_id, sfptr);

        fclose(sfptr);
          
        printf("\n");
          
        chosen_option_CSI = ZERO1;
      
        break; 

      case CSL:
        temp CL_ID;

        sfptr = fopen("../files/student.dat", "rb+");

        if (sfptr == NULL)
        {
          fputs("Can not open the file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &CL_ID.enter_id);

        printf("Enter new last name : ");
        scanf("%30s", &CL_ID.new_last_name);

        ChangeStudentLastName(CL_ID.new_last_name, CL_ID.enter_id, sfptr);

        fclose(sfptr);
          
        printf("\n");
          
        chosen_option_CSI = ZERO1;

        break;

      case CSA: 
        temp CA_ID;

        sfptr = fopen("../files/student.dat", "rb+");

        if (sfptr == NULL)
        {
          fputs("Can not open the file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &CA_ID.enter_id);

        printf("Enter new age : ");
        scanf("%u", &CA_ID.new_age);

        ChangeStudentAge(CA_ID.new_age, CA_ID.enter_id, sfptr);

        fclose(sfptr);
               
        printf("\n");
          
        chosen_option_CSI = ZERO1;

        break;
      
      case CSG:
      
        temp CG_ID;

        gsfptr = fopen("../files/grades.dat", "rb+");
          
        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &CG_ID.enter_id);

        ChangeStudentGrade(CG_ID.enter_id, gsfptr);

        fclose(gsfptr);
               
        printf("\n");
          
        chosen_option_CSI = ZERO1;
      
        break;
          
      case RSG: // حذف نمرات دانشجو
        temp RG_ID; // متغییر موقت که از کاربر می گیرد

        gsfptr = fopen("../files/grades.dat", "rb+");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &RG_ID.enter_id);

        RemoveStudentGrades(RG_ID.enter_id, gsfptr);

        fclose(gsfptr);
               
        printf("\n");
          
        chosen_option_CSI = ZERO1;

        break;
      }

      switch (command.c2)
      {
        case 0:
          break;

        case 1:
          chosen_option_PL = PLOS;
          command.c2 = 0;
          break;

        case 2:
          chosen_option_PL = SSI;
          command.c2 = 0;
          break;

        case 3:
          chosen_option_PL = PLOG;
          command.c2 = 0;
          break;

        case 4:
          chosen_option_PL = SSMC;
          command.c2 = 0;
          break;

        case 5:
          chosen_option_PL = SNFSC;
          command.c2 = 0;
          break;

        case 6:
          chosen_option_PL = SISGEU;
          command.c2 = 0;
          break;

        case 7:
          chosen_option_PL = GPA;
          command.c2 = 0;
          break;

        case 8:
          chosen_option_PL = GPACF;
          command.c2 = 0;
          break;

        case 9:
          chosen_option_PL = CS;
          command.c2 = 0;
          break;

        case 10:
          chosen_option_PL = LCYF;
          command.c2 = 0;
          break;

        case 11: // Back to main menu option.
          chosen_option_PL = ZERO2;
          command.c2 = 0;
          break;

        default:
          chosen_option_menu = ZERO2;
          printf("\n");
          puts("Wrong Number");
          puts("Try again...");
          command.c2 = 0;
          break;
      }


      switch (chosen_option_PL)
      {
      case PLOS:
        info PIL; // PIL : print student list

        sfptr = fopen("../files/student.dat", "rb");

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
        }

        printf("\n");
        puts("------------------------------");
        printf("\n");

        fseek(sfptr, 0, SEEK_SET);

        while (!feof(sfptr))
        {
          fread(&PIL, sizeof(info), 1, sfptr);

          if (!feof(sfptr) && PIL.student_id != 0)
          {
            ShowStudentInfo(&PIL);         
          }
        }       
       
        fclose(sfptr);

        chosen_option_PL = ZERO2;

        break;

      case SSI:
        temp search_ID;
        info SEARCH;

        sfptr = fopen("../files/student.dat", "rb");

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &search_ID.enter_id);

        fseek(sfptr, sizeof(info) * (search_ID.enter_id- 1), SEEK_SET);
        fread(&SEARCH, sizeof(info), 1, sfptr);

        SearchStudentInfo(&SEARCH);

        fclose(sfptr);
          
        chosen_option_PL = ZERO2;
        break;

      case PLOG:
        grades PGL; // PGL : print grades list

        gsfptr = fopen("../files/grades.dat", "rb");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        printf("\n");
        puts("------------------------------");
        printf("\n");

        fseek(gsfptr, 0, SEEK_SET);

        while (!feof(gsfptr))
        { 
          fread(&PGL, sizeof(grades), 1, gsfptr);

          if (!feof(gsfptr) && PGL.check_grade == true)
          {
            ShowGrades(&PGL);         
          }
        }       
       
        fclose(gsfptr);     

        chosen_option_PL = ZERO2;
        break;

      case SSMC:
        temp missed_ID;

        gsfptr = fopen("../files/grades.dat", "rb");

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &missed_ID.enter_id);
        printf("\n");

        ShowMissedCourses(missed_ID.enter_id, gsfptr);

        fclose(gsfptr);
               
        printf("\n");
          
        chosen_option_PL = ZERO2;
        break;

      case SNFSC:
        gsfptr = fopen("../files/grades.dat", "rb");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        ShowStudentFailedCounter(gsfptr);

        fclose(gsfptr);

        printf("\n");

        chosen_option_PL = ZERO2;
        break;

      case SISGEU:
        gsfptr = fopen("../files/grades.dat", "rb");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        ShowListOfStudentWithXgrade(gsfptr);

        fclose(gsfptr);

        printf("\n");

        chosen_option_PL = ZERO2;
        break;
      
      case GPA:
        temp student_ID;

        gsfptr = fopen("../files/grades.dat", "rb");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
          return 0;
        }

        printf("\n");
        printf("Enter student id : ");
        scanf("%u", &student_ID.enter_id);
        printf("\n");

        StudentGpa(student_ID.enter_id, gsfptr);

        fclose(gsfptr);
               
        printf("\n");
          
        chosen_option_PL = ZERO2;
        break;

      case GPACF:
        gsfptr = fopen("../files/grades.dat", "rb");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        CoursesGpa(gsfptr);

        fclose(gsfptr);

        printf("\n");

        chosen_option_PL = ZERO2;
        break;

      case CS:
        sfptr = fopen("../files/student.dat", "rb");
        gsfptr = fopen("../files/grades.dat", "rb");

        if (sfptr == NULL)
        {
          fputs("Can not open the student file !!!", stderr);
        }

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        Conditionalstudents(sfptr, gsfptr);

        fclose(sfptr);
        fclose(gsfptr);

        printf("\n");

        chosen_option_PL = ZERO2;
        break;

      case LCYF:
        gsfptr = fopen("../files/grades.dat", "rb");

        if (gsfptr == NULL)
        {
          fputs("Can not open the grades file !!!", stderr);
        }

        NoFailedLesson(gsfptr);

        fclose(gsfptr);

        printf("\n");

        chosen_option_PL = ZERO2;
        break;
      
      case ZERO2:
        break;
      }
    }while (command.cM != 6);
    
    return 0;
}