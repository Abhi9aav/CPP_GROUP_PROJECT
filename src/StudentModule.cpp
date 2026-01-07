#include "StudentModule.h"

#include <iostream>
#include <fstream>
#include <limits>

void StudentModule::addStudent()
{
    std::cout << "Enter student id (int): ";
    int id{};

    if (!(std::cin >> id))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid id input.\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter student name: ";
    std::string name;
    std::getline(std::cin, name);

    // avoid duplicates
    for (const auto& student : students_.all())
    {
        if (student.id == id)
        {
            std::cout << "Student with id " << id << " already exists.\n";
            return;
        }
    }

    students_.add(Student{id, name});
    std::cout << "Student added: " << Student{id, name} << '\n';
}

bool StudentModule::removeStudentById(int id)
{
    const auto& allStudents = students_.all();

    for (std::size_t i = 0; i < allStudents.size(); ++i)
    {
        if (allStudents[i].id == id)
        {
            students_.removeAt(i);
            return true;
        }
    }
    return false;
}

void StudentModule::saveToFile(const std::string& filename) const
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cout << "ERROR: cannot open student file.\n";
        return;
    }

    for (const auto& student : students_.all())
    {
        outFile << student.id << ',' << student.name << '\n';
    }

    std::cout << "Students saved to " << filename << '\n';
}

void StudentModule::loadFromFile(const std::string& filename)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        const auto commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            continue;
        }

        const int id = std::stoi(line.substr(0, commaPos));
        const std::string name = line.substr(commaPos + 1);

        students_.add(Student{id, name});
    }
}

void StudentModule::displayModuleInfo()
{
    std::cout << "--- Student Module ---\n";

    if (students_.size() == 0)
    {
        std::cout << "(no students)\n";
        return;
    }

    for (const auto& student : students_.all())
    {
    std::cout << student << '\n';
    }

}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << student.id << " : " << student.name;
    return os;
}
