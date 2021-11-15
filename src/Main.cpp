#include <iostream>
#include "CalculateSequentialMatrix.hpp"
#include "MatrixUtil.hpp"


const std::string nameMatrix1 = "M1.txt";
const std::string nameMatrix2 = "M2.txt";
const std::string nameMatrix3 = "RESULTADO.txt";

int main(){
    
    MatrixUtil::calculate(3,3,3,3, nameMatrix1, nameMatrix2);

    CalculateSequentialMatrix c;
    c.calculate(nameMatrix1, nameMatrix2, nameMatrix3);
    return 0;
}


/*
*site interessant:
* https://docs.microsoft.com/pt-br/cpp/parallel/amp/walkthrough-matrix-multiplication?view=msvc-170
*/