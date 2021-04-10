//
// Created by Tianyi Zhang on 4/9/21.
//

#include "19.Interpreter_pattern_2.h"
int main() {
    string expression{"(16-10)-(15+2)"};
    auto tokens = lex(expression);
    for (auto& t: tokens)
        cout << t << " ";
    cout<<endl;
    auto parsed = parse(tokens);
    cout << expression << " = " << parsed->eval() << endl;
    return EXIT_SUCCESS;
}