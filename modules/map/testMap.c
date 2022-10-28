#include "map.c"

int main(){
    Matrix m;
    ReadMap_FILE(&m, "testMap.txt");
    displayMap(m);
    return 0;
}