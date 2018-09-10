//
// Лабораторная рвбота №2. Деревья
// tree.h
//
#pragma once

// Описание узла дерева:
//     tree::datatype - тип данных дерева;
//     data - значение в узле дерева;
//     left - укзатель на левое поддерево;
//     right - указатель на правое поддерево.
struct tree
{
    typedef int datatype;
    datatype data;
    tree *left;
    tree *right;
};

// Функция создания дерева.
// Данные вводятся с конслои.
// Входные параметры:
//     count - количество элементов дерева.
// Возвращает указатель на корневой элемент дерева.
tree *get_tree(const size_t count);

// Функция вставки значения в неупорядоченное дерево.
// Входные параметры:
//     root - указатель на корень дерева;
//     x - вставляемое значение.
void insert(tree *&root, tree::datatype x);

// Функция удаления дерева.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
// root == nullptr после выполнения этой функции.
void delete_tree(tree *&root);

// Функция вывода дерева на консоль.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
void print_tree(const tree *root, size_t space = 0);

// Функция вычисления количества листьев в дереве.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
size_t leaves_count(const tree *root);

// Функция вычисляет глубинц дерева
//  root - указатель на корневой элемент дерева.
size_t depth_tree (tree *root);

// Функция опред количество узлов на задоной глубине 
size_t knot_tree(tree *root, size_t i, size_t level = 1);

// Фунция определят ширину дерева
size_t fat_tree(tree *root);

// Копия дерева
void coppy(tree *  root, tree *&  new_root);

// проверка на равенство 
bool equally(tree *  root, tree *  new_root);


// LAb_2

//Дерево поиска
tree * tree_p(const size_t count);

//Вывод дерева по убыванию (1) возрастанию(0)
void vivod(tree *root, bool a=1);

//Поиск заданого значения 
tree * google(tree *root, int a);

//Поиск с включением (при отсутцтвие добовляет элемент)
tree * googleCtrV (tree *&root, int a);


//удаление первого задоного элемента из дерева
void googledelet(tree *&root, int a);