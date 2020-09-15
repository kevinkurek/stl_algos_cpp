//
// Created by Kevin Kurek on 9/12/20.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include "../headers/sort.h"
#include "../headers/employee.h"
using std::cout; using std::endl;

void run_sort(){

    std::vector<float> v{1.0, 5.0, 10.3, -2.9, 5.4};

    auto v2 = v;
    // reverse sort by lambda with >. sort() naturally uses <.
    sort(begin(v2), end(v2), [](float e1, float e2){return e1 > e2;});

    //sorting custom employee class
    std::vector<Employee> staff{
            {"Kevin", "K", 2000},
            {"Ava", "K", 3000},
            {"Alex", "N", 2500},
            {"Alex", "K", 2800},
            {"Kevin", "L", 2900}
    };

    // Sort staff on member-function getSalary(), increasing = <.
    sort(begin(staff), end(staff),
         [](auto e1, auto e2){return e1.getSalary() < e2.getSalary(); });

    // Keeps v2 normal, but sorts and assigns v_sorted copy
    std::vector<float> v_sorted(v2.size());
    std::partial_sort_copy(begin(v2), end(v2),
                           begin(v_sorted), end(v_sorted));

    // Sort Staff on member-function getSortingName(), decreasing = >.
    std::vector<Employee> staff_name_sort(staff.size()); // Can only be initialized with default parameters in public:Empolyee().
    partial_sort_copy(begin(staff), end(staff),
                      begin(staff_name_sort), end(staff_name_sort),
         [](auto e1, auto e2){return e1.getSortingName() > e2.getSortingName(); });

    // Stable Sort, holds original order in place if a tie
    std::stable_sort(begin(staff), end(staff), [](auto i1, auto i2){return i1.getSalary() < i2.getSalary();});

    // Check if sorted; can check lambda variations like absolute value sort
    // false
    auto sorted = is_sorted(begin(v2), end(v2));
    // false
    sorted = is_sorted(begin(v2), end(v2), [](int e1, int e2){return abs(e1) > abs(e2);});
    // true; because original v2 was sorted based on largest to smallest
    sorted = is_sorted(begin(v2), end(v2), [](int e1, int e2){return e1 > e2;});

    // check max/min element
    sort(begin(v2), end(v2));
    // Gives same answer, but *(begin(v2)) is faster since v2 is already sorted
    int high = *(max_element(begin(v2), end(v2)));
    int high_sort = *(end(v2)-1);

    // Gives same answer, but *(begin(v2)) is faster since v2 is already sorted
    int low = *(min_element(begin(v2), end(v2)));
    int low_sort = *(begin(v2));
    cout << "The max element of current v2 is " << high << endl;
    cout << "The low element of current v2 is " << low << endl;

    // Finds first positive value because starts at 0 and next value.
    int positive = *upper_bound(begin(v2), end(v2), 0);

    // lower_bound is a quicker find if collection is already sorted
    sort(begin(staff), end(staff),
         [](Employee e1, Employee e2){return e1.getSortingName() < e2.getSortingName();});
    // find first sorted name after Kevin, K;
    auto p = lower_bound(begin(staff), end(staff), "Kevin, K",
                         [](Employee e1, std::string n){return e1.getSortingName() < n;});
    // find salary of first sorted name less than Kevin, Kurek
    int sal = p->getSalary(); cout << "Lower Bound salary " << sal << endl;

    // Shuffle
    std::random_device randomdevice;
    std::mt19937 generator(randomdevice());
    shuffle(begin(v2), end(v2), generator);

    // Partial sort
    std::vector<int> v3{1, 5, 4, 7, -9, -2};
    // find the position of the 4, 2nd element, so the 0th & 1st elements will be sorted then no guarantees after that.
    partial_sort(begin(v3), find(begin(v3), end(v3), 4), end(v3));

    // Partial sort copy
    std::vector<int> v4(3); // initialize empty vector of size 3
    partial_sort_copy(begin(v3), end(v3), begin(v4), end(v4)); // fill v4 with 3 lowest values from v3

    // Break into rough groups, nth-element, finds bisecting element then puts low and high values on opposite sides, not sorted
    std::vector<float> v5{-6, 5, 3, 8, -2, 10, -2.3, 5.0};
    int split = v5.size() / 2; // v5.size()/2 would give nth-value to bisect data
    nth_element(begin(v5), begin(v5)+split, end(v5));
    int median = *(begin(v5)+split);

}