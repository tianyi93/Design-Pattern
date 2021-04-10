//
// Created by Tianyi Zhang on 4/9/21.
//

#ifndef DESIGN_PATTERN_19_INTERPRETER_PATTERN_2_H
#define DESIGN_PATTERN_19_INTERPRETER_PATTERN_2_H
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

struct Token {
    enum Type { integer, plus, minus, lparen, rparen };
    Type        m_type;
    string      m_text;
    Token() = default;
    Token(Type typ, string txt): m_type(typ), m_text(txt) {}

    friend ostream& operator<<(ostream& os, Token const& token) { return os << "`" << token.m_text << "`"; }
};

vector<Token> lex(string const& input) {
    vector<Token> result;

    for (auto it = input.begin(); it!=input.end(); it++) {
        switch (*it) {
            case '+': result.push_back(Token(Token::plus, "+")); break;
            case '-': result.emplace_back(Token::minus, "-"); break;
            case '(': result.emplace_back(Token::lparen, "("); break;
            case ')': result.emplace_back(Token::rparen, ")"); break;
            default:
                auto firstNotInt = find_if(it, input.end(), [](char c){
                    return !isdigit(c);
                });
                result.emplace_back(Token::integer, string(it, firstNotInt));
                it = --firstNotInt;
                break;
        }
    }
    return result;
}

struct Element {
    virtual int eval() const = 0;
};

struct Integer : Element {
    int   m_value;
    Integer(const int v) : m_value(v) {}
    int eval() const { return m_value; }
};

struct BinaryOperation : Element {
    enum Type { addition, subtraction }   m_type;
    shared_ptr<Element> m_lhs, m_rhs;

    int eval() const {
        if (m_type == addition) return m_lhs->eval() + m_rhs->eval();
        return m_lhs->eval() - m_rhs->eval();
    }
};

shared_ptr<Element> parse(vector<Token> const& tokens) {
    auto result = make_unique<BinaryOperation>();

    for (auto it = tokens.begin(); it!=tokens.end(); it++) {
        switch (it->m_type) {
            //normal expression
            case Token::integer:
                if (!result->m_lhs) result->m_lhs = make_shared<Integer>(stoi(it->m_text));
                else result->m_rhs = make_shared<Integer>(stoi(it->m_text));
                break;

            case Token::plus: result->m_type = BinaryOperation::addition; break;
            case Token::minus: result->m_type = BinaryOperation::subtraction; break;

            //sub expression
            case Token::lparen:
                auto rparen = find_if(it, tokens.end(), [](auto& token) {
                    return token.m_type == Token::rparen;
                });

                vector<Token>  subexpression(it + 1, rparen);
                if (!result->m_lhs) result->m_lhs = parse(subexpression);
                else result->m_rhs = parse(subexpression);

                it = rparen;
                break;
                /* ----------------------------------------------------- */
        }
    }
    return result;
}
#endif //DESIGN_PATTERN_19_INTERPRETER_PATTERN_2_H
