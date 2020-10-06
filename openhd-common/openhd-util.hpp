#ifndef OPENHD_UTIL_H
#define OPENHD_UTIL_H



#include "openhd-types.h"
#include "openhd-structs.h"



inline std::string to_uppercase(std::string input) {
    for (std::string::iterator it = input.begin(); it != input.end(); ++ it) {
        *it = toupper((unsigned char)*it);
    }

    return input;
}

inline std::string camera_type_to_string(CameraType camera_type) {
    switch (camera_type) {
        case CameraTypeRaspberryPiCSI: {
            return "pi-csi";
        }
        case CameraTypeJetsonCSI: {
            return "jetson-csi";
        }
        case CameraTypeRockchipCSI: {
            return "rockchip-csi";
        }
        case CameraTypeUVC: {
            return "uvc";
        }
        case CameraTypeIP: {
            return "ip";
        }
        default: {
            return "unknown";
        }
    }
}



inline std::string platform_type_to_string(PlatformType platform_type) {
    switch (platform_type) {
        case PlatformTypeJetson: {
            return "jetson";
        }
        case PlatformTypeRaspberryPi: {
            return "raspberrypi";
        }
        case PlatformTypeNanoPi: {
            return "nanopi";
        }
        case PlatformTypePC: {
            return "pc";
        }
        default: {
            return "unknown";
        }
    }
}


inline std::string wifi_card_type_to_string(WiFiCardType card_type) {
    switch (card_type) {
        case WiFiCardTypeAtheros9k: {
            return "ath9k_htc";
        }
        case WiFiCardTypeRealtek8812au: {
            return "88xxau";
        }
        case WiFiCardTypeRealtek88x2bu: {
            return "88x2bu";
        }
        case WiFiCardTypeRealtek8188eu: {
            return "8188eu";
        }
        case WiFiCardTypeRalink: {
            return "rt2800usb";
        }
        case WiFiCardTypeIntel: {
            return "iwlwifi";
        }
        case WiFiCardTypeBroadcom: {
            return "brcmfmac";
        }
        default: {
            return "unknown";
        }
    }
}


inline WiFiCardType string_to_wifi_card_type(std::string driver_name) {
    if (to_uppercase(driver_name).find(to_uppercase("ath9k_htc")) != std::string::npos) {
        return WiFiCardTypeAtheros9k;
    } else if (to_uppercase(driver_name).find(to_uppercase("rt2800usb")) != std::string::npos) {
        return WiFiCardTypeRalink;
    } else if (to_uppercase(driver_name).find(to_uppercase("iwlwifi")) != std::string::npos) {
        return WiFiCardTypeIntel;
    } else if (to_uppercase(driver_name).find(to_uppercase("brcmfmac")) != std::string::npos) {
        return WiFiCardTypeBroadcom;
    } else if (to_uppercase(driver_name).find(to_uppercase("88xxau")) != std::string::npos) {
        return WiFiCardTypeRealtek8812au;
    } else if (to_uppercase(driver_name).find(to_uppercase("8812au")) != std::string::npos) {
        return WiFiCardTypeRealtek8812au;
    } else if (to_uppercase(driver_name).find(to_uppercase("88x2bu")) != std::string::npos) {
        return WiFiCardTypeRealtek88x2bu;
    } else if (to_uppercase(driver_name).find(to_uppercase("8188eu")) != std::string::npos) {
        return WiFiCardTypeRealtek8188eu;
    }

    return WiFiCardTypeUnknown;
}


inline std::string wifi_hotspot_type_to_string(WiFiHotspotType wifi_hotspot_type) {
    switch (wifi_hotspot_type) {
        case WiFiHotspotTypeInternal2GBand: {
            return "internal2g";
        }
        case WiFiHotspotTypeInternal5GBand: {
            return "internal5g";
        }
        case WiFiHotspotTypeInternalDualBand: {
            return "internaldualband";
        }
        case WiFiHotspotTypeExternal: {
            return "external";
        }
        default: {
            return "none";
        }
    }
}


inline WiFiHotspotType string_to_wifi_hotspot_type(std::string hotspot_type) {
    if (to_uppercase(hotspot_type).find(to_uppercase("internal2g")) != std::string::npos) {
        return WiFiHotspotTypeInternal2GBand;
    } else if (to_uppercase(hotspot_type).find(to_uppercase("internal5g")) != std::string::npos) {
        return WiFiHotspotTypeInternal5GBand;
    } else if (to_uppercase(hotspot_type).find(to_uppercase("internaldualband")) != std::string::npos) {
        return WiFiHotspotTypeInternalDualBand;
    } else if (to_uppercase(hotspot_type).find(to_uppercase("external")) != std::string::npos) {
        return WiFiHotspotTypeExternal;
    }

    return WiFiHotspotTypeNone;
}


#endif