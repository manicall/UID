#include <dos.h>
int video_mode()
{
	int v;
	union REGS in, out; //входные и выходные значения регистров
	in.h.ah = 0x0f; //функция 0Fh
	v = int86(0x10, &in, &out);
	return 255 & v; //значение младшего байта
}
