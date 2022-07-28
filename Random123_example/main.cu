#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include "CUDAKernels.hpp"

int main(int argc, char* argv[])
{
    int n; // number of device
    unsigned int N = 100;

    float *phost_rand1;
    float *phost_rand2;

    float *pdev_rand1;
    float *pdev_rand2;

    cudaDeviceProp prop;
    int mMultiProcessorCount;
    int THREADS_NUM = 256;

    phost_rand1 = (float *)malloc(N * sizeof(float));
    phost_rand2 = (float *)malloc(N * sizeof(float));

    for (int i = 0; i < N; ++i)
    {
        phost_rand1[i] = 0;
        phost_rand2[i] = 0;
    }

#ifdef _DEBUG
    for (int i = 0; i < N; ++i)
    {
        printf("%f, %f\n", phost_rand1[i], phost_rand2[i]);
    }
#endif // _DEBUG

    cudaMalloc((void **)&pdev_rand1, N * sizeof(float));
    cudaMalloc((void **)&pdev_rand2, N * sizeof(float));

    cudaMemcpy(phost_rand1, pdev_rand1, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(phost_rand2, pdev_rand2, N * sizeof(float), cudaMemcpyHostToDevice);

    cudaGetDeviceCount(&n);
#ifdef _DEBUG
    for (int i = 0; i < n; ++i)
    {
        cudaGetDeviceProperties(&prop, i);

        printf("device %d\n", i);
        printf("device name : %s\n", prop.name);
        printf("total global memory : %ld (MB)\n", prop.totalGlobalMem/1024/1024);
        printf("shared memory : %ld (KB)\n", prop.sharedMemPerBlock/1024);
        printf("register / block : %d\n", prop.regsPerBlock);
        printf("warp size : %d\n", prop.warpSize);
        printf("max pitch : %ld (B)\n", prop.memPitch);
        printf("max thread / block : %d\n", prop.maxThreadsPerBlock);
        printf("max size of each dim. of block : (%d, %d, %d)\n", 
                prop.maxThreadsDim[0], prop.maxThreadsDim[1], prop.maxThreadsDim[2]);
        printf("max size of each dim. of grid : (%d, %d, %d)\n", 
                prop.maxGridSize[0], prop.maxGridSize[1], prop.maxGridSize[2]);
        printf("clock rate : %d (MHz)\n", prop.clockRate);
        printf("total constant memory : %ld (KB)\n", prop.totalConstMem);
        printf("comute capatility  : %d.%d\n", prop.major, prop.minor);
        printf("alignment requirement for texture : %ld\n", prop.textureAlignment);
        printf("device overlap : %s\n", (prop.deviceOverlap ? "OK" : "NOT"));
        printf("num. of multiprocessors : %d\n", prop.multiProcessorCount);
        printf("kernel execution timeout : %s\n", (prop.kernelExecTimeoutEnabled ? "ON" : "OFF"));
        printf("integrate : %s\n", (prop.integrated ? "ON" : "OFF"));
        printf("host memory mapping : %s\n", (prop.canMapHostMemory ? "ON" : "OFF"));
        printf("compute mode : \n");
        if (prop.computeMode == cudaComputeModeDefault) printf("default mode (multiple threads can be used\n");
        else if (prop.computeMode == cudaComputeModeExclusive) printf("exclusive mode (only one thread can be used)\n");
        else if (prop.computeMode == cudaComputeModeProhibited) printf("prohibited mode (no threads can be used\n)");
    }
#endif
    mMultiProcessorCount = prop.multiProcessorCount;

    // cudaGenerateRandomNumberKernelTest<<<mMultiProcessorCount * 2, THREADS_NUM>>>();
    printf("pre\n");
    // cudaTest<<<1, 1>>>();
    cudaGenerateRandomNumberKernel<<<10, 10>>>(pdev_rand1, pdev_rand2, N);
    cudaDeviceSynchronize();
    printf("post\n");
    // cudaGenerateRandomNumberKernel<<<mMultiProcessorCount * 2, THREADS_NUM>>>(pdev_rand1, pdev_rand2, N);

    cudaFree(pdev_rand1);
    cudaFree(pdev_rand2);

    return 0;
}
