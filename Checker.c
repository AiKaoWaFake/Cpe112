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

void findPrerequisites(int index, int visited[]){
    visited[index] = 1;
    Node* temp = courses[index].prereqList;
    while (temp != NULL){
        int idx = findCourseIndex(temp->course);
        if (!visited[idx]){
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
    addCourse("Math101");
    addCourse("Programming");
    addCourse("DataStructures");
    addCourse("Algorithms");

    addPrereq("Programming", "Math101", 'C');
    addPrereq("DataStructures", "Programming", 'B');
    addPrereq("Algorithms", "DataStructures", 'C');
}

int main(){
    present choices
    input choice
    program run
    you are eligible!!! 
}

/*
module 1
CPE100 = COMPUTER PROGRAMMING FOR ENGINEERS
CPE101 = ENGINEERING EXPLORATION
CPE111 = DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
CPE123 = USER EXPERIENCE/USER INTERFACE
LNG221 = ACADEMIC ENGLISH IN INTERNATIONAL CONTEXTS
MTH10101 = LIMIT, CONTINUITY AND DERIVATIVES
MTH10102 = INTEGRALS

module 2
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
