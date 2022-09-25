#include <iostream>
using namespace std;

int g_data;

void display();

//constexpr int getSize(int seed) {
  //  return seed * 2;
//}

//int main() {
int main(int argc, char** argv) {
    //char str[]{"hello"};
    //for (int i = 0; i < argc; ++i)
    //    cout << i << ". " << argv[i] << endl;



    // const: value cannot change after creation
    // constexpr: a constant + value must be known at compile time
    //int iSize{};
    //cout << "Size? ";
    //cin >> iSize;

    //const int size = iSize;
    //constexpr int SIZE = size;
    //double arr[SIZE]{};

    // double arr[getSize(iSize)]{};

    // TODO: Linking
    g_data = 10;
    display();
}