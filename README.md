# TP-Algos
The pupose of this project is to compare algorithms for solving the traditional Transportation Problem and get better understanding of their working through their implementations. I studied these algorithms (for both balanced and unbalanced demand and supply) in the course "Quantitative Methods for Decision Making". 
Algorithms for 
- Initial basic feasible solution
  - North West Corner Method, 
  - Least Cost Method, 
  - Vogel's Approximation Method, 
- Optimal Solution 
  - Stepping Stone Method and
  - MODI Method


## Basic Design
- The algorithms are written in C++ and built using CMake. Testing is done in Python using [pybind11](https://github.com/pybind/pybind11).


## About Files
The project is developed conforming to the conventional standards. Thus, most of the directory structure, files and their functions are pretty straightforward and follow the conventional meaning. Descriptions for other files/folders is below:
- `common.hpp` contains functions used by all algorithms.
- `utils.hpp` contains specific utility functions for individual or a small group of algorithms.
- `tests` contain testing files. 
- `bindings` contains bindings between pybind 11 and C++.


## Future Developments
- The algorithm currently doesn't account for the unbalanced supply and demand case. The extension to which should be pretty starightforward.


### Alternatives for Testing
- Testing can be done in 2 ways:
  - Directly in C++
    - [catch2](https://github.com/catchorg/Catch2)
    - [googletest](https://google.github.io/googletest/) 
    - Both of these are really good options for testing. However, I inclined more towards pybind11 as I was more intrigued about how the wrapping/binding between python and C++ takes place here. 
    - NOTE: Since syntax of [googletest](https://google.github.io/googletest/) is very similar to [unittest](https://docs.python.org/3/library/unittest.html) library of python, converting from pybind11 to googletest shouldn't be a hassle.
  - C/C++ to Python binding
    - ctypes
    - cffi
    - cython
    - Out of these, I found pybind11 to be the most suitable for my need.


### Articles helpful in development:
- [Python Bindings Overview](https://realpython.com/python-bindings-overview/)
- [An example of CMake build and pybind11 project testing](https://www.benjack.io/2017/06/12/python-cpp-tests.html)


### Remarks
- Thinking of algorithms and data structures to implement these methods was perhaps the most fun part. If you are a student, I would sincerely encourage you to come up with your own implementation and compare with this one only for referece.
