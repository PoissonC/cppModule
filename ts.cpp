#include <list>
#include <iostream>

template<typename T>
bool list_binary_search(const std::list<T>& lst, const T& value) {
    if (lst.empty()) return false;

    auto it = lst.begin();
    auto steps = distance(it, lst.end());

    while (steps > 0) {
        auto mid = it;
        auto step = steps / 2;
        advance(mid, step);
        if (*mid == value) {
            return true;
        } else if (*mid < value) {
            it = ++mid;
            steps -= step + 1;
        } else {
            steps = step;
        }
    }

    return false;
}

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if (list_binary_search(lst, 11)) {
        std::cout << "Found the value!" << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    return 0;
}
