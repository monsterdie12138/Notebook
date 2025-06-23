#include <iostream>
#include <vector>
using namespace std;

class Subject;

class Observer
{
    public:
        virtual void update(Subject* s)=0;
};

class Subject
{
    public:
        void addObserver(Observer* o)
        {
            v.push_back(o);
        }
        void notify()
        {
            for(Observer* o:v)
            {
                o->update(this);
            }
        }
    private:
        vector<Observer*> v;
};

class ConcreteStringSubject : public Subject
{
    public:
        ConcreteStringSubject() {}
        const string &getValue() { return m_str; }
        void setValue(const string &s) { m_str = s; }
    private:
        string m_str;
};

class ConcreteIntSubject : public Subject
{
    public:
        ConcreteIntSubject() {}
        const int &getValue() { return m_int; }
        void setValue(const int &i) { m_int = i; }
    private:
        int m_int;
};

class ObserverLess : public Observer
{
    public:
        ObserverLess() {}
        virtual void update(Subject *pSubject)
        {
            ConcreteIntSubject *pIntSubject = static_cast<ConcreteIntSubject*>(pSubject);
            int v = pIntSubject->getValue();
            if (v < 40)
            cout << "True" << endl;
            else
                cout << "False" << endl;
        }
};

class ObserverIncrement : public Observer
{
    public:
        ObserverIncrement() {}
        virtual void update(Subject *pSubject)
        {
            ConcreteIntSubject *pIntSubject = static_cast<ConcreteIntSubject*>(pSubject);
            pIntSubject->setValue((int)((pIntSubject->getValue())*1.1));
            cout<<pIntSubject->getValue()<<endl;
        }
};

class ObserverAppend: public Observer
{
    public:
        ObserverAppend(){}
        virtual void update(Subject *pSubject)
        {
            ConcreteStringSubject *pStringSubject = static_cast<ConcreteStringSubject*>(pSubject);
            cout<<pStringSubject->getValue()<<" appended"<<endl;
        }
};

class ObserverTitle: public Observer
{
    public:
        ObserverTitle(){}
        virtual void update(Subject *pSubject)
        {
            ConcreteStringSubject *pStringSubject = static_cast<ConcreteStringSubject*>(pSubject);
            if(pStringSubject->getValue().compare("Manager")==0)
            {
                cout<<"True"<<endl;
            }
            else cout<<"False"<<endl;
        }
};

int main()
{
    // a object to store a string
    ConcreteStringSubject s1;
    // an observer to append a string "appended" to the subject and then print out the string
    ObserverAppend o1;
    // an observer to judge if the string is “Manager” or not and then print true or false
    ObserverTitle o2;
    s1.addObserver(&o1);
    s1.addObserver(&o2);
    s1.setValue("Employee");
    s1.notify(); // should update all the observers
    // a subject to store a int
    ConcreteIntSubject s2;
    // an observer to increase the value by 10 and then print out the value
    ObserverIncrement o3;
    // an observer to judge whether the value is less than 40 and then print the result is true //or false
    ObserverLess o4;
    s2.addObserver(&o3);
    s2.addObserver(&o4);
    s2.setValue(18);
    s2.notify(); // should update all the observer
    return 0;
}