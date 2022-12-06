#include <vector>

/*
Separa un numero en sus digitos. Utilizado para imprimir a los digitos del score individualmente.
El primer digito se considera el menos significativo, y se considera como el N = 1.
*/
class DigitSeparator {
public:
    static std::vector<int> getVectorOfDigits(int number);
    static int getFirstDigit(int number);
    static int getSecondDigit(int number);
    static int getNDigit(int number, int n);
};
