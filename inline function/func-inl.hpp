// A-inl.h

inline void A::doInline() {
    // Inline function definition
    data = 42;
    std::cout << "data is: " << data << std::endl;
}