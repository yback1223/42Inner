#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

int main()
{
    {
        std::cout << "MutantStack ver." << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }


    {
        std::cout << "\nlist ver." << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
	
    MutantStack<int> mstack;
	mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
	
    std::cout << "Using iterator:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "\nUsing const_iterator:" << std::endl;
    const MutantStack<int> cmstack(mstack);
    for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "\nUsing reverse_iterator:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }

    std::cout << "\nUsing const_reverse_iterator:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator rit = cmstack.rbegin(); rit != cmstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }

    std::cout << "\nCompatibility with std::stack:" << std::endl;
    std::stack<int> s(mstack);
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}