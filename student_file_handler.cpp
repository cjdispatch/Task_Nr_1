#include "student_file_handler.h"
#include <fstream>
#include <stdexcept>
#include <iostream>  

void StudentFileHandler::generateFiles() {
    std::vector<int> sizes = {10000, 100000, 1000000, 10000000};
    for (const auto& size : sizes) {
        std::ofstream file("students_" + std::to_string(size) + ".txt");
        if (!file) throw std::runtime_error("File creation failed!");

        for (int i = 1; i <= size; ++i) {
            file << "Name" << i << " Surname" << i << " " << (rand() % 10 + 1) << "\n";
        }
        file.close();
        std::cout << "Generated file: students_" + std::to_string(size) + ".txt\n";
    }
}

std::vector<Student> StudentFileHandler::readFromFile(const std::string& fileName) {
    std::vector<Student> students;
    std::ifstream file(fileName);
    if (!file) throw std::runtime_error("File not found!");

    std::string name, surname;
    double score;
    while (file >> name >> surname >> score) {
        students.emplace_back(name, surname, score);
    }

    file.close();
    return students;
}

void StudentFileHandler::writeToFile(const std::string& fileName, const std::vector<Student>& students) {
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error: Failed to create or open file " << fileName << "\n";
        throw std::runtime_error("File creation failed!");
    }

    std::cout << "Writing " << students.size() << " students to " << fileName << "\n";

    if (students.empty()) {
        std::cout << "No students to write to " << fileName << "\n";
        return;
    }

    for (const auto& student : students) {
        file << student.getName() << " " << student.getSurname() << " " << student.getFinalScore() << "\n";
    }

    file.close();
    std::cout << "Data successfully written to " << fileName << "\n";
}
