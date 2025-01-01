#include <iostream>
#include "student_file_handler.h"
#include "student_processor.h"

int main() {
    try {
        StudentFileHandler::generateFiles();  // Generate files with random data
        StudentProcessor::measureExecutionTime();  // Process the files
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
