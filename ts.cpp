#include <iostream>
#include <string>

class Weapon {
public:
    Weapon(const std::string& type) : type(type) {
        std::cout << type << " is created." << std::endl;
    }
    Weapon() : type("default weapon") {
        std::cout << type << " is created." << std::endl;
    }
    ~Weapon() {
        std::cout << type << " is destroyed." << std::endl;
    }

    const std::string& getType() const {
        return type;
    }

    void setType(const std::string& newType) {
        type = newType;
    }

private:
    std::string type;
};

class HumanB {
public:
    HumanB(const std::string& name) : name(name) {
        std::cout << name << " is created." << std::endl;
    }

    ~HumanB() {
        std::cout << name << " is destroyed." << std::endl;
    }

    void setWeapon(const Weapon& newWeapon) {
        weapon = &newWeapon;
    }

    void attack() const {
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    }

private:
    std::string name;
    Weapon weapon;
};

int main() {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");

    jim.setWeapon(club);
    jim.attack();  // 第一次攻擊，使用 "crude spiked club" 的狀態

    club.setType("some other type of club");
    jim.attack();  // 第二次攻擊，使用 "some other type of club" 的狀態

    return 0;
}
