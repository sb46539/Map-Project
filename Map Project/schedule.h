#pragma once

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "scheduleItem.h"
using namespace std;

class schedule {
private:
    map<string, scheduleItem> scheduleMap;

public:

    void initSchedule(ifstream& file) {
        string line, subject, catalog, section, component, session, instructor;
        int units, totEnrl, capEnrl;


        std::getline(file, line);

        while (std::getline(file, line)) {
            stringstream ss(line);
            std::getline(ss, subject, ',');
            std::getline(ss, catalog, ',');
            std::getline(ss, section, ',');
            std::getline(ss, component, ',');
            std::getline(ss, session, ',');
            ss >> units;
            ss.ignore();
            ss >> totEnrl;
            ss.ignore();
            ss >> capEnrl;
            ss.ignore();
            std::getline(ss, instructor);

            string key = subject + "_" + catalog + "_" + section;
            scheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
            scheduleMap[key] = item;
        }
    }

    void addEntry(const scheduleItem& item) {
        string key = item.getSubject() + "_" + item.getCatalog() + "_" + item.getSection();
        scheduleMap[key] = item;
    }

    void print() const {
        cout << setw(10) << "Subject" << setw(10) << "Catalog" << setw(10) << "Section"
            << setw(10) << "Component" << setw(10) << "Session" << setw(10) << "Units"
            << setw(10) << "TotEnrl" << setw(10) << "CapEnrl" << setw(20) << "Instructor" << endl;

        for (const auto& pair : scheduleMap) {
            pair.second.print();
        }
    }

    void findBySubject(const string& subject) const {
        for (const auto& pair : scheduleMap) {
            if (pair.second.getSubject() == subject) {
                pair.second.print();
            }
        }
    }

    void findBySubjectAndCatalog(const string& subject, const string& catalog) const {
        for (const auto& pair : scheduleMap) {
            if (pair.second.getSubject() == subject && pair.second.getCatalog() == catalog) {
                pair.second.print();
            }
        }
    }

    void findByInstructor(const string& lastName) const {
        for (const auto& pair : scheduleMap) {
            if (pair.second.getInstructor().find(lastName) != string::npos) {
                pair.second.print();
            }
        }
    }
};

