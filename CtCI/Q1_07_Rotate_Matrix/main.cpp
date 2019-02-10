
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

void rotateLayer(Matrix& mMatrix, int layer) {
  const int size = mMatrix.size();

  int lastItem = size - layer - 1;

  int i;
  for (i = layer; i < size - layer - 1; i++) {
    swap(mMatrix[layer][layer + i], mMatrix[layer + i][lastItem]);
    swap(mMatrix[layer + i][lastItem],
         mMatrix[lastItem][lastItem - i]);
    swap(mMatrix[lastItem][lastItem - i], mMatrix[lastItem - i][layer]);
  }
}

void rotateMatrix(Matrix& mMatrix) {
  const int size = mMatrix.size();
  const int layers = ceil(size / 2.0);
  for (int layer = 0; layer < layers; layer++) {
    rotateLayer(mMatrix, layer);
  }
}

void printMatrix(Matrix mMatrix) {
  for (const auto& row : mMatrix) {
    for (const auto& column : row) {
      cout << column << " ";
    }
    cout << endl;
  }
}
int main() {
  int const MATRIX_SIZE = 5;
  Matrix mMatrix = {{1, 2, 3, 4, 5},
                    {1, 2, 3, 4, 5},
                    {1, 2, 3, 4, 5},
                    {1, 2, 3, 4, 5},
                    {1, 2, 3, 4, 5}};

  printMatrix(mMatrix);

  cout << "rotating ===>" << endl;

  rotateMatrix(mMatrix);

  printMatrix(mMatrix);
  return 0;
}
