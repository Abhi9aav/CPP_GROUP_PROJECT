#include "MainProject.h"

#include <iostream>
#include <limits>


void MainProject::displayModuleInfo() 
{
    std::cout << "\n===== FULL STUDENT MANAGEMENT SYSTEM REPORT =====\n\n";

    std::cout << "(1) STUDENT MODULE:\n";
    studentModule_.displayModuleInfo();

    std::cout << "\n(2) FACULTY MODULE:\n";
    facultyModule_.displayModuleInfo();

    std::cout << "\n(3) DATABASE MODULE:\n";
    databaseModule_.displayModuleInfo();
}

void MainProject::saveAll() 
{
    studentModule_.saveToFile("students.txt");
    facultyModule_.saveToFile("faculty.txt");
}

void MainProject::run() 
{
    studentModule_.loadFromFile("students.txt");
    facultyModule_.loadFromFile("faculty.txt");

    bool running = true;
    while (running) {
        std::cout << "\n===== STUDENT MANAGEMENT SYSTEM MENU =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Faculty\n";
        std::cout << "3. Show Students\n";
        std::cout << "4. Show Faculty\n";
        std::cout << "5. Remove Student by ID\n";
        std::cout << "6. Remove Faculty by ID\n";
        std::cout << "7. Connect to Database (simulate)\n";
        std::cout << "8. Save to files\n";
        std::cout << "9. Show Full Report\n";
        std::cout << "10. Search Student by ID\n";
        std::cout << "11. Search Student by Name\n";
        std::cout << "12. Search Faculty by ID\n";
        std::cout << "13. Search Faculty by Name\n";
        std::cout << "14. Update Student Name\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose option: ";

        int choice{};
        if (!(std::cin >> choice)) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) 
        {
            case 1:
                studentModule_.addStudent();
                break;

            case 2:
                facultyModule_.addFaculty();
                break;

            case 3:
                studentModule_.displayModuleInfo();
                break;

            case 4:
                facultyModule_.displayModuleInfo();
                break;

            case 5: 
            {
                std::cout << "Enter student id to remove: ";
                int id{};
                std::cin >> id;

                if (studentModule_.removeStudentById(id))
                {
                    std::cout << "Student removed.\n";
                }
                else
                {
                    std::cout << "Student id not found.\n";
                }
                break;
            }

            case 6: 
            {
                std::cout << "Enter faculty id to remove: ";
                int id{};
                std::cin >> id;

                if (facultyModule_.removeFacultyById(id))
                {
                    std::cout << "Faculty removed.\n";
                }
                else
                {
                    std::cout << "Faculty id not found.\n";
                }
                break;
            }

            case 7:
                try 
                {
                    databaseModule_.connect();
                } 
                catch (const CustomException<std::string>& ex) 
                {
                    std::cout << "[CUSTOM EXCEPTION] " << ex.what() << "\n";
                }
                break;

            case 8:
                saveAll();
                break;

            case 9:
                displayModuleInfo();
                break;

            case 10:
            {
                std::cout <<"Enter student id: ";
                int id{};
                std::cin >> id;

                const Student* student = studentModule_.findbyID(id);
                if(student)
                {
                    std::cout << "Found: " << *student << "\n";
                }
                else
                {
                    std::cout << "student not found\n";
                }
                break;
            }

            case 11:
            {
                std::cout << "Search Student by name: ";
                std::string keyword;
                std::cin >> keyword;

                auto results = studentModule_.findStudentbyName(keyword);

                if (results.empty())
                {
                    std::cout << "no students found.\n";
                }
                else
                {
                    for(const auto& s : results)
                    {
                        std::cout << s << "\n";
                    }
                }
                break;
            }

            case 12:
            {
                std::cout << "Enter faculty id: ";
                int id{};
                std::cin >> id;

                const Faculty *faculty = facultyModule_.findFacultyById(id);
                if(faculty)
                {
                    std::cout << "Found: " << *faculty << "\n";
                }
                else
                {
                    std::cout << "Faculty not found.\n";
                }
                break;
            }

            case 13:
            {
                std::cout << "Search Faculty by name: ";
                std::string keyword;
                std::cin >> keyword;

                auto results = facultyModule_.findFacultyByName(keyword);

                if (results.empty())
                {
                    std::cout << "no faculty found.\n";
                }
                else
                {
                    for(const auto& f : results)
                    {
                        std::cout << f << "\n";
                    }
                }
                break;
            }

            case 14:
            {
                std::cout <<"Enter Student id to update: ";
                int id{};
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                const Student* student = studentModule_.findbyID(id);
                if (!student)
                {
                    std::cout <<"Student not found.\n";
                    break;
                }

                std::cout << "Current details: " << *student << "\n";
                std::cout << "Enter new name: ";

                std::string newName;
                std::getline(std::cin, newName);

                if (studentModule_.updateStudentName(id, newName))
                {
                    std::cout <<"Student updated successfully.\n";
                }
                else
                {
                    std::cout << "update failed.\n";
                }
                break;
            }   

            case 0:
                std::cout << "Saving before exit...\n";
                saveAll();
                running = false;
                break;

            default:
               std::cout << "Unknown option.\n";
        }
    }

    databaseModule_.disconnect();
    std::cout << "Goodbye.\n";
}
