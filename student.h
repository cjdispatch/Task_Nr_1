#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    std::string surname;
    double finalScore;

public:
    Student(const std::string& name, const std::string& surname, double finalScore)
        : name(name), surname(surname), finalScore(finalScore) {}

    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }
    double getFinalScore() const { return finalScore; }
};

#endif // STUDENT_H
