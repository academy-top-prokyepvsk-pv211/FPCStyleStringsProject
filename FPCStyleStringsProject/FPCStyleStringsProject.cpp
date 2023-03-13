#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

bool CStrCmp(char* lstr, char* rstr);
void CStrSwap(char*& lstr, char*& rstr);

void CStyleExample()
{
    int arr1[]{ 21, 12, 53, 84 };

    cout << sizeof(arr1) << "\n";

    char ch = 'a';
    cout << sizeof(ch) << "\n";

    char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char str2[] = "Hello";
    cout << sizeof(str1) << " " << str1 << "\n";
    cout << sizeof(str2) << " " << str2 << "\n";

    char* str3 = new char[strlen("Hello world") + 1];
    strcpy_s(str3, strlen("Hello world") + 1, "Hello world");
    //strcpy(str3, "Hello world");
    cout << strlen(str3) << " " << str3 << "\n";

    //strcpy(str3, "Hello world, hello people");
    strncpy_s(str3, 13, "Hello world, hello people", 12);
    cout << str3 << "\n"; // "Hello world,"

    char* str4 = new char;
    strncpy_s(str4, 6, str3 + 6, 5);
    cout << str4 << "\n";

    char* n1 = new char[4] { "Bob" };
    char* n2 = new char[4] { "Joe" };
    cout << n1 << " " << n2 << "\n";
    CStrSwap(n1, n2);
    cout << n1 << " " << n2 << "\n";
}

void CStyleStringSort()
{
    int userCount{ 5 };
    char** users = new char* [userCount];
    for (int i = 0; i < userCount; i++)
        users[i] = new char;

    strcpy_s(users[0], strlen("Leo") + 1, "Leo");
    strcpy_s(users[1], strlen("Jim") + 1, "Jim");
    strcpy_s(users[2], strlen("Bob") + 1, "Bob");
    strcpy_s(users[3], strlen("Tom") + 1, "Tom");
    strcpy_s(users[4], strlen("Tim") + 1, "Tim");

    for (int i = 0; i < userCount; i++)
        cout << users[i] << "\n";

    for (int i = 0; i < userCount - 1; i++)
    {
        for (int j = userCount - 1; j > i; j--)
            if (CStrCmp(users[j], users[j - 1]))
                CStrSwap(users[j], users[j - 1]);
    }

    cout << "\n";

    for (int i = 0; i < userCount; i++)
        cout << users[i] << "\n";
}

void CStrSubstring(char* dest, char* src, int position, int size);
void CStrReplace(char* dest, char* src, char* oldStr, char* newStr);
void CStrReplace(char* dest, char* src, const char* oldStr, const char* newStr);

int main()
{
    // CStyleExample();
    // CStyleStringSort();

    char* s1 = new char;
    strcpy(s1, "Hello");
    
    char* s2 = new char;
    strcpy(s2, " world");

    strcat(s1, s2);

    cout << s1 << "\n"; // "Hello world"
    char sym = 'o';
    char* fchar = strchr(s1, sym);
    if (fchar)
        cout << fchar << "\n";

    char word[] = "ll";
    fchar = strstr(s1, word);
    if (fchar)
        cout << fchar << "\n";

    char* s2 = new char;

    CStrReplace(s2, s1, "lo", "fr"); // s2 = "Helfr world";
    CStrSubstring(s2, s1, 3, 6); // s2 = lo wor
}

bool CStrCmp(char* lstr, char* rstr)
{
    return strcmp(lstr, rstr) < 0;
}

void CStrSwap(char*& lstr, char*& rstr)
{
    char* temp = new char;
    strcpy_s(temp, strlen(lstr) + 1, lstr);
    strcpy_s(lstr, strlen(rstr) + 1, rstr);
    strcpy_s(rstr, strlen(temp) + 1, temp);
}

void CStrSubstring(char* dest, char* src, int position, int size)
{

}
void CStrReplace(char* dest, char* src, char* oldStr, char* newStr)
{

}

void CStrReplace(char* dest, char* src, const char* oldStr, const char* newStr)
{

}