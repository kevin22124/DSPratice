

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

queue<node*> qu;

void width1(node*);
void first1(node*);
void mid1(node*);
void last1(node*);

void width2(node*);
void first2(node*);
void mid2(node*);
void last2(node*);

void width3(node*);
void first3(node*);
void mid3(node*);
void last3(node*);

int main(void)
{
    // {1, 2, 3, 4, 5, 6, 7, }
    node* root, * p1, * p2, * p3, * p4, * p5, * p6, * p7;
    p1 = new node;
    p1->data = '1';
    root = p1;
    p2 = new node;
    p2->data = '2';
    p3 = new node;
    p3->data = '3';
    p4 = new node;
    p4->data = '4';
    p5 = new node;
    p5->data = '5';
    p6 = new node;
    p6->data = '6';
    p7 = new node;
    p7->data = '7';

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p4->left = NULL;
    p4->right = NULL;
    p5->left = NULL;
    p5->right = NULL;
    p6->left = NULL;
    p6->right = NULL;
    p7->left = NULL;
    p7->right = NULL;

    // {7, 6, 5, 4, 3, 2, 1, }
    node* aroot, * a1, * a2, * a3, * a4, * a5, * a6, * a7;
    a1 = new node;
    a1->data = '7';
    aroot = a1;
    a2 = new node;
    a2->data = '6';
    a3 = new node;
    a3->data = '5';
    a4 = new node;
    a4->data = '4';
    a5 = new node;
    a5->data = '3';
    a6 = new node;
    a6->data = '2';
    a7 = new node;
    a7->data = '1';

    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->right = a7;
    a4->left = NULL;
    a4->right = NULL;
    a5->left = NULL;
    a5->right = NULL;
    a6->left = NULL;
    a6->right = NULL;
    a7->left = NULL;
    a7->right = NULL;

    // {4, 6, 5, 2, 7, 1, 3, }
    node* broot, * b1, * b2, * b3, * b4, * b5, * b6, * b7;
    b1 = new node;
    b1->data = '4';
    broot = b1;
    b2 = new node;
    b2->data = '6';
    b3 = new node;
    b3->data = '5';
    b4 = new node;
    b4->data = '2';
    b5 = new node;
    b5->data = '7';
    b6 = new node;
    b6->data = '1';
    b7 = new node;
    b7->data = '3';

    b1->left = b2;
    b1->right = b3;
    b2->left = b4;
    b2->right = b5;
    b3->left = b6;
    b3->right = b7;
    b4->left = NULL;
    b4->right = NULL;
    b5->left = NULL;
    b5->right = NULL;
    b6->left = NULL;
    b6->right = NULL;
    b7->left = NULL;
    b7->right = NULL;
    cout << "寬度優先" << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的寬度優先：";
    width1(root);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的寬度優先：";
    width2(aroot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的寬度優先：";
    width3(broot);
    cout << endl;

    cout << "前序走訪" << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的前序走訪：";
    first1(root);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的前序走訪：";
    first2(aroot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的前序走訪：";
   first3(broot);
    cout << endl;

    
    cout << "中序走訪" << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的中序走訪：";
    mid1(root);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的中序走訪：";
    mid2(aroot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的中序走訪：";
    mid3(broot);
    cout << endl;

    cout << "後序走訪" << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的後序走訪：";
    last1(root);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的後序走訪：";
    last2(aroot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的後序走訪：";
    last3(broot);
    cout << endl;
}

// {1, 2, 3, 4, 5, 6, 7, }
void width1(node* now)
{
    qu.push(now);
    while (!qu.empty())
    {
        cout << qu.front()->data << " ";
        if (qu.front()->left != NULL)
        {
            qu.push(qu.front()->left);
        }
        if (qu.front()->right != NULL)
        {
            qu.push(qu.front()->right);
        }
        qu.pop();
    }
}


void first1(node* p)
{
    if (p)
    {
        cout << p->data << " ";
        first1(p->left);
        first1(p->right);
    }
}

void mid1(node* p)
{
    if (p)
    {
        mid1(p->left);
        cout << p->data << " ";
        mid1(p->right);
    }
}

void last1(node* p)
{
    if (p)
    {
        last1(p->left);
        last1(p->right);
        cout << p->data << " ";
    }
}

// {7, 6, 5, 4, 3, 2, 1, }
void width2(node* now)
{
    qu.push(now);
    while (!qu.empty())
    {
        cout << qu.front()->data << " ";
        if (qu.front()->left != NULL)
        {
            qu.push(qu.front()->left);
        }
        if (qu.front()->right != NULL)
        {
            qu.push(qu.front()->right);
        }
        qu.pop();
    }
}

void first2(node* a)
{
    if (a)
    {
        cout << a->data << " ";
        first2(a->left);
        first2(a->right);
    }
}

void mid2(node* a)
{
    if (a)
    {
        mid2(a->left);
        cout << a->data << " ";
        mid2(a->right);
    }
}

void last2(node* a)
{
    if (a)
    {
        last2(a->left);
        last2(a->right);
        cout << a->data << " ";
    }
}

// {4, 6, 5, 2, 7, 1, 3, }
void width3(node* now)
{
    qu.push(now);
    while (!qu.empty())
    {
        cout << qu.front()->data << " ";
        if (qu.front()->left != NULL)
        {
            qu.push(qu.front()->left);
        }
        if (qu.front()->right != NULL)
        {
            qu.push(qu.front()->right);
        }
        qu.pop();
    }
}

void first3(node* b)
{
    if (b)
    {
        cout << b->data << " ";
        first3(b->left);
        first3(b->right);
    }
}

void mid3(node* b)
{
    if (b)
    {
        mid3(b->left);
        cout << b->data << " ";
        mid3(b->right);
    }
}

void last3(node* b)
{
    if (b)
    {
        last3(b->left);
        last3(b->right);
        cout << b->data << " ";
    }
}