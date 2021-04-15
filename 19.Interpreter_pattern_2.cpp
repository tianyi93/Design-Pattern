//
// Created by Tianyi Zhang on 4/9/21.
//

#include "19.Interpreter_pattern_2.h"
void execute(string const& expression){
    auto tokens = lex(expression);
    for (auto& t: tokens)
        cout << t << " ";
    cout<<endl;
    auto parsed = parse(tokens);
    cout << expression << " = " << parsed->eval() << endl;
}
int main() {
    string expression{"(16-10)-(15+2)"};
    execute(expression);

    execute("3");
    execute("3*5-(2+6)");
    execute("5/3");
    return 0;
}