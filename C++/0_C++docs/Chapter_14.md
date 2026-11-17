# Reusing Code in C++
---
## Classes with Object Members
- Class including class objects as members
- Simplifying a student to a name and a set of quiz scores 
- To represent a name, simply use `string` class
- To represent the quiz scores, use fixed-size array, or simpler, use a **suitable class** to represent the data

### The `valarray` Class: A Quick Look
- Targeted to deal with **numeric values**(or with classes **with similar properties**), supporting operations like summing and finding the largest
- Defined as a **template class**
    - We have to provide a specific type when declaring an object like `valarray<int> num`
    - The `vector` and `array` class works the same
    - Create an empty array of zero size: `valarray<double> test;`
    - Create an empty array of given size: `valarray<double> v2(8);`
    - Create an array of **given size(8) each set to the same(1)**: `valarray<double> v2(1,8);`
    - Create an array initialized using the value from an **ordinary array**: `double a[5] = {...}; valarray<double> v3(a,4);`
    - In C++11: `valarray<int> v5 = {20,10,12};`
- Methods: 
    - `operator[]()` access individual elements
    - `size()` returns the number of elements
    - `sum()` returns the sum of the elements
    - `max()`, `min()` are obvious

### The `STUDENT` Class Design
- Use a `string` object to represent the name, and a `valarray<double>` object to represent the quiz scores
- Multiple `public` inheritance is allowed, but not suitable here
- Here is a *has-a* relationship, a student **has a name** and **has an array of quiz scores**
- Create a class **composed of members that are objects of another class**
- Example: `class STUDENT{private: string name; valarray<double> scores...};`
- Usually the data members are `private`, thus class `STUDENT` must use the **`public` interfaces** of class `string` and `valarray<double>` to access and modify the `name` and `scores` **internally**
- The outside world will have the access to `name` and `scores` only through the **`public` interface defined for `STUDENT` class**, for example, not directly using `STUDENT s1; s1.sum()` where `sum()` is from class `valarray<double>`
- The `STUDENT` class acquires the **implementation of its member objects** but **not inherit the interface**
- `public` inheritance: *is-a* relationship, inherits an interface and an implementation(perhaps)
- *Has-a* relationship: acquiring the implementation without an interface, **not inheriting the interface**
- To use `operator<()`, define a `STUDENT::operator<()` member function internally uses the `string::operator<()`

### The `STUDENT` Class Example
- Make some `inline` `public` interfaces
