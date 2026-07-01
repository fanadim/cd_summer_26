#include <iostream>
using namespace std;

void tokenize(string input)
{
    string operators[] = {"+", "-", "*", "/", "<<", "=", "!"};
    char punctuations[] = {';', ',', '(', ')', '{', '}', '[', ']'};
    string keywords[] = {"int", "float", "double", "string", "void", "cout", "cin", "main"};

    int opCount = 1, puncCount = 1, keyCount = 1;
    int idCount = 1, numCount = 1;

    int n = input.length();
    int start = 0, end = 0;

    while (end <= n)
    {
        if (end == n || input[end] == ' ')
        {
            if (start != end)
            {
                string token = input.substr(start, end - start);

                bool found = false;

                for (int j = 0; j < 5; j++)
                {
                    if (token == keywords[j])
                    {
                        cout << "Keyword" << keyCount++ << " = " << token << endl;
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (token == operators[j])
                        {
                            cout << "Operator" << opCount++ << " = " << token << endl;
                            found = true;
                            break;
                        }
                    }
                }

                if (!found && token.length() == 1)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (token[0] == punctuations[j])
                        {
                            cout << "Punctuation" << puncCount++ << " = " << token << endl;
                            found = true;
                            break;
                        }
                    }
                }

                if (!found)
                {
                    bool numeric = true;
                    for (char c : token)
                    {
                        if (!((c >= '0' && c <= '9') || c == '.'))
                        {
                            numeric = false;
                            break;
                        }
                    }

                    if (numeric)
                    {
                        cout << "Numeric Constant" << numCount++ << " = " << token << endl;
                        found = true;
                    }
                }

                if (!found)
                {
                    bool identifier =
                        ((token[0] >= 'A' && token[0] <= 'Z') ||
                         (token[0] >= 'a' && token[0] <= 'z'));

                    for (int j = 1; j < token.length() && identifier; j++)
                    {
                        if (!((token[j] >= 'A' && token[j] <= 'Z') ||
                              (token[j] >= 'a' && token[j] <= 'z') ||
                              (token[j] >= '0' && token[j] <= '9')))
                        {
                            identifier = false;
                        }
                    }

                    if (identifier)
                        cout << "Identifier" << idCount++ << " = " << token << endl;
                    else
                        cout << "Lexical Error: " << token << endl;
                }
            }

            start = end + 1;
        }

        end++;
    }
}

int main()
{
    string input = "cout << 20 + a * 60.5";
    tokenize(input);

    return 0;
}
