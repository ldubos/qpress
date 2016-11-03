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
**	File : main.cpp
*/

#include "qpress.h"

int						main()
{
	int a;
	string addr = qpressFetchAdress("tets");
	cout << TEXT_FORMAT.length() << "|" << ADDR_FORMAT.length() << endl;
	cout << "Adrr : " << addr << endl;
	cout << "Content : " << endl << qpressGetChunkContent(addr) << endl;
	cin >> a;
	return 0;
}