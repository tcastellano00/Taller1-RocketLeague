#include "DigitSeparator.h"
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>

int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int DigitSeparator::getFirstDigit(int number) {
    return number % 10;
}

int DigitSeparator::getSecondDigit(int number) {
    int firstDigit = getFirstDigit(number);
    return ((number % 100) - firstDigit)/10;
}

int DigitSeparator::getNDigit(int number, int n) {
    if (n == 1) {
        return number % 10;
    }
    int answer = number % (int)(pow(10, n));
    for (int i = 1; i < n; i++) {
        answer -= getNDigit(number, i)*(int)pow(10, i);
    }
    return answer/(int)pow(10, n);
}

std::vector<int> DigitSeparator::getVectorOfDigits(int number) {
    std::vector<int> vector;
    vector.push_back(getSecondDigit(number));
    vector.push_back(getFirstDigit(number)); 
    return vector;
}

