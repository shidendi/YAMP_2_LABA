// Lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "Token.h"

// ����� Lexer ��������� ����������� ������ �������� ������.
class Lexer {
public:

    Lexer(const std::string& input); // �����������, ��������� ������ � �������� �������.
    Token getNextToken(); // ���������� ��������� ����� �� ������.
    const std::vector<Token>& getTokens() const;  // ���������� ��� ������, ���������� �� ������.

private:
    std::string input; // ������� �����
    size_t position; // ������� ������� � ������
    int line; // ������� ������
    int column;  // ������� �������
    std::vector<Token> tokens; // ������ �������

    char peek() const; // ���������� ������� ������, �� ������� �������.
    void advance(); // ��������� � ���������� �������.
    void skipWhitespaceAndComments(); // ���������� ������� � �����������.
    Token identifier(); // �������� ������������� (�����, ����������).
    Token number(); // �������� �������� ���������.
    Token symbol(); // �������� ������ (�������� ��� �����������).
    void tokenize(); // �������� ����� ��� ��������� �������� ������.
};

#endif // LEXER_H
