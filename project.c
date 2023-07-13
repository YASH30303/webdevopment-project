#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

int main()
{
    Patient *queue = NULL;

    // Enqueueing patients with their priority
    enqueue(&queue, "John", 2, "ortho", "Male", 18);
    enqueue(&queue, "Alice", 3, "ortho", "Male", 18);
    enqueue(&queue, "Bob", 1, "ortho", "Male", 18);

    // Displaying the priority queue
    displayQueue(queue);

    // Dequeueing the patients
    Patient *dequeuedPatient = dequeue(&queue);
    if (dequeuedPatient != NULL)
    {
        printf("priority patient: %s\n\n", dequeuedPatient->name);
        free(dequeuedPatient);
    }

    // Displaying the updated priority queue
    displayQueue(queue);

        struct Department departments[7];

    // Initialize the departments
    strcpy(departments[0].name, "Orthopedic");
    departments[0].size = 0;

    strcpy(departments[1].name, "General Medicine");
    departments[1].size = 0;

    strcpy(departments[2].name, "General Surgery");
    departments[2].size = 0;

    strcpy(departments[3].name, "Radiology");
    departments[3].size = 0;

    strcpy(departments[4].name, "Nephrology");
    departments[4].size = 0;

    strcpy(departments[5].name, "Cardiology");
    departments[5].size = 0;

    strcpy(departments[6].name, "Urology");
    departments[6].size = 0;

    // Insert doctors into the departments
    insertDoctor(&departments[0], (struct Doctor){"Doctor 1", 5});
    insertDoctor(&departments[0], (struct Doctor){"Doctor 2", 3});
    // ...

    insertDoctor(&departments[1], (struct Doctor){"Doctor 1", 10});
    insertDoctor(&departments[1], (struct Doctor){"Doctor 2", 7});
    
    insertDoctor(&departments[2], (struct Doctor){"Doctor 1", 15});
    insertDoctor(&departments[2], (struct Doctor){"Doctor 2", 9});

    insertDoctor(&departments[3], (struct Doctor){"Doctor 1", 4});
    insertDoctor(&departments[3], (struct Doctor){"Doctor 2", 3});
    
    insertDoctor(&departments[4], (struct Doctor){"Doctor 1", 5});
    insertDoctor(&departments[4], (struct Doctor){"Doctor 2", 3});
    
    insertDoctor(&departments[5], (struct Doctor){"Doctor 1", 5});
    insertDoctor(&departments[5], (struct Doctor){"Doctor 2", 3});
    
    insertDoctor(&departments[6], (struct Doctor){"Doctor 1", 5});
    insertDoctor(&departments[6], (struct Doctor){"Doctor 2", 3});
    // ...

    // Display the doctors in each department
    for (int i = 0; i < 7; i++) {
        displayDepartment(&departments[i]);
        printf("\n");
    }

    int departmentIndex;
    printf("Enter the department index (0-6) to delete a doctor: ");
    scanf("%d", &departmentIndex);

    if (departmentIndex < 0 || departmentIndex >= 7) {
        printf("Invalid department index.\n");
        return 0;
    }

    // Delete a doctor from the chosen department
    struct Doctor deletedDoctor = deleteDoctor(&departments[departmentIndex]);

    if (deletedDoctor.experience == 0) {
        printf("No doctors were deleted from Department %s.\n", departments[departmentIndex].name);
    } else {
        printf("Deleted Doctor - Name: %s, Department: %s, Experience: %d\n",
               deletedDoctor.name, departments[departmentIndex].name, deletedDoctor.experience);
    }

    // Display the remaining doctors in the department
    printf("\nRemaining doctors in Department %s:\n", departments[departmentIndex].name);
    displayDepartment(&departments[departmentIndex]);
    return 0;
}
