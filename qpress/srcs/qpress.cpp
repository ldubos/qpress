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
**	File : qpress.cpp
*/

#include "qpress.h"

uint64_t				qpressStrToInt(string str, int base)
{
	uint64_t			_return( 0 );

	for (size_t x(0); x < str.length(); x++)
		_return			+= static_cast<uint64_t>(floor(ADDR_FORMAT.find(str.at(str.length() - x - 1)) * pow(base, x)));

	return _return;
}

string					qpressIntToBase(uint64_t x, int base)
{
	string				_return( "" );

	while (x)
	{
		_return.push_back(ADDR_FORMAT.at(x % base));
		x				/= base;
	}

	reverse(_return.begin(), _return.end());
	return _return;
}

string					qpressFetchAdress(string str)
{
	string				_addrPartA(		""		);
	string				_addrPartB(		""		);
	string				_addrPartC(		""		);
	string				_addrPartD(		""		);
	string				_addrPartH(		""		);
	string				_leftPadding(	""		);
	string				_rightPadding(	""		);
	string				_addr(			""		);

	uint64_t			_location( 0 );
	uint64_t			_depth( 0 );

	srand(CHUNK_LENGHT % time(NULL));

	_addrPartA			= to_string(	rand() % 4 + 1	);
	_addrPartB			= to_string(	rand() % 5 + 1	);
	_addrPartC			= to_string(	rand() % 32 + 1	);
	_addrPartD			= to_string(	rand() % 410 + 1	);
	_location			= qpressStrToInt(_addrPartD + _addrPartC + _addrPartB + _addrPartA, 10);
	_depth				= CHUNK_LENGHT - str.length();

	for (size_t x(0); x <= _depth; x++)
			_leftPadding.push_back(ADDR_FORMAT.at(rand() % ADDR_FORMAT.length()));
//	reverse(_leftPadding.begin(), _leftPadding.end());
	for (size_t x(0); x <= (CHUNK_LENGHT - (_depth + str.length())); x++)
			_rightPadding.push_back(ADDR_FORMAT.at(rand() % ADDR_FORMAT.length()));
//	reverse(_rightPadding.begin(), _rightPadding.end());

	str					= _leftPadding + str + _rightPadding;
	_addrPartH			+= qpressIntToBase(qpressStrToInt(str, ADDR_FORMAT.length()) + _location * LOC_MULTI, ADDR_FORMAT.length());
	_addr				+= _addrPartH + ":" + _addrPartA + ":" + _addrPartB + ":" + _addrPartC + ":" + _addrPartD;

	return _addr;
}

string					qpressToText(uint64_t x)
{
	string				_return( "" );

	while (x)
	{
		_return.push_back(TEXT_FORMAT.at(x % TEXT_FORMAT.length()));
		x				/= TEXT_FORMAT.length();
	}

	reverse(_return.begin(), _return.end());

	return _return;
}

string					qpressGetChunkContent(string addr)
{
	string				_args[5];
	string				_temp(addr);

	for (int index = 0; index < 5; index++)
	{
		_args[index]	= _temp.substr(0, _temp.find(":"));
		cout << "args[" << index << "] => " << _args[index] << endl;
		_temp.erase(0, _temp.find(":") + 1);
	}

	uint64_t			_location(qpressStrToInt("000" + _args[4] + "00" + _args[3] + _args[2] + _args[1], 10));
	uint64_t			_key(qpressStrToInt(_args[0], 10));

	_key				-= _location * LOC_MULTI;

	string				_baseAddr( qpressIntToBase(_key, ADDR_FORMAT.length()) );
	string				_result( qpressToText(qpressStrToInt(_baseAddr, ADDR_FORMAT.length())) );

/*	if (_result.length() < CHUNK_LENGHT)
	{
		srand((int)_key);

		while (_result.length() < CHUNK_LENGHT)
			_result += TEXT_FORMAT.at(rand() % TEXT_FORMAT.length());
	}*/

	return _result;
}