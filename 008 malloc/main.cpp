#include <memory>
#include <cassert>

void* aligned_malloc(size_t size, size_t alignment) {
	// align为2的整数倍
	assert((alignment & (alignment - 1)) == 0);

	// malloc内存(需要的大小+一个用以保存buff地址的指针的大小+调整对齐需要的冗余大小)
	void* data = malloc(size + sizeof(void*) + alignment);

	if (data == nullptr)
		return nullptr;

	// data转为void**(即data保存指针)，移一位出来存buff首地址
	void* temp = (void**)data + 1;
	
	// 将adata对齐到align
	void* adata = (void*)(((size_t)temp + alignment - 1) & ~(size_t)(alignment - 1));
	
	// -1位置存放buff的首地址
	((void**)adata)[-1] = data;
	
	return adata;
}

void aligned_free(void* adata) {
	void* data = ((void**)adata)[-1];
	free(data);
}

int main(int argc, char** argv) {

	size_t size = 1000;
	size_t alignment = 64;
	
	void* adata = aligned_malloc(size, alignment);

	printf("%lu\n", (size_t)adata % alignment);

	aligned_free(adata);
}
