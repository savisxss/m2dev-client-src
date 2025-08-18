#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <assert.h>
//#include <crtdbg.h>

//#include "Forest.h"
#include "SpeedTreeForestDirectX8.h"

// Armadillo nanomite protection
#ifndef NANOBEGIN
	#ifdef __BORLANDC__
		#define NANOBEGIN     
		#define NANOEND       
	#else
		#define NANOBEGIN     
		#define NANOEND       
	#endif
#endif
