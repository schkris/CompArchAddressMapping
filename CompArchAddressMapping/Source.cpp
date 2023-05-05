#include <iostream>
#include <cmath>

int main()
{
	int address;
	int associativity;
	int wordPerBlock;
	int capacity;
	std::cout<<"Please enter a hex address to define its mapping: "<<std::endl;
	scanf_s("%x", &address);
	std::cout << "Please enter the associativity (-1 for direct-mapped and 0 for fully associative): " << std::endl;
	std::cin >> associativity;
	std::cout << "Please enter the capacity in bytes: " << std::endl;
	std::cin >> capacity;
	std::cout << "Please enter the number of words per block: " << std::endl;
	std::cin >> wordPerBlock;
	if (associativity == -1)
	{

	}
	else if (associativity == 0)
	{

	}
	else if (associativity > 0)
	{
		// First 2 bits
		int byteOffset = (address >> 30) & 0x03;
		printf("Byte Offset = 0X%X\n", byteOffset);

		int blockOffsetLength = log2(wordPerBlock);
		// Take the next "blockOffsetLength" number of digits after byteOffset
		int blockOffset = (address >> 2) & ((1 << blockOffsetLength) - 1);
		int blockOffsetExt = (blockOffset << 2) | byteOffset;
		printf("Word Offset = 0X%X or 0X%X\n", blockOffset, blockOffsetExt);

		// Assuming 32 bit architecture, 4 bytes in a word
		int wordNum = capacity / 4;
		int blockNum = wordNum / wordPerBlock;
		int setNum = blockNum / associativity;
		int setNumLength = log2(setNum);
		int setSelection = (address >> (2+ blockOffsetLength)) & ((1 << setNumLength) - 1);
		printf("Set Selection = 0X%X\n", setSelection);
		int tag = address >> (2 + setNumLength + blockOffsetLength);
		printf("Tag = 0X%X\n", tag);
	}
}