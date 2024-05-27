#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // ����������� �� ������������
    Matrix() : rows(0), cols(0) {}

    // ����������� � �����������
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, std::vector<double>(c, 0.0));
    }

    // ����������� ��ﳿ
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // �������� ������������
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    // �������� ���������
    bool operator==(const Matrix& other) const {
        return data == other.data;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    // �������� ��������
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices dimensions must match for subtraction.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // �������� ��������
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix multiplication is not defined for these dimensions.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // ����� ��� ���������� �������� ������� (����������� ����� ������-�������)
    Matrix inverse() const {
        if (rows != cols) {
            throw std::invalid_argument("Only square matrices can be inverted.");
        }

        int n = rows;
        Matrix result(n, n);
        Matrix augmented(*this);

        // �������� ��������� ������� (������� | �������� �������)
        for (int i = 0; i < n; ++i) {
            result.data[i][i] = 1.0;
        }

        for (int i = 0; i < n; ++i) {
            double pivot = augmented.data[i][i];
            if (std::abs(pivot) < 1e-10) {
                throw std::runtime_error("Matrix is singular and cannot be inverted.");
            }

            // ����������� �����
            for (int j = 0; j < n; ++j) {
                augmented.data[i][j] /= pivot;
                result.data[i][j] /= pivot;
            }

            // ��������� ����� �����
            for (int k = 0; k < n; ++k) {
                if (k == i) continue;
                double factor = augmented.data[k][i];
                for (int j = 0; j < n; ++j) {
                    augmented.data[k][j] -= factor * augmented.data[i][j];
                    result.data[k][j] -= factor * result.data[i][j];
                }
            }
        }

        return result;
    }

    // ����� ��� ���������� ������� ����������
    void fillMatrix(const std::vector<std::vector<double>>& values) {
        if (values.size() != rows || (rows > 0 && values[0].size() != cols)) {
            throw std::invalid_argument("Invalid matrix dimensions for the provided values.");
        }
        data = values;
    }

    // ����� ��� ����������� �������
    void display() const {
        for (const auto& row : data) {
            for (double val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    try {
        Matrix m1(2, 2);
        m1.fillMatrix({ {1, 2}, {3, 4} });

        Matrix m2(2, 2);
        m2.fillMatrix({ {5, 6}, {7, 8} });

        std::cout << "Matrix 1:" << std::endl;
        m1.display();

        std::cout << "Matrix 2:" << std::endl;
        m2.display();

        Matrix m3 = m1 - m2;
        std::cout << "Matrix 1 - Matrix 2:" << std::endl;
        m3.display();

        Matrix m4 = m1 * m2;
        std::cout << "Matrix 1 * Matrix 2:" << std::endl;
        m4.display();

        Matrix m5 = m1.inverse();
        std::cout << "Inverse of Matrix 1:" << std::endl;
        m5.display();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
