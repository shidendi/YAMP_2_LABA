// ������������ ���� ��������� ��������� �������, ������� ���������� ������.
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// ���� �������, ��������������� ��������� ��������� �����.
enum TokenType {
    WORDS_KEY, // �������� �����
    ID, // ��������������
    CONST, // ���������
    SYMBOLS_OF_OPERATION, // ���������
    SYMBOLS_OF_SEPARATING, // �����������
    END_OF_FILE // ����� �����
};

// ��������� Token �������� ���������� � ����, �������� � �������������� ������.
struct Token {
    TokenType type; // ��� ������
    std::string value; // ��������� �������� ������
    int line; // ����� ������
    int column; // ����� �������

    Token(TokenType type = END_OF_FILE, const std::string& value = "", int line = 0, int column = 0)
        : type(type), value(value), line(line), column(column) {}
};

#endif // TOKEN_H
