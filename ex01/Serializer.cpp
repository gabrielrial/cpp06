#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    std::cout << "A:" << ptr << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}