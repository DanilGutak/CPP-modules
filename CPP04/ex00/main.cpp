#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main( void ) {
    {
        Animal *sample = new Animal();
        Animal *dog = new Dog();
        Animal *cat = new Cat();

        std::cout << "Animal type: " << sample->getType() << std::endl;
        std::cout << "Dog type: " << dog->getType() << std::endl;
        std::cout << "Cat type: " << cat->getType() << std::endl;

        sample->makeSound();
        dog->makeSound();
        cat->makeSound();
        delete sample;
        delete dog;
        delete cat;
    }

    {
        WrongAnimal *sample = new WrongAnimal();
        WrongAnimal *wrongCat = new WrongCat();

        sample->makeSound();
        wrongCat->makeSound();
        delete sample;
        delete wrongCat;
    }

}