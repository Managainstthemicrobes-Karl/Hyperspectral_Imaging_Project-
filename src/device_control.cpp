#include "miicam.h"

// Example function for initializing the camera
bool InitCamera(HMiicam& cameraHandle) {
    cameraHandle = Miicam_Open(0);
    return cameraHandle != nullptr;
}

// Example function for starting live imaging
bool StartLiveImaging(HMiicam cameraHandle, PMIICAM_DATA_CALLBACK callback, void* context) {
    return Miicam_StartPushMode(cameraHandle, callback, context) == S_OK;
}

// Example function for capturing an image
bool CaptureImage(HMiicam cameraHandle, unsigned char* buffer, unsigned int bufferSize, unsigned int& width, unsigned int& height) {
    return Miicam_PullImage(cameraHandle, buffer, bufferSize, &width, &height) == S_OK;
}
