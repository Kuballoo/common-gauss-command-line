#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

long long randNum(long long min, long long max) {
    return rand()%(max + 1-min)+min;
}

void printVec(vector<size_t> &vec) {
    for(size_t i : vec) cout << i << " ";
    cout << endl;
}

void printDiagram(vector<size_t> &vec) {
    for(size_t j=0; j<vec.size(); j++) {
        cout << j << "\t";
        for(size_t i=0; i<vec.at(j); i++) cout << ".";
        cout << endl;
    }
}

int main() {
    srand(time(NULL));

    // settings
    const size_t times {800}, cubes{5}, min_cube_value{1}, max_cube_value{5};
    vector<size_t> vec ((cubes*(max_cube_value-min_cube_value))+1, 0);

    int sum_of_six{0};
    for(size_t i=0; i<times; i++) {
        sum_of_six = 0;
        for(size_t j=0; j<cubes; j++) sum_of_six += randNum(min_cube_value, max_cube_value);
        sum_of_six -= (min_cube_value*cubes);
        vec.at(sum_of_six)++;
    }

    printDiagram(vec); 
    printVec(vec);

    return 0;
}