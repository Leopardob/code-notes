////////////////////////////////////////////////////////////////////////////////////////////////////
//FACTORY
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "IMyObject.h"
class Factory
{
public:
    std::shared_ptr<IMyClass> CreateObject()
    {
        return std::shared_ptr<IMyClass>(new MyClass());
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//BUILDER
////////////////////////////////////////////////////////////////////////////////////////////////////

class MyBaseClass;
class Builder
{
public:
    void BuildObject(MyBaseClass& object)
    {
        object.BuildSomething();
        object.BuildSomethingElse(m_value);
    }
};

int main()
{
    Builder myBuilder;

    MyBaseClass* object1 = new MyDerivedClass1();
    myBuilder.BuildObject(object1);

    MyBaseClass* object2 = new MyDerivedClass2();
    myBuilder.BuildObject(object2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//PROTOTYPE
////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<MyClass> m_templates;
m_template.push_back(MyClass(a,b));
m_template.push_back(MyClass(c,d));

MyClass object1 = m_templates[0];
MyClass object2 = m_templates[1];

////////////////////////////////////////////////////////////////////////////////////////////////////
//SINGLETON
////////////////////////////////////////////////////////////////////////////////////////////////////

class MyClass : boost::noncopyable
{
public:
    static MyClass* GetPointer()
    {
        if(!sm_singleton)
        {
            sm_singleton.reset(new MyClass());
        }
        return sm_singleton.get();
    }
private:
    static std::unique_ptr<MyClass> sm_singleton;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//PIMPL
////////////////////////////////////////////////////////////////////////////////////////////////////

// Header File
class MyClass
{
public:
   void MyMethod();
private:

   class MyClassPimpl; 
   std::unique_ptr<MyClassPimpl> m_pimpl;
};

// CPP File
class MyClass::MyClassPimpl
{
public:
   void MyMethod();
};
 
MyClass::MyClass():  
    m_pimpl(new MyClassPimpl())
{
}

void MyClass::MyMethod()
{
   m_pimpl->MyMethod();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//DECORATOR
////////////////////////////////////////////////////////////////////////////////////////////////////

class MyBaseClass 
{
public:
    virtual void MyMethod() = 0;
};

class MyDerivedClass: public MyBaseClass 
{
public:
    virtual void MyMethod() override;
};

class Decorator: public MyBaseClass
{
private:
    MyBaseClass* inner;
public:
    Decorator(MyBaseClass* object)     { inner = object; }
    virtual ~Decorator()               { delete inner; }
    virtual void MyMethod() override   { inner->MyMethod(); }
};

// Derived object add-ons
class X: public Decorator
{
public:
    X(MyBaseClass* object): Decorator(object){}
    virtual void MyMethod() override { Decorator::MyMethod(); }
};

class Y: public Decorator 
{
public:
    Y(MyBaseClass* object): Decorator(object){}
    virtual void MyMethod() override { Decorator::MyMethod(); }
};

class Z: public Decorator
{
public:
    Z(MyBaseClass* object): Decorator(object){}
    virtual void MyMethod() override { Decorator::MyMethod(); }
};

int main() 
{ 
    // Each class holds MyBaseClass* of next object
    // Creation order right to left
    MyBaseClass* x = new X(new MyDerivedClass());
    MyBaseClass* yx = new Y(new X(new MyDerivedClass()));
    MyBaseClass* xzy = new X(new Z(new Y(new MyDerivedClass())));

    x->MyMethod();    // calls x, Decorator, MyDerivedClass
    yx->MyMethod();   // calls y, x, Decorator, MyDerivedClass
    xzy->MyMethod();  // calls x, z, y, Decorator, MyDerivedClass
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//FLYWEIGHT
////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::shared_ptr<MyClass>> m_templates;
m_template.push_back(std::shared_ptr<MyClass>(new MyClass(a,b)));
m_template.push_back(std::shared_ptr<MyClass>(new MyClass(c,d)));

std::shared_ptr<MyClass> object1 = m_templates[0];
std::shared_ptr<MyClass> object2 = m_templates[1];

////////////////////////////////////////////////////////////////////////////////////////////////////
//COMPOSITE
////////////////////////////////////////////////////////////////////////////////////////////////////

class Composite
{
public:

    void DrawComponents() 
    {
        for(Component& component : m_components)
        {
            component->Draw();
        }
    }

private:
    std::vector<Component> m_components;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//PROXY
////////////////////////////////////////////////////////////////////////////////////////////////////

class Proxy
{
    void DoSomething()
    {
        m_innerProxy->DoSomething();
    }

private:
    InnerProxy* m_innerProxy;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//FACADE
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//ADAPTER
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//BRIDGE
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//MEMENTO
////////////////////////////////////////////////////////////////////////////////////////////////////

class Memento
{
public:

    void Undo()
    {
        if(!m_states.Empty())
        {
            m_currentState = m_states[m_states.size()-1];
            m_states.pop_back();
        }
    }

    void ChangeState()
    {
        if(m_states.Size() > MAX_SIZE)
        {
            m_states.pop_front();
        }
        m_states.push_back(m_currentState);
        m_currentState.myInt++;
    }

private:
    std::deque<State> m_states;
    State m_currentState;
};


////////////////////////////////////////////////////////////////////////////////////////////////////
//ITERATOR
////////////////////////////////////////////////////////////////////////////////////////////////////

for(std::vector<int>::iterator itr = myVector.begin(); itr != myVector.end(); ++itr)
{
    itr->myMethod();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//INTERPRETER
////////////////////////////////////////////////////////////////////////////////////////////////////

class One : public Interpreter
{
    void Interpret(std::string str)
    {
        if(str.find("one") != std::string::npos)
        {
            DoSomething();
        }
    }
};

class Two : public Interpreter
{
    void Interpret(std::string str)
    {
        if(str.find("two") != std::string::npos)
        {
            DoSomething();
        }
    }
};

int main()
{
    std::vector<std::unique_ptr<Interpreter>> myContainer;
    myContainer.push_back(std::unique_ptr<Alphabet>(new ClassA));
    myContainer.push_back(std::unique_ptr<Alphabet>(new ClassB));
    myContainer.push_back(std::unique_ptr<Alphabet>(new ClassA));

    std::string myString("onetwofive");
    for(auto& interpreter : myContainer)
    {
        interpreter->Interpret(myString);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//TEMPLATE
////////////////////////////////////////////////////////////////////////////////////////////////////

class MyBaseClass
{
    virtual void Step1() = 0;
    virtual void Step2() = 0;
    virtual void Step3() = 0;

    void MyAlgorithm()
    {
        Step1();
        Step2();
        Step3();
    }
};

class MyClass1 : public MyBaseClass
{
    virtual void Step1() override {}
    virtual void Step2() override {}
    virtual void Step3() override {}
};

class MyClass2 : public MyBaseClass
{
    virtual void Step1() override {}
    virtual void Step2() override {}
    virtual void Step3() override {}
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//COMMAND
////////////////////////////////////////////////////////////////////////////////////////////////////

std::function<void(void)> command = std::bind(&MyClass::MyFunction, this, myInt);

////////////////////////////////////////////////////////////////////////////////////////////////////
//CHAIN OF RESPONSIBILITY
////////////////////////////////////////////////////////////////////////////////////////////////////

class ChainMember
{
public:
    void SetSuccesser(ChainMember* member)
    {
        m_successor = member;
    }

    void ProcessEvent(Event& e)
    {
        if(e.Member != this && m_successor)
        {
            m_successor->ProcessEvent(e);
        }
    }
private:
    ChainMember* m_successor;
};


int main()
{
    ChainMember* member1 = new ChainMember();
    ChainMember* member2 = new ChainMember();
    ChainMember* member3 = new ChainMember();

    member1->SetSuccesser(member2);
    member2->SetSuccesser(member3);
    member1->ProcessEvent(e); // calls member1, member2, member3
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//STATE
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//STRATEGY
////////////////////////////////////////////////////////////////////////////////////////////////////

class QuickSort : public SortStrategy
{
    virtual void Sort(std::vector<std::string>& container) override;
};

class ShellSort : public SortStrategy
{
    virtual void Sort(std::vector<std::string>& container) override;
};

class MyClass
{
    void SetSortStrategy(SortStrategy& strategy)
    {
        m_strategy = strategy;
    }

    void Sort()
    {
        m_strategy.Sort(m_container);
    }

private:
    std::vector<std::string> m_container;
    SortStrategy m_strategy;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//VISITOR
////////////////////////////////////////////////////////////////////////////////////////////////////

class ClassObject
{
    int m_myInt;
};

class ClassMethods
{
    void DoSomething(MyClass& obj)
    {
        obj.m_myInt = 10;
    }

    void DoSomethingElse(MyClass& obj)
    {
        obj.m_myInt = 20;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//OBSERVER
////////////////////////////////////////////////////////////////////////////////////////////////////

class MyClass
{
public:

    void ChangeSomething()
    {
        m_myInt++;
        if(m_observer)
        {
            m_observer->Update(m_myInt);
        }
    }

    void SetObserver(Observer* observer)
    {
        m_observer = observer;
    }

private:
    Observer* m_observer;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//MEDIATOR
////////////////////////////////////////////////////////////////////////////////////////////////////