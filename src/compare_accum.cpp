//
// Created by Kevin Kurek on 9/13/20.
//
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using std::cout; using std::endl; using std::string;
#include "../headers/compare_accum.h"

void run_compare_accum(){

    std::vector<int> a{1, 2, 5, 7, 0};
    std::vector<int> b{1, 2, 5, 4, 7};

    // Are the two vectors equal?
    bool same = equal(begin(a), end(a), begin(b), end(b));
    // Where does the first mismatch happen?
    auto mixup = mismatch(begin(a), end(a), begin(b));
    int avalue = *(mixup.first);
    int bvalue = *(mixup.second);
    auto distance = mixup.first - begin(a);
    cout << "first mismatch happens at position: " << distance << endl;

    // total up vector elements, can use lambda to find any sequence
    // accum all values in vector
    int total = accumulate(begin(a), end(a), 0);

    // accum+ even values
    int tot_lamda = accumulate(begin(b), end(b), 0,
                               [](int total, int i){if(i%2==0) return total + i; return total;});

    //accum multiplication if odd
    int tot_multi = accumulate(begin(b), end(b), 1,
                               [](int total, int i){if(i%2!=0) return total * i; return total;});

    //accum with string
    std::vector<std::string> words{"My", "Name", "is", "Kevin"};
    string concat = accumulate(begin(words), end(words), string{},
                                    [](const string& total, string& s){return total + " " + s;});


    // for_each examples vs. ranged-for loop
    // change all values of b to 1
    for(auto& i:b){
        i = 1;
    }
    // change all values of b to 2; not really better than ranged-for loop
    for_each(begin(b), end(b), [](int& e){e = 2;});

    // using for_each for vector manipulation
    // Find value 5 in vector b, then replace 5 and everything after it with 0
    std::vector<int> c{1, 2, 5, 4, 7};
    auto first3 = find(begin(c), end(c), 5);
    for_each(first3, end(c), [](int& e){e=0;});





}

