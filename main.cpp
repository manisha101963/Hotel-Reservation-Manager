#include <iostream>
#include "RoomTypes.h"

using namespace std;

int main() {
    SingleRoom r1(101);
    DoubleRoom r2(102);
    SuiteRoom r3(103);

    cout << r1.getRoomType() << endl;
    cout << r2.getRoomType() << endl;
    cout << r3.getRoomType() << endl;

    return 0;
}