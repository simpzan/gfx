
.PHONY: vktest
vktest: 26_texture_mapping.cpp
	g++ utils.cpp -c -o utils.o -I `pwd` -std=c++17
	g++ 26_texture_mapping.cpp -c -o main.o \
		-std=c++17 \
		-I ${HOME}/VulkanSDK/1.3.236.0/macOS/include/ \
		`pkg-config --cflags glfw3` \
		-I `pwd`
	g++ main.o  utils.o -o vktest -lvulkan \
		`pkg-config --libs glfw3`
	/Users/simpzan/VulkanSDK/1.3.236.0/macOS/bin/glslc 26_shader_textures.vert -o vert.spv
	/Users/simpzan/VulkanSDK/1.3.236.0/macOS/bin/glslc 26_shader_textures.frag -o frag.spv
	./vktest

clean:
	rm -rf *.spv vktest *.o
