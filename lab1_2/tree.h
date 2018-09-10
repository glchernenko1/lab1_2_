//
// ������������ ������ �2. �������
// tree.h
//
#pragma once

// �������� ���� ������:
//     tree::datatype - ��� ������ ������;
//     data - �������� � ���� ������;
//     left - �������� �� ����� ���������;
//     right - ��������� �� ������ ���������.
struct tree
{
    typedef int datatype;
    datatype data;
    tree *left;
    tree *right;
};

// ������� �������� ������.
// ������ �������� � �������.
// ������� ���������:
//     count - ���������� ��������� ������.
// ���������� ��������� �� �������� ������� ������.
tree *get_tree(const size_t count);

// ������� ������� �������� � ��������������� ������.
// ������� ���������:
//     root - ��������� �� ������ ������;
//     x - ����������� ��������.
void insert(tree *&root, tree::datatype x);

// ������� �������� ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
// root == nullptr ����� ���������� ���� �������.
void delete_tree(tree *&root);

// ������� ������ ������ �� �������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
void print_tree(const tree *root, size_t space = 0);

// ������� ���������� ���������� ������� � ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
size_t leaves_count(const tree *root);

// ������� ��������� ������� ������
//  root - ��������� �� �������� ������� ������.
size_t depth_tree (tree *root);

// ������� ����� ���������� ����� �� ������� ������� 
size_t knot_tree(tree *root, size_t i, size_t level = 1);

// ������ ��������� ������ ������
size_t fat_tree(tree *root);

// ����� ������
void coppy(tree *  root, tree *&  new_root);

// �������� �� ��������� 
bool equally(tree *  root, tree *  new_root);


// LAb_2

//������ ������
tree * tree_p(const size_t count);

//����� ������ �� �������� (1) �����������(0)
void vivod(tree *root, bool a=1);

//����� �������� �������� 
tree * google(tree *root, int a);

//����� � ���������� (��� ���������� ��������� �������)
tree * googleCtrV (tree *&root, int a);


//�������� ������� �������� �������� �� ������
void googledelet(tree *&root, int a);