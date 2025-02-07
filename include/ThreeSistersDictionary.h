#ifndef THREESISTERDICTIONARY_H
#define THREESISTERDICTIONARY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Entry {
    int id;
    string description;
    string brief;
};

class ThreeSistersDictionary {
private:
    vector<Entry> entries;
    void saveToFile();
    void loadFromFile();

public:
    ThreeSistersDictionary(); // Constructor
    void insert(int id, string description, string brief);
    void searchById(int id);
    void searchByKeyword(string keyword);
    void update(int id, string newDescription, string newBrief);
    void remove(int id);
    void sortById();
    void sortByDescription();
    void displayAll();
};

#endif
