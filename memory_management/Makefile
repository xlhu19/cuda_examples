

SOURCE := uma.cu
OBJECT := uma

uma: uma.cu
	nvcc -O3 -arch=sm_32 uma.cu -o uma

.PHONY: clean
clean:
	@rm -rf ${OBJECT}
