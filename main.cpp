#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int id;
    char name[50];
    char grade[5];
};

void addStudent() {
    ofstream outFile("tar.data", ios::binary | ios::app);
    if (!outFile) {
        cout << "Error opening file!\n";
        return;
    }
    
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Student Name: ";
    cin.getline(s.name, 50);
    cout << "Enter Student Grade: ";
    cin.getline(s.grade, 5);
    
    outFile.write(reinterpret_cast<const char*>(&s), sizeof(s));
    outFile.close();
    cout << "Student added successfully!\n";
}
void viewStudent() {
    ifstream inFile("tar.data", ios::binary);
    if (!inFile) {
        cout << "Error opening file!\n";
        return;
    }
    Student s;
    cout << "ID\tName\tGrade\n";
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        cout << s.id << "\t" << s.name << "\t" << s.grade << "\n";
    }
    inFile.close();
}
void searchStudent() {
    ifstream inFile("tar.data", ios::binary);
    if (!inFile) {
        cout << "Error opening file!\n";
        return;
    }
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;
    Student s;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.id == searchId) {
            cout << "Student found!\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Grade: " << s.grade << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!\n";
    }
    inFile.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    while (choice != 4);
    return 0;
}