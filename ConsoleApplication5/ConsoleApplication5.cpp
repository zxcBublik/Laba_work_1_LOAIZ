#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void first_task() {
    int arr[10], max_el = -1, min_el = 101, raznost;
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        if (max_el < arr[i]) {
            max_el = arr[i];
        }
        if (min_el > arr[i]) {
            min_el = arr[i];
        }
        cout << arr[i] << "  ";
    }
    raznost = max_el - min_el;
    cout << "\nРезультат: Макс занч = " << max_el << "; Мин знач = " << min_el << "\nРазность = " << raznost;
}
void second_task() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << "  ";
    }
}
int error_fix(int arg) {
    while (!(cin >> arg)) {
        cin.clear(); // Сброс флага ошибки
        cin.ignore(numeric_limits <streamsize>::max(), '\n'); //Очищение от необработанных символов в cin
        cout << "Вы ввели некорректный символ!\n";
        cout << "Введите число:\n";
    }
    return arg;
}
void third_task() {
    int count = 0;
    cout << "Введите количество элементов массива:\n";
    count = error_fix(count);
    int* arr = (int*)malloc(count * (sizeof(int)));
    for (int i = 0; i < count; i++) {
        arr[i] = rand() % count;
        cout << arr[i] << "  ";
    }
    free(arr);
}

void fourth_task() {
    int arr[10][10], sum_string[10], sum_column[10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }
    for (int i = 0; i < 10; i++) {
        int tmp = 0, tmp_2 = 0;
        for (int j = 0; j < 10; j++) {
            tmp += arr[i][j];
            tmp_2 += arr[j][i];
        }
        sum_string[i] = tmp;
        sum_column[i] = tmp_2;
    }
    cout << "\nСумма значений в каждой строке: ";
    for (int i = 0; i < 10; i++) {
        cout << sum_string[i] << "  ";
    }
    cout << "\nСумма значений в каждом столбце: ";
    for (int i = 0; i < 10; i++) {
        cout << sum_column[i] << "  ";
    }
}
struct Student {
    string surname, name, faculty;
    int Nomzach;
} stud[3];
void print_students(const vector<int>& students) {
    for (int i = 0; i < students.size(); i++) {
        int id_student = students[i];
        cout << "Имя: " << stud[id_student].name << '\n';
        cout << "Фамилия: " << stud[id_student].surname << '\n';
        cout << "Факультет: " << stud[id_student].faculty << '\n';
        cout << "Номер зачетной книжки: " << stud[id_student].Nomzach << '\n';
        cout << "------------------\n";
    }
}
int find_number(string stud) {
    string numbers = "0123456789";
    bool flag = 0;
    for (int i = 0; i < stud.length(); i++) {
        for (int j = 0; j < numbers.length(); j++) {
            if (numbers[j] == stud[i]) {
                flag = 1;
            }
        }
    }
    if (flag == 1) {
        cout << "Вы ввели некорректный символ!\n";
        return 0;
    }
    if (flag == 0) {
        return 1;
    }
}
int last_task() {
    for (int i = 0; i < 3; i++) {
        int tmp = i + 1;
        do {
            cout << "Введите фамилию студента № " << tmp << '\n';
            cin >> stud[i].surname;
        } while (find_number(stud[i].surname) == 0);
        do {
            cout << "Введите имя студента № " << tmp << '\n';
            cin >> stud[i].name;
        } while (find_number(stud[i].name) == 0);
        do {
            cout << "Введите факультет студнета № " << tmp << '\n';
            cin >> stud[i].faculty;
        } while (find_number(stud[i].faculty) == 0);
        cout << "Введите номер зачетной книжики студента № " << tmp << '\n';
        int tmp_2 = 0;
        stud[i].Nomzach = error_fix(tmp_2);
    }
    cout << "\nПоиск студента\n";
    bool find_student = 1;
    vector<int> students;
    vector<int> filter;
    string SearchName, SearchSurname, SearchFaculty;
    int SearchNomzach = 0;
    cout << "Введите имя для поиска\n";
    cin >> SearchName;

    for (int i = 0; i < 3; i++) {
        if (stud[i].name == SearchName) {
            students.push_back(i);
        }
    }
    if (students.empty()) {
        cout << "Совпадений не было найдено\n";
        return 0;
    }
    cout << "Было найдено " << students.size() << " студента(/ов) с таким именем:\n";
    print_students(students);
    if (students.size() == 1) {
        return 0;
    }
    cout << "\nВведите фамилию студента\n";
    cin >> SearchSurname;
    filter.clear();
    for (int i = 0; i < students.size(); i++) {
        int id_student = students[i];
        if (stud[id_student].surname == SearchSurname) {
            filter.push_back(id_student);
        }
    }
    students = move(filter);
    if (students.empty()) {
        cout << "Совпадений не было найдено\n";
        return 0;
    }
    cout << "С такими параметрами найдено " << students.size() << " совпадений:\n";
    print_students(students);
    if (students.size() == 1) {
        return 0;
    }
    cout << "\nВведите факультет студента\n";
    cin >> SearchFaculty;
    filter.clear();
    for (int i = 0; i < students.size(); i++) {
        int id_student = students[i];
        if (stud[id_student].faculty == SearchFaculty) {
            filter.push_back(id_student);
        }
    }
    students = move(filter);
    if (students.empty()) {
        cout << "Совпадений не было найдено\n";
        return 0;
    }
    cout << "С такими параметрами найдено " << students.size() << " совпадений:\n";
    print_students(students);
    if (students.size() == 1) {
        return 0;
    }
    cout << "\nВведите номер зачетной книжики студента\n";
    SearchNomzach = error_fix(SearchNomzach);
    filter.clear();
    for (int i = 0; i < students.size(); i++) {
        int id_student = students[i];
        if (stud[id_student].Nomzach == SearchNomzach) {
            filter.push_back(id_student);
        }
    }
    students = move(filter);
    if (students.empty()) {
        cout << "Совпадений не было найдено\n";
        return 0;
    }
    cout << "С такими параметрами найдено " << students.size() << " совпаден(ия/ие):\n";
    print_students(students);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));
    int tasks_number = 0;
    do {
        cout << "\nВведите номер задания (чтобы выйти введите 0):\n";
        tasks_number = error_fix(tasks_number);
        if (tasks_number > 5) {
            cout << "Такого задания нет";
            continue;
        }
        switch (tasks_number) {
        case 1:
            first_task();
            break;
        case 2:
            second_task();
            break;
        case 3:
            third_task();
            break;
        case 4:
            fourth_task();
            break;
        case 5:
            last_task();
            break;
        }
    } while (tasks_number != 0);
}

