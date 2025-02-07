#include "include/ThreeSistersDictionary.h"

int main() {
    ThreeSistersDictionary dict;

    dict.insert(1, "A large mammal found in Africa", "Elephant");
    dict.insert(2, "A small insect known for honey", "Bee");

    cout << "\n🔎 Searching for ID 1:\n";
    dict.searchById(1);

    cout << "\n🔎 Searching for keyword 'honey':\n";
    dict.searchByKeyword("honey");

    cout << "\n📌 Sorting by description:\n";
    dict.sortByDescription();
    cout << "Sorted by Description.\n";

    cout << "\n📜 Displaying all:\n";
    dict.displayAll();

    return 0;
}
