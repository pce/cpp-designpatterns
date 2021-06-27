// g++ -std=c++11 calculator.cpp
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Token {
  enum Type { integer, plus, minus, mul, div, lparen, rparen } type;
  string text;

  Token(Type type, const string& text) : type(type), text(text) {}

  friend ostream& operator<<(ostream& os, const Token& token) {
    os << " " << token.text << " ";
    return os;
  }
};

std::string parse(vector<Token> tokens) {
  // ast
  ostringstream buffer;

  for (vector<Token>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
    buffer << it->text << "<";
    buffer << it->type << ">";
    // buffer << *it;
  }

  return buffer.str();
}

vector<Token> tokenize(const string& input) {
  // lex
  vector<Token> res;
  for (int i = 0; i < input.size(); i++) {
    switch (input[i]) {
      case '+':
        res.push_back(Token{Token::plus, "+"});
        break;
      case '-':
        res.push_back(Token{Token::minus, "-"});
        break;
      case '*':
        res.push_back(Token{Token::mul, "*"});
        break;
      case '/':
        res.push_back(Token{Token::div, "/"});
        break;
      case '(':
        res.push_back(Token{Token::lparen, "("});
        break;
      case ')':
        res.push_back(Token{Token::rparen, ")"});
        break;
      default:
        ostringstream buffer;
        buffer << input[i];
        for (int j = i + 1; j < input.size(); j++) {
          if (isdigit(input[j])) {
            buffer << input[j];
            ++i;
          } else {
            res.push_back(Token{Token::integer, buffer.str()});
            break;
          }
        }
        break;
    }
  }
  return res;
}

int main() {
  string input{"8 + (23 + 45)"};

  auto res = parse(tokenize(input));

  cout << res;

  // auto calc = Calculator;

  return 1;
}
