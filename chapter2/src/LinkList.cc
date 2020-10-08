#include <iostream>
#define null 0
using namespace std;
struct LinkListNode {
  int data;
  LinkListNode *next;
};

struct LinkList {
  LinkListNode *head;
  int length = 0;
};

int main() {
  void Init_List(LinkList * &lnode, LinkListNode * &l);
  void Insert_List(LinkList * &lnode, LinkListNode * &l, LinkListNode * &p,
                   int index);
  void Get_List(LinkListNode * &l, LinkListNode * &p, int e);
  void Delete_List(LinkList * &lnode, LinkListNode * &l, LinkListNode * &p,
                   int index);
  void Change_Data(LinkListNode * &l, LinkListNode * &p, int index);
  void Print_List(LinkList * &lnode, LinkListNode * &l, LinkListNode * &p);
  void Reverse_List(LinkList * &lnode, LinkListNode * &l, LinkListNode * &p);
  LinkListNode *l = new LinkListNode;
  l->next = NULL;
  LinkListNode *p = new LinkListNode;
  LinkList *lnode = new LinkList;
  lnode->head = NULL;
  int index, command;
  int e, count;
  cout << "Please enter the command: " << endl
       << "(1)enter 1 to init a linklist;"
       << "(2)enter 2 to insert a data;" << endl
       << "(3)enter 3 to get a data;"
       << "(4)enter 4 to delete a data;" << endl
       << "(5)enter 5 to rplace a data;"
       << "(6)enter 6 to traverse a linklist;" << endl
       << "(7)enter 7 to print the linklist;"
       << "(8)enter 8 to quit;" << endl;
  do {
    cout << "Please enter the operate you want to start: ";
    cin >> command;
    if (command == 1) {
      Init_List(lnode, l);
    } else if (command == 2) {
      cout << "Please enter the position you want to insert: ";
      cin >> index;
      cout << "Please enter the count of data you want to input: ";
      cin >> count;
      for (int i = 0; i < count; ++i)
        Insert_List(lnode, l, p, index);
    } else if (command == 3) {
      cout << "Please enter the data you want to get: ";
      cin >> e;
      Get_List(l, p, e);
    } else if (command == 4) {
      cout << "Please enter the position you want to delete: ";
      cin >> index;
      Delete_List(lnode, l, p, index);
    } else if (command == 5) {
      cout << "Please enter the position of data you want to change: ";
      cin >> index;
      Change_Data(l, p, index);
    } else if (command == 6) {
      Reverse_List(lnode, l, p);
    } else if (command == 7)
      Print_List(lnode, l, p);
    cout << endl;
  } while (command != 8);
  delete p;
  delete l;
  delete lnode;
  return 0;
}

void Init_List(LinkList *&lnode, LinkListNode *&l) { lnode->head = l; }

void Insert_List(LinkList *&lnode, LinkListNode *&l, LinkListNode *&p,
                 int index) {
  LinkListNode *s = new LinkListNode;
  int count = 0;
  p = l;
  if (lnode->length == 0)
    index -= 1;
  while (count < (index - 1)) {
    p = p->next;
    ++count;
  }
  cout << "Please enter the data: ";
  cin >> s->data;
  cin.get();
  s->next = p->next;
  p->next = s;
  if (index == 2)
    cout << s->next->data << endl;
  ++lnode->length;
}

void Get_List(LinkListNode *&l, LinkListNode *&p, int e) {
  p = l;
  int i = 0, j = 0;
  do {
    if (p->next && (p->data != e)) {
      p = p->next;
      ++i;
    } else if (p->data == e)
      j = 1;
  } while (!j);
  if (j != 1)
    cout << "No such a data: " << endl;
  else
    cout << p->data << " on No." << i << " node." << endl;
}

void Delete_List(LinkList *&lnode, LinkListNode *&l, LinkListNode *&p,
                 int index) {
  LinkListNode *q = new LinkListNode;
  p = l;
  int count = 0;
  while (p && (count < (index - 1))) {
    p = p->next;
    ++count;
  }
  if (!p || (count > index - 1))
    cout << "Error" << endl;
  q = p->next;
  p->next = q->next;
  delete q;
  --lnode->length;
  if (!p->next)
    cout << "OK" << endl;
}

void Change_Data(LinkListNode *&l, LinkListNode *&p, int index) {
  p = l;
  for (int i = 0; i < index; ++i)
    p = p->next;
  cout << "Please enter the data you want to rplace: ";
  cin >> p->data;
}

void Print_List(LinkList *&lnode, LinkListNode *&l, LinkListNode *&p) {
  int k = 0;
  p = l;
  cout << "Here is the data: " << endl;
  while ((p->next != NULL) && (k < (lnode->length))) {
    p = p->next;
    cout << "#" << k + 1 << ": " << p->data << "\t";
    ++k;
  }
}

void Reverse_List(LinkList *&lnode, LinkListNode *&l, LinkListNode *&p) {
  LinkListNode *l1 = new LinkListNode;
  LinkListNode *q = new LinkListNode;
  q = l1;
  LinkListNode *t = new LinkListNode;
  p = l;
  p = p->next;
  t = l->next->next;
  for (int i = 0; i < (lnode->length); ++i) {
    p->next = q->next;
    q->next = p;
    p = t;
    if ((i < (lnode->length - 1)) && (t->next != NULL))
      t = t->next;
  }
  l->next = l1->next;
  delete l1;
}
