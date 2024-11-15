template <std::input_iterator T, typename U>
auto min (const T& a, const U& b) {
    return a < b ? a : b;
}

template <Comparable T>
concept Comparable = requires(const T a, const T b) {
    {a < b} -> std::convertible_to<bool>;
}; 

int main() {
    min(106, 22.4);
};