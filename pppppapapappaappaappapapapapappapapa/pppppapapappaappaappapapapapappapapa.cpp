#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Worker 
{
public:
    Worker()
    {
        std::cout << "Введите имя работника: ";
        std::cin >> firstName;
        std::cout << "Введите фамилию работника: ";
        std::cin >> lastName;
        std::cout << "Введите стаж работника (в годах): ";
        std::cin >> experience;
        std::cout << "Введите часовую зарплату работника: ";
        std::cin >> hourlyWage;
        std::cout << "Введите количество отработанных часов: ";
        std::cin >> hoursWorked;
    }

    double calculateSalary() 
    {
        return hourlyWage * hoursWorked;
    }

    double calculateBonus() 
    {
        if (experience <= 1) 
        {
            return 0;
        }
        else if (experience <= 3) 
        {
            return calculateSalary() * 0.05;
        }
        else if (experience <= 5) 
        {
            return calculateSalary() * 0.08;
        }
        else 
        {
            return calculateSalary() * 0.15;
        }
    }

    void printInformation() 
    {
        std::cout << "Информация о работнике:" << "\n";
        std::cout << "Имя: " << firstName << "\n";
        std::cout << "Фамилия: " << lastName << "\n";
        std::cout << "Стаж: " << experience << " года/лет" << "\n";
        std::cout << "Часовая зарплата: " << hourlyWage << " руб." << "\n";
        std::cout << "Отработанные часы: " << hoursWorked << "\n";
        std::cout << "Зарплата: " << calculateSalary() << " руб." << "\n";
        std::cout << "Премия: " << calculateBonus() << " руб." << "\n";
    }


    void saveToFile(const std::string& filename)
    {
        std::ofstream outfile;
        outfile.open(filename, std::ios::app);
        if (!outfile.is_open()) 
        {
            std::cout << "Ошибка открытия файла" << "\n";
        }
        else 
        {
            outfile << firstName << "  " << lastName << "  " << experience << "   " << hourlyWage << "   " << hoursWorked << "  "
                << calculateSalary() << "  " << calculateBonus() << "\n";
            outfile.close();
        }
    }

private:
    std::string firstName;
    std::string lastName;
    int experience;
    double hourlyWage;
    int hoursWorked;
};


void printWorkerInfoFromFile(const std::string& filename)
{
    std::ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) 
    {
        std::cout << "Ошибка открытия файла!" << "\n";
    }
    else {
        std::string line;
        while (getline(infile, line)) 
        {
            std::cout << line;
        }
        infile.close();
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ofstream outfile("workers.txt");
    outfile << "Имя" << "   " << "Фамилия" << "  " << "Стаж" << "  " << "Часовая зп" << "  " << "Отработанные часы" << "  "
        << "ЗП" << "  " << "Премия" << "\n";
    outfile.close();

    Worker employee1;
    Worker employee2;
    Worker employee3;


    employee1.saveToFile("workers.txt");
    employee2.saveToFile("workers.txt");
    employee3.saveToFile("workers.txt");


    std::cout << "Информация из файла workers.txt:" << "\n";
    printWorkerInfoFromFile("workers.txt");

    return 0;
}
