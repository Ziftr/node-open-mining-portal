#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

#include "zr5.h"

// g++ zr5test.cpp zr5.c -o testzr5
int main(int argc, char* argv[])
{
	int			passed = 0;
	int			failed = 0;
	unsigned int	i;
	uint8_t		zr5_out_512[64];
//	char		test0[] = "\x01\x00\x00\x00\x4e\x42\xb7\x59\xbd\x65\x68\x59\x9c\xff\x71\x4b\x67\x9d\xbf\x94\x6543c9ba\x8444f7b8\xb964bf21\x71070000\xc6bb8526\xc7e59d3b\xc92afd77\xb11e544a\xf69ae0d4\xda4f98bc\x6e981f3d\xbb20f185\xa918e654\xffff0b1e\x00000000";
	// three byte test
//	uint8_t 		test1[] = "\x00\x11\x22";
	uint8_t		   test1[] = "\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x2a\xb0\x32\x51\x87\xd4\xf2\x8b\x6e\x22\xf0\x86\x48\x45\xdd\xd5\x0a\xc4\xe6\xaa\x22\xa1\x70\x9f\xfb\x42\x75\xd9\x25\xf2\x66\x36\x30\x0e\xed\x54\xff\xff\x0f\x1e\xa4\x0d\x12\x00";
	uint8_t		 xpec_k1[] = "\x4b\xcf\x8f\x62\x57\x19\x23\x4e\xf2\xf9\x6e\xd5\x5d\x6d\xa3\x55\xbb\xbc\xc9\xb9\x95\x95\xa2\x80\xff\x9a\x85\x61\xbe\x3d\x70\x42\xe5\xe8\x8c\x0c\x59\x4d\x6e\x3c\x8e\x41\x53\xb9\x81\xe0\x1c\x60\x8d\xbe\xd2\xc5\x7b\xc3\xb8\x89\x42\xe0\xa5\x9b\xcd\x06\x9a\x07";
	uint8_t		empty[] = "\x00\x00\x00\x00\x00\x00\x00\x00";
//	uint8_t 	  xpec_k1[] = "\x94\x77\x84\xf1\x39\x86\x9e\xac\xae\xff\x6b\xd6\x72\x97\xa4\xfb\xb6\xec\x56\x2a\x50\xfa\x17\x4f\x95\x2c\x75\x9b\x2e\x1a\xcf\x73\xf6\xf8\x0a\x0f\x6e\x24\x12\x73\x9a\x80\xdc\xe0\x41\x45\xc5\xb4\x5b\x72\xb1\xb7\xb1\xd2\x25\x97\x23\xaa\xa7\x04\xfa\xae\x5b\xe6";
	uint8_t 	xpec1_512[] = "\xf5\x2f\x44\x4f\x7e\xe6\xa5\x0b\x19\x7c\xc9\xf0\x3e\xd0\x2d\xbe\xec\x3d\xe9\x10\xd1\x84\xb1\xd2\x03\xc7\xf1\xe0\x45\x4e\xd1\xb3\x28\x0a\xab\x39\xdc\x67\xa6\xff\xdb\xdb\x42\x8c\x48\xce\xa4\xae\x5e\xa5\x60\x15\x4c\x8a\xd0\x16\xdd\xf3\x8d\x2e\x7c\x49\xfc\x2e";
	uint8_t 		xpec1[] = "\x28\x0a\xab\x39\xdc\x67\xa6\xff\xdb\xdb\x42\x8c\x48\xce\xa4\xae\x5e\xa5\x60\x15\x4c\x8a\xd0\x16\xdd\xf3\x8d\x2e\x7c\x49\xfc\x2e";

	// 65 byte test
	uint8_t		test2[] = "\x04\xfc\x97\x02\x84\x78\x40\xaa\xf1\x95\xde\x84\x42\xeb\xec\xed\xf5\xb0\x95\xcd\xbb\x9b\xc7\x16\xbd\xa9\x11\x09\x71\xb2\x8a\x49\xe0\xea\xd8\x56\x4f\xf0\xdb\x22\x20\x9e\x03\x74\x78\x2c\x09\x3b\xb8\x99\x69\x2d\x52\x4e\x9d\x6a\x69\x56\xe7\xc5\xec\xbc\xd6\x82\x84";
	uint8_t	  xpec_k2[] = "\x62\xf8\xd0\xca\x61\xeb\xbe\xef\x22\x31\x37\xf5\x71\xd6\x5c\xf7\x0f\x1a\x89\xce\x44\x07\x46\x83\x02\x3e\x25\x8c\xa8\x48\xb5\x23\xb7\x18\x39\x67\x15\x61\xf3\x5e\x5a\x26\x50\xb0\x03\x8e\xf6\xfb\x90\x7b\xc7\xb3\x81\x2c\x34\x42\x3b\x3b\xd6\x77\xb0\x22\xa3\x39";
	uint8_t	xpec2_512[] = "\xa7\x9c\xeb\x61\x08\xa9\xe3\xf0\xcf\x4a\xd6\xd0\x50\x46\x19\x76\xaa\xae\xb1\xa4\xa8\x5b\xcb\xb3\x84\x26\x46\xf9\x9d\xf7\xf6\xc3\x85\xff\xc1\xbf\x48\x08\x41\xe3\x65\x70\xd6\x9f\xd8\x5f\xff\xe5\xd9\x21\x66\x6c\xad\x28\x8b\x70\xc9\x4a\x40\xe2\xd4\xa2\xc9\x28";
	char		xpec2[] = "\x85\xff\xc1\xbf\x48\x08\x41\xe3\x65\x70\xd6\x9f\xd8\x5f\xff\xe5\xd9\x21\x66\x6c\xad\x28\x8b\x70\xc9\x4a\x40\xe2\xd4\xa2\xc9\x28";

	// 80 byte test
	uint8_t		test3[] = "\x01\x80\x64\x86\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x2a\xb0\x32\x51\x87\xd4\xf2\x8b\x6e\x22\xf0\x86\x48\x45\xdd\xd5\x0a\xc4\xe6\xaa\x22\xa1\x70\x9f\xfb\x42\x75\xd9\x25\xf2\x66\x36\x30\x0e\xed\x54\xff\xff\x0f\x1e\x2a\x9e\x23\x00";
	uint8_t	  xpec_k3[] = "\0x51\xb4\x30\x9f\x78\x9f\xba\xa7\xe5\xf0\x40\x2b\x70\x07\x2a\x60\xe8\xa7\x05\xb1\x95\x92\x38\x6b\xd1\x36\x37\x79\x93\x5c\x45\xf0\x11\xe1\x33\x63\x49\x18\x20\x95\x03\x92\x50\x2a\x9d\x3c\x1f\x76\x45\x1c\x37\x9f\x9d\x98\x3c\x98\x86\x43\x22\xf2\xec\xb9\x5f\x84";
	uint8_t	xpec3_512[] = "\xee\x0c\x3d\x3b\xe3\xdc\x49\xed\x47\xa6\x0b\xda\x98\x76\x1e\xc6\x01\x2b\x8c\x3f\x54\xc5\x86\xd1\x00\x9f\xe5\x96\xef\xc5\x4c\x35\x00\x00\x03\x58\x88\xfe\xa2\xf9\x6e\x3e\xf9\x96\xbe\xda\x4f\xa4\xc4\xc4\xd0\x3b\x37\x11\x84\xd1\xf5\x75\xf9\xd1\x44\xb7\xa1\x64";
	uint8_t		xpec3[] = "\x00\x00\x03\x58\x88\xfe\xa2\xf9\x6e\x3e\xf9\x96\xbe\xda\x4f\xa4\xc4\xc4\xd0\x3b\x37\x11\x84\xd1\xf5\x75\xf9\xd1\x44\xb7\xa1\x64";
	uint8_t	xr5_out[64];

	// another 80 byte test from the second examples
	uint8_t		   test4[] = "\x0100000000000000000000000000000000000000000000000000000000000000000000002ab0325187d4f28b6e22f0864845ddd50ac4e6aa22a1709ffb4275d925f26636300eed54ffff0f1ea40d1200";
	uint8_t		 xpec_k4[] = "\x4bcf8f625719234ef2f96ed55d6da355bbbcc9b99595a280ff9a8561be3d7042e5e88c0c594d6e3c8e4153b981e01c608dbed2c57bc3b88942e0a59bcd069a07";
	uint8_t		  skein4[] = "\xcaa3298105207e16cf3bd464483b73ad427b2f55a2230adc9147e7900272feedf616bdfa45bdafc204a260354b6dd81e0a9ff5d5e1789e9137ba77c33ed251b3";
	uint8_t		  blake4[] = "\x8b27abbe2e770d4c90baa70b11d5e9c265069a3f19bc674231c5310a956b55d12fd87857492a69abf173abd8ac25bc314c9e2e923158d9befc005a9c8652fa58";
	uint8_t			 jh4[] = "\xb4a6f585883594ccfda48a751c7d88d6321e8e2023a060fd67ae7009282b92b1f9976f4e93d453facbb81a4219158b7759abe1dedb4734b48a73a6d60f2c64bf";
	uint8_t		groestl4[] = "\x98e4dc0281fa2cdf48e616475a420dae425c99467630b0c4edb3ae6eafeba8171d2843fea919bb169fd3c76369db10fdc990ea83228dae51e21035b4c122d765";
	uint8_t		 zr5_512[] = "\65d722c1b43510e251ae8d2283ea90c9fd10db6963c7d39f16bb19a9fe43281d17a8ebaf6eaeb3edc4b0307646995c42ae0d425a4716e648df2cfa8102dce498";

	printf("zr5_hash_512 test1 input: ");
	for(i=0; i< 3; i++) { printf("%02x", test1[i]); }
	printf("\n");
	printf("%12s", "ExpectedK: ");
	for(i=0; i< 64; i++) { printf("%02x", xpec_k1[i]); }
	printf("\n");
	uint32_t gls32 = getleastsig32((uint8_t *)&xpec_k1[0], 0);
	printf("Expected getleastsig32: %u   (0x", gls32);
	for(i=0; i< sizeof(uint32_t); i++)
		{ printf("%02x", *( (uint8_t *)(&gls32) + i) ); }
	printf(")\n");
//	zr5_hash(test1, zr5_out_512, (uint32_t)sizeof(test1) );
	zr5_hash(test1, zr5_out_512, 80 );
	printf("%12s", "Expected: ");
	for(i=0; i< 64; i++) { printf("%02x", xpec1_512[i]); }
	printf("\n");
	printf("%12s", "Got: ");
	for(i=0; i< 64; i++) { printf("%02x", zr5_out_512[i]); }
	printf("\n\n");

/*
	printf("zr5_hash_512 test2 input: ");
	for(i=0; i< sizeof(test2); i++) { printf("%02x", test2[i]); }
	printf("\n)");
	printf("%12s", "ExpectedK: ");
	for(i=0; i< sizeof(xpec_k2); i++) { printf("%02x", xpec_k2[i]); }
	printf("\n");
	zr5_hash(test2, zr5_out_512, (uint32_t)sizeof(test2) );

	printf("zr5_hash_512 test3 input: ");
	for(i=0; i< sizeof(test3); i++) { printf("%02x", test3[i]); }
	printf("\n)");
	printf("%12s", "ExpectedK: ");
	for(i=0; i< sizeof(xpec_k3); i++) { printf("%02x", xpec_k3[i]); }
	printf("\n");
	zr5_hash(test3, zr5_out_512, (uint32_t)sizeof(test3) );
*/

	printf("%d tests total.\n", passed+failed);
	printf("%d tests passed.\n", passed);
	printf("%d tests failed.\n", failed);

	return 0;
}

