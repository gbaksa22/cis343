#include "recipe.h"
#include <iostream>
#include <string>
 
 
void Recipe::addIngredient(Ingredient& ingredient){
        ingredients.push_back(ingredient);
}
 
 
void Recipe::updateIngredient(Ingredient& ingredient){
        ingredient.amount = ingredient.amount * 2.0f;
}
 
 
void Recipe::printRecipe(){
        std::cout << name << std::endl;
        std::cout << "===================================" << std::endl;
        for(auto it = ingredients.begin(); it != ingredients.end(); ++it){
                std::cout << it->get().amount << " " << it->get().unit << " " << it->get().name << std::endl;
        }
}
 
int main(int argc, char** argv){
        Recipe soup;
        soup.name = "Soup";
        Ingredient milk;
        milk.name = "Lowfat Milk";
        milk.amount = 2.5f;
        milk.unit = "cups";
 
 
        soup.addIngredient(milk);
        soup        soup.updateIngredient(milk);
        soup.printRecipe();
 
        std::cout << std::endl;
        soup.updateIngredient(milk);
        soup.printRecipe();.updateIngredient(milk);
}