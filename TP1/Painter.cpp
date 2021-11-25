#include "Painter.h"



/**
* \brief Создание буфера кадра (двумерный массив структур RGBQUAD)
* \param width Ширина буфера кадра
* \param height Высота буфера кадра
* \param clearColor Изначальный цвет
* \return Указатель на массив
*/
RGBQUAD* CreateFrameBuffer(uint32_t width, uint32_t height, RGBQUAD clearColor)
{

	RGBQUAD* frame = new RGBQUAD[width * height];
	ClearFrame(frame, width * height, clearColor);
	return frame;
}

/**
* \brief Заполнение буфера изображения каким-то конкретным цветом
* \param buffer Буфер кадра (указатель на массив)
* \param pixelCount Кол-во пикселей в буфере
* \param clearColor Цвет
*/
void ClearFrame(RGBQUAD* buffer, uint32_t pixelCount, RGBQUAD clearColor)
{
	std::fill_n(buffer, pixelCount, clearColor);
}

/**
* \brief Установка пикселя
* \param buffer Буфер кадра (указатель на массив)
* \param x Положение по оси X
* \param y Положение по ост Y
* \param w Ширина фрейм-буфера
* \param color Очистка цвета
*/
void SetPoint(RGBQUAD* buffer, int x, int y, uint32_t w, RGBQUAD color)
{

	buffer[(y * w) + x] = color;
}

/**
* \brief Рисование линии (быстрый вариант, алгоритм Брэзенхема)
* \param buffer Буфер кадра (указатель на массив)
* \param x0 Начальная точка (компонента X)
* \param y0 Начальная точка (компонента Y)
* \param x1 Конечная точка (компонента X)
* \param y1 Конечная точка (компонента Y)
* \param w Ширина фрейм-буфера
* \param color Очистка цвета
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
 * \brief Отрисовка кадра
 * \param width Ширина
 * \param height Высота
 * \param pixels Массив пикселов
 * \param hWnd Хендл окна, device context которого будет использован
 */
void PresentFrame(uint32_t width, uint32_t height, void* pixels, HWND hWnd)
{
	// Получить хендл на временный bit-map (4 байта на пиксель)
	HBITMAP hBitMap = CreateBitmap(width, height, 1, 8 * 4, pixels);

	// Получить device context окна
	HDC hdc = GetDC(hWnd);


	// Временный DC для переноса bit-map'а
	HDC srcHdc = CreateCompatibleDC(hdc);

	// Связать bit-map с временным DC
	SelectObject(srcHdc, hBitMap);
	// Копировать содержимое временного DC в DC окна
	BitBlt(
		hdc,    // HDC назначения
		0,      // Начало вставки по оси X
		0,      // Начало вставки по оси Y
		width,  // Ширина
		height, // Высота
		srcHdc, // Исходный HDC (из которого будут копироваться данные)
		0,      // Начало считывания по оси X
		0,      // Начало считывания по оси Y
		SRCCOPY // Копировать
	);

	// Уничтожить bit-map
	DeleteObject(hBitMap);
	// Уничтодить временный DC
	DeleteDC(srcHdc);
	// Уничтодить DC
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