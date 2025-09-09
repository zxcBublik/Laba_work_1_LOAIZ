#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;


void first_task() {
	int Mass[5], max = 0, min = 100;
	cout << "Массив: ";
	for (int i = 0; i < 5; i++) {
		Mass[i] = rand() % 100;
		cout << Mass[i] << " ";
		if (max < Mass[i])
			max = Mass[i];
		if (min > Mass[i])
			min = Mass[i];

	}
	cout << "\nМинимальное число: " << min << "\nМаксимальное число: " << max;
}

void second_task() {
	int Mass[5];
	srand(static_cast<unsigned int>(time(NULL)));
	cout << "Случайный массив: ";
	for (int i = 0; i < 5; i++) {
		Mass[i] = rand() % 100;
		cout << Mass[i] << " ";
	}
}

void third_task() {
	int digit;
	cout << "Введите размер массива: ";
	cin >> digit;
	cout << "Массив размера " << digit << ": ";
	int* Mass = (int*)malloc(digit * sizeof(int));

	for (int i = 0; i < digit; i++) {
		Mass[i] = rand() % 100;
		cout << Mass[i] << " ";
	}
	free(Mass);
}
void anought_task() {
	int a, b;
	cout << "Введите размер массива ";
	cin >> a;
	int** Mass = (int**)malloc(a * sizeof(int*));
	
	cout << "Введите вероятность единицы от 1 до 10 ";
	cin >> b;
	for (int i = 0; i < a; i++) {
		Mass[i] = (int*)malloc(a * sizeof(int));
		for (int j = 0; j < a; j++) {
			int random_number = rand()%10+1;
			if (random_number > b) {
				Mass[i][j] = 0;
			}
			else {
				Mass[i][j] = 1;
			}
			cout << Mass[i][j] << " ";
		}
		cout << "\n";
	}
	free(Mass);
}
void fourth_task() {
	int Mass[10][10], Strings[10] = { 0 }, Colums[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Mass[i][j] = rand() % 90 + 10;
			cout << Mass[i][j] << ' ';
		}
		cout << "\n";
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Strings[i] += Mass[i][j];
			Colums[i] += Mass[j][i];
		}
	}
	cout << "\nСтроки: ";
	for (int i = 0; i < 10; i++)
		cout << Strings[i] << ' ';
	cout << "\nСтолбцы: ";
	for (int i = 0; i < 10; i++)
		cout << Colums[i] << ' ';
}

void fifth_task() {
	struct Student {
		string name;
		string surname;
		string group;
		int course;
	};

	vector<Student>All_students;
	int digit;
	bool EndProgramm = false;

	do {
		cout << "\n1. Добавить студента\n";
		cout << "2. Показать всех студентов\n";
		cout << "3. Поиск студента\n";
		cout << "4. Выход\n";
		cout << "\nВведите номер пункта: ";
		cin >> digit;
		cin.ignore();

		switch (digit) {
		case 1: {
			Student New_student;
			cout << "Введите имя студента: ";
			getline(cin, New_student.name);

			cout << "Введите фамилию студента: ";
			getline(cin, New_student.surname);

			cout << "Введите группу студента: ";
			getline(cin, New_student.group);

			cout << "Введите курс студента: ";
			cin >> New_student.course;
			cin.ignore();

			All_students.push_back(New_student);

			break;
		}
		case 2: {
			if (All_students.empty()) {
				cout << "Список пуст\n";
			}
			else {
				for (int i = 0; i < All_students.size(); i++) {
					cout << All_students[i].name << "\t" << All_students[i].surname << "\t" << All_students[i].group << "\t" << All_students[i].course << " Курс\n";
				}
			}
			break;
		}
		case 3: {
			if (All_students.empty()) {
				cout << "Список пуст\n";
				break;
			}
			bool found = false;
			int search;

			cout << "\n1. Поиск по:\n";
			cout << "\n1. Имени\n";
			cout << "2. Фамилии\n";
			cout << "3. Группе\n";
			cout << "4. Курсу\n";
			cout << "\nВведите номер пункта: ";

			cin >> search;
			cin.ignore();

			switch (search) {
			case 1: {
				string search_name;
				cout << "Введите фамилию для поиска: ";
				getline(cin, search_name);

				cout << "\nРезультаты поиска:\n";
				for (int i = 0; i < All_students.size(); i++) {
					if (search_name == All_students[i].name.substr(0, search_name.length()) || search_name == All_students[i].surname.substr(0, search_name.length())) {
						cout << All_students[i].name << "\t" << All_students[i].surname << "\t" << All_students[i].group << "\t" << All_students[i].course << " Курс\n";
						found = true;
					}
				}
				
				break;
			}
			case 2: {
				string search_surname;
				cout << "Введите фамилию для поиска: ";
				getline(cin, search_surname);

				cout << "\nРезультаты поиска:\n";
				for (int i = 0; i < All_students.size(); i++) {
					if (All_students[i].surname == search_surname) {
						cout << All_students[i].name << "\t" << All_students[i].surname << "\t" << All_students[i].group << "\t" << All_students[i].course << " Курс\n";
						found = true;
					}
				}
				break;
			}
			case 3: {
				string search_group;
				cout << "Введите группу для поиска: ";
				getline(cin, search_group);

				cout << "\nРезультаты поиска:\n";
				for (int i = 0; i < All_students.size(); i++) {
					if (All_students[i].group == search_group) {
						cout << All_students[i].name << "\t" << All_students[i].surname << "\t" << All_students[i].group << "\t" << All_students[i].course << " Курс\n";
						found = true;
					}
				}
				break;
			}
			case 4: {
				int search_course;
				cout << "Введите курс для поиска: ";
				cin >> search_course;
				cin.ignore();

				cout << "\nРезультаты поиска:\n";
				for (size_t i = 0; i < All_students.size(); i++) {
					if (All_students[i].course == search_course) {
						cout << All_students[i].name << "\t" << All_students[i].surname << "\t" << All_students[i].group << "\t" << All_students[i].course << " Курс\n";
						found = true;
					}
				}
				break;
			}
			default:
				cout << "Неверный выбор поиска!\n";
				break;
			}
			if (!found && search >= 1 && search <= 3) {
				cout << "Студенты не найдены!\n";
			}
			break;
		}
		case 4: {
			cout << "Выход из программы";
			EndProgramm = true;
			break;
		}
		
		default: {
			cout << "Некорректный ввод!";
			break;
		}

		}
	} while (!EndProgramm);
}

int main() {
	setlocale(LC_ALL, "Rus");
	int number;
	cout << "Введите номер задания (1-5), первой лабораторной работы: \n";
	cin >> number;
	switch (number)
	{
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
		fifth_task();
		break;

	case 6:
		anought_task();
		break;
	default:
		cout << "Некорректный ввод";
		break;
	}
}