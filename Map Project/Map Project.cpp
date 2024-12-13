#include <iostream>
#include <fstream>
#include "schedule.h"
using namespace std;

int main() {
    schedule mySchedule;
    
    ifstream file("STEM - Summer 2022 Schedule of Classes as of 05-02-22.csv");

    mySchedule.initSchedule(file);
    file.close();

    int choice;


    do {

        cout << "Schedule Selection screen\n";
        cout << "1) Print the schedule\n";
        cout << "2) Find by subject\n";
        cout << "3) Find by subject and catalog\n";
        cout << "4) Find by instructor\n";
        cout << "5) Exit\n";


        cout << "Enter your choice: ";
        cin >> choice;


        if (choice == 1) {
            mySchedule.print(); 
        }
        else if (choice == 2) {
            string subject;
            cout << "Enter subject: ";
            cin >> subject;
            mySchedule.findBySubject(subject);
        }
        else if (choice == 3) {
            string subject, catalog;
            cout << "Enter subject: ";
            cin >> subject;
            cout << "Enter catalog number: ";
            cin >> catalog;
            mySchedule.findBySubjectAndCatalog(subject, catalog);
        }
        else if (choice == 4) {
            string lastName;
            cout << "Enter instructor's last name: ";
            cin >> lastName;
            mySchedule.findByInstructor(lastName);
        }

    } while (choice != 5);

    return 0;
}
