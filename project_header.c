#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

// Function to create a new patient node
Patient *createPatient(char name[], int priority, char category[], char gender[], int age)
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    strcpy(newPatient->category, category);
    strcpy(newPatient->gender, gender);
    newPatient->priority = priority;
    newPatient->age = age;
    newPatient->next = NULL;
    return newPatient;
}

// Function to insert a patient into the priority queue
void enqueue(Patient **head,char name[], int priority, char category[], char gender[], int age)
{
    Patient *newPatient = createPatient(name, priority, category, gender, age);

    // If the queue is empty or the new patient has higher priority, make it the new head
    if (*head == NULL || priority < (*head)->priority)
    {
        newPatient->next = *head;
        *head = newPatient;
    }
    else
    {
        Patient *temp = *head;

        // Find the appropriate position to insert the new patient
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        // Insert the new patient
        newPatient->next = temp->next;
        temp->next = newPatient;
    }
}

// Function to remove and return the patient with the highest priority
Patient *dequeue(Patient **head)
{
    if (*head == NULL)
    {
        printf("Priority queue is empty.\n");
        return NULL;
    }

    Patient *dequeuedPatient = *head;
    *head = (*head)->next;
    dequeuedPatient->next = NULL;
    return dequeuedPatient;
}

// Function to display the patients in the priority queue
void displayQueue(Patient *head)
{
    if (head == NULL)
    {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Patients in the priority queue:\n");
    printf("Name\tGender\tAge\tCategory\n");
    printf("\n");
    while (head != NULL)
    {
        printf("%s\t%s\t%d\t%s\n", head->name, head->gender, head->age, head->category);
        head = head->next;
    }
    printf("\n");
}



// Function to swap two doctors
void swap(struct Doctor* a, struct Doctor* b) {
    struct Doctor temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform max heapify operation on a department
void maxHeapify(struct Department* department, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < department->size && department->doctors[left].experience > department->doctors[largest].experience)
        largest = left;

    if (right < department->size && department->doctors[right].experience > department->doctors[largest].experience)
        largest = right;

    if (largest != i) {
        swap(&department->doctors[i], &department->doctors[largest]);
        maxHeapify(department, largest);
    }
}

// Function to build a max heap for a department
void buildMaxHeap(struct Department* department) {
    int n = department->size;
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(department, i);
}

// Function to insert a doctor into a department heap
void insertDoctor(struct Department* department, struct Doctor newDoctor) {
    if (department->size == 10) {
        printf("Department %s is full. Cannot insert more doctors.\n", department->name);
        return;
    }

    department->doctors[department->size++] = newDoctor;

    // Perform heapify operation to maintain the heap property
    for (int i = department->size / 2 - 1; i >= 0; i--)
        maxHeapify(department, i);
}

// Function to delete the doctor with the highest experience level from a department heap
struct Doctor deleteDoctor(struct Department* department) {
    if (department->size == 0) {
        printf("Department %s is empty. Cannot delete any doctors.\n", department->name);
        struct Doctor emptyDoctor = {"", 0};
        return emptyDoctor;
    }

    struct Doctor deletedDoctor = department->doctors[0];
    department->doctors[0] = department->doctors[--department->size];
    maxHeapify(department, 0);

    return deletedDoctor;
}

// Function to display the doctors in a department
void displayDepartment(struct Department* department) {
    printf("Doctors in Department %s:\n", department->name);
    for (int i = 0; i < department->size; i++) {
        printf("Name: %s, Experience: %d\n", department->doctors[i].name, department->doctors[i].experience);
    }
}