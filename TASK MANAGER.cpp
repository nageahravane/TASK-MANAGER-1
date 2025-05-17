#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task {
    int id;
    string title;
    string description;
};

Task tasks[MAX_TASKS];
int taskCount = 0;

// Create
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!" << endl;
        return;
    }
    Task newTask;
    newTask.id = taskCount + 1;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, newTask.title);
    cout << "Enter description: ";
    getline(cin, newTask.description);

    tasks[taskCount] = newTask;
    taskCount++;
    cout << "Task added successfully!" << endl;
}

// Read
void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks found." << endl;
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        cout << "\nTask ID: " << tasks[i].id
             << "\nTitle: " << tasks[i].title
             << "\nDescription: " << tasks[i].description << endl;
    }
}

// Update
void updateTask() {
    int id;
    cout << "Enter task ID to update: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, tasks[i].title);
            cout << "Enter new description: ";
            getline(cin, tasks[i].description);
            found = true;
            cout << "Task updated successfully!" << endl;
            break;
        }
    }

    if (!found)
        cout << "Task not found." << endl;
}

// Delete
void deleteTask() {
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            // Shift remaining tasks
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
                tasks[j].id = j + 1;  // Reassign IDs
            }
            taskCount--;
            found = true;
            cout << "Task deleted successfully!" << endl;
            break;
        }
    }

    if (!found)
        cout << "Task not found." << endl;
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n--- Task Manager ---" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Update Task\n4. Delete Task\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: updateTask(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
