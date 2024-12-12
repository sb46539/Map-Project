#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class scheduleItem {
private:

    string subject;
    string catalog;
    string section;
    string component;
    string session;
    int units;
    int totEnrl;
    int capEnrl;
    string instructor;

public:

    scheduleItem(string subj = "", string cat = "", string sec = "", string comp = "",
        string sess = "", int u = 0, int tot = 0, int cap = 0, string instr = "")
        : subject(subj), catalog(cat), section(sec), component(comp),
        session(sess), units(u), totEnrl(tot), capEnrl(cap), instructor(instr) {}


    string getSubject() const { return subject; }
    string getCatalog() const { return catalog; }
    string getSection() const { return section; }
    string getComponent() const { return component; }
    string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotEnrl() const { return totEnrl; }
    int getCapEnrl() const { return capEnrl; }
    string getInstructor() const { return instructor; }


    bool operator==(const scheduleItem& other) const {
        return (subject + "_" + catalog + "_" + section) ==
            (other.subject + "_" + other.catalog + "_" + other.section);
    }
    bool operator!=(const scheduleItem& other) const { return !(*this == other); }
    bool operator>=(const scheduleItem& other) const {
        return (subject + "_" + catalog + "_" + section) >=
            (other.subject + "_" + other.catalog + "_" + other.section);
    }


    void print() const {

        cout << setw(10) << subject << setw(10) << catalog << setw(10) << section
            << setw(10) << component << setw(10) << session << setw(6) << units
            << setw(10) << totEnrl << setw(10) << capEnrl << setw(20) << instructor << endl;
    }
};
