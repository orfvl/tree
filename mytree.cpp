
#include <memory>
#include <iostream>

using namespace std;

template <typename T> class mytree 
{
private:
    T value {0};
    unique_ptr<mytree> leftChild {};
    unique_ptr<mytree> rightChild {};
public:
    mytree() = default;
    explicit mytree(T nodeValue); //core guide line C??
    mytree(mytree const& other) = delete; //must be implemented 
    mytree& operator=(mytree const& other) = delete; //must be implemented 
    mytree(mytree && other) noexcept = delete;
    mytree & operator=(mytree && other) noexcept = delete;
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
}