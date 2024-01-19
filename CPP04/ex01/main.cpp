#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
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
     Animal *animals[10];
     for (int i = 0; i < 10; i++) {
         if (i % 2 == 0)
        {
            animals[i] = new Dog();
            animals[i]->makeSound();
         }
         else
         {

            animals[i] = new Cat();
            animals[i]->makeSound();
         }
     }
        for (int i = 0; i < 10; i++)
        {
            delete animals[i];
        }
        Brain brain;
    }

}