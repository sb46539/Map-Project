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

        cout << "Subject   | Catalog  | Section  | Component | Session | Units | TotEnrl | CapEnrl | Instructor\n";


        for (const auto& pair : scheduleMap) {
            const scheduleItem& item = pair.second;

            cout << item.getSubject() << "   | "
                << item.getCatalog() << "       | "
                << item.getSection() << "       | "
                << item.getComponent() << "      | "
                << item.getSession() << "  | "
                << item.getUnits() << "    | "
                << item.getTotEnrl() << "       | "
                << item.getCapEnrl() << "      | "
                << item.getInstructor() << endl;
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
