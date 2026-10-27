/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

/*
 * Minimal <sys/mman.h> for H2 + picolibc builds whose picolibc doesn't
 * provide one (e.g. the CodeLinaro Hexagon toolchains).  Only what
 * sys_mmap.c and the syscall wrapper's mmap()/munmap()/mprotect() need;
 * values follow Linux/musl.
 */
#ifndef H2_SYS_MMAN_H
#define H2_SYS_MMAN_H

#include <sys/types.h>

#define PROT_NONE	0x0
#define PROT_READ	0x1
#define PROT_WRITE	0x2
#define PROT_EXEC	0x4

#define MAP_SHARED	0x01
#define MAP_PRIVATE	0x02
#define MAP_FIXED	0x10
#define MAP_ANONYMOUS	0x20
#define MAP_ANON	MAP_ANONYMOUS

#define MAP_FAILED	((void *)-1)

void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off);
int munmap(void *addr, size_t len);
int mprotect(void *addr, size_t len, int prot);

#endif /* H2_SYS_MMAN_H */
