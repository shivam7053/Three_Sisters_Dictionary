#include "../include/ThreeSistersDictionary.h"

ThreeSistersDictionary::ThreeSistersDictionary() {
    loadFromFile();
}

void ThreeSistersDictionary::insert(int id, string description, string brief) {
    entries.push_back({id, description, brief});
    saveToFile();
}

void ThreeSistersDictionary::searchById(int id) {
    for (const auto& entry : entries) {
        if (entry.id == id) {
            cout << "ID: " << entry.id << "\nDescription: " << entry.description << "\nBrief: " << entry.brief << endl;
            return;
        }
    }
    cout << "Entry with ID " << id << " not found.\n";
}

void ThreeSistersDictionary::searchByKeyword(string keyword) {
    for (const auto& entry : entries) {
        if (entry.description.find(keyword) != string::npos) {
            cout << "Found in ID " << entry.id << ": Description = " << entry.description << ", Brief = " << entry.brief << endl;
        }
    }
}

void ThreeSistersDictionary::update(int id, string newDescription, string newBrief) {
    for (auto& entry : entries) {
        if (entry.id == id) {
            entry.description = newDescription;
            entry.brief = newBrief;
            saveToFile();
            return;
        }
    }
    cout << "Entry with ID " << id << " not found.\n";
}

void ThreeSistersDictionary::remove(int id) {
    entries.erase(remove_if(entries.begin(), entries.end(),
               [id](const Entry& entry) { return entry.id == id; }),
               entries.end());
    saveToFile();
}

void ThreeSistersDictionary::sortById() {
    sort(entries.begin(), entries.end(), [](const Entry& a, const Entry& b) { return a.id < b.id; });
}

void ThreeSistersDictionary::sortByDescription() {
    sort(entries.begin(), entries.end(), [](const Entry& a, const Entry& b) { return a.description < b.description; });
}

void ThreeSistersDictionary::displayAll() {
    for (const auto& entry : entries) {
        cout << "ID: " << entry.id << " | Description: " << entry.description << " | Brief: " << entry.brief << endl;
    }
}

void ThreeSistersDictionary::saveToFile() {
    ofstream file("dictionary.txt");
    for (const auto& entry : entries) {
        file << entry.id << "|" << entry.description << "|" << entry.brief << "\n";
    }
}

void ThreeSistersDictionary::loadFromFile() {
    ifstream file("dictionary.txt");
    int id;
    string description, brief;
    while (file >> id) {
        file.ignore();
        getline(file, description, '|');
        getline(file, brief);
        entries.push_back({id, description, brief});
    }
}
