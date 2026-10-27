/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

/*
 * <sys/dirent.h> for H2 + picolibc.  Generic picolibc builds (e.g. the
 * CodeLinaro Hexagon toolchains) ship a <sys/dirent.h> that only #errors;
 * this one is found first through the wrapper's -Iinclude and describes the
 * DIR that syscall_wrapper.c builds on top of the angel opendir/readdir
 * calls.
 */
#ifndef H2_SYS_DIRENT_H
#define H2_SYS_DIRENT_H

#include <sys/types.h>

#define DT_UNKNOWN	0
#define DT_FIFO		1
#define DT_CHR		2
#define DT_DIR		4
#define DT_BLK		6
#define DT_REG		8
#define DT_LNK		10
#define DT_SOCK		12

struct dirent {
	ino_t		d_ino;
	unsigned char	d_type;
	char		d_name[256];
};

typedef struct {
	int		fd;
	/* angel readdir buffer, holds a dirent_internal (long + char[255]) */
	long		buf[(sizeof(long) + 255 + sizeof(long) - 1) / sizeof(long)];
	struct dirent	dirent;
} DIR;

#endif /* H2_SYS_DIRENT_H */
