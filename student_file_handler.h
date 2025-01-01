#ifndef STUDENT_FILE_HANDLER_H
#define STUDENT_FILE_HANDLER_H

#include "student.h"  // Include the Student class for passing student objects
#include <vector>
#include <string>

class StudentFileHandler {
public:
    static void generateFiles();  // Method to generate files with student data
    static std::vector<Student> readFromFile(const std::string& fileName);  // Read students from a file
    static void writeToFile(const std::string& fileName, const std::vector<Student>& students);  // Write students to a file
};

#endif // STUDENT_FILE_HANDLER_H
