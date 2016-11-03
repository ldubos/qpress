#ifndef QPRESS_H

# define QPRESS_H

/*
**
**	 _                 _            _          ______  _   _ ______  _____  _____
**	| |               | |          (_)         |  _  \| | | || ___ \|  _  |/  ___|
**	| |     _   _   __| |__      __ _   __ _   | | | || | | || |_/ /| | | |\ `--.
**	| |    | | | | / _` |\ \ /\ / /| | / _` |  | | | || | | || ___ \| | | | `--. \
**	| |____| |_| || (_| | \ V  V / | || (_| |  | |/ / | |_| || |_/ /\ \_/ //\__/ /
**	\_____/ \__,_| \__,_|  \_/\_/  |_| \__, |  |___/   \___/ \____/  \___/ \____/
**	                                    __/ |
**	                                   |___/
**
**	File : qpress.h
*/

# include <stdio.h>
# include <stdint.h>
# include <malloc.h>
# include <chrono>
# include <thread>
# include <string.h>
# include <math.h>
# include <time.h>
# include <iostream>
# include <string>
# include <algorithm>
# include <stdexcept>
# include <vector>


using namespace std;

static const uint16_t		CHUNK_LENGHT( 4096 );
static const uint64_t		LOC_MULTI( powl(39, CHUNK_LENGHT) );
static const string			TEXT_FORMAT( "abcdefghijklmnopqrstuvwxyz .,ABCDEFGHIJKLMNOPQRTUVWXYZ0123456789+/'\"\\\n\t[]{} = +-_)(*&^%$#@!~`\r" );
static const string			ADDR_FORMAT( "0123456789ABCDEFGHIJKLMNOPQRTUVWXYZabcdefghijklmnopqrstuvwxyz+/;'\"[]{}\\|=-_)(*&^%$#@!~`?.><þ" );


/*
**	qpress.cpp
*/
string					qpressFetchAdress(string str);
string					qpressGetChunkContent(string addr);

#endif
