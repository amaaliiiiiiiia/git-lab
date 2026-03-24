#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <immintrin.h>
#include <vector>
#include <sys/random.h>
#include <unistd.h>
#include <ctime>

using namespace std;

// 1. Standard C++ rand
int method_rand() {
    return rand() % 200;
}

// 2. Hardware RDRAND
int method_rdrand() {
    unsigned int ret;
    if (_rdrand32_step(&ret)) return ret % 200;
    return -1;
}

// 3. /dev/urandom
int method_urandom() {
    int ret;
    FILE *f = fopen("/dev/urandom", "r");
    fread(&ret, sizeof(ret), 1, f);
    fclose(f);
    return abs(ret) % 200;
}

// 4. getrandom syscall
int method_getrandom() {
    int ret;
    getrandom(&ret, sizeof(ret), 0);
    return abs(ret) % 200;
}

// 5. getentropy (Provocarea!)
int method_getentropy() {
    int ret;
    if (getentropy(&ret, sizeof(ret)) == 0) return abs(ret) % 200;
    return -1;
}

int main() {
    srand(time(NULL));
    cout << "Method 1 (rand): " << method_rand() << endl;
    cout << "Method 2 (rdrand): " << method_rdrand() << endl;
    cout << "Method 3 (urandom): " << method_urandom() << endl;
    cout << "Method 4 (getrandom): " << method_getrandom() << endl;
    cout << "Method 5 (getentropy): " << method_getentropy() << endl;
    return 0;
}
