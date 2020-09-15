//
// Created by Kevin Kurek on 9/15/20.
//

#include "../headers/copy.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void run_copy(){

vector<int> source{3, 6, 1, 0, -2, 5};
vector<int> v2(source.size());

copy(begin(source), end(source), begin(v2));

auto v3 = source; // true full copy

// Find number 3, init new vector, copy values 1-3, then 0's for rest of vector
auto position = find(begin(source), end(source), 1);
vector<int> v4(source.size());
copy(begin(source), position+1, begin(v4));
for_each(begin(v4), end(v4), [](auto& i){cout << i << endl;});

// copy_if() value is even. Remember these values will be added to begin of v5, then subsequent 0's after
vector<int> v5(source.size());
copy_if(begin(source), end(source), begin(v5), [](auto& i){return i%2==0;});

//vector<int> source{3, 6, 1, 0, -2, 5};
//auto position = find(begin(source), end(source), 1);
//vector<int> v4(source.size());
//copy(begin(source), position+1, begin(v4));

//for(auto & i: v4){
//    std::cout << i;
//}
//for_each(begin(v3), end(v3), [](auto i){if(i>3) return 1;});

}

