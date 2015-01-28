#ifndef _STDINT_H_
#define _STDINT_H_


typedef signed char		int8_t;
typedef signed short		int16_t;
typedef signed int 		int32_t;
typedef signed long long	int64_t;
typedef __int128		int128_t;

typedef unsigned char		uint8_t;
typedef unsigned short		uint16_t;
typedef unsigned long		uint32_t;
typedef unsigned long long	uint64_t;
typedef unsigned __int128	uint128_t;


typedef int64_t			native_int_t;
typedef uint64_t		native_uint_t;


typedef native_uint_t		ptr_t;


typedef native_int_t		ssize_t;
typedef native_uint_t		size_t;


#endif
