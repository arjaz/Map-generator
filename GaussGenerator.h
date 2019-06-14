#ifndef GAUSSGENERATOR_H
#define GAUSSGENERATOR_H

#include "GeneratorInterface.h"
#include "Heightmap.h"

class GaussGenerator : public GeneratorInterface {
public:
    GaussGenerator();
    void generate(Heightmap &heightmap);
    virtual ~GaussGenerator();
};

#endif /* GAUSSGENERATOR_H */
