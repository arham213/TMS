#pragma once
#include "Vehicle.h"

class delivery_vehicle :public virtual Vehicle {
public:
	delivery_vehicle(int vid = 0, int rno = 0, float mil = 0.0f, char* lic = nullptr, char* ftype = nullptr, float rank = 0.0f, int d = 0, int m = 0, int y = 0) :Vehicle(vid, rno, mil, lic, ftype, rank, d, m, y) {}
	virtual const char* get_vehicle_service_category();
};