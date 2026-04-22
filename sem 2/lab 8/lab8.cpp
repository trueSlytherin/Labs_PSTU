//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//struct Schoolboy {
//    string lastName;
//    string firstName;
//    string patronymic;
//    string className;
//    string phone;
//    int math;
//    int physics;
//    int russian;
//    int literature;
//};
//
//void printOne(Schoolboy s) {
//    cout << "familia: " << s.lastName << endl;
//    cout << "name: " << s.firstName << endl;
//    cout << "otchestvo: " << s.patronymic << endl;
//    cout << "class: " << s.className << endl;
//    cout << "nomber: " << s.phone << endl;
//    cout << "matem: " << s.math << endl;
//    cout << "fisika: " << s.physics << endl;
//    cout << "russian: " << s.russian << endl;
//    cout << "literatura: " << s.literature << endl;
//    cout << "------------------------" << endl;
//}
//
//void printAll(Schoolboy* arr, int size) {
//    if (size == 0) {
//        cout << "spisok pust." << endl;
//        return;
//    }
//
//    for (int i = 0; i < size; i++) {
//        cout << "shkolnik №" << i + 1 << endl;
//        printOne(arr[i]);
//    }
//}
//
//int countLines(const string& fileName) {
//    ifstream file(fileName.c_str());
//    if (!file.is_open()) {
//        return 0;
//    }
//
//    string line;
//    int count = 0;
//
//    while (getline(file, line)) {
//        if (!line.empty()) {
//            count++;
//        }
//    }
//
//    file.close();
//    return count;
//}
//
//bool parseLine(const string& line, Schoolboy& s) {
//    string temp;
//    stringstream ss(line);
//
//    getline(ss, s.lastName, ';');
//    getline(ss, s.firstName, ';');
//    getline(ss, s.patronymic, ';');
//    getline(ss, s.className, ';');
//    getline(ss, s.phone, ';');
//
//    getline(ss, temp, ';');
//    s.math = stoi(temp);
//
//    getline(ss, temp, ';');
//    s.physics = stoi(temp);
//
//    getline(ss, temp, ';');
//    s.russian = stoi(temp);
//
//    getline(ss, temp, ';');
//    s.literature = stoi(temp);
//
//    return true;
//}
//
//Schoolboy* readFromFile(const string& fileName, int& size) {
//    size = countLines(fileName);
//
//    if (size == 0) {
//        return nullptr;
//    }
//
//    ifstream file(fileName.c_str());
//    if (!file.is_open()) {
//        cout << "oshibka otkritiya faila!" << endl;
//        size = 0;
//        return nullptr;
//    }
//
//    Schoolboy* arr = new Schoolboy[size];
//    string line;
//    int i = 0;
//
//    while (getline(file, line)) {
//        if (!line.empty()) {
//            parseLine(line, arr[i]);
//            i++;
//        }
//    }
//
//    file.close();
//    return arr;
//}
//
//void saveToFile(const string& fileName, Schoolboy* arr, int size) {
//    ofstream file(fileName.c_str());
//
//    if (!file.is_open()) {
//        cout << "oshibka zapisi faila!" << endl;
//        return;
//    }
//
//    for (int i = 0; i < size; i++) {
//        file << arr[i].lastName << ";"
//            << arr[i].firstName << ";"
//            << arr[i].patronymic << ";"
//            << arr[i].className << ";"
//            << arr[i].phone << ";"
//            << arr[i].math << ";"
//            << arr[i].physics << ";"
//            << arr[i].russian << ";"
//            << arr[i].literature;
//
//        if (i != size - 1) {
//            file << endl;
//        }
//    }
//
//    file.close();
//}
//
//bool hasBadMark(Schoolboy s) {
//    return s.math == 2 || s.physics == 2 || s.russian == 2 || s.literature == 2;
//}
//
//Schoolboy* deleteBadSchoolboys(Schoolboy* arr, int& size) {
//    int countBad = 0;
//
//    for (int i = 0; i < size; i++) {
//        if (hasBadMark(arr[i])) {
//            countBad++;
//        }
//    }
//
//    int newSize = size - countBad;
//
//    if (newSize <= 0) {
//        delete[] arr;
//        size = 0;
//        return nullptr;
//    }
//
//    Schoolboy* newArr = new Schoolboy[newSize];
//    int j = 0;
//
//    for (int i = 0; i < size; i++) {
//        if (!hasBadMark(arr[i])) {
//            newArr[j] = arr[i];
//            j++;
//        }
//    }
//
//    delete[] arr;
//    size = newSize;
//    return newArr;
//}
//
//Schoolboy inputSchoolboy() {
//    Schoolboy s;
//
//    cout << "vvedite familia: ";
//    getline(cin, s.lastName);
//
//    cout << "vvedite name: ";
//    getline(cin, s.firstName);
//
//    cout << "vvedite otchestvo: ";
//    getline(cin, s.patronymic);
//
//    cout << "vvvedite class: ";
//    getline(cin, s.className);
//
//    cout << "vvedite nomder: ";
//    getline(cin, s.phone);
//
//    cout << "vvedite ozenky po matem: ";
//    cin >> s.math;
//
//    cout << "vvedite ozenky po fizike: ";
//    cin >> s.physics;
//
//    cout << "vvedite ozenky po russian: ";
//    cin >> s.russian;
//
//    cout << "vvedite ozenky po literature: ";
//    cin >> s.literature;
//
//    cin.ignore();
//
//    return s;
//}
//
//Schoolboy* addToBeginning(Schoolboy* arr, int& size, Schoolboy s) {
//    Schoolboy* newArr = new Schoolboy[size + 1];
//
//    newArr[0] = s;
//
//    for (int i = 0; i < size; i++) {
//        newArr[i + 1] = arr[i];
//    }
//
//    delete[] arr;
//    size++;
//    return newArr;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    string fileName = "schoolboys.txt";
//    int size = 0;
//
//    Schoolboy* arr = readFromFile(fileName, size);
//
//    if (arr == nullptr && size == 0) {
//        cout << "fail pustoy ili ne ydalos prochitat dannb|E." << endl;
//        return 0;
//    }
//
//    cout << "===== isxodnыe dannыe =====" << endl;
//    printAll(arr, size);
//
//    arr = deleteBadSchoolboys(arr, size);
//
//    cout << endl;
//    cout << "===== posle deleted shoklilov s ozenko 2 =====" << endl;
//    printAll(arr, size);
//
//    cout << endl;
//    cout << "vvedite dannыe new shkolnik:" << endl;
//    Schoolboy newBoy = inputSchoolboy();
//
//    arr = addToBeginning(arr, size, newBoy);
//
//    cout << endl;
//    cout << "===== posle dobavlenia new shkolnika v nachalo =====" << endl;
//    printAll(arr, size);
//
//    saveToFile(fileName, arr, size);
//
//    delete[] arr;
//    return 0;
//}

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string lastName = "?";
    string firstName = "?";
    string patronymic = "?";
    string address = "?";
    string group = "?";
    float rating = 0.0;

    void print() {
        cout << "    Фамилия: \t" << lastName << endl;
        cout << "        Имя: \t" << firstName << endl;
        cout << "   Отчество: \t" << patronymic << endl;
        cout << "      Адрес: \t" << address << endl;
        cout << "     Группа: \t" << group << endl;
        cout << "    Рейтинг: \t" << rating << endl;
    }
};

Student* deleteByRating(Student* students, int& size, float minRating) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].rating < minRating) {
            count++;
        }
    }

    Student* newStudents = new Student[size - count];

    for (int i = 0, j = 0; i < size; i++) {
        if (students[i].rating >= minRating) {
            newStudents[j] = students[i];
            j++;
        }
    }

    delete[] students;
    size -= count;
    return newStudents;
}

Student* addElement(Student* students, int& size) {
    string lastName, firstName, patronymic, address, group, ratingStr;

    cout << "\nВведите данные нового студента:" << endl;
    cout << "Фамилия: "; getline(cin, lastName);
    cout << "Имя: "; getline(cin, firstName);
    cout << "Отчество: "; getline(cin, patronymic);
    cout << "Адрес: "; getline(cin, address);
    cout << "Группа: "; getline(cin, group);
    cout << "Рейтинг: "; getline(cin, ratingStr);

    Student newStudent = { lastName, firstName, patronymic, address, group, stof(ratingStr) };

    cout << "\nДобавлен новый студент:" << endl;
    newStudent.print();
    cout << endl;

    Student* newStudents = new Student[size + 1];

    for (int i = 0; i < size; i++) {
        newStudents[i] = students[i];
    }
    newStudents[size] = newStudent;

    size += 1;
    delete[] students;
    return newStudents;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    fstream file("Spisok.txt");
    string buff;

    int studentCount = 10;
    Student* students = new Student[studentCount];

    string lastName, firstName, patronymic, address, group, ratingStr;

    for (int i = 0; i < studentCount; i++) {
        getline(file, lastName);
        getline(file, firstName);
        getline(file, patronymic);
        getline(file, address);
        getline(file, group);
        getline(file, ratingStr);

        students[i] = { lastName, firstName, patronymic, address, group, stof(ratingStr) };

        getline(file, buff);
    }

    cout << "=== Исходные данные ===" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        students[i].print();
    }

    float minRating = 3.8;
    students = deleteByRating(students, studentCount, minRating);
    cout << "\n=== После удаления студентов с рейтингом < " << minRating << " ===" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        students[i].print();
    }
    cin.ignore();
    students = addElement(students, studentCount);

    cout << "\n=== После добавления студента ===" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        students[i].print();
    }

    delete[] students;
    return 0;
}