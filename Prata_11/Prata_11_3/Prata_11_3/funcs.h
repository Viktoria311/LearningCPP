#ifndef FUNCS_H_
#define FUNCS_H_

#include <fstream>
#include <vector>
#include "vect.h"

void StartingOutputToFile(std::ofstream& fout, double& target, double& dstep);
int CountingOfSteps(Vect& result, double& target, unsigned long& steps, double& direction, double& dstep);
void EndingOutputToFile(std::ofstream& fout, std::vector<int>& vec_of_steps_for_every_attempts);
void ToFile();

#endif