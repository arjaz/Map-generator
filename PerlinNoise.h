#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <vector>

class PerlinNoise {
private:
	std::vector<int> p;

	double fade(double t);
	double lerp(double t, double a, double b);
	double grad(int hash, double x, double y, double z);

    void generate_p(unsigned int seed);
public:
	PerlinNoise();
	PerlinNoise(unsigned int seed);
	double noise(double x, double y, double z);
};

#endif
