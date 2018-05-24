/*
*  sha1.h
*
*  Description:
*      This is the header file for code which implements the Secure
*      Hashing Algorithm 1 as defined in FIPS PUB 180-1 published
*      April 17, 1995.
*
*      Many of the variable names in this code, especially the
*      single character names, were used because those were the names
*      used in the publication.
*
*      Please read the file sha1.c for more information.
*
*/

#ifndef _SHA1_H_
#define _SHA1_H_

//#include <stdint.h>
/*
* If you do not have the ISO standard stdint.h header file, then you
* must typdef the following:
*    name              meaning
*  uint32_t         unsigned 32 bit integer
*  uint8_t          unsigned 8 bit integer (i.e., unsigned char)
*  int_least16_t    integer of >= 16 bits
*
*/
//defined in .cpp instead of .h


#ifndef _SHA_enum_
#define _SHA_enum_
enum
{
	shaSuccess = 0,
	shaNull,            /* Null pointer parameter */
	shaInputTooLong,    /* input data too long */
	shaStateError       /* called Input after Result */
};
#endif
#define SHA1HashSize 20

/*
*  This structure will hold context information for the SHA-1
*  hashing operation
*/
typedef struct SHA1Context
{
	unsigned int Intermediate_Hash[SHA1HashSize/4]; /* Message Digest  */

	unsigned int Length_Low;            /* Message length in bits      */
	unsigned int Length_High;           /* Message length in bits      */

	/* Index into message block array   */
	int Message_Block_Index;
	unsigned char Message_Block[64];      /* 512-bit message blocks      */

	int Computed;               /* Is the digest computed?         */
	int Corrupted;             /* Is the message digest corrupted? */
} SHA1Context;

/*
*  Function Prototypes
*/

int SHA1Reset(  SHA1Context *);
int SHA1Input(  SHA1Context *,
			  const unsigned char *,
			  unsigned int);
int SHA1Result( SHA1Context *,
			   unsigned char Message_Digest[SHA1HashSize]);

#endif
