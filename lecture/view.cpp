#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ranges>

bool isVowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e'};
    auto UpperVowel = letters 
        | std::ranges::views::filter(isVowel)
        | std::ranges::views::transform(toupper)
        | std::ranges::views::common;
//在这段代码中，我使用了 std::ranges::views::common 将范围转换
//成一个标准的输入输出范围（普通范围），这样你就可以用向量的构造函数来将其转换为一个 std::vector<char>。


    std::vector<char> result(UpperVowel.begin(), UpperVowel.end());

    for (char c : result) {
        std::cout << c << "\n";
    }
}