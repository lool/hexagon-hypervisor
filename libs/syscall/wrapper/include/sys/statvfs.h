/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

/*
 * Minimal POSIX <sys/statvfs.h> for H2 + picolibc builds whose picolibc
 * doesn't provide one; syscall_wrapper.c only needs the declarations.
 */
#ifndef H2_SYS_STATVFS_H
#define H2_SYS_STATVFS_H

#include <sys/types.h>


struct statvfs {
	unsigned long	f_bsize;
	unsigned long	f_frsize;
	fsblkcnt_t	f_blocks;
	fsblkcnt_t	f_bfree;
	fsblkcnt_t	f_bavail;
	fsfilcnt_t	f_files;
	fsfilcnt_t	f_ffree;
	fsfilcnt_t	f_favail;
	unsigned long	f_fsid;
	unsigned long	f_flag;
	unsigned long	f_namemax;
};

#define ST_RDONLY	1
#define ST_NOSUID	2

int statvfs(const char *__restrict path, struct statvfs *__restrict buf);
int fstatvfs(int fd, struct statvfs *buf);

#endif /* H2_SYS_STATVFS_H */
