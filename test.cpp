#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    std::string surname;
    double finalScore;

public:
    Student(const std::string& name, const std::string& surname, double score)
        : name(name), surname(surname), finalScore(score) {}

    double getFinalScore() const { return finalScore; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
};

#endif // STUDENT_H
