/*
 * Common code for the StarOffice format.
 */

#include <string.h>

#include "formats.h"

#define FORMAT_NAME             "StarOffice (.sxc, .sdw, .sxd, .sxw, .sxi)"
#define FORMAT_TAG              "$sxc$*"
#define FORMAT_TAG_LEN          (sizeof(FORMAT_TAG)-1)
#define BINARY_SIZE             20

struct custom_salt {
	int cipher_type; // FIXME: cipher_type seems to be ignored. NOTE: only samples with Blowfish exist / are known.
	int checksum_type;
	int iterations;
	int key_size;
	int iv_length;
	int salt_length;
	int original_length;
	int length;
	unsigned char iv[16];
	unsigned char salt[32];
	unsigned char content[1024];
};

extern struct fmt_tests staroffice_tests[];

extern int staroffice_valid(char *ciphertext, struct fmt_main *self);
extern void *staroffice_get_salt(char *ciphertext);
extern void *staroffice_get_binary(char *ciphertext);
