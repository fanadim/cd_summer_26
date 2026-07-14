#include <iostream>
#include <fstream>
#include <set>
using namespace std;

void tokenize(string input, ofstream& output, set<string>& duplicates)
{
    string operators[] = {"+", "-", "*", "/", "<<", "=", "!"};
    char punctuations[] = {';', ',', '(', ')', '{', '}', '[', ']'};
    string keywords[] = {"int", "float", "double", "string", "void", "main", "cout", "cin", "return"};

    int opCount = 1, puncCount = 1, keyCount = 1, idCount = 1, numCount = 1;

    string token = "";

    for (size_t i = 0; i <= input.length(); i++)
    {
        bool separator = false;
        if (i < input.length()) {
            for (int j = 0; j < 8; j++) {
                if (input[i] == punctuations[j] || input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
                    separator = true;
                    break;
                }
            }
            if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '=') {
                separator = true;
            }
        }

        if (i == input.length() || separator)
        {
            if (token != "")
            {
                if (duplicates.find(token) == duplicates.end())
                {
                    bool found = false;

                    for (int j = 0; j < 9; j++)
                    {
                        if (token == keywords[j])
                        {
                            output << "\n    " << token << " = " << "Keyword" << keyCount++;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            if (token == operators[j])
                            {
                                output << "\n    " << token << " = "<< "Operator" << opCount++;
                                found = true;
                                break;
                            }
                        }
                    }

                    if (!found && token.length() == 1)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (token[0] == punctuations[j])
                            {
                                output << "\n    " << token << " = " << "Punctuation" << puncCount++;
                                found = true;
                                break;
                            }
                        }
                    }

                    if (!found)
                    {
                        bool numeric = true;
                        for (size_t j = 0; j < token.length(); j++)
                        {
                            if (!((token[j] >= '0' && token[j] <= '9') || token[j] == '.'))
                            {
                                numeric = false;
                                break;
                            }
                        }

                        if (numeric)
                        {
                            output << "\n    " << token << " = " << "Numeric Constant" << numCount++;
                            found = true;
                        }
                    }

                    if (!found)
                    {
                        bool identifier = true;

                        if (!((token[0] >= 'A' && token[0] <= 'Z') ||
                              (token[0] >= 'a' && token[0] <= 'z') || token[0] == '_'))
                        {
                            identifier = false;
                        }

                        for (size_t j = 1; j < token.length(); j++)
                        {
                            if (!((token[j] >= 'A' && token[j] <= 'Z') ||
                                  (token[j] >= 'a' && token[j] <= 'z') ||
                                  (token[j] >= '0' && token[j] <= '9') || token[j] == '_'))
                            {
                                identifier = false;
                                break;
                            }
                        }

                        if (identifier)
                        {
                            output << "\n    " << token << " = " << "Identifier" << idCount++;
                        }
                        else
                        {
                            if (token[0] != '"') {
                                output << "\n    " << "Lexical Error: " << token;
                            }
                        }
                    }

                    duplicates.insert(token);
                }

                token = "";
            }


            if (i < input.length() && input[i] != ' ' && input[i] != '\t' && input[i] != '\n') {
                string lexeme = "";
                lexeme += input[i];

                if (input[i] == '<' && i + 1 < input.length() && input[i+1] == '<') {
                    lexeme = "<<";
                    i++;
                }

                if (duplicates.find(lexeme) == duplicates.end())
                {
                    bool matched = false;
                    for (int j = 0; j < 8; j++) {
                        if (lexeme[0] == punctuations[j]) {
                            output << "\n    " << lexeme << " = " << "Punctuation" << puncCount++;
                            matched = true;
                            break;
                        }
                    }
                    if (!matched) {
                        for (int j = 0; j < 7; j++) {
                            if (lexeme == operators[j]) {
                                output << "\n    " << lexeme << " = " << "Operator" << opCount++;
                                matched = true;
                                break;
                            }
                        }
                    }

                    if (matched) {
                        duplicates.insert(lexeme);
                    }
                }
            }
        }
        else
        {
            token += input[i];
        }
    }
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    int currentLine = 1;

    set<string> inputTokens;

    output << "Tokenization:" << endl;

    while (getline(input, line))
    {
        if (!line.empty()) {
            output << "\nLine " << currentLine << ":";
            tokenize(line, output, inputTokens);
            output << endl;
        }
        currentLine++;
    }

    cout << "Successful." << endl;

    input.close();
    output.close();
    return 0;
}

