#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string date;
    string genre;
    double ratings;

public:
    Book(string t, string a, string d, string g, double r) {
        title = t;
        author = a;
        date = d;
        genre = g;
        ratings = r;
    }

    ~Book() {
        cout << "Book destroyed: " << title << endl;
    }

    void displayLibrary() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Date: " << date << endl;
        cout << "Genre: " << genre << endl;
        cout << "Ratings: " << ratings << endl;
        cout << "-----------------------------" << endl;
    }

    string getTitle() const {
        return title;
    }
};

int main() {
    vector<Book> books;
    int choice;

    do {
        cout << "Library Management System" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search for a Book by Title" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string title, author, date, genre;
                double ratings;

                cout << "Enter book title: ";
                getline(cin, title);

                cout << "Enter author's name: ";
                getline(cin, author);

                cout << "Enter date: ";
                getline(cin, date);

                cout << "Enter genre: ";
                getline(cin, genre);

                cout << "Enter ratings: ";
                cin >> ratings;
                cin.ignore(); 

    
                books.push_back(Book(title, author, date, genre, ratings));
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2: {
                
                cout << "\nBooks in the library:" << endl;
                for (const auto& book : books) {
                    book.displayLibrary();
                }
                break;
            }
            case 3: {
                string searchTitle;
                cout << "Enter the title of the book to search: ";
                getline(cin, searchTitle);
                bool found = false;

                for (const auto& book : books) {
                    if (book.getTitle() == searchTitle) {
                        cout << "Book found!" << endl;
                        book.displayLibrary();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}