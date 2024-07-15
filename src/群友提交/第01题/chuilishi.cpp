// chuilishi 7.15
#include <functional>
#include <iostream>
#include <vector>

template<typename R,typename F>
auto operator| (R&& r,F&& f) {
    for(auto val:r) {
        f(r);
    }
    return r;
}

int main(){
    std::vector v{1, 2, 3};
    std::function f {[](const int& i) {std::cout << i << ' '; } };
    auto f2 = [](int& i) {i *= i; };
    v | f2 | f;
}