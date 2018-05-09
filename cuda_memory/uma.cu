/*****************************************************
* This file tests cuda memory management APIs.
*****************************************************/
#include <cuda_runtime.h>
#include <stdio.h>

void initialData(float *h, long long n, float data) {
    long long i;
    for (i = 0; i < n; i++) {
        h[i] = data;
    }
}

__global__ void vecAdd(float* A, float* B, float* C)
{
    long long i = blockIdx.x * blockDim.x + threadIdx.x;
    C[i] = A[i] + B[i];
}

void test_cudaDeviceGetAttribute(int* value, cudaDeviceAttr attr, int device) {
    cudaDeviceGetAttribute(value, attr, device);
}

void test_cudaMallocManaged(int dev, int ipower) {
    int val;

    // Check if supports managed memory
    cudaDeviceGetAttribute(&val, cudaDevAttrManagedMemory, dev);
    if (!val) {
        printf("*** Error: Managed memory is not supported!\n");
        return;
    }

    // Check concurrent managed access, for cuda 8.0
    cudaDeviceGetAttribute(&val, cudaDevAttrConcurrentManagedAccess, dev);
    if (!val) {
        printf("*** Warn: Concurrent managed access is not supported!\n");
    }

    // Calculate number of elements and bytes
    long long nElem = ((long long)1)<<ipower;
    long long nBytes = nElem * sizeof(float);
    if (ipower < 18) {
        printf("Vector size is %lld, nbytes is %f KB\n", nElem, (float)nBytes/(1024.0f));
    } else {
        printf("Vector size is %lld, nbytes is %f MB\n", nElem, (float)nBytes/(1024.0f*1024.0f));
    }

    // allocate memory
    float *g_A, *g_B, *g_C;
    float *g_D, *g_E, *g_F;
    // unsigned int flags = cudaMemAttachHost;
    unsigned int flags = cudaMemAttachGlobal;
    int ret1 = cudaMallocManaged(&g_A, nBytes, flags);
    int ret2 = cudaMallocManaged(&g_B, nBytes, flags);
    int ret3 = cudaMallocManaged(&g_C, nBytes, flags);
    int ret4 = cudaMallocManaged(&g_D, nBytes, flags);
    int ret5 = cudaMallocManaged(&g_E, nBytes, flags);
    int ret6 = cudaMallocManaged(&g_F, nBytes, flags);
    printf("===== %d %d %d %d %d %d\n", ret1, ret2, ret3, ret4, ret5, ret6);

    printf("===== inital data begins...\n");
    initialData(g_A, nElem, 2.0f);
    initialData(g_B, nElem, 2.0f);
    initialData(g_D, nElem, 2.0f);
    initialData(g_E, nElem, 2.0f);
    printf("===== synchronize begins...\n");
    cudaDeviceSynchronize();

    printf("===== add data begins...\n");
    dim3 threadsPerBlock(1024);
    dim3 numBlocks((nElem)/threadsPerBlock.x);
    printf("===== numBlocks is %d, threadsPerBlock is %d\n", numBlocks.x, threadsPerBlock.x);
    // Kernel invocation with N threads
    vecAdd<<<numBlocks, threadsPerBlock>>>(g_A, g_B, g_C);
    cudaDeviceSynchronize();
    vecAdd<<<numBlocks, threadsPerBlock>>>(g_D, g_E, g_F);
    cudaDeviceSynchronize();

    printf("===== check the results...\n");

    long long i;
    float ans = 4.0f;
    printf("===== ans is %f\n", ans);
    for (i = 0; i < nElem; i++) {
        if (g_C[i] != ans) {
            printf("Result g_C[%lld] is error, error value is %3.0f\n", i, g_C[i]);
            break;
        }
        if (g_F[i] != ans) {
            printf("Result g_F[%lld] is error, error value is %3.0f\n", i, g_F[i]);
            break;
        }
        // printf("Result g_C[%lld] value is %3.0f\n", i, g_C[i]);
    }

    cudaFree(g_A);
    cudaFree(g_B);
    cudaFree(g_C);
    cudaFree(g_D);
    cudaFree(g_E);
    cudaFree(g_F);
    cudaDeviceReset();

}

int main(int argc, char* argv[]) {

    // set up device
    int dev = 0;
    cudaSetDevice(dev);

    // get device properties
    cudaDeviceProp deviceProp;
    cudaGetDeviceProperties(&deviceProp, dev);

    // check uva supporting
    if (deviceProp.unifiedAddressing) {
        printf("Device %d supports uva memory!\n", dev);
    }
    else {
        printf("Device %d does not support uva memory!\n", dev);
        exit(EXIT_SUCCESS);
    }

    // set up date size of vectors
    int ipower = 10;
    if (argc > 1) ipower = atoi(argv[1]);

    test_cudaMallocManaged(dev, ipower);

}
