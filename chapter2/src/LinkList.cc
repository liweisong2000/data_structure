#include <iostream>
using namespace std;
struct LinkListNode {
  int data;
  LinkListNode *next;
};

struct LinkList {
  LinkListNode *head;
  int length;
};

int main() {
  void Init_List(LinkList * &l);
  void Insert_List(LinkList * &l, LinkListNode * &p, int index);
  void Get_List(LinkList * &l, LinkListNode * &p, int e);
  void Delete_List(LinkList * &l, LinkListNode * &p, int e);
  void Change_Data(LinkList * &l, LinkListNode * &p, int e);
  void Print_List(LinkList * &l, LinkListNode * &p);
  void Reverse_List(LinkList * &l, LinkListNode * &p);
  LinkListNode *p;
  LinkList *l;
  int index, command;
  int e, count;
  cout << "Here is the command: " << endl
       << "(1)enter 1 to init a linklist;"
       << "(2)enter 2 to insert a data;" << endl
       << "(3)enter 3 to get a data;"
       << "(4)enter 4 to delete a data;" << endl
       << "(5)enter 5 to replace a data;"
       << "(6)enter 6 to reverse a linklist;" << endl
       << "(7)enter 7 to print the linklist;"
       << "(8)enter 8 to quit;" << endl;
  do {
    cout << "Please enter the operate you want to start: ";
    cin >> command;
    if (command == 1) {
      Init_List(l);
    } else if (command == 2) {
      cout << "Please enter the position you want to insert: ";
      cin >> index;
      cout << "Please enter the count of data you want to input: ";
      cin >> count;
      for (int i = 0; i < count; ++i)
        Insert_List(l, p, index);
    } else if (command == 3) {
      cout << "Please enter the data you want to get: ";
      cin >> e;
      Get_List(l, p, e);
    } else if (command == 4) {
      cout << "Please enter the data you want to delete: ";
      cin >> e;
      Delete_List(l, p, e);
    } else if (command == 5) {
      cout << "Please enter the origin data: ";
      cin >> e;
      Change_Data(l, p, e);
    } else if (command == 6) {
      Reverse_List(l, p);
    } else if (command == 7)
      Print_List(l, p);
    cout << endl;
  } while (command != 8);

  for (int i = 0; i < l->length; ++i) {
    p = l->head;
    for (int j = 1; j < (l->length - i); ++j)
      p = p->next;
    delete p;
  }
  return 0;
}

void Init_List(LinkList *&l) {
  l->head = NULL;
  l->length = 0;
}

void Insert_List(LinkList *&l, LinkListNode *&p, int index) {
  LinkListNode *s = new LinkListNode;
  int count = 1;
  p = l->head;
  while (count < (index - 1)) {
    p = p->next;
    ++count;
  }
  cout << "Please enter the data: ";
  cin >> s->data;
  cin.get();
  if (index == 1) {
    s->next = p;
    l->head = s;
  } else {
    s->next = p->next;
    p->next = s;
  }
  ++l->length;
}

void Get_List(LinkList *&l, LinkListNode *&p, int e) {
  int i = 0;
  p = l->head;
  while ((p->data != e) && (p->next != NULL)) {
    p = p->next;
    ++i;
  }
  if (p->data != e)
    cout << "No such a data! " << endl;
  else
    cout << p->data << " on No." << i + 1 << " node." << endl;
}

void Delete_List(LinkList *&l, LinkListNode *&p, int e) {
  LinkListNode *q;
  q = l->head;
  p = l->head;
  while ((q->data != e) && (q->next != NULL))
    q = q->next;

  if (q->data != e)
    cout << "No such a data!" << endl;
  else if (q == l->head) {
    l->head = q->next;
    delete q;
  } else {
    while (p->next != q)
      p = p->next;
    p->next = q->next;
    delete q;
  }

  if (q->data != e) {
    cout << "Already delete!" << endl;
    --l->length;
  }
}

void Change_Data(LinkList *&l, LinkListNode *&p, int e) {
  p = l->head;
  while ((p->data != e) && (p->next != NULL))
    p = p->next;

  if (p->data != e)
    cout << "No such a data!" << endl;
  else {
    cout << "Please enter the new data: ";
    cin >> p->data;
    cin.get();
  }
}

void Reverse_List(LinkList *&l, LinkListNode *&p) {
  LinkListNode *q;
  LinkListNode *t;
  q = l->head;
  p = q->next;
  t = p->next;
  for (int i = 1; i < (l->length - 1); ++i) {
    p->next = q;
    q = p;
    p = t;
    t = t->next;
  }
  p->next = q;
  l->head = p;
}

void Print_List(LinkList *&l, LinkListNode *&p) {
  p = l->head;
  if (p == NULL)
    cout << "Empty list!" << endl;
  else {
    cout << "List data: " << endl;
    for (int j = 0; j < (l->length); ++j) {
      cout << "#" << j + 1 << ": " << p->data << "\t";
      p = p->next;
    }
  }
}
