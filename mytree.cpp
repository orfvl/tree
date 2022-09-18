
#include <memory>
#include <iostream>

using namespace std;

template <typename T> class mytree 
{
private:
    T value {0};
    shared_ptr<mytree> leftChild {};
    shared_ptr<mytree> rightChild {};
    weak_ptr<mytree> parent {};
public:
    mytree() = default;
    explicit mytree(T nodeValue); //make 1 argument constuctor explicit core guide line C??
    mytree(mytree const& other) = default; //mustnt be implemented rule 0?
    mytree& operator=(mytree const& other) = default;  
    mytree(mytree && other) noexcept = default;
    mytree & operator=(mytree && other) noexcept = default;
    ~mytree() = default;

    void addChild(T childValue);
    void print();
};


template <typename T> mytree<T>::mytree(T nodeValue)
    : value{nodeValue}
    {
    };

template <typename T> void mytree<T>::addChild(T childValue)
    {
        
        if (childValue < value)
        {
            if (leftChild)
            {
                leftChild->addChild(childValue);
            }
            else
            {
                leftChild.reset(new mytree(childValue));
            }
        }
        else
        {
            if (rightChild)
            {
                rightChild->addChild(childValue);
            }
            else
            {
                rightChild.reset(new mytree(childValue));
            }
        }
    }

template <typename T> void mytree<T>::print()
{
    
    cout << value << ", ";
    if (leftChild)
    {
        leftChild->print();
    }
    if(rightChild)
    {
        rightChild->print();
    }
    
}

int main()
{
    mytree<int> head(10);
    head.addChild(20);
    head.addChild(5);
    head.print();

    mytree<int> t(head);
    t.addChild(7);
    head = t;
    head.print();
}