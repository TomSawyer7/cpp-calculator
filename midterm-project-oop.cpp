#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Item {
public:
    int id;
    string name;
    int quantity;
    float price;
};

vector<Item> inventory;

void addItem() {
    Item item;
    cout << "Enter Item ID: ";
    cin >> item.id;
    cin.ignore();
    cout << "Enter Item Name: ";
    getline(cin, item.name);
    cout << "Enter Quantity: ";
    cin >> item.quantity;
    cout << "Enter Price: ";
    cin >> item.price;

    inventory.push_back(item);
    cout << "Item added successfully." << endl;
}

void updateItem() {
    int id;
    cout << "Enter Item ID to update: ";
    cin >> id;

    for (auto& item : inventory) {
        if (item.id == id) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, item.name);
            cout << "Enter New Quantity: ";
            cin >> item.quantity;
            cout << "Enter New Price: ";
            cin >> item.price;
            cout << "Item updated successfully." << endl;
            return;
        }
    }
    cout << "Item not found." << endl;
}

void removeItem() {
    int id;
    cout << "Enter Item ID to remove: ";
    cin >> id;

    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].id == id) {
            inventory.erase(inventory.begin() + i);
            cout << "Item removed successfully." << endl;
            return;
        }
    }
    cout << "Item not found." << endl;
}

void displayAllItems() {
    if (inventory.empty()) {
        cout << "No items in inventory." << endl;
        return;
    }

    cout << "--- Inventory Items ---" << endl;
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Qty"
         << setw(10) << "Price" << endl;

    for (const auto& item : inventory) {
        cout << left << setw(10) << item.id;
        cout << setw(20) << item.name;
        cout << setw(10) << item.quantity;
        cout << fixed << setprecision(2) << item.price << endl;
    }
}

void searchItem() {
    int id;
    cout << "Enter Item ID to search: ";
    cin >> id;

    for (const auto& item : inventory) {
        if (item.id == id) {
            cout << "--- Item Found ---" << endl;
            cout << left << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(10) << "Qty"
                 << setw(10) << "Price" << endl;
            cout << left << setw(10) << item.id;
            cout << setw(20) << item.name;
            cout << setw(10) << item.quantity;
            cout << fixed << setprecision(2) << item.price << endl;
            return;
        }
    }
    cout << "Item not found." << endl;
}

void sortItems() {
    if (inventory.empty()) {
        cout << "No items to sort." << endl;
        return;
    }
    
    int sortChoice;
    cout << "Sort by:" << endl;
    cout << "1. Quantity" << endl;
    cout << "2. Price" << endl;
    cout << "3. Name (default)" << endl;
    cout << "Enter your choice: ";
    cin >> sortChoice;
    
    int orderChoice;
    cout << "Order:" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "Enter your choice: ";
    cin >> orderChoice;
    
    bool ascending = (orderChoice != 2); 
    
    switch (sortChoice) {
        case 1: 
            if (ascending) {
                sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
                    return a.quantity < b.quantity;
                });
                cout << "Items sorted by quantity (ascending)." << endl;
            } else {
                sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
                    return a.quantity > b.quantity;
                });
                cout << "Items sorted by quantity (descending)." << endl;
            }
            break;
            
        case 2: 
            if (ascending) {
                sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
                    return a.price < b.price;
                });
                cout << "Items sorted by price (ascending)." << endl;
            } else {
                sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
                    return a.price > b.price;
                });
                cout << "Items sorted by price (descending)." << endl;
            }
            break;
            
        default: 
            if (ascending) {
                sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
                    return a.name < b.name;
                });
                cout << "Items sorted by name (ascending)." << endl;
            } else {
                sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
                    return a.name > b.name;
                });
                cout << "Items sorted by name (descending)." << endl;
            }
            break;
    }
}

void displayLowStockItems() {
    bool found = false;
    cout << "--- Low Stock Items (Qty = 5) ---" << endl;
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Qty"
         << setw(10) << "Price" << endl;

    for (const auto& item : inventory) {
        if (item.quantity <= 5) {
            cout << left << setw(10) << item.id;
            cout << setw(20) << item.name;
            cout << setw(10) << item.quantity;
            cout << fixed << setprecision(2) << item.price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No low stock items found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << endl;
        cout << "--- Inventory Management System ---" << endl;
        cout << "(1) - Add Item" << endl;
        cout << "(2) - Update Item" << endl;
        cout << "(3) - Remove Item" << endl;
        cout << "(4) - Display All Items" << endl;
        cout << "(5) - Search Item" << endl;
        cout << "(6) - Sort Items" << endl;
        cout << "(7) - Display Low Stock Items" << endl;
        cout << "(8) - Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout<<"ADD ITEM"<<endl;
                addItem();
                break;
            }
            case 2: {
                cout<<"UPDATE ITEM"<<endl;
                updateItem();
                break;
            }
            case 3: {
                cout<<"REMOVE ITEM"<<endl;
                removeItem();
                break;
            }
            case 4: {
                cout<<"DISPLAY ALL ITEMS"<<endl;
                displayAllItems();
                break;
            }
            case 5: {
                cout<<"SEARCH ITEM"<<endl;
                searchItem();
                break;
            }
            case 6: {
                cout<<"SORT ITEMS"<<endl;
                sortItems();
                break;
            }
            case 7: {
                cout<<"DISPLAY LOW STOCK ITEMS"<<endl;
                displayLowStockItems();
                break;
            }
            case 8: {
                cout << "EXITING PROGRAM..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        }
    } while (choice != 8);

    return 0;
}