#include <Eigen/Dense>
#include <iostream>

int main() {
    Eigen::Matrix2d A;
    A << 1, 2,
         3, 4;

    Eigen::Matrix2d B;
    B << 2, 0,
         1, 2;

    Eigen::Matrix2d C = A * B;

    std::cout << "A * B =\n" << C << std::endl;
    return 0;
}
