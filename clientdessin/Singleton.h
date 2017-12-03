#pragma once

/**
singleton contenant l'initialisation de la librairie winsock2.

Assure que la DLL de la winsock est initialisée une unique fois

*/

#include <WinSock2.h>
#include <iostream>


class Singleton
{
	WSADATA wsaData;	//  structure contenant les données de la librairie winsock à initialiser. représente la DLL.

public:
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}
private:
	Singleton();
	Singleton(Singleton const&);
	~Singleton();
};

