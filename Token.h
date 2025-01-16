// Заголовочный файл описывает структуру токенов, которые генерирует лексер.
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// Типы токенов, соответствующие различным элементам языка.
enum TokenType {
    WORDS_KEY, // Ключевые слова
    ID, // Идентификаторы
    CONST, // Константы
    SYMBOLS_OF_OPERATION, // Операторы
    SYMBOLS_OF_SEPARATING, // Разделители
    END_OF_FILE // Конец файла
};

// Структура Token содержит информацию о типе, значении и местоположении токена.
struct Token {
    TokenType type; // Тип токена
    std::string value; // Текстовое значение токена
    int line; // Номер строки
    int column; // Номер столбца

    Token(TokenType type = END_OF_FILE, const std::string& value = "", int line = 0, int column = 0)
        : type(type), value(value), line(line), column(column) {}
};

#endif // TOKEN_H
