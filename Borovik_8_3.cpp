/* Borovik_8_3.cpp : Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор,
издательство, жанр).Создайте массив из 10 книг.Реализуйте для него следующие возможности :
Редактировать книгу
Печать всех книг
Поиск книг по автору
Поиск книги по названию
Сортировка массива по названию книг
Сортировка массива по автору
Сортировка массива по издательству
*/

#include <iostream>
using namespace std;
struct Book
{
    char NameBook[255];
    char AutorBook[255];
    char PublishingBook[255];
    char GenreBook[50];

};
Book Put()
{
    Book temporary{ 0 };
    cout << endl << "Добавление книги в библиотеку";
    cout << endl << "Введите название книги:"; 
    cin >> temporary.NameBook;
    cout << endl << "Введите автора книги:"; 
    cin >> temporary.AutorBook;
    cout << endl << "Введите издательство книги:"; 
    cin >> temporary.PublishingBook;
    cout << endl << "Введите жанр книги:"; 
    cin >> temporary.GenreBook;
    return temporary;
};
void Show(Book L) {
    cout << endl<< "---------------------------------------";
    cout << endl << "Название книги: " << L.NameBook;
    cout << endl << "Автор книги: " << L.AutorBook;
    cout << endl << "Издательство книги: " << L.PublishingBook;
    cout << endl << "Жанр книги: " << L.GenreBook;
    cout << endl << "---------------------------------------";
}
void Search(Book L[], int size) {
    cout << "Поиск книги: \n" << "1. Поиск по автору\n " << "2. Поиск по названию\n" << "Введите критерий поиска: ";
    int m{ 0 };
    cin >> m;
    switch (m)
    {
    case 1:
        cout << endl << "Введите автора книги которую необходимо найти: ";
        char a[255];
        cin >> a;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(L[i].AutorBook, a) == 0)
            {
                Show(L[i]);
            }
        }
        break;
    case 2:
        cout << endl << "Введите название книги которую необходимо найти: ";
        char n[255];
        cin >> n;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(L[i].NameBook, n) == 0)
            {
                Show(L[i]);
            }
        }
        break;
    default:
        break;
    }
}
void Change(Book L[], int size) {
    cout << endl << "Введите назание книги которую необходимо отредактировать: ";
    char n[255];
    cin >> n;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(L[i].NameBook, n) == 0)
        {
            L[i] = Put();
        }
    }
}
Book Sorting(Book L[], int size) {
    Book temporary{ 0 };
    cout << "Сортировка книг: \n" << "1. По названию\n " << "2. По автору\n" << "3. По издательству\n" << "Введите критерий поиска: ";
    int m{ 0 };
    cin >> m;
    switch (m)
    {
    case 1:
        cout << endl << "Введите название книги которую хотите видеть первой: ";
        char n[255];
        cin >> n;
        Book temp;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(L[i].NameBook, n) != 0)
            {
                temp = L[i]; 
                L[i] = L[i + 1];
                L[i + 1] = temp;
            }
        }
        break;
    case 2:
        cout << endl << "Введите автора книги которую хотите видеть первой: ";
        char a[255];
        cin >> a;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(L[i].AutorBook, a) == 0)
            {
                temp = L[i];
                L[i] = L[i + 1];
                L[i + 1] = temp;
            }
        }
        break;
    case 3:
        cout << endl << "Введите издательство книги которую хотите видеть первой: ";
        char p[255];
        cin >> p;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(L[i].PublishingBook, p) == 0)
            {
                temp = L[i];
                L[i] = L[i + 1];
                L[i + 1] = temp;
            }
        }
        break;
    default:
        break;
    }
    return temporary;
};
int main()
{
    setlocale(LC_ALL, "rus");
    int const size{ 10 };
    Book Library[size]{0};
    Show(Library[0]);
    for (int i = 0; i < size; i++)
    {
        Library[i] = Put();
    }
    for (int i = 0; i < size; i++)
    {
        Show(Library[i]);
    }
    Change(Library, size);
    for (int i = 0; i < size; i++)
    {
        Show(Library[i]);
    }
    Search(Library, size);

}

