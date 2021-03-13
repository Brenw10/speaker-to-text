#define MINIAUDIO_IMPLEMENTATION
#include "lib/miniaudio.h"

ma_encoder_config encoderConfig;
ma_encoder encoder;
ma_device_config deviceConfig;
ma_device device;
ma_backend backends[] = {ma_backend_wasapi};

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    ma_encoder* pEncoder = (ma_encoder*)pDevice->pUserData;
    MA_ASSERT(pEncoder != NULL);
    ma_encoder_write_pcm_frames(pEncoder, pInput, frameCount);
}

void start_system_record(char* path) {
    encoderConfig = ma_encoder_config_init(ma_resource_format_wav, ma_format_f32, 2, 44100);
    ma_encoder_init_file(path, &encoderConfig, &encoder);

    deviceConfig = ma_device_config_init(ma_device_type_loopback);
    deviceConfig.capture.pDeviceID = NULL;
    deviceConfig.capture.format = encoder.config.format;
    deviceConfig.capture.channels = encoder.config.channels;
    deviceConfig.sampleRate = encoder.config.sampleRate;
    deviceConfig.dataCallback = data_callback;
    deviceConfig.pUserData = &encoder;

    ma_device_init_ex(backends, sizeof(backends) / sizeof(backends[0]), NULL, &deviceConfig, &device);
    ma_device_start(&device);
}

void stop_system_record() {
    ma_device_uninit(&device);
    ma_encoder_uninit(&encoder);
}