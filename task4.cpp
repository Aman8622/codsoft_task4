#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << (i + 1) << "] ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int index) {
    if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;
    string userInput;

    cout << "Simple To-Do List Manager" << endl;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> userInput;

        if (userInput == "1") {
            string description;
            cout << "Enter task description: ";
            cin.ignore(); // Clear the input buffer
            getline(std::cin, description);
            addTask(tasks, description);
        } else if (userInput == "2") {
            viewTasks(tasks);
        } else if (userInput == "3") {
            int index;
            cout << "Enter the task number to mark as completed: ";
            cin >> index;
            markTaskCompleted(tasks, index);
        } else if (userInput == "4") {
            int index;
            cout << "Enter the task number to remove: ";
            cin >> index;
            removeTask(tasks, index);
        } else if (userInput == "5") {
            break; // Exit the program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}
