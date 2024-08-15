# Introduction
The cppModules project is a key part of the curriculum at 42 that focuses on solidifying a student's understanding of object-oriented programming (OOP) in C++. It consists of several modules, each building on the previous one to introduce increasingly complex concepts such as inheritance, polymorphism, and abstract classes. The project emphasizes writing clean, modular, and well-documented code, which is critical in professional C++ development. By completing cppModules, students gain a deep understanding of how to structure and manage larger C++ projects effectively, making it an essential stepping stone for more advanced programming challenges.

# Module 09, Exercise 02
The culmination of the cppModules project is found in the final exercise of Module 09, which challenges students with the implementation of the Ford–Johnson algorithm. This algorithm, also known as the "merge-insertion sort," is a complex and efficient sorting algorithm with a time complexity of O(n log n). It requires a deep understanding of both algorithm design and optimization, pushing students to apply their knowledge of C++ and problem-solving skills to a real-world scenario.

## The problem of the algorithm

The Ford–Johnson algorithm consists of two key sorting phases, each employing different techniques to minimize the overall number of operations. Each step in the algorithm is designed to reduce the complexity of the sorting process.

The two sorting phases utilize different algorithms that are not well-suited to a single data structure. To fully leverage the efficiency of merge sort, a linked list is ideal due to its superior performance in division and merging operations. However, linked lists do not allow random access, making them unsuitable for binary search, which is crucial for the insertion sort. Conversely, data structures that support random access, such as arrays, perform poorly with merge sort.

The primary objective of the Ford–Johnson algorithm is to minimize the total number of sorting operations. However, in real-world scenarios, the steps it employs can actually increase the number of operations required when using any available data structure.

## The key point of Ford–Johnson algorithm

The Ford–Johnson algorithm begins by dividing the unsorted array into two parts, pairing up the elements, and positioning the larger elements at the top. Merge sort is then applied to the pairs with the larger numbers, while insertion sort is used for the smaller numbers in each pair.

A common mistake made by those attempting this exercise is forgetting to reorder the smaller array before performing the insertion sort. This reordering step is crucial for reducing the number of operations in the Ford–Johnson algorithm, as it helps limit the maximum number of comparisons needed.

