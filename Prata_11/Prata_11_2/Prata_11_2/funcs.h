#ifndef FUNCS_H_
#define FUNCS_H_

#include <fstream>
#include "vect.h"

void StartingOutputToFile(std::ofstream& fout, double& target, double& dstep);
void OutputEveryStepToFile(std::ofstream& fout, Vect& result, double& target, unsigned long& steps, double& direction, double& dstep);
void EndingOutputToFile(std::ofstream& fout, Vect& result, unsigned long& steps);
void MainLoop(double& target, unsigned long& steps, double& direction, double& dstep);

#endif