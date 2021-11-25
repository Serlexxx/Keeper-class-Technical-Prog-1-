#pragma once
#include <Windows.h>
#include <iostream>
#include "Point.h"


/**
 * \brief �������� ������ ����� (��������� ������ �������� RGBQUAD)
 * \param width ������ ������ �����
 * \param height ������ ������ �����
 * \param clearColor ����������� ����
 * \return ��������� �� ������
 */
RGBQUAD* CreateFrameBuffer(uint32_t width, uint32_t height, RGBQUAD clearColor = { 0,0,0,0 });

/**
 * \brief ���������� ������ ����������� �����-�� ���������� ������
 * \param buffer ����� ����� (��������� �� ������)
 * \param pixelCount ���-�� �������� � ������
 * \param clearColor ����
 */
void ClearFrame(RGBQUAD* buffer, uint32_t pixelCount, RGBQUAD clearColor = { 0,0,0,0 });


/**
 * \brief ��������� �������
 * \param buffer ����� ����� (��������� �� ������)
 * \param x ��������� �� ��� X
 * \param y ��������� �� ��� Y
 * \param w ������ �����-������
 * \param color ������� �����
 */
void SetPoint(RGBQUAD* buffer, int x, int y, uint32_t w, RGBQUAD color = { 0,0,0,0 });


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
void SetLine(Point* vertexesBrenz, RGBQUAD* buffer, uint32_t w, RGBQUAD color = { 0,0,0,0 });


/**
 * \brief ��������� �����
 * \param width ������
 * \param height ������
 * \param pixels ������ ��������
 * \param hWnd ����� ����, device context �������� ����� �����������
 */
void PresentFrame(uint32_t width, uint32_t height, void* pixels, HWND hWnd);

void Sketch(RGBQUAD* buffer, int x, int y, int32_t w, RGBQUAD OldColor, RGBQUAD NewColor);
