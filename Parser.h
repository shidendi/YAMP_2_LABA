// Заголовочный файл для парсера. Определяет интерфейс класса Parser.
#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "Node.h"
#include <vector>
#include <memory>

// Класс Parser осуществляет синтаксический разбор на основе токенов из Lexer.
class Parser {
public:
    Parser(Lexer& lexer); // Конструктор
    std::shared_ptr<Node> parse(); // Основной метод разбора
    const std::vector<std::string>& getErrors() const; // Получить список ошибок

private:
    Token currentToken; // Текущий токен
    Lexer& lexer; // Лексер
    std::vector<std::string> errors; // Список ошибок

    // Вспомогательные методы
    void advance();
    void error(const std::string& message);

    // Методы для различных элементов грамматики
    std::shared_ptr<Node> parse_Function();
    std::shared_ptr<Node> parse_Begin();
    std::shared_ptr<Node> parse_FunctionName();
    std::shared_ptr<Node> parse_Descriptions();
    std::shared_ptr<Node> parse_Descr();
    std::shared_ptr<Node> parse_VarList();
    std::shared_ptr<Node> parse_Type();
    std::shared_ptr<Node> parse_Operators();
    std::shared_ptr<Node> parse_Op();
    std::shared_ptr<Node> parse_SimpleExpr();
    std::shared_ptr<Node> parse_Expr();
    std::shared_ptr<Node> parse_Condition();
    std::shared_ptr<Node> parse_End();
    bool isRelationOperator(const std::string& op);  // Проверка на оператор сравнения
};

#endif // PARSER_H
