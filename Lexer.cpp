// Lexer.cpp
#include "Lexer.h"
#include <cctype>
#include <stdexcept>

// Конструктор лексера, инициализирует текст, позицию и вызывает разбиение на токены.
Lexer::Lexer(const std::string& input)
    : input(input), position(0), line(1), column(1) {
    tokenize();
}

// Основной метод для разбиения текста на токены.
void Lexer::tokenize() {
    while (position < input.length()) {
        skipWhitespaceAndComments();
        if (position >= input.length()) break;

        char current_char = peek();
        if (std::isalpha(current_char) || current_char == '_') {
            tokens.push_back(identifier());
        } else if (std::isdigit(current_char)) {
            tokens.push_back(number());
        } else {
            tokens.push_back(symbol());
        }
    }
    tokens.push_back(Token(END_OF_FILE, "", line, column));
}

// Возвращает текущий символ без изменения позиции.
char Lexer::peek() const {
    return input[position];
}

// Переходит к следующему символу.
void Lexer::advance() {
    if (peek() == '\n') {
        line++;
        column = 1;
    } else {
        column++;
    }
    position++;
}

// Пропускает пробельные символы и однострочные комментарии.
void Lexer::skipWhitespaceAndComments() {
    while (position < input.length()) {
        char current_char = peek();
        if (isspace(current_char)) {
            advance();
        } else if (current_char == '/' && position + 1 < input.length() && input[position + 1] == '/') {
            // Пропускаем однострочные комментарии
            while (position < input.length() && peek() != '\n') {
                advance();
            }
        } else {
            break;
        }
    }
}

// Обрабатывает идентификаторы и ключевые слова.
Token Lexer::identifier() {
    int start_line = line;
    int start_column = column;
    std::string result;
    while (position < input.length() && (std::isalnum(peek()) || peek() == '_')) {
        result += peek();
        advance();
    }
    if (result == "int" || result == "for" || result == "return" || result == "if") {
        return Token(WORDS_KEY, result, start_line, start_column);
    }
    return Token(ID, result, start_line, start_column);
}

// Обрабатывает числовые константы.
Token Lexer::number() {
    int start_line = line;
    int start_column = column;
    std::string result;
    while (position < input.length() && std::isdigit(peek())) {
        result += peek();
        advance();
    }
    return Token(CONST, result, start_line, start_column);
}

// Обрабатывает символы (операторы и разделители).
Token Lexer::symbol() {
    int start_line = line;
    int start_column = column;
    char current_char = peek();
    std::string value(1, current_char);
    advance();

    // Обработка операторов с двумя символами, например, '==', '!=', '<=', '>='
    if ((current_char == '=' || current_char == '!' || current_char == '<' || current_char == '>') &&
        position < input.length() && peek() == '=') {
        value += peek();
        advance();
    } else if ((current_char == '+' || current_char == '-') &&
               position < input.length() && peek() == current_char) {
        // Для операторов '++' и '--', если нужно
        value += peek();
        advance();
    }

    if (value == ";" || value == "," || value == "(" || value == ")" || value == "{" || value == "}") {
		return Token(SYMBOLS_OF_SEPARATING, value, start_line, start_column);
	}
    return Token(SYMBOLS_OF_OPERATION, value, start_line, start_column);
}

// Возвращает следующий токен из списка.
Token Lexer::getNextToken() {
    if (!tokens.empty()) {
        Token token = tokens.front();
        tokens.erase(tokens.begin());
        return token;
    }
    return Token(END_OF_FILE, "", line, column);
}

// Возвращает все токены.
const std::vector<Token>& Lexer::getTokens() const {
    return tokens;
}
