#include <iostream>
#include <string>
#include <fstream>
#include <direct.h> // For _mkdir and _chdir

using namespace std;

void viewfiles(string file) {
    ifstream in(file);
    string read;
    if (in.is_open()) {
        cout << "File opened successfully" << endl;
        while (getline(in, read)) {
            cout << read << endl;
            cout<<"**************************"<<endl;
        }
        in.close();
    } else {
        cout << "File cannot be opened" << endl;
    }
}

void copy(string source, string dest) {
    ifstream in(source);
    ofstream out(dest);
    string get;
    if (in.is_open() && out.is_open()) {
        while (getline(in, get)) {
            out << get << endl;
        }
        cout << "File copied successfully" << endl;
        cout<<"*************************"<<endl;
        in.close();
        out.close();
    } else {
        cout << "File not available" << endl;
    }
}

void create_directory(string dirname) {
    if (_mkdir(dirname.c_str()) == 0) {
        cout << "Directory " << dirname << " created successfully" << endl;
        cout<<"**************************"<<endl;
    } else {
        cerr << "Failed to create directory" << endl;
    }
}

void navigate(string dirname1) {
    if (_chdir(dirname1.c_str()) == 0) {
        cout << "Successfully navigated to " << dirname1 << " directory" << endl;
        cout<<"*************************"<<endl;
    } else {
        cout << "Failed to navigate " << dirname1 << " directory" << endl;
    }
}

int main() {
    string file, source, dest, dirname, dirname1;
    int ch, n;
    do {
        cout << "\nFile Manager Menu" << endl;
        cout << "1. View file" << endl;
        cout << "2. Copy file" << endl;
        cout << "3. Create directory" << endl;
        cout << "4. Navigate directory" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter file to be viewed: ";
                cin >> file;
                viewfiles(file);
                break;
            case 2:
                cout << "\nEnter source file: ";
                cin >> source;
                cout << "Enter destination file: ";
                cin >> dest;
                copy(source, dest);
                break;
            case 3:
                cout << "\nEnter directory name: ";
                cin >> dirname;
                create_directory(dirname);
                break;
            case 4:
                cout << "\nEnter directory name: ";
                cin >> dirname1;
                navigate(dirname1);
                break;
            case 5:
                cout << "\nExiting the program" << endl;
                return 0;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << "Do you want to continue? If yes, press 1: ";
        cin >> n;
    } while (n == 1);

    return 0;
}
