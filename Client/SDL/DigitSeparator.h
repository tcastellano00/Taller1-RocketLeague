//El primer digito se considera el menos significativo, y se considera como el N = 1.
#include <vector>
class DigitSeparator {
public:
    static std::vector<int> getVectorOfDigits(int number);
    static int getFirstDigit(int number);
    static int getSecondDigit(int number);
    static int getNDigit(int number, int n);
};
