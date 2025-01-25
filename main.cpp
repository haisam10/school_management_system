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