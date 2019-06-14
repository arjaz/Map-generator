#ifndef GENERATORINTERFACE_H
#define GENERATORINTERFACE_H

#include "Heightmap.h"

class GeneratorInterface {
public:
    void virtual generate(Heightmap &heightmap) = 0;
};

#endif /* GENERATORINTERFACE_H */
