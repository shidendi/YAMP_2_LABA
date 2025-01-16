// ������������ ���� ��� �������� ����� ������ �������.
#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <memory>
#include "Token.h"

// ����� Node ������������ ���� � ������ �������.
class Node {
public:
    Node(const std::string& name, const Token& token = Token()); // �����������
    void addChild(std::shared_ptr<Node> child); // �������� �������� ����
    const std::string& getName() const; // �������� ��� ����
    const Token& getToken() const; // �������� �����, ��������� � �����
    const std::vector<std::shared_ptr<Node>>& getChildren() const; // �������� �������� ����


private:
    std::string name; // ��� ����
    Token token; // ��������� �����
    std::vector<std::shared_ptr<Node>> children; // �������� ����
};

// ��������������� ������� ��� ������ ������ � �������.
void printTree(const std::shared_ptr<Node>& node, int indent = 0);

#endif // NODE_H
