#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book{
    private : 
    string nameBook;
    string nameAuthur;
    int numberBook;
    public :
    Book(){}
    Book (string nameBook, string nameAuthur, int numberBook){
        this -> nameBook = nameBook;
        this -> nameAuthur = nameAuthur;
        this -> numberBook = numberBook;
    }
    void display(){
        cout << "nameBook: " << this->nameBook << endl;
        cout << "nameAuthur: "  << this->nameAuthur << endl;
        cout << "numberBook: "  << this->numberBook<< endl;
    }
    int getNumberBook(){
        return this -> numberBook;
    }
    string getNameBook(){
        return this -> nameBook;
    }
    string getNameAuthur(){
        return this -> nameAuthur;
    }
};
class Person {
    private :
     string name;
     int age;
     string add;
     vector <Book> vb;
    public :
    Person (){}
    Person (string name,int age, string add,vector <Book> vb)
    : name(name), age(age),vb(vb){}
     string getName(){
        return name;
     }
     int getAge(){
        return age;
     }
    string getAdd(){
        return add;
    }
    vector <Book> getVb(){
        return vb;
    }
    virtual long moneyPay() =0;
    virtual void display(){
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "add: " << add << endl;
        cout << "List Book Borrowed:" << endl;
        for (int i =0; i< vb.size(); i++){
            cout << "Cuon sach: %d" << i << endl;
            vb[i].display();
        }
    }
    static void sortPersonAge(vector <Person *> &vt){
          for (int i =0; i< vt.size()-1; i++){
              for (int j =0; j< vt.size(); j++){
                if (vt[i]->getAge() > vt[j]->getAge()){
                    swap (vt[i], vt[j]);
                }
            }
        }
    }
    static vector<int> getListAge(vector < Person*>vt){
        vector <int> str;
    }
};
