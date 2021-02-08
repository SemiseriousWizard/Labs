#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;
string inputFilePath = "F1.txt";
string outputFilePath = "F2.txt";
struct LongWord {
    string Word;
    unsigned int Length;
};
LongWord longestWord;
fstream outputFile;
bool has_spaces(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            return true;
    return false;
}
void find_longest_word() {
    longestWord.Word = "";
    longestWord.Length = 0;
    if (outputFile.is_open()) {
        getline(outputFile, longestWord.Word);
        longestWord.Length = longestWord.Word.length();
        string line;
        while (!outputFile.eof()) {
            line = "";
            getline(outputFile, line);
            if (line.length() > longestWord.Length) {
                longestWord.Word = line;
                longestWord.Length = line.length();
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    string line;
    fstream inputFile;
    inputFile.open(inputFilePath, fstream::in);
    outputFile.open(outputFilePath, fstream::out | fstream::app);
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            line = "";
            getline(inputFile, line);
            if (!has_spaces(line))
                outputFile << line << "\n";
        }
    }
    outputFile.close();
    outputFile.open(outputFilePath, fstream::in);
    find_longest_word();
    inputFile.close();
    outputFile.close();
    cout << "Самое длинное слово: " << longestWord.Word << "\n";
    cout << "Его длина: " << longestWord.Length << " символов\n";
    system("pause");
    return 0;
}