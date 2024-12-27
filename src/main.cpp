#include "miicam.h"
#include <iostream>

// Callback function for receiving frames
void __stdcall FrameCallback(const void* pData, const BITMAPINFOHEADER* pHeader, void* pContext) {
    std::cout << "Frame received: Width = " << pHeader->biWidth << ", Height = " << pHeader->biHeight << std::endl;
}

int main() {
    HMiicam cameraHandle;

    // Initialize the camera
    if (!InitCamera(cameraHandle)) {
        std::cerr << "Error initializing camera." << std::endl;
        return -1;
    }

    // Start live imaging with the callback
    if (!StartLiveImaging(cameraHandle, FrameCallback, nullptr)) {
        std::cerr << "Error starting live imaging." << std::endl;
        Miicam_Close(cameraHandle);
        return -1;
    }

    // Prepare a buffer for image capture
    unsigned char imageBuffer[1920 * 1080 * 3]; // Example buffer size for 1080p RGB image
    unsigned int width = 1920, height = 1080;

    // Capture an image into the buffer
    if (!CaptureImage(cameraHandle, imageBuffer, sizeof(imageBuffer), width, height)) {
        std::cerr << "Error capturing image." << std::endl;
        Miicam_Close(cameraHandle);
        return -1;
    }

    std::cout << "Image captured successfully!" << std::endl;

    // Close the camera
    Miicam_Close(cameraHandle);
    return 0;
}
