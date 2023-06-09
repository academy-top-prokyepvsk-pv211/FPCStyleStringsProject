﻿#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

bool CStrCmp(char* lstr, char* rstr);
void CStrSwap(char*& lstr, char*& rstr);

void CStyleExample()
{
    //int arr1[]{ 21, 12, 53, 84 };

    //cout << sizeof(arr1) << "\n";

    //char ch = 'a';
    //cout << sizeof(ch) << "\n";

    //char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    //char str2[] = "Hello";
    //cout << sizeof(str1) << " " << str1 << "\n";
    //cout << sizeof(str2) << " " << str2 << "\n";

    //char* str3 = new char[strlen("Hello world") + 1];
    //strcpy_s(str3, strlen("Hello world") + 1, "Hello world");
    ////strcpy(str3, "Hello world");
    //cout << strlen(str3) << " " << str3 << "\n";

    ////strcpy(str3, "Hello world, hello people");
    //strncpy_s(str3, 13, "Hello world, hello people", 12);
    //cout << str3 << "\n"; // "Hello world,"

    //char* str4 = new char;
    //strncpy_s(str4, 6, str3 + 6, 5);
    //cout << str4 << "\n";

    //char* n1 = new char[4] { "Bob" };
    //char* n2 = new char[4] { "Joe" };
    //cout << n1 << " " << n2 << "\n";
    //CStrSwap(n1, n2);
    //cout << n1 << " " << n2 << "\n";

    //char* s1 = new char;
    //strcpy(s1, "Hello");

    //char* s2 = new char;
    //strcpy(s2, " world");

    //strcat(s1, s2);

    //cout << s1 << "\n"; // "Hello world"
    //char sym = 'o';
    //char* fchar = strchr(s1, sym);
    //if (fchar)
    //    cout << fchar << "\n";

    //char word[] = "ll";
    //fchar = strstr(s1, word);
    //if (fchar)
    //    cout << fchar << "\n";

    //char* s2 = new char;
}

void CStyleStringSort()
{
    /*int userCount{ 5 };
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
        cout << users[i] << "\n";*/
}

void CStrSubstring(char*& dest, const char* src, int position, int size);

void CStrReplace(char*& dest, char* src, const char* oldStr, const char* newStr);

int main()
{
    // CStyleExample();
    // CStyleStringSort();

    char* str;
    char cstr[] = "How to Learn the C++ Programming Language";
    char cstr2[] = "I love lang C++, and lang C++ is good, but C++ and C# actuality";
    
    /*
    char* begin = strstr(cstr, "the");
    char* end = strstr(cstr, "Lan");
    
    int indexStart = begin - cstr;
    int size = end - begin - 1;

    CStrSubstring(str, cstr, indexStart, size); // s2 = lo wor
    cout << str << "\n";

    char* str2;

    CStrSubstring(str2, str, 5, 5);

    cout << str2 << "\n";
    */

    CStrReplace(str, cstr2, "C++", ""); // s = "Helfr world";
    cout << str;
}



void CStrSubstring(char*& dest, const char* src, int position, int size)
{
    //if (dest) delete[] dest;
    if (position + size > strlen(src))
        size -= position;

    dest = new char[size + 1];

    for (int i = 0; i < size; i++)
        dest[i] = src[i + position];
    dest[size] = '\0';
}

void CStrReplace(char*& dest, char* src, const char* oldStr, const char* newStr)
{
    int position{};
    int count{};
    char* find = src;
    while (true)
    {
        find = strstr(find, oldStr);
        if (find == nullptr)
            break;
        count++;
        find += strlen(oldStr);
    }

    int destSize = strlen(src) - count * (strlen(oldStr) - strlen(newStr));
    dest = new char[destSize + 1];

    int indexSrc{};
    int indexDest{};

    find = src;

    while (true)
    {
        find = strstr(find, oldStr);
        if (find == nullptr)
            break;
        
        int subSize = find - src - indexSrc;

        for (int i = 0; i < subSize; i++)
            dest[indexDest++] = src[indexSrc++];

        for (int i = 0; i < strlen(newStr); i++)
            dest[indexDest++] = newStr[i];

        find += strlen(oldStr);
        indexSrc += strlen(oldStr);
        //indexDest += strlen(newStr);
    }
    int endSize = strlen(src) - indexSrc;
    for(int i = 0; i < endSize; i++)
        dest[indexDest++] = src[indexSrc++];
    dest[indexDest] = '\0';
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