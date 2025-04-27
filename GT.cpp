#include <iostream>
#include <string>

using namespace std;

class Performer {
private:
    string name;
    int age;

public:
    Performer(string name, int age) : name(name), age(age) {}

    int getAge() const { return age; }
    string getName() const { return name; }
};

class Singer : public Performer {
private:
    string voiceType;

public:
    Singer(string name, int age, string voiceType) : Performer(name, age), voiceType(voiceType) {}

    string getVoiceType() const { return voiceType; }

    void sing() {
        cout << getName() << " is singing with a " << voiceType << " range." << endl;
    }
};

class Dancer : public Performer {
private:
    string danceStyle;

public:
    Dancer(string name, int age, string danceStyle) : Performer(name, age), danceStyle(danceStyle) {}

    string getDanceStyle() const { return danceStyle; }

    void dance() {
        cout << getName() << " is performing a " << danceStyle << " dance." << endl;
    }
};

int main() {
    char choice;
    string name, vocalType, danceStyle;
    int age;

    cout << "Enter 1 for Singer, 2 for Dancer: ";
    cin >> choice;

    cin.ignore();

    switch (choice) {
    case '1': {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter vocal style: ";
        getline(cin, vocalType);
        Singer singer(name, age, vocalType);
        singer.sing();
        break;
    }
    case '2': {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter dance style: ";
        getline(cin, danceStyle);
        Dancer dancer(name, age, danceStyle);
        dancer.dance();
        break;
    }
    default:
        cout << "Invalid choice." << endl;
    }

    return 0;
}