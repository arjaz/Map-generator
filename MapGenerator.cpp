#include "MapGenerator.h"

#include "Heightmap.h"
#include "PerlinNoise.h"
#include <vector>
#include <algorithm>

MapGenerator::MapGenerator(int size) {
    generateHeightmap(size);
}

MapGenerator::~MapGenerator() = default;

void MapGenerator::generateHeightmap(int size) {
    heightmap = Heightmap{std::vector<std::vector<double>>(size, std::vector<double>(size, 0))};

    PerlinNoise pn;

    for (int i = 0; i < heightmap.heightmap.size(); ++i) {
        for (int j = 0; j < heightmap.heightmap.back().size(); ++j) {
            double x = (double)j / (double)heightmap.heightmap.back().size();
            double y = (double)i / (double)heightmap.heightmap.size();
            heightmap.heightmap.at(i).at(j) = pn.noise(x, y, 0);
        }
    }
}

void MapGenerator::erodeHeigtmap(int iterations) {

}

void MapGenerator::normalizeHeightmap() {
    double min = heightmap.heightmap.back().back();
    double max = heightmap.heightmap.back().back();
    for (auto const &x : heightmap.heightmap) {
        double cur_min = std::min(*(std::min_element(std::begin(x), std::end(x))), min);
        double cur_max = std::max(*(std::max_element(std::begin(x), std::end(x))), max);
        if (cur_max > max)
            max = cur_max;
        if (cur_min < min)
            min = cur_min;
    }
    for (auto &x : heightmap.heightmap) {
        for (auto &y : x) {
            y = (y - min) / (max - min);
        }
    }
}

void MapGenerator::setHeightmap(Heightmap heightmap) {
    this->heightmap = heightmap;
}

Heightmap MapGenerator::getHeightmap() {
    return heightmap;
}

std::vector<std::vector<double>> MapGenerator::getHeightmapVector() {
    return getHeightmap().heightmap;
}

void MapGenerator::gaussGenerate() {

}
