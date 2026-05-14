#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node{
    char course[50];
    char minGrade;
    struct Node* next;
} Node;

typedef struct {
    char course[50];
    Node* prereqList;
} Course;

typedef struct {
    char course[50];
    char grade;
} EnrolledCourse;

Course courses[MAX];
int courseCount = 0;

EnrolledCourse profile[MAX];
int profileCount = 0;

int findCourseIndex(char name[]){
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].course, name) == 0) 
            return i;
    }
    return -1;
}

void addCourse(char name[]){
    if (findCourseIndex(name) != -1) return;
    strcpy(courses[courseCount].course, name);
    courses[courseCount].prereqList = NULL;
    courseCount++;
}

void addPrereq(char course[], char prereq[], char minGrade){
    int i = findCourseIndex(course);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->course, prereq);
    newNode->minGrade = minGrade;
    newNode->next = courses[i].prereqList;
    courses[i].prereqList = newNode;
}

int checkProfileMet(char prereqCourse[], char minGrade){
    for(int i =0; i < profileCount; i++){
        if(strcmp(profile[i].course, prereqCourse) == 0){
            return profile[i].grade <= minGrade;
        }
    }
    return 0;
}

void addToProfile(char courseName[], char grade){
    if (findCourseIndex(courseName) == -1){
        printf("Course '%s' not found in system.\n", courseName);
        return;
    }

    for (int i = 0; i < profileCount; i++){
        if (strcmp(profile[i].course, courseName) == 0){
            profile[i].grade = grade;
            printf("Updated %s with grade %c in your profile.\n", courseName, grade);
            return;
        }
    }
    strcpy(profile[profileCount].course, courseName);
    profile[profileCount].grade = grade;
    profileCount++;
    printf("Added %s (Grade: %c) to your profile.\n", courseName, grade);
}

void displayProfile(){
    printf("\n--- Your Profile ---\n");
    if (profileCount == 0){
        printf("No courses added yet.\n");
        return;
    }
    for (int i = 0; i < profileCount; i++){
        printf("- %s: %c\n", profile[i].course, profile[i].grade);
    }
    printf("--------------------\n");
}

void findPrerequisites(int index, int visited[]){
    visited[index] = 1;
    Node* temp = courses[index].prereqList;
    while (temp != NULL){
        int idx = findCourseIndex(temp->course);
        if (!visited[idx]){
            int met = checkProfileMet(temp->course, temp->minGrade);
            if (met)
                printf("- %s (MIN GRADE: %c) %s\n", temp->course, temp->minGrade, "✅");
            else
                printf("- %s (MIN GRADE: %c) %s\n", temp->course, temp->minGrade, "❌");
            findPrerequisites(idx, visited);
        }
        temp = temp->next;
    }
}

void displayCourses() {
    printf("\nAvailable Courses:\n");
    for (int i = 0; i < courseCount; i++){
        printf("- %s\n", courses[i].course);
    }
}

void loadSampleData(){
    //term1
    addCourse("MTH10101");
    addCourse("MTH10102");
    addCourse("CPE100");
    addCourse("CPE101");
    addCourse("CPE111");
    addCourse("CPE123");
    addCourse("LNG221");

    //term 2
    addCourse("CPE112");
    addCourse("CPE121");
    addCourse("GEN121");
    addCourse("LNG222");
    addCourse("MTH10201");
    addCourse("MTH10202");
    addCourse("MTH10203");
    addCourse("PHY10301");
    addCourse("PHY10302");
    addCourse("PHY10303");
    
    //term1
    addPrereq("MTH10102", "MTH10101", 'D');


    //term2
    addPrereq("MTH10201", "MTH10102", 'D');
    addPrereq("CPE112", "CPE100", 'C');
    addPrereq("LNG222", "LNG221", 'D');
    addPrereq("MTH10202", "MTH10201", 'D');
    addPrereq("MTH10203", "MTH10202", 'D');
    addPrereq("PHY10302", "PHY10301", 'D');
    addPrereq("PHY10303", "PHY10302", 'D');
}

void profileMenu(){
    int running = 1;
    while (running){
        printf("\n--- Profile Menu ---\n");
        printf("1. View profile\n");
        printf("2. Add/Update a course grade\n");
        printf("3. Back\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displayProfile();
                break;
            case 2: {
                char courseName[50];
                char gradeStr[5];
                displayCourses();
                printf("Enter course name: ");
                scanf("%s", courseName);
                printf("Enter grade (A/B/C/D/F): ");
                scanf("%s", gradeStr);
                char grade = gradeStr[0];
                if (grade!='A' && grade!='B' && grade!='C' && grade!='D' && grade!='F'){
                    printf("Invalid grade. Use A, B, C, D, or F.\n");
                } else {
                    addToProfile(courseName, grade);
                }
                break;
            }
            case 3:
                running = 0;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main(){
    char input[50];
    loadSampleData();
    printf("\n==============");
    while (1){
        printf("\n\n[MAIN MENU]\n");
        printf("1. Check prerequisites\n");
        printf("2. Manage profile\n");
        printf("3. Exit\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 3) break;

        if (choice == 2){
            profileMenu();
            continue;
        }

        if (choice == 1){
            displayCourses();
            printf("\nEnter course to check: ");
            scanf("%s", input);

            int index = findCourseIndex(input);
            if (index == -1){
                printf("Course not found!\n");
                continue;
            }

            int visited[MAX] = {0};
            printf("\nPrerequisites for %s:\n", input);
            if (courses[index].prereqList == NULL){
                printf("No prerequisites\n");
            } else {
                findPrerequisites(index, visited);
            }
            printf("===============================\n");
        }
    }
    return 0;
}

/*
term 1
CPE100 = COMPUTER PROGRAMMING FOR ENGINEERS
CPE101 = ENGINEERING EXPLORATION
CPE111 = DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
CPE123 = USER EXPERIENCE/USER INTERFACE
LNG221 = ACADEMIC ENGLISH IN INTERNATIONAL CONTEXTS
MTH10101 = LIMIT, CONTINUITY AND DERIVATIVES
MTH10102 = INTEGRALS

term 2
CPE112 = PROGRAMMING WITH DATA STRUCTURES
CPE121 = BASIC CIRCUITS AND ELECTRONICS
GEN121 = LEARNING AND PROBLEM SOLVING SKILLS
LNG222 = ACADEMIC LISTENING AND SPEAKING IN INTERNATIONAL CONTEXTS
MTH10201 = MATHEMATICAL INDUCTION, SEQUENCES AND SERIES
MTH10202 = VECTORS, LINES AND PLANES IN A 3D-SPACE AND VECTOR FUNCTIONS
MTH10203 = MULTIPLE INTEGRALS
PHY10301 = FORCE AND MOTION
PHY10302 = OSCILLATIONS AND WAVES
PHY10303 = THERMAL PHYSICS
*/

/*
cpe112 >= c
cpe100 >= c
PHY10301 > f
PHY10301 > f
PHY10301 > f
*/

