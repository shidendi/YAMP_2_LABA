// ������������ ���� ��� �������. ���������� ��������� ������ Parser.
#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "Node.h"
#include <vector>
#include <memory>

// ����� Parser ������������ �������������� ������ �� ������ ������� �� Lexer.
class Parser {
public:
    Parser(Lexer& lexer); // �����������
    std::shared_ptr<Node> parse(); // �������� ����� �������
    const std::vector<std::string>& getErrors() const; // �������� ������ ������

private:
    Token currentToken; // ������� �����
    Lexer& lexer; // ������
    std::vector<std::string> errors; // ������ ������

    // ��������������� ������
    void advance();
    void error(const std::string& message);

    // ������ ��� ��������� ��������� ����������
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
    bool isRelationOperator(const std::string& op);  // �������� �� �������� ���������
};

#endif // PARSER_H
