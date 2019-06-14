#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Heightmap.h"
#include <vector>

class MapGenerator {
private:
    Heightmap heightmap;

    void gaussGenerate();

public:
    MapGenerator(int size);
    virtual ~MapGenerator();

    void generateHeightmap(int size);
    void erodeHeigtmap(int iterations);
    void normalizeHeightmap();

    void setHeightmap(Heightmap heightmap);
    Heightmap getHeightmap();
    std::vector<std::vector<double>> getHeightmapVector();
};

#endif /* MAPGENERATOR_H */
