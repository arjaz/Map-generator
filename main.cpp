#include <iostream>
#include <iomanip>

#include "MapGenerator.h"

int main() {
    MapGenerator generator(5);
    generator.erodeHeigtmap(10);
    generator.normalizeHeightmap();

    for (auto x : generator.getHeightmapVector()) {
        for (auto y : x) {
            std::cout << std::setw(12) << std::left << y;
        }
        std::cout << std::endl;
    }

    return 0;
}
