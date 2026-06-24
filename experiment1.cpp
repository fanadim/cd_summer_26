#include <iostream>
using namespace std;

void checkNumericConstant(char input[])
{
    int isNumeric = 1;

    for (int i = 0; input[i] != '\0'; i++)
    {
        int asciiVal = input[i];

        if (asciiVal < 48 || asciiVal > 57)
        {
            isNumeric = 0;
        }
    }

    if (isNumeric == 1)
    {
        cout << "Result: Numeric Constant" << endl;
    }
    else
    {
        cout << "Result: Not Numeric" << endl;
    }
}

void findOperators(char exp[])
{
    bool found = false;
    int count = 1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||
            exp[i] == '/' || exp[i] == '%' || exp[i] == '=')
        {
            cout << "operator" << count << ": " << exp[i] << endl;
            count++;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Operator Found" << endl;
    }
}

void checkComment(char str[])
{
    if (str[0] == '/' && str[1] == '/')
    {
        cout << "Single Line Comment" << endl;
    }
    else if (str[0] == '/' && str[1] == '*')
    {
        cout << "Multiple Line Comment" << endl;
    }
    else
    {
        cout << "Not a Comment" << endl;
    }
}

void checkIdentifier(char s[])
{
    int i;
    if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z') || s[0] == '_'))
    {
        cout << "Invalid Identifier" << endl;
        return;
    }

    for (i = 1; s[i] != '\0'; i++)
    {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
        {
            cout << "Invalid Identifier" << endl;
            return;
        }
    }

    if (cin.peek() == ' ')
    {
        cout << "Invalid Identifier" << endl;
        return;
    }

    cout << "Valid Identifier" << endl;
}

void findAverage(int arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double average = sum / size;
    cout << "Average value of the elements: " << average << endl;
}

void findMinMax(int arr[], int size)
{
    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;
}

void concatenateName(char firstName[], char lastName[])
{
    char fullName[100];
    int i = 0, j = 0;

    while (firstName[i] != '\0')
    {
        fullName[i] = firstName[i];
        i++;
    }

    fullName[i] = ' ';
    i++;

    while (lastName[j] != '\0')
    {
        fullName[i] = lastName[j];
        i++;
        j++;
    }

    fullName[i] = '\0';

    cout << "Full name = \"" << fullName << "\"" << endl;
}

int main()
{

    cout << "Question 1:" << endl;
    char input[50];
    cout << "Enter Input: ";
    cin >> input;

    checkNumericConstant(input);

    cout << endl;

    cout << "Question 2:" << endl;
    char exp[100];
    cout << "Enter Expression: ";
    cin >> exp;
    findOperators(exp);

    cout << endl;

    cout << "Question 3:" << endl;
    char comment[100];
    cout << "Enter Comment: ";
    cin >> comment;
    checkComment(comment);

    cout << endl;

    cout<< "Question 4:"<<endl;
    char s[50];
    cout << "Enter an identifier: ";
    cin >> s;
    checkIdentifier(s);

    cin.ignore(100, '\n');

    cout << endl;

    cout << "Question 5:" << endl;

    int size1;
    cout << "Enter the number of elements: ";
    cin >> size1;

    int arr1[100];
    cout << "Enter " << size1 << " integers: ";
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    findAverage(arr1, size1);

    cout << endl;

    cout << "Question 6:" << endl;

    int size2;
    cout << "Enter the number of elements: ";
    cin >> size2;

    int arr2[100];
    cout << "Enter " << size2 << " integers: ";
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    findMinMax(arr2, size2);

    cout << endl;

    cout<< "Question 7:"<<endl;
    char firstName[50];
    char lastName[50];

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;

    concatenateName(firstName, lastName);

    return 0;
}
