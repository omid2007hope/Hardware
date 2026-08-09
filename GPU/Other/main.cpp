#include <cuda_runtime.h>
#include <iostream>

__global__ void add_vectors(const float* A, float* B, float* C, int N) {
	// ! This specifies the block index of the current thread within the x-dimension of the thread grid
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < N) {
		C[i] = A[i] + B[i];
	}
}


int main() {
	int N = 1e6;
	size_t bytes = N * sizeof(float);

	// ! Learned here -- learn down here

	float *d_A, *d_B, *d_C;
	cudaMalloc(&d_A, bytes);
	cudaMalloc(&d_B, bytes);
	cudaMalloc(&d_C, bytes);

	// Launch kernel with 256 threads per block
	int threads_per_block = 256;
	int blocks = (N + threads_per_block - 1) / threads_per_block;
	add_vectors<<<blocks, threads_per_block>>>(d_A, d_B, d_C, N);

	cudaDeviceSynchronize();
	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);
	return 0;
};