#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

// Node structure for Three Sisters Dictionary
struct Node {
    int id;
    string description;
    string brief;
    Node* next;

    Node(int id, string desc, string brf) {
        this->id = id;
        this->description = desc;
        this->brief = brf;
        this->next = nullptr;
    }
};

// Convert string to lowercase for case-insensitive search
string toLowerCase(const string& str) {
    string result = str;
    for (char& c : result) c = tolower(c);
    return result;
}

// Custom Three Sisters Dictionary
class ThreeSistersDictionary {
private:
    Node* head; // Pointer to the first node
    string filename = "dictionary.txt"; // File to store dictionary data

public:
    // Constructor (loads from file)
    ThreeSistersDictionary() {
        head = nullptr;
        loadFromFile();
    }

    // Insert a new entry
    void insert(int id, string description, string brief) {
        // Check if ID already exists
        if (searchById(id, false)) {
            cout << "Error: ID " << id << " already exists!\n";
            return;
        }
        // Create a new node and insert at the head
        Node* newNode = new Node(id, description, brief);
        newNode->next = head;
        head = newNode;
        cout << "Inserted ID: " << id << "\n";
        saveToFile();
    }

    // Search by ID (helper function allows silent search)
    bool searchById(int id, bool display = true) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (display) {
                    cout << "ID: " << temp->id << "\nDescription: " << temp->description << "\nBrief: " << temp->brief << "\n";
                }
                return true;
            }
            temp = temp->next;
        }
        if (display) cout << "ID not found!\n";
        return false;
    }

    // Search by keyword (case-insensitive)
    void searchByKeyword(const string& keyword) {
        Node* temp = head;
        bool found = false;
        string lowerKeyword = toLowerCase(keyword);
        
        while (temp) {
            if (toLowerCase(temp->description).find(lowerKeyword) != string::npos || 
                toLowerCase(temp->brief).find(lowerKeyword) != string::npos) {
                cout << "Found in ID " << temp->id << ": Description = " << temp->description << ", Brief = " << temp->brief << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No matching entries found!\n";
    }

    // Delete an entry by ID
    void remove(int id) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->id == id) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                cout << "Deleted ID: " << id << "\n";
                saveToFile();
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "ID not found!\n";
    }

    // Update an entry
    void update(int id, string newDescription, string newBrief) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->description = newDescription;
                temp->brief = newBrief;
                cout << "Updated ID: " << id << "\n";
                saveToFile();
                return;
            }
            temp = temp->next;
        }
        cout << "ID not found!\n";
    }

    // Sort dictionary by ID (ascending)
    void sortById() {
        if (!head || !head->next) return;
        
        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            Node* prev = nullptr;
            
            while (curr && curr->next) {
                if (curr->id > curr->next->id) {
                    swap(curr->id, curr->next->id);
                    swap(curr->description, curr->next->description);
                    swap(curr->brief, curr->next->brief);
                    swapped = true;
                }
                prev = curr;
                curr = curr->next;
            }
        } while (swapped);
        cout << "Sorted by ID.\n";
    }

    // Sort dictionary alphabetically by description
    void sortByDescription() {
        if (!head || !head->next) return;
        
        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            Node* prev = nullptr;
            
            while (curr && curr->next) {
                if (curr->description > curr->next->description) {
                    swap(curr->id, curr->next->id);
                    swap(curr->description, curr->next->description);
                    swap(curr->brief, curr->next->brief);
                    swapped = true;
                }
                prev = curr;
                curr = curr->next;
            }
        } while (swapped);
        cout << "Sorted by Description.\n";
    }

    // Display all entries
    void displayAll() {
        if (!head) {
            cout << "No entries available.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << " | Description: " << temp->description << " | Brief: " << temp->brief << "\n";
            temp = temp->next;
        }
    }

    // Save dictionary to file
    void saveToFile() {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing!\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            file << temp->id << "\n" << temp->description << "\n" << temp->brief << "\n";
            temp = temp->next;
        }
        file.close();
    }

    // Load dictionary from file
    void loadFromFile() {
        ifstream file(filename);
        if (!file) return; // No file exists yet

        int id;
        string desc, brief;
        while (file >> id) {
            file.ignore();
            getline(file, desc);
            getline(file, brief);
            insert(id, desc, brief);
        }
        file.close();
    }

    // Destructor to free memory
    ~ThreeSistersDictionary() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function for testing
int main() {
    ThreeSistersDictionary dict;

    // Sample operations
    dict.insert(1, "A large mammal found in Africa", "Elephant");
    dict.insert(2, "A small insect known for honey", "Bee");

    cout << "\nSearching for ID 1:\n";
    dict.searchById(1);

    cout << "\nSearching for keyword 'honey':\n";
    dict.searchByKeyword("honey");

    cout << "\nSorting by description:\n";
    dict.sortByDescription();

    cout << "\nDisplaying all:\n";
    dict.displayAll();

    cout << "\nDelete id:1 \n";
    dict.remove(1);

    cout << "\nDisplaying all:\n";
    dict.displayAll();


    return 0;
}
