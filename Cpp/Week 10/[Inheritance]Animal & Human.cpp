#include <iostream>
#include <string>

// animal.h
class animal
{
    public:
        animal(std::string s, int e);
        void print_eyes();
    private:
        std::string _species;
        int _eyes;
};

animal::animal(std::string s, int e)
{
    _species = s;
    _eyes = e; 
}

void animal::print_eyes()
{
    std::cout << _species << " has " << _eyes << " eyes." << std::endl;
}

// human.h
class human: public animal
{
    public:
        human(std::string n);
        void greeting() const;
    private:
        std::string _name;
};

human::human(std::string n): animal("Human",2)
{
    _name = n;
}

void human::greeting() const
{
    std::cout << "Hello, I'm " << _name << "." << std::endl;
}

int main() {
    std::string s, n;
    int e;
    std::cin >> s >> e >> n;
    animal * p = new animal(s, e);
    p->print_eyes();
    delete p;
    human h(n);
    p = &h;
    p->print_eyes();
    const human & q = h;
    q.greeting();
    return 0;
}

