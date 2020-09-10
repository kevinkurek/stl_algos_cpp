//
// Created by Kevin Kurek on 9/9/20.
//
#include "../headers/find.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::cout; using std::endl;

void run_find(){

//  Counting
    std::vector<int> v{1, 5, 4, 3, 5, 2, 4, 5, 9, 0, 1};
    int num_fives = count(begin(v), end(v), 5);
    cout << num_fives << endl;

    int num_odds = count_if(begin(v), end(v), [](auto i) {return i % 2 != 0;});
    cout << "Number of odds are: " << num_odds << endl;

    bool allof = all_of(begin(v), end(v), [](auto i) {return i % 2 != 0;});
    cout << "All of the values are odd: " << allof << endl;

//  Finding
    auto result = find(begin(v), end(v), 5); // worthless on its own
    int weLookedFor = *result; // have to dereference if we want actual value
    cout << weLookedFor << endl;

    // Find next 3 after first 5
    result = find(result, end(v), 3);
    if (result != end(v)) weLookedFor = *result; cout << weLookedFor << endl;

    // find_if, find_if_not, find_first_of, search, find_end, search_n, adjacent_find
    result = find_if(begin(v), end(v), [](auto i){return i%2!=0;});
    cout << "Find first odd number in vector: " << *result << endl;

    // Find first prime in vector v
    std::vector<int> primes{1,2,3,5,7,11,13};
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
    int first_prime = *result; cout << "First prime number is: " << first_prime << endl;

    // Search if subsequence is in vector v: return true or false
    std::vector<int> sub{2,4};
    result = search(begin(v), end(v), begin(sub), end(sub));
    std::string sub_in_v = *result != 0?"True":"False";
    cout << "Subsequence is inside v: " << sub_in_v;



}