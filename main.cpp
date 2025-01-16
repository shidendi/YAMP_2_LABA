#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Parser.h"
#include "Node.h"

int main() {
    // �������� �������� �����
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the input file: input.txt" << std::endl;
        std::cout << "\nPress Enter to close the program...";
        std::cin.get();
        return 1;
    }

    // ������ ����������� ����� � ������
    std::string inputText((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // �������� �������
    Lexer lexer(inputText);

    // �������� �������
    Parser parser(lexer);

    try {
        // ���������� ��������������� �������
        auto parseTree = parser.parse();

        // �������� �� ������� ������
        const auto& errors = parser.getErrors();
        if (!errors.empty()) {
            for (const auto& error : errors) {
                std::cerr << error << std::endl;
            }
            std::cout << "\nPress Enter to close the program...";
            std::cin.get();
            return 1;
        }

        // ������ ������ ������� � �������� ����
        std::ofstream outputFile("output.txt");
        if (!outputFile) {
            std::cerr << "Failed to open the output file: output.txt" << std::endl;
            std::cout << "\nPress Enter to close the program...";
            std::cin.get();
            return 1;
        }

        // ��������������� std::cout ��� ������ ������ ������� � ����
        std::streambuf* coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(outputFile.rdbuf());

        // ������ ������ �������
        printTree(parseTree);

        // �������������� std::cout
        std::cout.rdbuf(coutBuf);

        std::cout << "Syntax analysis completed successfully. Parse tree saved to output.txt" << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;

        // �������� �����, ����� �������� ������� ��������
        std::cout << "\nPress Enter to close the program...";
        std::cin.get();
        return 1;
    }

    // �������� ����� ����� ��������� ���������
    std::cout << "\nPress Enter to close the program...";
    std::cin.get();

    return 0;
}
