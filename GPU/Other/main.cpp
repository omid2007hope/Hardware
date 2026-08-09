#include <cuda_runtime.h>
#include <iostream>

__global__ void add_vectors(const float* A, float* B, float* C, int N) {

	int i = blockIdx.x * blockDim.x + threadIdx.x;
}


int main() {

};