#include <iostream>
#include <fstream>
#include <string>

constexpr int ASCIIto1{96};

int getWordNumber(int stringLength, const char* str)
{
    int calculator{ 0 };
    int loop{ 0 };
    while (stringLength > loop)
    {
        int strPosition{ loop };
        calculator += str[strPosition];
        calculator -= ASCIIto1;
        ++loop;
    }
    return calculator;
}

int main()
{
    int longestWordSum{ 0 };
    std::string longestwordName{ 0 };
    int oddCounter{ 0 };
    int commonWordSumSave{ 0 };
    int commonWordSumBigger{ 0 };
    int commonWordSumBiggerSave{ 0 };
    int sumArray[320]{};
    int arrayPosition{ 0 };

    std::string stringLine{};
    std::ifstream enable1{};
    enable1.open("enable1.txt");

    //error message
    if (!enable1.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    while (getline(enable1, stringLine))
    {
        int stringLength = stringLine.length();
        const char* str = stringLine.c_str();

        int wordNumber = getWordNumber(stringLength, str);

        ++sumArray[wordNumber];

        if (wordNumber > longestWordSum)
        {
            longestWordSum = wordNumber;
            longestwordName = stringLine;
        }
        if (wordNumber % 2 != 0)
        {
            ++oddCounter;
        }
    }

    int arrayLargest{ sumArray[0]};
    int arrayLoop{ 0 };

    while (arrayLoop < sizeof(sumArray) / sizeof(sumArray[0]))
    {
        if (sumArray[arrayLoop] > arrayLargest)
        {
            arrayLargest = sumArray[arrayLoop];
            arrayPosition = arrayLoop;
        }
        ++arrayLoop;
    }

    std::cout << "The largest word sum is called " << longestwordName << " with a sum of " << longestWordSum << ".\n";
    std::cout << "There are " << oddCounter << " words with an odd sum.\n";
    std::cout << "There are " << arrayLargest << " with the sum of " << arrayPosition << ".\n";
}