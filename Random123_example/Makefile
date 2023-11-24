# パスとコンパイラの設定
CUDA_PATH = /usr/local/cuda
CUDA_BIN_PATH = $(CUDA_PATH)/bin
CUDA_INCLUDE_PATH = $(CUDA_PATH)/include
CUDA_LIB_PATH = $(CUDA_PATH)/lib64
NVCC = $(CUDA_BIN_PATH)/nvcc

# Random123のインクルードパス
RANDOM123_INCLUDE_PATH = /home/rio/work/git/ONEMAX/Random123

# ターゲットとソースファイル
TARGET = rand123Philox curand_sample
#SOURCE = rand123Philox.cu

# フラグとライブラリの設定
NVCC_FLAGS = -I$(CUDA_INCLUDE_PATH) -arch=sm_60
NVCC_FLAGS_RAND123 = -I$(CUDA_INCLUDE_PATH) -I$(RANDOM123_INCLUDE_PATH) -arch=sm_60
LIBS = -L$(CUDA_LIB_PATH) -lcudart -lcurand

# コンパイルルール
all: $(TARGET)

rand123Philox: rand123Philox.cu
	$(NVCC) $(NVCC_FLAGS_RAND123) $^ -o $@ $(LIBS)

curand_sample: curand_sample.cu
	$(NVCC) $(NVCC_FLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
