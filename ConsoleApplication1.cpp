#include <iostream>
#include <string>
using namespace std;
//класс mixins
class Mixin {
public:
    void LogAction(const string& action) {
        cout << action << endl;
    }
};
//класс оружие. оружие может существовать отдельно от персонажа
class Weapon {
    //стоит сделать поля приватными и дописать гетеры и сеттеры
public:
    string name; //название оружия
    int damage; //урон

    Weapon(const string& n, int d) : name(n), damage(d) {};
    
    void Print() const {
        cout << "оружие: " << name << ", урон: " <<damage <<endl;
    }
};
//класс заклинание. Заклинание не может существовать без персонажа
class Spell {
public:
    int fireball_damage;//урон 
    int healing_amount;//сколько здоровья восстанавливает

    Spell(int f, int h) : fireball_damage(f), healing_amount(h) {};
    void Print() const {
        cout << "урон от огненого шара: " << fireball_damage << ", исцеление на " << healing_amount << " едениц"<< endl;
    }
};
//базовый класс для персонажа
class Character {
protected:
    string name;
    int health;
public:
    Character(const string& n, int h) : name(n), health(h) {};
    //виртуальный метод, который будем переопределять в потомках
    virtual void Print() const {
        cout << "Персонаж: " << name << ", здоровье:" << health << endl;
    }
    //чистый виртуальный метод, обязательно должен быть переопределен в классах-наследниках
    virtual void Attack(Character& target) = 0;
    //проверка жив ли персонаж
    bool IsAlive() const {
        return health > 0;
    }
    //метод получения урона
    void TakeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        if (health == 0) {
            cout << name << " повержен(а)" << endl;
        }
    }
    friend void Fight(Character& pers1, Character& pers2);
};
//производный класс воин
class Warrior : public Character, public Mixin {
private:
    //создание оружия по указателю
    Weapon* weapon; //агрегация классов. Оружие может существовать независимо от воина
public:
    Warrior(const string& n, int h, Weapon* w) : Character(n, h), weapon(w) {};
    //переопределяем метод
    void Print() const override {
        Character::Print(); //так как наследуемся от character
        //weapon->Print();//вызываем от указателя
    }
    //переопределяем чистый виртуальный метод базового класса
    void Attack(Character& target) override {
        LogAction(name + " атакует, используя " + weapon->name + "!");
        target.TakeDamage(weapon->damage);
    }
};
//производный класс маг
class Mage : public Character, public Mixin {
private:
    //создание объекта
    Spell spell; //композиция классов. Заклинание не может существовать независимо от мага
public:
    Mage(const string& n, int h, Spell s) : Character(n, h), spell(s) {};
    //переопределяем метод
    void Print() const override {
        Character::Print(); //так как наследуемся от character
        //spell.Print();//вызываем от объекта
    }
    //восстановление здоровья
    void RestoreHealth() {
        health += spell.healing_amount;
        LogAction(name + " восстанавливает здоровье на " + to_string(spell.healing_amount) + " едениц" + "!");
    }
    //переопределяем чистый виртуальный метод базового класса
    void Attack(Character& target) override {
        LogAction(name + " атакует, используя огненный шар" + "!");
        target.TakeDamage(spell.fireball_damage);
        RestoreHealth();
        
    }
};
void Fight(Character& pers1, Character& pers2) {
    //создание строки из большого количества символов
    string line(40, '-');
    cout << line << endl;
    cout << "Бой между "<<pers1.name << " и " << pers2.name<< "."<<endl;
    while (pers1.IsAlive() && pers2.IsAlive()) {
        pers1.Attack(pers2);
        
        if (!pers2.IsAlive()) break;
        pers2.Attack(pers1);
        pers1.Print();
        pers2.Print();
    }
    cout << "бой завершен" << endl;
    cout << line << endl;
}
int main()
{
    setlocale(LC_ALL, "rus");
    Weapon* sword = new Weapon("меч", 15);
    Spell spell(10, 2);
    Character* pers1 = new Warrior("Гера", 40, sword);
    Character* pers2 = new Mage("Оптимус прайм", 55, spell);
    Fight(*pers1, *pers2);

    return 0;
}


//контрольная полиформизм наследование. в четверг консультация пятой парой