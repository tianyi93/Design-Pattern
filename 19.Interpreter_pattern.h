//
// Created by Tianyi Zhang on 4/4/21.
//

#ifndef DESIGN_PATTERN_INTERPRETER_PATTERN_H
#define DESIGN_PATTERN_INTERPRETER_PATTERN_H
#include <string>
#include <memory>
/*
   Interpreter Design Pattern is a Behavioural Design Pattern which is a component
   that processes structured text data by turning it into separate lexical tokens(lexing) and then interpreting sequences of tokens(parsing)
*/

/*
 Benefits of Interpreter Design Pattern
    It’s easy to change and extend the grammar. Because classes used to represent grammar rules, we can use inheritance to change or extend the grammar.
    Implementing the grammar is easy, too. As each symbol represents a token that essentially a class. To add a new symbol you need to create a new class.
 */
struct Expression{
    virtual bool interpreter(std::string const& con) = 0;
};

struct TerminalExpression : public Expression{
    TerminalExpression(std::string const& data) : data_(data){}

    bool interpreter(std::string const& con) override{
        if(con.find(data_) != std::string::npos)
            return true;
        else
            return false;
    }
private:
    std::string data_;
};

struct OrExpression : public Expression{
    OrExpression(
            std::shared_ptr<Expression> expr1,
            std::shared_ptr<Expression> expr2): expr1_(expr1), expr2_(expr2){};
    bool interpreter(std::string const& con) override{
        return expr1_->interpreter(con) || expr2_->interpreter(con);
    }

private:
    std::shared_ptr<Expression> expr1_;
    std::shared_ptr<Expression> expr2_;
};

struct AndExpression : public Expression{
    AndExpression(
            std::shared_ptr<Expression> expr1,
            std::shared_ptr<Expression> expr2): expr1_(expr1), expr2_(expr2){};
    bool interpreter(std::string const& con) override{
        return expr1_->interpreter(con) && expr2_->interpreter(con);
    }

private:
    std::shared_ptr<Expression> expr1_;
    std::shared_ptr<Expression> expr2_;
};
#endif //DESIGN_PATTERN_INTERPRETER_PATTERN_H
