#include <stdio.h>
#include <string.h>
#ifndef B64_H
#define B64_H 1
#endif
unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p){
	int* ip = (int*)p;
	int i;
	int res=0;
	for(i=0; i<5; i++){
		res += ip[i];
	}
	return res;
}

char *b64_encode (const unsigned char *, size_t);
static const char b64_table[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '+', '/'
};

int main(int argc, char* argv[]){
	if (argc < 2){
		printf("usage : %s filename\n", *argv);
		return;
	}
	char* filename = argv[1];
	char* compare = "EthicalHacking";
	int res = argc == 2;
	int t = 15;
	do {
		if(!t){
			break;
		}
		res = *filename++ == *compare++;
		t--;
	} while (res);
	if (!res){
		printf("filename wrong\n");
		return;
	}
	FILE *fp = fopen(argv[1], "rb");
	if (!fp) {
		printf("open file failure\n");
		return;
	}
	char t1[10];
	char t2[43];
	fgets(t1, 10, fp);
	fgets(t2, 43, fp);
	t = 9;
	char* tmp = t1;
	compare = "enterkey ";
	do {
		if(!t) {
			break;
		}
		res = *tmp++ == *compare++;
		t--;
	}while(res);
	if(!res || strlen(t2) != 42){
		printf("something wrong in your file\n");
		return;
	}
	int i = 0;
	for(i = 0; i < 10; i++){
		t2[i] -= 2;
	}
	for(i = 10; i < 34; i++){
		t2[i] += 1;
	}
	char subs[9];
	memcpy(subs, &t2[34], 8);
	subs[8] = '\0';
	char *enc = b64_encode(subs, strlen(subs));
	char f[47];
	strncpy(f, t2, 34);
	f[34] = '\0';
	strncat(f, enc, strlen(enc));
	f[46] = '\0';
	t = 46;
	tmp = f;
	compare = "qcapcrsqcpzpvdboopuhfuuijtqbttxpseMTEyMzU4MTM=";
	do {
		if(!t) {
			break;
		}
		res = *tmp++ == *compare++;
		t--;
	}while(res);
	if(!res){
		printf("something wrong in your file\n");
		return;
	}
	printf("key is the second string in your file!\n");
	return;
}

char *b64_encode (const unsigned char *src, size_t len) {
  int i = 0;
  int j = 0;
  char *enc = NULL;
  size_t size = 0;
  unsigned char buf[4];
  unsigned char tmp[3];

  // alloc
  enc = (char *) malloc(0);
  if (NULL == enc) { return NULL; }

  // parse until end of source
  while (len--) {
    // read up to 3 bytes at a time into `tmp'
    tmp[i++] = *(src++);

    // if 3 bytes read then encode into `buf'
    if (3 == i) {
      buf[0] = (tmp[0] & 0xfc) >> 2;
      buf[1] = ((tmp[0] & 0x03) << 4) + ((tmp[1] & 0xf0) >> 4);
      buf[2] = ((tmp[1] & 0x0f) << 2) + ((tmp[2] & 0xc0) >> 6);
      buf[3] = tmp[2] & 0x3f;

      // allocate 4 new byts for `enc` and
      // then translate each encoded buffer
      // part by index from the base 64 index table
      // into `enc' unsigned char array
      enc = (char *) realloc(enc, size + 4);
      for (i = 0; i < 4; ++i) {
        enc[size++] = b64_table[buf[i]];
      }

      // reset index
      i = 0;
    }
  }

  // remainder
  if (i > 0) {
    // fill `tmp' with `\0' at most 3 times
    for (j = i; j < 3; ++j) {
      tmp[j] = '\0';
    }

    // perform same codec as above
    buf[0] = (tmp[0] & 0xfc) >> 2;
    buf[1] = ((tmp[0] & 0x03) << 4) + ((tmp[1] & 0xf0) >> 4);
    buf[2] = ((tmp[1] & 0x0f) << 2) + ((tmp[2] & 0xc0) >> 6);
    buf[3] = tmp[2] & 0x3f;

    // perform same write to `enc` with new allocation
    for (j = 0; (j < i + 1); ++j) {
      enc = (char *) realloc(enc, size + 1);
      enc[size++] = b64_table[buf[j]];
    }

    // while there is still a remainder
    // append `=' to `enc'
    while ((i++ < 3)) {
      enc = (char *) realloc(enc, size + 1);
      enc[size++] = '=';
    }
  }

  // Make sure we have enough space to add '\0' character at end.
  enc = (char *) realloc(enc, size + 1);
  enc[size] = '\0';

  return enc;
}
