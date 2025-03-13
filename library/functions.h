#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

#define NAME_LENGTH 20
#define LAST_NAME_LENGTH 30

typedef struct information info;

// Designed for each menu options
enum MENU{ZERO, ADDS, ADDSG, RS, CSI, PSI}; // ADDS : Add student, ADDSG : Add student grades, RS : Remove student, PSI : Print student information, PSI : Print student information  CSI تغییرات
enum CHANGEINFOMENU{ZERO1, CSN, CSL, CSA, CSG, RSG}; // CSN : Change student name, CSL : Change student last name, CSA : Change student age, CSG : Change student grade, RSG : Remove student grades
enum PRINTINFOMENU{ZERO2, PLOS, SSI, PLOG, SSMC, SNFSC, SISGEU, GPA, GPACF, CS, LCYF}; //PLOS : Print List of Student, SSI : Search student information, PLOG : Print list of grades, SSMC : Show the student's missed courses, SNFSC : Show the number of failed students in a course, SISGEU : Sisplay information of all students with the grade entered by the user, Show student GPA : GPA display, GPACF : GPA display of courses in the faculty, CS : Conditional students, LCYF : List of the courses that have not yet failed

// Variables for each menu selection
typedef struct
{
  unsigned char cM; // Main menu
  unsigned char c1; // (Changing student informations) menu
  unsigned char c2; // (Print informations) menu
  unsigned char c3; 
}choice;

struct information
{
  char name[NAME_LENGTH];
  char last_name[LAST_NAME_LENGTH];
  unsigned int student_id; // The student ID is our unique code
  unsigned int student_age;
};

typedef struct
{
  bool check_grade;
  unsigned int student_id;
  float math1;
  float physic1;
  float computer_workshop;
  float basic_programming;
  float persian_lan;
  float english_lan;
  float rules;  
}grades;

typedef struct  // Temporary variables
{ 
  char new_name[NAME_LENGTH]; // The new student name that is taken from the user
  char new_last_name[LAST_NAME_LENGTH]; // The new student last name that is taken from the user
  unsigned int enter_id; // The student ID that is taken from the user
  unsigned int new_age; 
  float new_math1;
  float new_physic1;
  float new_computer_workshop;
  float new_basic_programming;
  float new_persian_lan;
  float new_english_lan;
  float new_rules;
}temp;

typedef struct
{
  bool m1;
  bool ph1;
  bool cw;
  bool bp;
  bool pl;
  bool el;
  bool r;
}check;

int getcommand()
{
  int choice;

  printf("\n");
  puts("Main menu :");
  puts("1. Add student.");
  puts("2. Add student grades");
  puts("3. Remove student.");
  puts("4. Changes in students information.");
  puts("5. Display options");
  puts("6. Exit");
  printf("\a");
  scanf("%d" , &choice);
  return choice;
}

int getcommand1()
{
  int choice;

  printf("\n");
  puts("1. Change student name.");
  puts("2. Change student last name.");
  puts("3. Change student age.");
  puts("4. Change student grades.");
  puts("5. Remove student grades.");
  puts("6. Back to main menu");
  
  scanf("%d", &choice);
  return choice;
}

int getcommand2()
{
  int choice;
  
  printf("\n");
  puts("1. Display all students information.");
  puts("2. Search student information by ID.");
  puts("3. Display just all students grades.");
  puts("4. Display the student's missed courses.");
  puts("5. Display the number of failed students in a course.");
  puts("6. Display information of all students with the grade entered by the user.");
  puts("7. GPA display by ID.");
  puts("8. GPA display of courses in the faculty.");
  puts("9. Conditional students.");
  puts("10. List of the courses that have not yet failed.");
  puts("11. Back to main menu");

  scanf("%d", &choice);
  return choice;
}

int getcommand3()
{
  int choice;

  printf("\n");
  puts("1. Change Math1 grade");
  puts("2. Change Physic1 grade");
  puts("3. Change Computer workshop grade");
  puts("4. Change Basic programming grade");
  puts("5. Change Persian language grade");
  puts("6. Change Engilish language grade");
  puts("7. Change Rules grade");
  puts("8. Back to main menu");

  scanf("%d", &choice);
  return choice;
}

int getcommand4()
{
  int choice;

  printf("\n");
  puts("1. Math1");
  puts("2. Physic1");
  puts("3. Computer workshop");
  puts("4. Basic programming");
  puts("5. Persian language");
  puts("6. Engilish language");
  puts("7. Rules");
  puts("8. Back to main menu");

  scanf("%d", &choice);
  return choice;
}

void GetStudentInfo(info* stu, grades* gstu)
{
  printf("\n");
  printf("Enter student name : ");
  scanf("%20s", stu->name);
  printf("Enter student last name : ");
  scanf("%30s", stu->last_name);
  printf("Enter student id : ");
  scanf("%u", &(stu->student_id)); 
  printf("Enter student age : ");
  scanf("%u", &(stu->student_age));

  gstu->check_grade = true;
  gstu->student_id = stu->student_id;

  printf("\n");
 
  puts("Enter student grades :");

  printf("Enter Math1 grade -----> ");
  scanf("%f", &(gstu->math1));
  printf("Enter Physic1 grade -----> ");
  scanf("%f", &(gstu->physic1));
  printf("Enter Computer workshop grade -----> ");
  scanf("%f", &(gstu->computer_workshop));
  printf("Enter Basic programming grade -----> ");
  scanf("%f", &(gstu->basic_programming));
  printf("Enter Persian language grade -----> ");
  scanf("%f", &(gstu->persian_lan));
  printf("Enter English language grade -----> ");
  scanf("%f", &(gstu->english_lan));
  printf("Enter Rules grade -----> ");
  scanf("%f", &(gstu->rules));
}

void AddStudentGrades(grades* addG)
{
  addG->check_grade = true;

  puts("Enter student grades :");

  printf("Enter Math1 grade -----> ");
  scanf("%f", &(addG->math1));
  printf("Enter Physic1 grade -----> ");
  scanf("%f", &(addG->physic1));
  printf("Enter Computer workshop grade -----> ");
  scanf("%f", &(addG->computer_workshop));
  printf("Enter Basic programming grade -----> ");
  scanf("%f", &(addG->basic_programming));
  printf("Enter Persian language grade -----> ");
  scanf("%f", &(addG->persian_lan));
  printf("Enter English language grade -----> ");
  scanf("%f", &(addG->english_lan));
  printf("Enter Rules grade -----> ");
  scanf("%f", &(addG->rules));
}

void RemoveStudent(unsigned int sid, FILE* fptr, FILE* gfptr)
{
  info Rstudent;
  grades GradesPart;
  
  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fread(&Rstudent, sizeof(info), 1, fptr);
  Rstudent.student_id = 0;
  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fwrite(&Rstudent, sizeof(info), 1, fptr);

  fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
  fread(&GradesPart, sizeof(grades), 1, gfptr);
  GradesPart.check_grade = false;
  fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
  fwrite(&GradesPart, sizeof(grades), 1, gfptr);

  printf("\n");
  puts("------------------------------");
  printf("\n");
  puts("Student information was removed from the list !!!");
  printf("\n");
  puts("------------------------------");
}

void ChangeStudentName(char newname[], unsigned int sid, FILE* fptr)
{
  info changeN;

  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fread(&changeN, sizeof(info), 1, fptr);
  strcpy(changeN.name, newname);
  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fwrite(&changeN, sizeof(info), 1, fptr);
}

void ChangeStudentLastName(char newlastname[], unsigned int sid, FILE* fptr)
{
  info changeL;

  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fread(&changeL, sizeof(info), 1, fptr);
  strcpy(changeL.last_name, newlastname);
  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fwrite(&changeL, sizeof(info), 1, fptr);
}

void ChangeStudentAge(unsigned int newage, unsigned int sid, FILE* fptr)
{
  info changeA;

  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fread(&changeA, sizeof(info), 1, fptr);
  changeA.student_age = newage;
  fseek(fptr, sizeof(info) * (sid - 1), SEEK_SET);
  fwrite(&changeA, sizeof(info), 1, fptr);
}

void ChangeStudentGrade(unsigned int sid, FILE* gfptr)
{
  grades changeG;
  temp neW;
  int choice;

  do
  {
    choice = getcommand3(); 
    switch (choice)
    {
      case 1:
          printf("\n");

          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fread(&changeG, sizeof(grades), 1, gfptr);
          printf("Enter new Math1 grade : ");
          scanf("%f", &neW.new_math1);
          changeG.math1 = neW.new_math1;
          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fwrite(&changeG, sizeof(grades), 1, gfptr);

          printf("\n");
      break;

      case 2:
        printf("\n");

        fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
        fread(&changeG, sizeof(grades), 1, gfptr);
        printf("Enter new Physic1 grade : ");
        scanf("%f", &neW.new_physic1);
        changeG.physic1 = neW.new_physic1;
        fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
        fwrite(&changeG, sizeof(grades), 1, gfptr);

        printf("\n");
      break;

      case 3:
        printf("\n");

        fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
        fread(&changeG, sizeof(grades), 1, gfptr);
        printf("Enter new Computer workshop grade : ");
        scanf("%f", &neW.new_computer_workshop);
        changeG.computer_workshop = neW.new_computer_workshop;
        fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
        fwrite(&changeG, sizeof(grades), 1, gfptr);

        printf("\n");
      break;

      case 4:
        printf("\n");

        fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
        fread(&changeG, sizeof(grades), 1, gfptr);
        printf("Enter new Basic programming grade : ");
        scanf("%f", &neW.new_basic_programming);
        changeG.basic_programming = neW.new_basic_programming;
        fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
        fwrite(&changeG, sizeof(grades), 1, gfptr);

        printf("\n");
      break;

      case 5:
          printf("\n");

          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fread(&changeG, sizeof(grades), 1, gfptr);
          printf("Enter new Persian language grade : ");
          scanf("%f", &neW.new_persian_lan);
          changeG.persian_lan = neW.new_persian_lan;
          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fwrite(&changeG, sizeof(grades), 1, gfptr);

          printf("\n");
      break;

      case 6:
          printf("\n");

          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fread(&changeG, sizeof(grades), 1, gfptr);
          printf("Enter new English language grade : ");
          scanf("%f", &neW.new_english_lan);
          changeG.english_lan = neW.new_english_lan;
          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fwrite(&changeG, sizeof(grades), 1, gfptr);

          printf("\n");
      break;

      case 7:
          printf("\n");

          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fread(&changeG, sizeof(grades), 1, gfptr);
          printf("Enter new Rules grade : ");
          scanf("%f", &neW.new_rules);
          changeG.rules = neW.new_rules;
          fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
          fwrite(&changeG, sizeof(grades), 1, gfptr);

          printf("\n");
      break;

      default:
          puts("This is wrong number !!!");
          puts("Try again...");
      break;
    }
  }while (choice != 8);
}

void RemoveStudentGrades(unsigned int sid, FILE* gfptr)
{
  grades Rgrades;

  fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
  fread(&Rgrades, sizeof(grades), 1, gfptr);
  Rgrades.check_grade = false;
  fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
  fwrite(&Rgrades, sizeof(grades), 1, gfptr);

  printf("\n");
  puts("------------------------------");
  printf("\n");
  puts("Student's grades were successfully removed !!!");
  printf("\n");
  puts("------------------------------");
}

void ShowStudentInfo(info* chapI) // all students information
{
  printf("* name : %s\n", chapI->name);
  printf("* Last name : %s\n", chapI->last_name);
  printf("* Student id : %u\n", chapI->student_id);
  printf("* Student age : %u\n", chapI->student_age);

  printf("\n");
  puts("------------------------------");
  printf("\n");
}


void SearchStudentInfo(info* search)
{
  printf("\n");
  puts("------------------------------");
  printf("\n");

  printf("* name : %s\n", search->name);
  printf("* Last name : %s\n", search->last_name);
  printf("* Student id : %u\n", search->student_id);
  printf("* Student age : %u\n", search->student_age);

  printf("\n");
  puts("------------------------------");
  printf("\n");
}


void ShowGrades(grades* chapG)
{
  if (chapG->check_grade == true)
  {
    printf("Student ID : %u\n", chapG->student_id);
    printf("* lesson : math1 \t course : 3 \t grade : %.2f\n", chapG->math1);
    printf("* lesson : physic1 \t course : 3 \t grade : %.2f\n", chapG->physic1);
    printf("* lesson : computer workshop \t course : 1 \t grade : %.2f\n", chapG->computer_workshop);
    printf("* lesson : basic programming \t course : 3 \t grade : %.2f\n", chapG->basic_programming);
    printf("* lesson : persian language \t course : 3 \t grade : %.2f\n", chapG->persian_lan);
    printf("* lesson : english language \t course : 3 \t grade : %.2f\n", chapG->english_lan);
    printf("* lesson : rules \t course : 2 \t grade : %.2f\n", chapG->rules);

    printf("\n");
    puts("------------------------------");
    printf("\n");
  }
}

void ShowMissedCourses(unsigned int sid, FILE* gfptr)
{
  grades Missed;
  int counter = 0;

  fseek(gfptr, sizeof(grades) * (sid - 1), SEEK_SET);
  fread(&Missed, sizeof(grades), 1, gfptr);

  puts("------------------------------");
  printf("\n");

  printf("Student ID : %u\n", sid);
  printf("\n");

  if (Missed.math1 < 10)
  {
    printf("* math1 : failed \t grade : %.2f\n", Missed.math1);
    counter++;
  }

  if (Missed.physic1 < 10)
  {
    printf("* physic1 : failed \t grade : %.2f\n", Missed.physic1);
    counter++;
  }

  if (Missed.computer_workshop < 10)
  {
    printf("* computer workshop : failed \t grade : %.2f\n", Missed.computer_workshop);
    counter++;
  }

  if (Missed.basic_programming < 10)
  {
    printf("* basic programming : failed \t grade : %.2f\n", Missed.basic_programming);
    counter++;
  }

  if (Missed.persian_lan < 10)
  {
    printf("* persian language : failed \t grade : %.2f\n", Missed.persian_lan);
    counter++;
  }

  if (Missed.english_lan < 10)
  {
    printf("* english language : failed \t grade : %.2f\n", Missed.english_lan);
    counter++;
  }

  if (Missed.rules < 10)
  {
    printf("* rules : failed \t grade : %.2f\n", Missed.rules);
    counter++;
  }

  if (counter == 0)
  {
    puts("This student has succeeded in all subjects !!!");
  }

  printf("\n");
  puts("------------------------------");
}

