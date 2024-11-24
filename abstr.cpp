#include <iostream>

class Weapon {
protected:
    int _damage;
    int _bullets;
public:
    Weapon(int damage, int bullets) :
        _damage{ damage }, _bullets{ bullets } {}

    virtual ~Weapon() {
        std::cout << "Weapon destructur!" << std::endl;
    }

    virtual void Shoot() = 0;
};

class Gun : public Weapon {
public:
    Gun(int damage, int bullets) :
        Weapon(damage, bullets) {}

    ~Gun() {
        std::cout << "Gun destructur!" << std::endl;
    }

    void Shoot() override {
        std::cout << "---Gun---" << std::endl;
        _bullets--;
        std::cout << "Bang!" << std::endl;
        std::cout << "Bullets: " << _bullets << std::endl;
    }
};

class Rifle : public Weapon {
public:
    Rifle(int damage, int bullets) :
        Weapon(damage, bullets) {}

    void Shoot() override {
        std::cout << "---Rifle---" << std::endl;
        _bullets -= 3;
        std::cout << "Bang! Bang! Bang!" << std::endl;
        std::cout << "Bullets: " << _bullets << std::endl;
    }
};

int main()
{
    Weapon* weapon = new Gun(15, 1);
    weapon->Shoot();
    delete weapon;
}
