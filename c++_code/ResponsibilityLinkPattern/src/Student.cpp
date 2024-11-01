#include "Student.h"
void Student::Request(taskType task, AbstructManager *manager)
{
    manager->handleTask(task);
}