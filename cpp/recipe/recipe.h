#ifndef__H__RECIPE__
#define__H__RECIPE__
 
#include <functional>
#include <string>
#include <vector>
 
class Ingredient {
  public:
    std::string name;
    float amount;
    std::string unit;
};
 
 
class Recipe {
  public:
    std::string name;
    std::vector<std::reference_wrapper<Ingredient>> ingredients;
    void addIngredient(Ingredient& ingredient);
    void updateIngredient(Ingredient& ingredient);
    void printRecipe();
};
 
#endif