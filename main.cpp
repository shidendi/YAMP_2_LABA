#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Parser.h"
#include "Node.h"

int main() {
    // Открытие входного файла
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the input file: input.txt" << std::endl;
        std::cout << "\nPress Enter to close the program...";
        std::cin.get();
        return 1;
    }

    // Чтение содержимого файла в строку
    std::string inputText((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // Создание лексера
    Lexer lexer(inputText);

    // Создание парсера
    Parser parser(lexer);

    try {
        // Выполнение синтаксического анализа
        auto parseTree = parser.parse();

        // Проверка на наличие ошибок
        const auto& errors = parser.getErrors();
        if (!errors.empty()) {
            for (const auto& error : errors) {
                std::cerr << error << std::endl;
            }
            std::cout << "\nPress Enter to close the program...";
            std::cin.get();
            return 1;
        }

        // Запись дерева разбора в выходной файл
        std::ofstream outputFile("output.txt");
        if (!outputFile) {
            std::cerr << "Failed to open the output file: output.txt" << std::endl;
            std::cout << "\nPress Enter to close the program...";
            std::cin.get();
            return 1;
        }

        // Перенаправление std::cout для записи дерева разбора в файл
        std::streambuf* coutBuf = std::cout.rdbuf();
        std::cout.rdbuf(outputFile.rdbuf());

        // Печать дерева разбора
        printTree(parseTree);

        // Восстановление std::cout
        std::cout.rdbuf(coutBuf);

        std::cout << "Syntax analysis completed successfully. Parse tree saved to output.txt" << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;

        // Ожидание ввода, чтобы оставить консоль открытой
        std::cout << "\nPress Enter to close the program...";
        std::cin.get();
        return 1;
    }

    // Ожидание ввода перед закрытием программы
    std::cout << "\nPress Enter to close the program...";
    std::cin.get();

    return 0;
}
