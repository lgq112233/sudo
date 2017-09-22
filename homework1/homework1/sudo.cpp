#include "stdafx.h"
#include "sudo.h"


sudo::sudo(int m2[9][9]) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				this->m[i][j] = m2[i][j];
			}
		}
	}
sudo::~sudo() {}




