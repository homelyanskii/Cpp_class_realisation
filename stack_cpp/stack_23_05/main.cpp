#include <iostream>
#include <locale.h>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <conio.h>

using namespace std;

 struct node
      {
       char n; //информационное поле узла
       node*next;
      };
 class Stack
 {
  public:
  node*head;
  Stack(){head = NULL;}
  //void CopyStack(node*&headnew,node*headold);
  //Stack(const Stack&ob); //конструктор копирования
// Рекурсивная функция, используемая в деструкторе (освобождение памяти)
  void DelStack();
  ~Stack(){DelStack();}
  void Push(char data);// Вставка элемента
  int Pop(char *data);
  void Look(node*wer);          //- Вывод на экран
 };

/*void Stack::CopyStack(node*&headnew,node*headold)
{
 if(headold->next!=0)
 {
   Push(headnew,(headold->next)->n);
   CopyStack(headnew,headold->next);
 }
}
Stack::Stack(const Stack&ob)
{
 if(ob.head==0)head=0;
 else {
       head=new node;
       head->n=ob.head->n;
       head->next=0;
       CopyStack(head,ob.head);
      }
}*/
void Stack::DelStack()
{
    if(head != NULL)
    {
        node *wer;
        wer = head;
        head = head->next;
        delete wer;
        DelStack();
    }
}

int Stack::Pop(char *data)
{
    if(head == NULL)
        return 1;

    *data = head->n;

    node *wer;
    wer = head;
    head = head->next;
    delete wer;
    return 0;
}

void Stack::Push(char data)
    {
            node *wer;
            wer=new node;
            wer->n=data;
            wer->next=head;
            head = wer;
    }
void Stack::Look(node*wer)
{
 if(wer!=0)
   {
    cout<<(" ")<<wer->n;
    Look(wer->next);
   }
}

int main()
{
        setlocale(LC_ALL,"russian");

        string buf;
        char check_ch = ' ';
        cout << "Введите строку скобок\n";
        cin >> buf;

        if(buf[0] == ']' || buf[0] == '}' || buf[0] == ')')
        {
            cout <<"Скобки установлены не верно!!!\n";
            return 0;
        }


        Stack st_1;

        for(int i=0; buf[i]!='\0'; i++)
        {
            if(buf[i] != '{' && buf[i] != '[' && buf[i] != '(' && buf[i] != '}' && buf[i] != ']' && buf[i] != ')')
                continue;

            if (buf[i] == '{' || buf[i] == '[' || buf[i] == '(')
            {
                st_1.Push(buf[i]);
            }
            else
            {
                if (st_1.Pop(&check_ch) == 1)
                {
                    cout << "Пустой стек\n";
                    return 0;
                }
                st_1.Pop(&check_ch);
                if((check_ch == '(' && buf[i] != ')') || (check_ch == '[' && buf[i] != ']') || (check_ch == '{' && buf[i] != '}'))
                {
                    cout << "Скобки установлены не верно!!!\n";
                    return 0;
                }
            }
        }

        if (st_1.Pop(&check_ch) == 1)
            cout << "Все верно!";
        else
            cout << "Скобки установлены не верно!!!\n";

        return 0;
}
