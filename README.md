# Three Sisters Dictionary (C++ Data Structure)

## **Overview**
The **Three Sisters Dictionary** is a custom **data structure** implemented in **C++** that stores entries in the form of `{ID : Description : Brief}`. It allows **fast insertion, searching, deletion, and sorting** while maintaining **low memory usage and high efficiency**.

This implementation includes:
- ✅ **Insertion, Deletion, Update, and Search operations**
- ✅ **Sorting by ID (Ascending) and Description (Alphabetically)**
- ✅ **Case-insensitive search for keyword-based lookups**
- ✅ **Persistent storage (saving & loading from a file)**
- ✅ **Custom memory-efficient linked list structure**

---

## **Getting Started**
### **1️⃣ Compile & Run**
```sh
g++ three_sisters_dictionary.cpp -o dictionary
./dictionary

2️⃣ Example Operations
The following examples demonstrate how to use all operations:

🔹 Insert Entries
dict.insert(1, "A large mammal found in Africa", "Elephant");
dict.insert(2, "A small insect known for honey", "Bee");
dict.insert(3, "A bird that cannot fly", "Penguin");

🔹 Search by ID
dict.searchById(1);  // Output: ID: 1 | Description: A large mammal found in Africa | Brief: Elephant

🔹 Case-Insensitive Keyword Search
dict.searchByKeyword("honey"); // Output: Found in ID 2: Description = A small insect known for honey | Brief = Bee

🔹 Update an Entry
dict.update(2, "A flying insect that makes honey", "Bee");

🔹 Delete an Entry
dict.remove(3); // Removes "Penguin"

🔹 Sorting
dict.sortById();         // Sorts by ID in ascending order
dict.sortByDescription(); // Sorts alphabetically by Description

🔹 Display All Entries
dict.displayAll();
🔹 Persistent Storage

All data is automatically saved in dictionary.txt when inserted, updated, or deleted.
When the program restarts, it automatically loads existing data.

Code Structure
📌 Core Functions
Function	Description
insert(int id, string description, string brief)	Adds a new entry to the dictionary.
searchById(int id)	Finds an entry by ID and displays its details.
searchByKeyword(string keyword)	Finds all entries where the keyword appears (case-insensitive).
update(int id, string newDescription, string newBrief)	Updates an existing entry.
remove(int id)	Deletes an entry by ID.
sortById()	Sorts all entries in ascending order based on ID.
sortByDescription()	Sorts all entries alphabetically by Description.
displayAll()	Displays all dictionary entries.
saveToFile()	Saves the dictionary to a file (dictionary.txt).
loadFromFile()	Loads dictionary data from the file when the program starts.

💡 Features
Optimized Custom Data Structure (No STL dependency)
Memory-Efficient Linked List Implementation
Sorting & Searching for Faster Retrieval
Persistent Storage for Data Safety
Case-Insensitive Search for Ease of Use
Contributing
Feel free to contribute by improving efficiency, adding features, or enhancing sorting algorithms.
Simply fork the repository and submit a pull request!

License
This project is open-source and available for personal and educational use.

🚀 Happy Coding!


This README provides **clear instructions, function descriptions, and example usages** for everyone.

📥 Step 3: How Users Can Use Your Library
Users will follow these steps to integrate it into their projects.

1️⃣ Download the Library
Users can download the library file:


wget https://github.com//shivam7053/Three_Sisters_Dictionary/raw/main/lib/libThreeSistersDictionary.a

Or they can clone your repository:


git clone https:///shivam7053/Three_Sisters_Dictionary.git
2️⃣ Include the Header in Their Code
Users should include your library's header file in their main.cpp:


#include "Three_Sisters_Dictionary/include/ThreeSistersDictionary.h"

int main() {
    ThreeSistersDictionary dict;
    
    dict.insert(1, "A large mammal found in Africa", "Elephant");
    dict.searchById(1);
    
    return 0;
}
3️⃣ Compile Their Project with the Library
Users should link the static library during compilation:

g++ main.cpp -IThree_Sisters_Dictionary/include -LThree_Sisters_Dictionary/lib -lThreeSistersDictionary -o my_project
If libThreeSistersDictionary.a is in the current directory:


g++ main.cpp -IThree_Sisters_Dictionary/include -L. -lThreeSistersDictionary -o my_project
4️⃣ Run the Program

./my_project