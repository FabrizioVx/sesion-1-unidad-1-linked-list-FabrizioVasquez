#include <iostream>
#include <string>
#include "LinkedList.hpp"

int main() {

    //PUSH FRONT
    utec::first::LinkedList<int> linkedList0,linkedList00;
    utec::first::LinkedList<int> linkedList1,linkedList1v;
    utec::first::LinkedList<int> linkedList2,linkedList2v;
    utec::first::LinkedList<int> linkedList3;
    utec::first::LinkedList<int> linkedList4;
    utec::first::LinkedList<int> linkedList5;
    utec::first::LinkedList<int> linkedList6;
    std::vector<utec::first::LinkedList<string>> linkedList0001;



    for (size_t i = 0; i < 10 ; ++i) {
        linkedList00.push_front(i);
        linkedList1.push_front(i);
        linkedList2.push_front(i);
        linkedList3.push_front(i);
        linkedList4.push_front(i);
        linkedList5.push_front(i);

    }
    //Verificar PUSH FRONT
    assert(linkedList1.size() == 10);


    linkedList0.push_front(20);
    linkedList0.push_front(50);
    linkedList0.push_front(90);
    linkedList0.push_front(90);

    cout<<"ORIGINAL"<<endl;
    cout<<linkedList00;


    cout<<"PUSH_FRONT"<<endl;
    cout<<linkedList0;


    cout<<"PUSH_BACK"<<endl;
    linkedList1.push_back(29);
    linkedList1.push_back(80);

    cout<<linkedList1;


    cout<<"INSERT"<<endl;
    linkedList2.insert(2,500);
    cout<<linkedList2;


    cout<<"POP_FRONT"<<endl;
    linkedList3.pop_front();
    cout<<linkedList3;


    cout<<"POP_BACK"<<endl;
    linkedList4.pop_back();
    cout<<linkedList4;


    cout<<"ERASE"<<endl;
    linkedList5.erase(4,5);
    linkedList5.erase(2,7);
    cout<<linkedList5;


    linkedList6 = linkedList1;
    cout<<linkedList6<<endl;
    assert(linkedList6.size() == 10);


    for (size_t i = 0; i < 10 ; ++i) {
        linkedList2v.push_back(i);
    }
    cout<<"Push-Back"<<endl;
    cout<<linkedList2v;




    string result;
    for (size_t i = 9; i >= 0; --i) {
        result += to_string(linkedList1v.item(i)) + " ";
    }
    //Verificar
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");



    //POP FRONT
    for (size_t i = 0; i < 5; ++i) {
        linkedList1v.pop_front();
    }
    //Verificar POP FRONT
    assert(linkedList1v.size() == 5);



    for (size_t i = 0; i < 5; ++i) {
        linkedList1v.pop_front();
    }
    //Segunda Verificacion POP FRONT
    assert(linkedList1v.size() == 0);



    return 0;
}
