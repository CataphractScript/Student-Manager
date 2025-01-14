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
  puts("1. Change math1 grade");
  puts("2. Change physic1 grade");
  puts("3. Change computer workshop grade");
  puts("4. Change basic programming grade");
  puts("5. Change persian language grade");
  puts("6. Change engilish language grade");
  puts("7. Change rules grade");
  puts("8. Back to main menu");

  scanf("%d", &choice);
  return choice;
}


int getcommand4()
{
  int choice;

  printf("\n");
  puts("1. math1");
  puts("2. physic1");
  puts("3. computer workshop");
  puts("4. basic programming");
  puts("5. persian language");
  puts("6. engilish language");
  puts("7. rules");
  puts("8. Back to main menu");

  scanf("%d", &choice);
  return choice;
}
