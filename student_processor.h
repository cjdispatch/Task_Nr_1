#ifndef STUDENT_PROCESSOR_H
#define STUDENT_PROCESSOR_H

#include "student.h"  // Include the Student class
#include <vector>

class StudentProcessor {
public:
    static void categorizeStudents(const std::vector<Student>& students,
                                   std::vector<Student>& passed,
                                   std::vector<Student>& failed);
    static void measureExecutionTime();  // Measure execution time for file processing
};

#endif // STUDENT_PROCESSOR_H
