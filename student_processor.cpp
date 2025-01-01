#include "student_processor.h"
#include "student_file_handler.h"
#include "student.h"
#include <chrono>
#include <iostream>

void StudentProcessor::categorizeStudents(const std::vector<Student>& students,
                                          std::vector<Student>& passed,
                                          std::vector<Student>& failed) {
    for (const auto& student : students) {
        if (student.getFinalScore() < 5.0) {
            failed.push_back(student);
        } else {
            passed.push_back(student);
        }

        std::cout << "Student: " << student.getName() << " " << student.getSurname()
                  << " Score: " << student.getFinalScore() << " Categorized as: "
                  << (student.getFinalScore() < 5.0 ? "Failed" : "Passed") << "\n";
    }
}

void StudentProcessor::measureExecutionTime() {
    using namespace std::chrono;
    std::vector<int> sizes = {10000, 100000, 1000000, 10000000};

    for (const auto& size : sizes) {
        std::string inputFile = "students_" + std::to_string(size) + ".txt";
        std::string passedFile = "passed_" + std::to_string(size) + ".txt";
        std::string failedFile = "failed_" + std::to_string(size) + ".txt";

        std::cout << "Processing file: " << inputFile << "\n";
        std::cout << "Writing to passed file: " << passedFile << "\n";
        std::cout << "Writing to failed file: " << failedFile << "\n";

        auto start = high_resolution_clock::now();

        auto students = StudentFileHandler::readFromFile(inputFile);
        std::cout << "Read " << students.size() << " students from " << inputFile << "\n";

        auto readTime = high_resolution_clock::now();

        std::vector<Student> passed, failed;
        categorizeStudents(students, passed, failed);

        auto sortTime = high_resolution_clock::now();

        if (!passed.empty()) {
            StudentFileHandler::writeToFile(passedFile, passed);
        } else {
            std::cout << "No passed students to write in " << passedFile << "\n";
        }

        if (!failed.empty()) {
            StudentFileHandler::writeToFile(failedFile, failed);
        } else {
            std::cout << "No failed students to write in " << failedFile << "\n";
        }

        auto writeTime = high_resolution_clock::now();

        std::cout << "Read Time: " << duration_cast<milliseconds>(readTime - start).count() << " ms\n";
        std::cout << "Sort Time: " << duration_cast<milliseconds>(sortTime - readTime).count() << " ms\n";
        std::cout << "Write Time: " << duration_cast<milliseconds>(writeTime - sortTime).count() << " ms\n";
    }
}
