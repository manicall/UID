#include <dos.h>
int video_mode()
{
	int v;
	union REGS in, out; //������� � �������� �������� ���������
	in.h.ah = 0x0f; //������� 0Fh
	v = int86(0x10, &in, &out);
	return 255 & v; //�������� �������� �����
}
