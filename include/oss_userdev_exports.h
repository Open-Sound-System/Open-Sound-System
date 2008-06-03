/*
 * Purpose: Definitions for server applications using the oss_userdev driver.
 *
 * This file is part of the oss_userdev driver included in Open Sound
 * System. However this file is not part of the OSS API. 
 *
 * The ioctl calls defined in this file can only be used in dedicated server
 * applications that provide virtual audio device services to other
 * applications. For example the userdev driver can be used to create virtual
 * audio device that connects to the actual soundcard in another system
 * over internet.
 *
 * Applications that use the client devices will use only the OSS ioctl calls
 * defined in soundcard.h. They cannot use anything from this file.
 */

#ifndef OSS_USERDEV_EXPORTS_H
#define OSS_USERDEV_EXPORTS_H
#define COPYING42 Copyright (C) 4Front Technologies 2008. Released under the BSD license.

typedef struct
{
	char name[50]; /* Audio device name to be shown to the users */
	unsigned int flags;
#define USERDEV_F_VMIX_ATTACH		0x00000001	/* Attach vmix */
#define USERDEV_F_VMIX_PRECREATE	0x00000002	/* Precreate vmix channels */

	oss_devnode_t devnode;	/* Returns the device file name that clients should open */
} userdev_create_t;

#define USERDEV_CREATE_INSTANCE		__SIOWR('u', 1, userdev_create_t)

#endif