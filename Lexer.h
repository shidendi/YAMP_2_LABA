// Lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "Token.h"

// Класс Lexer выполняет лексический анализ входного текста.
class Lexer {
public:

    Lexer(const std::string& input); // Конструктор, принимает строку с исходным текстом.
    Token getNextToken(); // Возвращает следующий токен из потока.
    const std::vector<Token>& getTokens() const;  // Возвращает все токены, полученные из текста.

private:
    std::string input; // Входной текст
    size_t position; // Текущая позиция в тексте
    int line; // Текущая строка
    int column;  // Текущий столбец
    std::vector<Token> tokens; // Список токенов

    char peek() const; // Возвращает текущий символ, не изменяя позицию.
    void advance(); // Переходит к следующему символу.
    void skipWhitespaceAndComments(); // Пропускает пробелы и комментарии.
    Token identifier(); // Выделяет идентификатор (слова, переменные).
    Token number(); // Выделяет числовую константу.
    Token symbol(); // Выделяет символ (оператор или разделитель).
    void tokenize(); // Основной метод для обработки входного текста.
};

#endif // LEXER_H
