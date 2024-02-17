#include <iostream>
#include "Serializer.hpp"

int main() {
    Data myData = {
		.value = 42
	};
    uintptr_t serializedData = Serializer::serialize(&myData); // serialize를 사용하여 Data 객체의 주소를 정수형으로 변환
    Data* deserializedData = Serializer::deserialize(serializedData); // deserialize를 사용하여 정수형을 다시 Data 객체 포인터로 변환

    // 원본 포인터와 직렬화/역직렬화를 통해 얻은 포인터 비교
    if (&myData == deserializedData) {
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original data: " << myData.value << ", Deserialized data: " << deserializedData->value << std::endl;
    } else {
        std::cout << "Failed." << std::endl;
    }

    return 0;
}