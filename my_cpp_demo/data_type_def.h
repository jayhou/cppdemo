#ifndef _DATA_TYPE_DEF_H_
#define _DATA_TYPE_DEF_H_
#include <iostream>
struct InnerDataType {
    int data1;
    int data2;
    InnerDataType(int d1, int d2) {
        std::cout << "InnerDataType construct1 called" << std::endl;
        data1 = d1;
        data2 = d2;
    }
    InnerDataType(InnerDataType&& moveData) {
        std::cout << "InnerDataType move construct called" << std::endl;
    }
    InnerDataType() {
        data1 = 0;
        data2 = 1;
        std::cout << "InnerDataType default construct called" << std::endl;
    }
    void operator=(const InnerDataType& innerData) {
        std::cout << "InnerDataType operator= called" << std::endl;
        data1 = innerData.data1;
        data2 = innerData.data2;
    }
};

struct TestData
{
    InnerDataType innerData;
    TestData() {
        std::cout << "TestData default construct called" << std::endl;
    }
    TestData(const InnerDataType& data) {
        std::cout << "TestData construct1 called" << std::endl;
        innerData.data1 = data.data1;
        innerData.data2 = data.data2;
    }
    TestData(TestData&& testData) {
        std::cout << "TestData mov construct called" << std::endl;
    }
    TestData& operator=(TestData&& testData) {
        std::cout << "TestData operator && = called " << std::endl;
        return testData;
    }
    void operator=(const TestData& testData) {
        std::cout << "TestData operator && = called " << std::endl;
        TestData data;
        data.innerData = testData.innerData;
    }
};

struct MoveData {
    int a;
    MoveData() {        
        std::cout << "MoveData default construct called" << std::endl;
        a = 2;
    }
    MoveData(const int& pa) {
        std::cout << "MoveData copy construct called" << std::endl;
        a = 5;
    }
    MoveData(MoveData&& move) {
        std::cout << "MoveData move construct called" << std::endl;
        a = 4;
    }
    MoveData& operator=(MoveData&& move) {

    }
};

#endif