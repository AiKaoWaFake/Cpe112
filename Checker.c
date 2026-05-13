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

int findCourseIndex(char name[]){
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].course, name) == 0) 
            return i;
    }
    return -1;
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
