// Copyright (c) 2022 Peter Sobowale All rights reserved.
// Created by: Peter Sobowale
// Created on: Dec 1, 2022
// This program asks user for 2 numbers and an operator and
// calculates the answer using a function

#include <cmath>
#include <iomanip>
#include <iostream>


// calculates the result of two numbers
double calculate(char operatorR, float firstNum, float secondNum) {
    float answer;

    if (operatorR == '%') {
        answer = fmod(firstNum, secondNum);
    } else if (operatorR == '/') {
        answer = firstNum / secondNum;
    } else if (operatorR == '*') {
        answer = firstNum * secondNum;
    } else if (operatorR == '-') {
        answer = firstNum - secondNum;
    } else {
        answer = firstNum + secondNum;
    }

    return answer;
}

// checks for invalid input and calls
// function to determine result of two numbers
int main() {
    // declares variables
    char userOperator;
    std::string firstNumString, secondNumString;
    float firstNumFloat, secondNumFloat;
    double userAnswer;

    // gets operation from user
    std::cout << "Enter the operation you want to perform (+, -, *, /, %): ";
    std::cin >> userOperator;

    // checks if invalid operator is entered
    if (userOperator == '+' || userOperator == '-' ||
    userOperator == '*' || userOperator == '/' || userOperator == '%') {
        std::cout << "Enter your first number here: ";
        std::cin >> firstNumString;

        try {
            // convert the user's input to a float
            firstNumFloat = std::stof(firstNumString);

            std::cout << "Enter your second number here: ";
            std::cin >> secondNumString;

            try {
                // convert the user's input to a float
                secondNumFloat = std::stof(secondNumString);

                // assigns variable to function call that gives return value
                userAnswer = calculate(userOperator, firstNumFloat,
                secondNumFloat);

                // displays results to user
                std::cout << std::endl;
                std::cout << "The result of " << firstNumFloat << "";
                std::cout << userOperator << "" << secondNumFloat;
                std::cout << " is " << userAnswer;

                // determines if the input is valid
            } catch (std::invalid_argument) {
                // tells user did the input is not a number
                std::cout << secondNumString << " is not a valid number.";
            }

            // determines if the input is valid
        } catch (std::invalid_argument) {
            // tells user did the input is not a number
            std::cout << firstNumString << " is not a valid number.";
        }
    } else {
        std::cout << userOperator << " is not a valid operator.";
    }
}
