// Visual Studio command
// -m sequence K.xml

#include <stdio.h>
#include <string.h>

#include "sfm.h"

/// �ΰ��� �ɼ��� ����. Structure from Motion�� �ϴ���, Sequence Play�� �ϴ���.
#define doSFM		0
#define doPlaySeq	1

/**
 * ���� �Լ� : Ŀ�ǵ���� ��ǲ�� �޾Ƽ� �ش� �Լ��� �б�.
 * 
 * \author Hyon Lim
 *
 * Usage : main [-s|-p] [<sequence-path>] [<K-matrix.xml>]
 *
 * - -s  SfM�� �����Ѵ�.
 * - -p  Sequence�� ����Ѵ�.
**/
int main(int argc,char *argv[])
{
	int option = -1;

	if (argc >= 3)
	{
		if(argc >= 4 && strcmp(argv[1], "-m") == 0)
		{
			option = doSFM;
		}
		else if(strcmp(argv[1], "-p") == 0)
		{
			option = doPlaySeq;
		}
	}

	switch(option)
	{
		case doSFM:
			SfM(argv[2], argv[3]);
			break;

		case doPlaySeq:
			break;

		default:
			printf("Usage : %s [-s|-p] [<sequence-path>] [<K-matrix.xml>]\n", argv[0]);
			printf("-s\tdo structure from motion (K matrix required)\n");
			printf("-p\tplay the sequence\n");
			break;
	}

	return 0;
}