#include <cuda_runtime.h>
#include <curand_kernel.h>
#include <iostream>

const int N = 1024;

__global__ void generateRandomNumbers(curandStatePhilox4_32_10_t* states, float* output) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    curand_init(tid, 0, 0, &states[tid]);
    output[tid] = curand_uniform(&states[tid]);
}

int main() {
    curandStatePhilox4_32_10_t* d_states;
    float h_output[N];

    cudaMalloc(&d_states, N * sizeof(curandStatePhilox4_32_10_t));
    // cudaMalloc(&h_output, N * sizeof(float));
    generateRandomNumbers<<<N/256, 256>>>(d_states, h_output);
    cudaMemcpy(h_output, d_states, N * sizeof(float), cudaMemcpyDeviceToHost);

    for (int i = 0; i < 10; i++) {
        std::cout << h_output[i] << std::endl;
    }

    cudaFree(d_states);
    cudaFree(h_output);
    return 0;
}
