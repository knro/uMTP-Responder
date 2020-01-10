/*
 * uMTP Responder
 * Copyright (c) 2018 - 2020 Viveris Technologies
 *
 * uMTP Responder is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * uMTP Responder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 3 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with uMTP Responder; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * @file   mtp_op_closesession.c
 * @brief  Close session operation.
 * @author Jean-Fran�ois DEL NERO <Jean-Francois.DELNERO@viveris.fr>
 */

#include "buildconf.h"

#include <sys/types.h>

#include <stdio.h>
#include <stdint.h>

#include <errno.h>

#include <pthread.h>

#include <inttypes.h>

#include "logs_out.h"

#include "mtp_helpers.h"

#include "mtp.h"

#include "mtp_constant.h"
#include "mtp_constant_strings.h"

#include "mtp_support_def.h"

#include "mtp_operations.h"

uint32_t mtp_op_CloseSession(mtp_ctx * ctx,MTP_PACKET_HEADER * mtp_packet_hdr, int * size,uint32_t * ret_params, int * ret_params_size)
{
	if(!ctx->fs_db)
		return MTP_RESPONSE_SESSION_NOT_OPEN;

	deinit_fs_db(ctx->fs_db);

	ctx->fs_db = 0;

	return MTP_RESPONSE_OK;
}