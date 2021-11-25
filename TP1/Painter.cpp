#include "Painter.h"



/**
* \brief �������� ������ ����� (��������� ������ �������� RGBQUAD)
* \param width ������ ������ �����
* \param height ������ ������ �����
* \param clearColor ����������� ����
* \return ��������� �� ������
*/
RGBQUAD* CreateFrameBuffer(uint32_t width, uint32_t height, RGBQUAD clearColor)
{

	RGBQUAD* frame = new RGBQUAD[width * height];
	ClearFrame(frame, width * height, clearColor);
	return frame;
}

/**
* \brief ���������� ������ ����������� �����-�� ���������� ������
* \param buffer ����� ����� (��������� �� ������)
* \param pixelCount ���-�� �������� � ������
* \param clearColor ����
*/
void ClearFrame(RGBQUAD* buffer, uint32_t pixelCount, RGBQUAD clearColor)
{
	std::fill_n(buffer, pixelCount, clearColor);
}

/**
* \brief ��������� �������
* \param buffer ����� ����� (��������� �� ������)
* \param x ��������� �� ��� X
* \param y ��������� �� ��� Y
* \param w ������ �����-������
* \param color ������� �����
*/
void SetPoint(RGBQUAD* buffer, int x, int y, uint32_t w, RGBQUAD color)
{

	buffer[(y * w) + x] = color;
}

/**
* \brief ��������� ����� (������� �������, �������� ����������)
* \param buffer ����� ����� (��������� �� ������)
* \param x0 ��������� ����� (���������� X)
* \param y0 ��������� ����� (���������� Y)
* \param x1 �������� ����� (���������� X)
* \param y1 �������� ����� (���������� Y)
* \param w ������ �����-������
* \param color ������� �����
*/

void SetLine(Point* vertexesBrenz, RGBQUAD* buffer, uint32_t w, RGBQUAD color)
{
	int j = 0;
	for (int i = 0; i < 4; i++) {
		i < (4 - 1) ? j++ : j = 0;
		double const deltaX = abs(vertexesBrenz[i].x - vertexesBrenz[j].x);
		double const deltaY = abs(vertexesBrenz[i].y - vertexesBrenz[j].y);
		double x_1, x_2, y_1, y_2;
		double x, y, xend, yend, s, d, inc1, inc2;
		double check_x, check_y;
		x_1 = vertexesBrenz[i].x;
		x_2 = vertexesBrenz[j].x;
		y_1 = vertexesBrenz[i].y;
		y_2 = vertexesBrenz[j].y;

		if (deltaX > deltaY) {
			inc1 = 2 * deltaY;
			inc2 = 2 * (deltaY - deltaX);
			d = 2 * deltaY - deltaX;
			if (x_1 < x_2) {
				x = x_1; y = y_1; xend = x_2;
				(y_1 < y_2) ? s = 1 : s = -1;
			}
			else {
				x = x_2;
				y = y_2;
				xend = x_1;
				(y_1 > y_2) ? s = 1 : s = -1;
			}
			SetPoint(buffer, x, y, w, color);
			while (x < xend) {
				x++;
				if (d > 0) {
					y += s;
					d += inc2;
				}
				else
					d += inc1;
				SetPoint(buffer, x, y, w, color);
			}
		}
		else {
			inc1 = 2 * deltaX;
			inc2 = 2 * (deltaX - deltaY);
			d = 2 * deltaX - deltaY;
			if (y_1 < y_2) {
				y = y_1;
				x = x_1;
				yend = y_2;
				(x_1 < x_2) ? s = 1 : s = -1;
			}
			else {
				y = y_2;
				x = x_2;
				yend = y_1;
				(x_1 > x_2) ? s = 1 : s = -1;
			}
			SetPoint(buffer, x, y, w, color);
			while (y < yend) {
				y++;
				if (d > 0) {
					x += s;
					d += inc2;
				}
				else
					d += inc1;
				SetPoint(buffer, x, y, w, color);
			}

		}
	}
}


/**
 * \brief ��������� �����
 * \param width ������
 * \param height ������
 * \param pixels ������ ��������
 * \param hWnd ����� ����, device context �������� ����� �����������
 */
void PresentFrame(uint32_t width, uint32_t height, void* pixels, HWND hWnd)
{
	// �������� ����� �� ��������� bit-map (4 ����� �� �������)
	HBITMAP hBitMap = CreateBitmap(width, height, 1, 8 * 4, pixels);

	// �������� device context ����
	HDC hdc = GetDC(hWnd);


	// ��������� DC ��� �������� bit-map'�
	HDC srcHdc = CreateCompatibleDC(hdc);

	// ������� bit-map � ��������� DC
	SelectObject(srcHdc, hBitMap);
	// ���������� ���������� ���������� DC � DC ����
	BitBlt(
		hdc,    // HDC ����������
		0,      // ������ ������� �� ��� X
		0,      // ������ ������� �� ��� Y
		width,  // ������
		height, // ������
		srcHdc, // �������� HDC (�� �������� ����� ������������ ������)
		0,      // ������ ���������� �� ��� X
		0,      // ������ ���������� �� ��� Y
		SRCCOPY // ����������
	);

	// ���������� bit-map
	DeleteObject(hBitMap);
	// ���������� ��������� DC
	DeleteDC(srcHdc);
	// ���������� DC
	DeleteDC(hdc);
	//ReleaseDC(hWnd, hdc);
	//PostQuitMessage(0);
}

void Sketch(RGBQUAD* buffer, int x, int y, int32_t w, RGBQUAD OldColor, RGBQUAD NewColor)
{
	if ((buffer[(y * w) + x].rgbRed == OldColor.rgbRed)&& 
		(buffer[(y * w) + x].rgbGreen == OldColor.rgbGreen)&& 
		(buffer[(y * w) + x].rgbBlue == OldColor.rgbBlue))
	{
		SetPoint(buffer, x, y, w, NewColor);
		Sketch(buffer, x + 1, y, w, OldColor, NewColor);
		Sketch(buffer, x - 1, y, w, OldColor, NewColor);
		Sketch(buffer, x, y + 1, w, OldColor, NewColor);
		Sketch(buffer, x, y - 1, w, OldColor, NewColor);
	}
}