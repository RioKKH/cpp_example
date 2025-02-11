#include <cuda_runtime.h>
#include <iostream>
#include "Random123/philox.h"

const int N = 96;

__global__ void generateRandomNumbers(uint32_t* output)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    // printf("idx: %d\n", idx);
    r123::Philox4x32 rng;
    r123::Philox4x32::key_type key = {{idx, 0}};
    r123::Philox4x32::ctr_type ctr = {{0, 0}};

    auto result = rng(ctr, key);
    output[idx] = result.v[0];
    __syncthreads();
}

int main() {
    uint32_t* d_output;
    uint32_t* h_output[N];

    cudaMalloc(&d_output, N * sizeof(uint32_t));
    generateRandomNumbers<<<N/32, 32>>>(d_output);
    cudaMemcpy(h_output, d_output, N * sizeof(uint32_t), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) {
        std::cout << h_output[i] << std::endl;
    }

    cudaFree(d_output);
    return 0;
}
