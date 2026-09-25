/*
 * Full Name:     Kevin Chen
 * Student ID:    003979928
 * Course:        EECE 2140 - Computing Fundamentals for Engineers
 * Section:       F26
 * Semester:      Fall 2026
 * Assignment:    Homework 1 - Quiz Grade Analyzer
 * Compilation:   g++ -std=c++11 main.cpp -o main
 * Description:   Reads an unknown number of quiz scores from standard
 *                input and reports the count, sum, minimum, maximum,
 *                average, and letter grade for the quiz.
 */

#include <iostream>

int main()
{
    // TODO 1: Declare and initialize the variables you will need to keep
    //         a running count, sum, minimum, and maximum of the scores
    //         entered so far. Give each one a starting value that will
    //         not produce an incorrect result before any score has been
    //         read.
    int count = 0;
    int sum = 0;
    int score = 0;
    int min = 0;
    int max = 0;

    const int GRADE_A = 90;
    const int GRADE_B = 80;
    const int GRADE_C = 70;
    const int GRADE_D = 60;

    // TODO 2: Print this prompt exactly once, before reading any input:
    //         "Enter quiz scores (Ctrl+D / Ctrl+Z to end):"
    std::cout << "Enter quiz scores (Ctrl+D / Ctrl+Z to end):" << std::endl;

    // TODO 3: Read scores one at a time, for as many scores as the user
    //         enters, updating your count/sum/min/max variables for each
    //         score read. You do not know in advance how many scores
    //         will be entered, so the number of times you read a score
    //         must not be fixed or asked from the user.
    while (std::cin >> score) {
        if (count == 0) {
            min = score;
            max = score;
        }

        count += 1;
        sum += score;

        if (score < min) {
            min = score;
        }
        if (score > max) {
            max = score;
        }
    }

    // TODO 4: If no scores were entered, print exactly:
    //         "No scores were entered."
    //         and end the program without doing anything else below.
    if (count == 0) {
        std::cout << "No scores were entered." << std::endl;
        return 0;
    }

    // TODO 5: Compute the class average as a value that can represent a
    //         fraction (not truncated to a whole number).
    double average = static_cast<double>(sum) / count;

    // TODO 6: Declare named const variables for the five grade cutoffs
    //         described in the assignment (90, 80, 70, 60), then use
    //         them (not the raw numbers) to determine the correct letter
    //         grade for the average.
    char letter = 'F';
    if (average >= GRADE_A) {
        letter = 'A';
    } else if (average >= GRADE_B) {
        letter = 'B';
    } else if (average >= GRADE_C) {
        letter = 'C';
    } else if (average >= GRADE_D) {
        letter = 'D';
    }

    // TODO 7: Print the final summary in the exact format described in
    //         the assignment:
    //         --- Quiz Summary ---
    //         Scores entered: <count>
    //         Sum: <sum>
    //         Minimum: <minimum>
    //         Maximum: <maximum>
    //         Average: <average>
    //         Letter grade: <letter>
    std::cout << "--- Quiz Summary ---" << std::endl;
    std::cout << "Scores entered: " << count << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Maximum: " << max << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Letter grade: " << letter << std::endl;

    return 0;
}
