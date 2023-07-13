#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient
{
    char name[100];
    int priority;
    char category[100];
    char gender[100];
    int age;
    struct patient *next;
}Patient;


struct Doctor {
    char name[50];
    int experience;
};


struct Department {
    char name[50];
    struct Doctor doctors[10];
    int size;
};

Patient *createPatient(char name[], int priority, char category[], char gender[], int age);
void enqueue(Patient **head,char name[], int priority, char category[], char gender[], int age);
Patient *dequeue(Patient **head);
void displayQueue(Patient *head);


void swap(struct Doctor* a, struct Doctor* b);
void maxHeapify(struct Department* department, int i);
void buildMaxHeap(struct Department* department);
void insertDoctor(struct Department* department, struct Doctor newDoctor);
struct Doctor deleteDoctor(struct Department* department);
void displayDepartment(struct Department* department);

