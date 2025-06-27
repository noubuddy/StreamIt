#pragma once
#ifndef SIGNALIT_TYPES_H
#define SIGNALIT_TYPES_H

#include <stdint.h>

///* Signed integer types *///
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

///* Unsigned integer types *///
typedef uint8_t byte;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef size_t sz;

///* Floating types *///
typedef float f32;
typedef double f64;

typedef const char* STRING;
typedef u64 SOCKET;
typedef void* VOIDPTR;

#endif //SIGNALIT_TYPES_H