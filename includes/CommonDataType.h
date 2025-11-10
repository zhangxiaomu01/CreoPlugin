#pragma once

#ifndef NDSFloat32
#define NDSFloat32 float
#endif

#ifndef NDSDouble
#define NDSDouble double
#endif

#ifndef NDSInt32
#define NDSInt32 int
#endif

#ifndef NDSUInt32
#define NDSUInt32 unsigned int
#endif

namespace ModelTransfer {
	struct NDSMaterial {
		NDSUInt32 id = -1;
		NDSMaterial() = default;
	};
}

struct NDSMatrix {
	NDSDouble matrix[16] = { 0 };

	NDSMatrix() {
		matrix[0] = 1.0;
		matrix[5] = 1.0;
		matrix[10] = 1.0;
		matrix[15] = 1.0;
	}
};
